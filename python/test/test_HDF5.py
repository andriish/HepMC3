from pyHepMC3TestUtils import update_path, python_label
import sys

sys.path = update_path()

from pyHepMC3TestUtils import COMPARE_ASCII_FILES
from pyHepMC3 import HepMC3 as hm
from pyHepMC3.hdf5IO import HepMC3 as hmhdf5


def test_HDF5():
    inputA = hm.ReaderAsciiHepMC2("inputIO26.hepmc")
    if inputA.failed():
        sys.exit(2)

    outputA = hmhdf5.WriterHDF5(python_label() + "frominputIO26.h5")
    if outputA.failed():
        sys.exit(3)

    while not inputA.failed():
        evt = hm.GenEvent()
        inputA.read_event(evt)
        if inputA.failed():
            print("End of file reached. Exit.\n")
            break
        outputA.write_event(evt)
        evt.clear()

    inputA.close()
    outputA.close()

    inputB = hmhdf5.ReaderHDF5(python_label() + "frominputIO26.h5")
    if inputB.failed():
        sys.exit(4)

    outputB = hm.WriterAsciiHepMC2(python_label() + "fromfrominputIO26.hepmc")
    if outputB.failed():
        sys.exit(5)

    while not inputB.failed():
        evt = hm.GenEvent()
        inputB.read_event(evt)
        if inputB.failed():
            print("End of file reached. Exit.\n")
            break
        outputB.write_event(evt)
        evt.clear()

    inputB.close()
    outputB.close()

    print("Checking file correspondence")
    assert 0 == COMPARE_ASCII_FILES(python_label() + "fromfrominputIO26.hepmc", "inputIO26.hepmc")
    print("Files match")
    return 0


if __name__ == "__main__":
    result = 1
    try:
        result = test_HDF5()
    except:
        result = 6
    sys.exit(result)
