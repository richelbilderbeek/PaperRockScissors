# Qt does not go well with -Weffc++
include(../RibiLibraries/DesktopApplicationNoWeffcpp.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralDesktop.pri)

include(../RibiClasses/CppPaperRockScissors/CppPaperRockScissors.pri)
include(../RibiClasses/CppPaperRockScissorsSimulation/CppPaperRockScissorsSimulation.pri)
include(../RibiClasses/CppQtPaperRockScissorsSimulation/CppQtPaperRockScissorsSimulation.pri)

include(PaperRockScissorsDesktop.pri)

SOURCES += qtmain.cpp
