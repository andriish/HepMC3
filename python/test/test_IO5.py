from pyHepMC3TestUtils import update_path, python_label
import sys

sys.path = update_path()


from pyHepMC3TestUtils import COMPARE_ASCII_FILES
from pyHepMC3 import HepMC3 as hm
from pyHepMC3.rootIO import HepMC3 as hmrootIO

print(dir(hmrootIO))


def test_IO5():
    inputA = hmrootIO.ReaderRootTree("inputIO5.root")
    if inputA.failed():
        sys.exit(1)
    inputB = hm.ReaderuprootTree("inputIO5.root")
    if inputB.failed():
        sys.exit(2)
    outputA = hm.WriterAsciiHepMC2(python_label() + "ReaderRootTreeinputIO5.hepmc")
    if outputA.failed():
        sys.exit(3)
    outputB = hm.WriterAsciiHepMC2(python_label() + "ReaderuprootTreeinputIO5.hepmc")
    if outputB.failed():
        sys.exit(4)

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

    assert 0 == COMPARE_ASCII_FILES(python_label() + "ReaderRootTreeinputIO5.hepmc", python_label() + "ReaderuprootTreeinputIO5.hepmc")
    return 0


if __name__ == "__main__":
    result = 1
    try:
        result = test_IO5()
    except:
        result = 1
    sys.exit(result)
