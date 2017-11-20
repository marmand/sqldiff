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
# include <boost/spirit/include/qi_no_case.hpp>

BOOST_FUSION_ADAPT_STRUCT(
  sqldiff::Character,
  (size_t, size)
)

BOOST_FUSION_ADAPT_STRUCT(
  sqldiff::Integer,
  (size_t, size)
)

BOOST_FUSION_ADAPT_STRUCT(
  sqldiff::Column,
  (std::string, name)
  (sqldiff::Type, type)
)

BOOST_FUSION_ADAPT_STRUCT(
  sqldiff::Table,
  (std::string, name)
  (std::vector<sqldiff::Column>, columns)
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
      using qi::fail;
      using qi::int_;
      using qi::lexeme;
      using qi::lit;
      using qi::on_error;

      using asc::alpha;
      using asc::no_case;

      using namespace qi::labels;

      using boost::phoenix::at_c;
      using boost::phoenix::construct;
      using boost::phoenix::push_back;
      using boost::phoenix::val;

      // /////// //
      // Grammar //
      // /////// //

      identifier = lexeme[+alpha                [_val += _1]];

      sql =
        *table                                  [push_back(at_c<0>(_val), _1)]
      ;

      table =
        no_case["CREATE TABLE"]
        > identifier                            [at_c<0>(_val) = _1]
        > "("
        > column                                [push_back(at_c<1>(_val), _1)]
          % lit(",")
        > ");"
      ;

      column =
        identifier                              [at_c<0>(_val) = _1]
        >> type                                 [at_c<1>(_val) = _1]
      ;

      type =
        integer                                 [_val = _1]
        | character                             [_val = _1]
      ;

      integer =
          no_case["TINYINT"]                    [at_c<0>(_val) = 1]
          >> -("(" >> int_ >> ")")
        | no_case["SMALLINT"]                   [at_c<0>(_val) = 2]
          >> -("(" >> int_ >> ")")
        | no_case["MEDIUMINT"]                  [at_c<0>(_val) = 3]
          >> -("(" >> int_ >> ")")
        | no_case["INTEGER"]                    [at_c<0>(_val) = 4]
          >> -("(" >> int_ >> ")")
        | no_case["INT"]                        [at_c<0>(_val) = 4]
          >> -("(" >> int_ >> ")")
        | no_case["BIGINT"]                     [at_c<0>(_val) = 8]
          >> -("(" >> int_ >> ")")
      ;

      character =
        no_case["VARCHAR"]
        >> "("
        >> int_                                 [at_c<0>(_val) = _1]
        >> ")"
      ;

# if 0
      sql.name("sql");
      debug(sql);

      table.name("table");
      debug(table);

      column.name("column");
      debug(column);
# endif

      on_error<fail>(
        table
        , std::cout << val("Error ! Expecting ")
                    << _4
                    << val(" here: \"")
                    << construct<std::string>(_3, _2)
                    << val("\"")
                    << std::endl
      );
    }

  public:
    qi::rule<Iterator, SQL(), asc::space_type>          sql;
    qi::rule<Iterator, Table(), asc::space_type>        table;
    qi::rule<Iterator, std::string(), asc::space_type>  identifier;
    qi::rule<Iterator, Column(), asc::space_type>       column;
    qi::rule<Iterator, Type(), asc::space_type>         type;
    qi::rule<Iterator, Integer(), asc::space_type>      integer;
    qi::rule<Iterator, Character(), asc::space_type>    character;
  }; // struct sql_grammar
} /* namespace sqldiff */

#endif /* !SQL_GRAMMAR_HH */
