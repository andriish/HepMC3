from pyHepMC3TestUtils import update_path, python_label
import sys

sys.path = update_path()

from pyHepMC3 import HepMC3 as hm
from pyHepMC3.hdf5IO import LHEFHDF5


def create_lhe_event(event_number):
    heprup = hm.LHEF.HEPRUP()
    heprup.IDBMUP = (2212, 2212)
    heprup.EBMUP = (6500.0, 6500.0)
    heprup.PDFGUP = (0, 0)
    heprup.PDFSUP = (260000, 260000)
    heprup.IDWTUP = 3
    heprup.NPRUP = 1
    heprup.resize()
    heprup.XSECUP = [100.0]
    heprup.XERRUP = [2.5]
    heprup.XMAXUP = [1.0]
    heprup.LPRUP = [100]

    hepeup = hm.LHEF.HEPEUP()
    hepeup.NUP = 4
    hepeup.IDPRUP = 100
    hepeup.XWGTUP = 1.25 + 0.1 * event_number
    hepeup.SCALUP = 91.188
    hepeup.AQEDUP = 0.00729735
    hepeup.AQCDUP = 0.118
    hepeup.ntries = event_number + 1
    hepeup.IDUP = [2212, 2212, 11, -11]
    hepeup.ISTUP = [-1, -1, 1, 1]
    hepeup.MOTHUP = [(0, 0), (0, 0), (1, 2), (1, 2)]
    hepeup.ICOLUP = [(0, 0), (0, 0), (0, 0), (0, 0)]
    momentum = 10.0 + event_number
    hepeup.PUP = [
        [0.0, 0.0, 6500.0, 6500.0, 0.938],
        [0.0, 0.0, -6500.0, 6500.0, 0.938],
        [momentum, 20.0, 30.0, 50.0, 0.000511],
        [-momentum, -20.0, -30.0, 50.0, 0.000511],
    ]
    hepeup.VTIMUP = [0.0, 0.0, 0.0, 0.0]
    hepeup.SPINUP = [9.0, 9.0, 9.0, 9.0]
    return heprup, hepeup


def test_LHEFHDF5():
    heprup, _ = create_lhe_event(0)
    writer = LHEFHDF5.Writer(python_label() + "lhehdf5.h5")
    writer.heprup = heprup
    writer.init()
    for event_number in range(3):
        _, event = create_lhe_event(event_number)
        writer.hepeup = event
        writer.writeEvent()
    if writer.failed():
        return 1
    writer.close()

    reader = LHEFHDF5.Reader(python_label() + "lhehdf5.h5")
    for event_number in range(3):
        if not reader.readEvent():
            return 1
        if reader.hepeup.NUP != 4 or reader.hepeup.IDPRUP != 100:
            return 1
        if reader.hepeup.IDUP != [2212, 2212, 11, -11]:
            return 1
        if reader.hepeup.PUP[0][2] != 6500.0 or reader.hepeup.PUP[1][2] != -6500.0:
            return 1
        if reader.hepeup.XWGTUP != 1.25 + 0.1 * event_number:
            return 1
    if reader.readEvent():
        return 1
    reader.close()
    return 0


if __name__ == "__main__":
    sys.exit(test_LHEFHDF5())