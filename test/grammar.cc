/*!
 * \author: Armand Leclercq
 * \file: grammar.cc
 * \date: Sat 22 Jul 2017 02:37:20 PM UTC
 */
#include <sql_grammar.hh>

#include <gtest/gtest.h>

TEST(Grammar, empty_script)
{
  std::string script = "";
  sqldiff::sql_grammar<std::string::const_iterator> sql;
  sqldiff::SQL ast;

  std::string::const_iterator first = std::begin(script);
  std::string::const_iterator last = std::end(script);

  ASSERT_TRUE(
    phrase_parse(
      first
      , last
      , sql
      , boost::spirit::ascii::space
      , ast
    )
  );
}

TEST(Grammar, Create_Table)
{
  std::string script = "CREATE TABLE toto ();";
  sqldiff::sql_grammar<std::string::const_iterator> sql;
  sqldiff::SQL ast;

  std::string::const_iterator first = std::begin(script);
  std::string::const_iterator last = std::end(script);

  ASSERT_TRUE(
    phrase_parse(
      first
      , last
      , sql
      , boost::spirit::ascii::space
      , ast
    )
  );

  std::string scriptCamel = "Create Table toto ();";
  sqldiff::sql_grammar<std::string::const_iterator> sqlCamel;
  sqldiff::SQL astCamel;

  std::string::const_iterator firstCamel = std::begin(scriptCamel);
  std::string::const_iterator lastCamel = std::end(scriptCamel);

  ASSERT_TRUE(
    phrase_parse(
      firstCamel
      , lastCamel
      , sqlCamel
      , boost::spirit::ascii::space
      , astCamel
    )
  );
}
