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

  po::options_description desc("Allowed options");
  desc.add_options()
    ("help,h", "Produces help message")
  ;

  po::positional_options_description p;
  p.add("input-file", -1);

  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv)
              .options(desc)
              .positional(p)
              .run()
            , vm);
  po::notify(vm);

  if (vm.count("help"))
  {
    std::cout << desc;
    return 1;
  }

  if (2 != vm.count("input-file"))
  {
    std::cerr << "sqldiff should have two files to diff." << std::endl;
    std::cerr << desc;
    return 2;
  }

  std::cout << "Hello Word" << std::endl;
  return (0);
}
