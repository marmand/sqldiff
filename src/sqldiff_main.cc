/*!
 * \author: Armand Leclercq
 * \file: sqldiff_main.cc
 * \date: Sat 14 Oct 2017 08:42:39 PM UTC
 */
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

#include <iostream>

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

  po::options_description command_line;
  command_line.add(general).add(hidden);

  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv)
              .options(command_line)
              .run()
            , vm);
  po::notify(vm);

  if (vm.count("help"))
  {
    std::cout << general;
    return 1;
  }

  if (!!!vm.count("input-file"))
  {
    std::cerr << "Usage: sqldiff [option]… <file>…" << std::endl;
    std::cerr << general;
    return 2;
  }
  if (vm.count("input-file") < 2)
  {
    std::cerr << "Error: sqldiff needs at least two files to compare."
              << std::endl;
    std::cerr << general;
    return 2;
  }

  std::cout << "Hello Word" << std::endl;
  return 0;
}
