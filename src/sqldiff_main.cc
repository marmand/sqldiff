/*!
 * \author: Armand Leclercq
 * \file: sqldiff_main.cc
 * \date: Sat 14 Oct 2017 08:42:39 PM UTC
 */
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/spirit/include/support_istream_iterator.hpp>

#include <fstream>
#include <iostream>

#include <config.hh>
#include <sqldiff.hh>

namespace po = boost::program_options;

int
main(int argc
     , char* argv[])
{
  po::options_description general("General options");
  general.add_options()
    ("help,h", "Produces help message")
    ("version,v", "Show program version")
  ;

  po::options_description hidden("Hidden options");
  hidden.add_options()
    ("input-file", po::value<std::vector<std::string>>(), "File")
  ;
  po::positional_options_description p;
  p.add("input-file", -1);

  po::options_description all("All options");
  all.add(general).add(hidden);

  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv)
              .options(all)
              .positional(p)
              .run()
            , vm);

  if (vm.count("help"))
  {
    std::cout << general;
    return 1;
  }

  if (vm.count("version"))
  {
    std::cout << PACKAGE_STRING << std::endl
              << "Project page: " << PACKAGE_URL << std::endl
              << "Report bugs to " << PACKAGE_BUGREPORT << std::endl
    ;
    return 0;
  }

  if (!!!vm.count("input-file"))
  {
    std::cerr << "Usage: sqldiff [options…] <file> <file>" << std::endl;
    std::cerr << general;
    return 2;
  }
  if (2 != vm.count("input-file"))
  {
    std::cerr << "Error: sqldiff needs two files to compare."
              << std::endl;
    std::cerr << general;
    return 2;
  }

  std::cout << "Hello Word" << std::endl;
  return 0;
}
