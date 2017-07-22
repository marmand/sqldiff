/*!
 * \author: Armand Leclercq
 * \file: sql_grammar.hh
 * \date: Sat 22 Jul 2017 02:22:34 PM UTC
 */

#ifndef SQL_GRAMMAR_HH
# define SQL_GRAMMAR_HH

# include "sql.hh"

# include <boost/fusion/include/adapt_struct.hpp>
# include <boost/spirit/include/phoenix_core.hpp>
# include <boost/spirit/include/phoenix_fusion.hpp>
# include <boost/spirit/include/phoenix_operator.hpp>
# include <boost/spirit/include/phoenix_stl.hpp>
# include <boost/spirit/include/qi.hpp>

BOOST_FUSION_ADAPT_STRUCT(
  sqldiff::Column,
  (std::string, name)
  (std::string, type)
)

BOOST_FUSION_ADAPT_STRUCT(
  sqldiff::Table,
  (std::string, name)
  (std::vector<sqldiff::Column>, columns)
)

BOOST_FUSION_ADAPT_STRUCT(
  sqldiff::Statement,
  (std::vector<sqldiff::Table>, tables)
)

BOOST_FUSION_ADAPT_STRUCT(
  sqldiff::SQL,
  (std::vector<sqldiff::Statement>, tables)
)

namespace sqldiff
{
  namespace qi = boost::spirit::qi;
  namespace asc = boost::spirit::ascii;

  template <typename Iterator>
  class sql_grammar
    : public boost::spirit::qi::grammar
        <
          Iterator
          , SQL()
          , boost::spirit::ascii::space_type
        >
  {
  public:
    sql_grammar()
      : sql_grammar::base_type(sql)
    {
      using qi::lit;
      using qi::lexeme;
      using asc::char_;
      using asc::string;
      using namespace qi::labels;

      using boost::phoenix::at_c;
      using boost::phoenix::push_back;

      sql =
        *table
      ;

      table =
        "CREATE TABLE"
        >> text                 [at_c<0>(_val) = _1]
        >> "();"
      ;

      text = lexeme[+(char_) [_val += _1]];
    }

  public:
    qi::rule<Iterator, SQL(), asc::space_type> sql;
    qi::rule<Iterator, Table(), asc::space_type> table;
    qi::rule<Iterator, std::string(), asc::space_type> text;
  }; // struct sql_grammar
} /* namespace sqldiff */

#endif /* !SQL_GRAMMAR_HH */
