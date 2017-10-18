/*!
 * \author: Armand Leclercq
 * \file: sqldiff_main.cc
 * \date: Sat 14 Oct 2017 08:42:39 PM UTC
 */
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_multi_pass.hpp>

#include <fstream>
#include <iostream>

#include <config.hh>
#include <sql_grammar.hh>
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
  auto input_files = vm["input-file"].as<std::vector<std::string>>();
  if (2 != input_files.size())
  {
    std::cerr << "Error: sqldiff needs two files to compare."
              << std::endl
              << "Got " << input_files.size()
              << std::endl
    ;
    return 2;
  }

  std::ifstream fileA(input_files[0]);
  if (!fileA.is_open())
  {
    std::cerr << "Couldn't open file" << input_files[0] << std::endl;
    return 3;
  }
  using base_iterator_type = std::istreambuf_iterator<char>;
  using grammar_iterator = boost::spirit::multi_pass<base_iterator_type>;
  sqldiff::sql_grammar<grammar_iterator> sql;

  sqldiff::SQL sqlA;
  grammar_iterator first = boost::spirit::make_default_multi_pass(base_iterator_type(fileA));
  bool result = boost::spirit::qi::phrase_parse(
    first
    , boost::spirit::make_default_multi_pass(base_iterator_type())
    , sql
    , boost::spirit::ascii::space
    , sqlA
  );

  if (!result)
  {
    std::cerr << "Error while parsing file " << input_files[0] << std::endl;
    return 4;
  }

  std::cout << "TableName: " << sqlA.tables[0].name << std::endl;

  return 0;
}
