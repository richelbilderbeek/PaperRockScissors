include(../RibiLibraries/Boost.pri)

include(../RibiClasses/CppAbout/CppAbout.pri)
include(../RibiClasses/CppFileIo/CppFileIo.pri)
include(../RibiClasses/CppHelp/CppHelp.pri)
include(../RibiClasses/CppMenuDialog/CppMenuDialog.pri)
include(../RibiClasses/CppQtAboutDialog/CppQtAboutDialog.pri)
include(../RibiClasses/CppQtHideAndShowDialog/CppQtHideAndShowDialog.pri)

include(PaperRockScissors.pri)
include(PaperRockScissorsSimulation.pri)
include(QtPaperRockScissorsSimulation.pri)

include(PaperRockScissorsDesktop.pri)

SOURCES += qtmain.cpp

unix:!macx{
  # Linux only
  message("GNU/Linux")
  message(Host name: $$QMAKE_HOST.name)
  CONFIG += c++14

  # Qt does not go well with -Weffc++
  QMAKE_CXXFLAGS += -Wall -Wextra -Werror -std=c++14

  equals(QT_MAJOR_VERSION, 4): LIBS +=  -lQtSvg
  greaterThan(QT_MAJOR_VERSION, 4): QT +=  concurrent opengl printsupport svg
}

CONFIG += debug_and_release

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

CONFIG(release, debug|release) {
  message(Release mode)
  DEFINES += NDEBUG
}


# Thanks to Qt
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
