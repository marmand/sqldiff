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

TEST(Distance, saturday_sunday)
{
  std::string lhs = "saturday";
  std::string rhs = "sunday";
  ASSERT_EQ(3, sqldiff::distance(lhs, rhs));
}

TEST(Distance, orange_pumpkin)
{
  std::string lhs = "orange";
  std::string rhs = "pumpkin";
  ASSERT_EQ(7, sqldiff::distance(lhs, rhs));
}

TEST(Distance, int_4_8)
{
  sqldiff::Integer four;
  four.size = 4;
  sqldiff::Integer eight;
  eight.size = 8;
  ASSERT_EQ(4, sqldiff::distance(four, eight));
}

TEST(Distance, int_8_4)
{
  sqldiff::Integer eight;
  eight.size = 8;
  sqldiff::Integer four;
  four.size = 4;
  ASSERT_EQ(4, sqldiff::distance(eight, four));
}

TEST(Distance, int_0_0)
{
  sqldiff::Integer zerro;
  zerro.size = 0;
  sqldiff::Integer zorro;
  zorro.size = 0;
  ASSERT_EQ(0, sqldiff::distance(zerro, zorro));
}

TEST(Distance, column_orange_4_pumpkin_4)
{
  sqldiff::Column lhs;
  lhs.name = "orange";
  lhs.type.size = 4;
  sqldiff::Column rhs;
  rhs.name = "pumpkin";
  rhs.type.size = 4;
  ASSERT_EQ(7, sqldiff::distance(lhs, rhs));
}

TEST(Distance, column_orange_4_pumpkin_8)
{
  sqldiff::Column lhs;
  lhs.name = "orange";
  lhs.type.size = 4;
  sqldiff::Column rhs;
  rhs.name = "pumpkin";
  rhs.type.size = 8;
  ASSERT_EQ(7 + 4, sqldiff::distance(lhs, rhs));
}
