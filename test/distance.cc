/*!
 * \author: Armand Leclercq
 * \file: distance.cc
 * \date: Sun 23 Jul 2017 06:05:18 PM UTC
 */
#include <diff.hh>

#include <gtest/gtest.h>

TEST(Distance, empty)
{
  std::string lhs = "";
  std::string rhs = "";
  ASSERT_EQ(0, sqldiff::distance(lhs, rhs));
}

TEST(Distance, first_empty)
{
  std::string lhs = "";
  std::string rhs = "toto";
  ASSERT_EQ(4, sqldiff::distance(lhs, rhs));
}

TEST(Distance, second_empty)
{
  std::string lhs = "toto";
  std::string rhs = "";
  ASSERT_EQ(4, sqldiff::distance(lhs, rhs));
}

TEST(Distance, gifts_pgifts)
{
  std::string lhs = "gifts";
  std::string rhs = "pgifts";
  ASSERT_EQ(1, sqldiff::distance(lhs, rhs));
}

TEST(Distance, pgifts_prgifts)
{
  std::string lhs = "pgifts";
  std::string rhs = "prgifts";
  ASSERT_EQ(1, sqldiff::distance(lhs, rhs));
}

TEST(Distance, prgifts_proifts)
{
  std::string lhs = "prgifts";
  std::string rhs = "proifts";
  ASSERT_EQ(1, sqldiff::distance(lhs, rhs));
}

TEST(Distance, proifts_profits)
{
  std::string lhs = "proifts";
  std::string rhs = "profits";
  ASSERT_EQ(1, sqldiff::distance(lhs, rhs));
}

TEST(Distance, profits_profit)
{
  std::string lhs = "profits";
  std::string rhs = "profit";
  ASSERT_EQ(1, sqldiff::distance(lhs, rhs));
}

TEST(Distance, gifts_profit)
{
  std::string lhs = "gifts";
  std::string rhs = "profit";
  ASSERT_EQ(5, sqldiff::distance(lhs, rhs));
}
