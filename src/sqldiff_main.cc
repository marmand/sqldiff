/*!
 * \author: Armand Leclercq
 * \file: sqldiff_main.cc
 * \date: Sat 14 Oct 2017 08:42:39 PM UTC
 */
#include <boost/program_options/>

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

  po::variable_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help"))
  {
    std::cout << desc << std::endl;
    return 1;
  }

  std::cout << "Hello Word" << std::endl;
  return (0);
}
