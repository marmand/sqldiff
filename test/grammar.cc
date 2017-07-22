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
