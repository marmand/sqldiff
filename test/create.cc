/*!
 * \author: Armand Leclercq
 * \file: create.cc
 * \date: Sat 22 Jul 2017 10:27:45 AM UTC
 */
#include <sqldiff.hh>

#include <gtest/gtest.h>

#include <iostream>

TEST(Create, single_column)
{
  sqldiff::SQLDiff diff;
  std::string old_stmt = "CREATE TABLE Toto (id INT);";
  std::string new_stmt = "CREATE_TABLE Toto (id BIGINT);";
  diff(old_stmt, new_stmt);
}
