#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "paperrockscissorsmenudialog.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>

#include <boost/lexical_cast.hpp>

#include <QFile>

#include "paperrockscissorssimulation.h"
#include "fileio.h"
#include "testtimer.h"
#include "trace.h"
#pragma GCC diagnostic pop

ribi::prs::MenuDialog::MenuDialog()
{
  #ifndef NDEBUG
  Test();
  #endif
}

int ribi::prs::MenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc > 0) //Always
  {
    std::cout << GetHelp() << '\n';
    return 0;
  }
  return 0;
}

ribi::About ribi::prs::MenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "PaperRockScissors",
    "paper-rock-scissors simulation",
    "the 19th of November 2015",
    "2015-2015",
    "http://www.richelbilderbeek.nl/ToolPaperRockScissors.htm",
    GetVersion(),
    GetVersionHistory()
  );
  a.AddLibrary("TestTimer version: " + TestTimer::GetVersion());
  a.AddLibrary("Trace version: " + Trace::GetVersion());
  return a;
}

std::string ribi::prs::MenuDialog::GetVersion() const noexcept
{
  return "3.0";
}

std::vector<std::string> ribi::prs::MenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2015-05-03: Version 0.1: initial standalone version",
    "2015-05-11: Version 1.0: conformized version",
    "2015-05-24: Version 2.0: put in namespace ribi::prs",
    "2015-11-19: Version 3.0: moved to own GitHub"
  };
}

ribi::Help ribi::prs::MenuDialog::GetHelp() const noexcept
{
  return ribi::Help(
    "PaperRockScissors",
    "paper-rock-scissors simulation",
    {
      //No additional options
    },
    {
    }
  );
}

#ifndef NDEBUG
void ribi::prs::MenuDialog::Test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  {
    fileio::FileIo();
    TestPaperRockScissors();
  }
  const TestTimer test_timer(__func__,__FILE__,1.0);
}
#endif
