from pyHepMC3TestUtils import update_path, python_label
import sys

sys.path = update_path()

from pyHepMC3TestUtils import COMPARE_ASCII_FILES
from pyHepMC3 import HepMC3 as hm


def test_IO81(ext, form):
    inputA = hm.ReaderAsciiHepMC2("inputIO8.hepmc")
    if inputA.failed():
        sys.exit(1)
    outputA = hm.WriterGZ("WriterAscii", python_label() + "frominputIO8.hepmc" + ext, form)
    if outputA.failed():
        sys.exit(12)
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


def test_IO82(ext, form):
    inputB = hm.ReaderGZ("ReaderAscii", python_label() + "frominputIO8.hepmc" + ext, form)
    if inputB.failed():
        sys.exit(3)
    outputB = hm.WriterAsciiHepMC2(python_label() + "fromfrominputIO8" + ext + ".hepmc")
    if outputB.failed():
        sys.exit(4)
    while not inputB.failed():
        evt = hm.GenEvent()
        inputB.read_event(evt)
        print(evt.event_number())
        if inputB.failed():
            print("End of file reached. Exit.\n")
            break
        outputB.write_event(evt)
        evt.clear()
    inputB.close()
    outputB.close()
    assert 0 == COMPARE_ASCII_FILES(python_label() + "fromfrominputIO8" + ext + ".hepmc", "inputIO8.hepmc")
    return 0


def available_formats():
    formats = [('.gz', 'gzip')]

    try:
        import bz2  # noqa: F401
        formats.append(('.bz2', 'bz2'))
    except ImportError:
        pass

    try:
        import lzma  # noqa: F401
        formats.append(('.lzma', 'lzma'))
    except ImportError:
        pass

# 
    try:
        import zstandard  # noqa: F401
        # zstandard is a third-party module; only add support if it exposes open()
        if hasattr(zstandard, 'open'):
            formats.append(('.z', 'zstandard'))
    except ImportError:
        pass

    return formats


def test_IO8():
    result = 0
    for ext, form in available_formats():
        test_IO81(ext, form)
        result += test_IO82(ext, form)
    return result


if __name__ == '__main__':
    result = 1
    try:
        result = test_IO8()
    except:
        result = 1
    sys.exit(result)
