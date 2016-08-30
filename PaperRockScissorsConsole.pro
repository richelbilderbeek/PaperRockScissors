include(../RibiLibraries/ConsoleApplicationNoWeffcpp.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/GeneralConsole.pri)

include(../RibiClasses/CppPaperRockScissors/CppPaperRockScissors.pri)
include(../RibiClasses/CppPaperRockScissorsSimulation/CppPaperRockScissorsSimulation.pri)

include(PaperRockScissorsConsole.pri)

SOURCES += main.cpp

# Thanks to Qt
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
