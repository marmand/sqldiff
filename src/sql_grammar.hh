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
# include <boost/spirit/include/phoenix_object.hpp>
# include <boost/spirit/include/phoenix_operator.hpp>
# include <boost/spirit/include/phoenix_stl.hpp>
# include <boost/spirit/include/qi.hpp>

// BOOST_FUSION_ADAPT_STRUCT(
//   sqldiff::Column,
//   (std::string, name)
//   (std::string, type)
// )

BOOST_FUSION_ADAPT_STRUCT(
  sqldiff::Table,
  (std::string, name)
  // (std::vector<sqldiff::Column>, columns)
)

// BOOST_FUSION_ADAPT_STRUCT(
//   sqldiff::Statement,
//   (std::vector<sqldiff::Table>, tables)
// )

BOOST_FUSION_ADAPT_STRUCT(
  sqldiff::SQL,
  (std::vector<sqldiff::Table>, tables)
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
      using qi::on_error;
      using qi::fail;
      using asc::char_;
      using asc::string;
      using namespace qi::labels;

      using boost::phoenix::construct;
      using boost::phoenix::val;
      using boost::phoenix::at_c;
      using boost::phoenix::push_back;

      // /////// //
      // Grammar //
      // /////// //

      sql =
        *table                                  [push_back(at_c<0>(_val), _1)]
      ;

      table =
        "CREATE TABLE"
        >> identifier                           [at_c<0>(_val) = _1]
        >> "();"
      ;

      identifier = lexeme[+(char_("a-zA-Z"))    [_val += _1]];

# if 0
      sql.name("sql");
      debug(sql);

      table.name("table");
      debug(table);
# endif
    }

  public:
    qi::rule<Iterator, SQL(), asc::space_type>          sql;
    qi::rule<Iterator, Table(), asc::space_type>        table;
    qi::rule<Iterator, std::string(), asc::space_type>  identifier;
  }; // struct sql_grammar
} /* namespace sqldiff */

#endif /* !SQL_GRAMMAR_HH */
