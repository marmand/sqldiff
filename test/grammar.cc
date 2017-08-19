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
  std::string script = "CREATE TABLE toto (id INT);";
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
  ASSERT_STREQ("toto", ast.tables[0].name.c_str());
}

TEST(Grammar, Create_Table_Camel_Identifier)
{
  std::string scriptCamel = "CREATE TABLE Tata (ID INT);";
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
  ASSERT_STREQ("Tata", astCamel.tables[0].name.c_str());
}

TEST(Grammar, Create_Table_Camel_SQL_and_Identifier)
{
  std::string scriptSQLCamel = "Create Table TuTu (ID INT);";
  sqldiff::sql_grammar<std::string::const_iterator> sqlSQLCamel;
  sqldiff::SQL astSQLCamel;

  std::string::const_iterator firstSQLCamel = std::begin(scriptSQLCamel);
  std::string::const_iterator lastSQLCamel = std::end(scriptSQLCamel);

  ASSERT_TRUE(
    phrase_parse(
      firstSQLCamel
      , lastSQLCamel
      , sqlSQLCamel
      , boost::spirit::ascii::space
      , astSQLCamel
    )
  );
  ASSERT_STREQ("TuTu", astSQLCamel.tables[0].name.c_str());
}

TEST(Grammar, Create_Two_Tables)
{
  std::string script = "CREATE TABLE toto (id int); CREATE TABLE Tata (id INT);";
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
  ASSERT_STREQ("toto", ast.tables[0].name.c_str());
  ASSERT_STREQ("Tata", ast.tables[1].name.c_str());
}

TEST(Grammar, Create_Table_One_Column)
{
  sqldiff::sql_grammar<std::string::const_iterator> sql;
  sqldiff::SQL ast;
  std::string script = "CREATE Table toto(id INT);";

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
  ASSERT_STREQ("toto", ast.tables[0].name.c_str());
  ASSERT_STREQ("id", ast.tables[0].columns[0].name.c_str());
  ASSERT_STREQ("INT", ast.tables[0].columns[0].type.c_str());
}

TEST(Grammar, Create_Table_Two_Columns)
{
  sqldiff::sql_grammar<std::string::const_iterator> sql;
  sqldiff::SQL ast;
  std::string script = "CREATE Table toto(id INT, name TEXT);";

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
  ASSERT_STREQ("toto", ast.tables[0].name.c_str());
  ASSERT_STREQ("id", ast.tables[0].columns[0].name.c_str());
  ASSERT_STREQ("INT", ast.tables[0].columns[0].type.c_str());

  ASSERT_STREQ("name", ast.tables[0].columns[1].name.c_str());
  ASSERT_STREQ("TEXT", ast.tables[0].columns[1].type.c_str());
}

TEST(Grammar, Create_Table_Two_Columns_Camel)
{
  sqldiff::sql_grammar<std::string::const_iterator> sql;
  sqldiff::SQL ast;
  std::string script = "CREATE Table toto(ID INT, Name TEXT);";

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
  ASSERT_STREQ("toto", ast.tables[0].name.c_str());
  ASSERT_STREQ("ID", ast.tables[0].columns[0].name.c_str());
  ASSERT_STREQ("INT", ast.tables[0].columns[0].type.c_str());

  ASSERT_STREQ("Name", ast.tables[0].columns[1].name.c_str());
  ASSERT_STREQ("TEXT", ast.tables[0].columns[1].type.c_str());
}
