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
  ASSERT_EQ(0ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, first_empty)
{
  std::string lhs = "";
  std::string rhs = "toto";
  ASSERT_EQ(4ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, second_empty)
{
  std::string lhs = "toto";
  std::string rhs = "";
  ASSERT_EQ(4ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, gifts_pgifts)
{
  std::string lhs = "gifts";
  std::string rhs = "pgifts";
  ASSERT_EQ(1ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, pgifts_prgifts)
{
  std::string lhs = "pgifts";
  std::string rhs = "prgifts";
  ASSERT_EQ(1ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, prgifts_proifts)
{
  std::string lhs = "prgifts";
  std::string rhs = "proifts";
  ASSERT_EQ(1ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, proifts_profits)
{
  std::string lhs = "proifts";
  std::string rhs = "profits";
  ASSERT_EQ(1ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, profits_profit)
{
  std::string lhs = "profits";
  std::string rhs = "profit";
  ASSERT_EQ(1ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, gifts_profit)
{
  std::string lhs = "gifts";
  std::string rhs = "profit";
  ASSERT_EQ(5ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, saturday_sunday)
{
  std::string lhs = "saturday";
  std::string rhs = "sunday";
  ASSERT_EQ(3ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, orange_pumpkin)
{
  std::string lhs = "orange";
  std::string rhs = "pumpkin";
  ASSERT_EQ(7ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, int_4_8)
{
  sqldiff::Integer four;
  four.size = 4;
  sqldiff::Integer eight;
  eight.size = 8;
  ASSERT_EQ(4ul, sqldiff::distance(four, eight));
}

TEST(Distance, int_8_4)
{
  sqldiff::Integer eight;
  eight.size = 8;
  sqldiff::Integer four;
  four.size = 4;
  ASSERT_EQ(4ul, sqldiff::distance(eight, four));
}

TEST(Distance, int_0_0)
{
  sqldiff::Integer zerro;
  zerro.size = 0;
  sqldiff::Integer zorro;
  zorro.size = 0;
  ASSERT_EQ(0ul, sqldiff::distance(zerro, zorro));
}

TEST(Distance, column_orange_4_pumpkin_4)
{
  sqldiff::Column lhs;
  lhs.name = "orange";
  boost::get<sqldiff::Integer>(lhs.type).size = 4;
  sqldiff::Column rhs;
  rhs.name = "pumpkin";
  boost::get<sqldiff::Integer>(rhs.type).size = 4;
  ASSERT_EQ(7ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, column_orange_4_pumpkin_8)
{
  sqldiff::Column lhs;
  lhs.name = "orange";
  boost::get<sqldiff::Integer>(lhs.type).size = 4;
  sqldiff::Column rhs;
  rhs.name = "pumpkin";
  boost::get<sqldiff::Integer>(rhs.type).size = 8;
  ASSERT_EQ(static_cast<size_t>(7 + 4), sqldiff::distance(lhs, rhs));
}

TEST(Distance, column_orange_8_pumpkin_4)
{
  sqldiff::Column lhs;
  lhs.name = "orange";
  boost::get<sqldiff::Integer>(lhs.type).size = 8;
  sqldiff::Column rhs;
  rhs.name = "pumpkin";
  boost::get<sqldiff::Integer>(rhs.type).size = 4;
  ASSERT_EQ(static_cast<size_t>(7 + 4), sqldiff::distance(lhs, rhs));
}

TEST(Distance, column_pumpkin_4_pumpkin_8)
{
  sqldiff::Column lhs;
  lhs.name = "pumpkin";
  boost::get<sqldiff::Integer>(lhs.type).size = 4;
  sqldiff::Column rhs;
  rhs.name = "pumpkin";
  boost::get<sqldiff::Integer>(rhs.type).size = 8;
  ASSERT_EQ(4ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, table_1_pumpkin_4_vs_1_pumpkin_8)
{
  sqldiff::Table lhs;
  lhs.name = "table";
  lhs.columns.push_back({});
  lhs.columns.back().name = "pumpkin";
  boost::get<sqldiff::Integer>(lhs.columns.back().type).size = 4;

  sqldiff::Table rhs;
  rhs.name = "table";
  rhs.columns.push_back({});
  rhs.columns.back().name = "pumpkin";
  boost::get<sqldiff::Integer>(rhs.columns.back().type).size = 8;
  ASSERT_EQ(4ul, sqldiff::distance(lhs, rhs));
}

TEST(Distance, table_2_pumpkin_4_orange_4_vs_1_pumpkin_8)
{
  sqldiff::Table lhs;
  lhs.name = "table";
  lhs.columns.push_back({});
  lhs.columns.back().name = "pumpkin";
  boost::get<sqldiff::Integer>(lhs.columns.back().type).size = 4;
  lhs.columns.push_back({});
  lhs.columns.back().name = "orange";
  boost::get<sqldiff::Integer>(lhs.columns.back().type).size = 4;

  sqldiff::Table rhs;
  rhs.name = "table";
  rhs.columns.push_back({});
  rhs.columns.back().name = "pumpkin";
  boost::get<sqldiff::Integer>(rhs.columns.back().type).size = 8;
  ASSERT_EQ(static_cast<size_t>(4 + 1), sqldiff::distance(lhs, rhs));
}

TEST(Diff, table_1_id_vs_2_id_hash)
{
  sqldiff::Table lhs;
  lhs.name = "Toto";
  lhs.columns.push_back({});
  lhs.columns.back().name = "ID";
  boost::get<sqldiff::Integer>(lhs.columns.back().type).size = 4;

  sqldiff::Table rhs;
  rhs.name = "Toto";
  rhs.columns.push_back({});
  rhs.columns.back().name = "ID";
  boost::get<sqldiff::Integer>(rhs.columns.back().type).size = 4;
  rhs.columns.push_back({});
  rhs.columns.back().name = "hash";
  boost::get<sqldiff::Integer>(rhs.columns.back().type).size = 4;

  auto result = sqldiff::diff(lhs, rhs);
  size_t count{0};
  for (const auto& add: std::get<0>(result))
  {
    ++count;
    ASSERT_STREQ("hash", add.name.c_str());
    ASSERT_EQ(4ul, boost::get<sqldiff::Integer>(add.type).size);
  }
  ASSERT_EQ(1ul, count);

  count = 0;
  for (const auto& drop: std::get<1>(result))
  {
    ++count;
    (void) drop;
  }
  ASSERT_EQ(0ul, count);

#if 0
  for (const auto& modifiy: std::get<2>(result))
  {
  }
#endif
}

TEST(Diff, table_2_id_hash_vs_1_id)
{
  sqldiff::Table lhs;
  lhs.name = "Toto";
  lhs.columns.push_back({});
  lhs.columns.back().name = "ID";
  boost::get<sqldiff::Integer>(lhs.columns.back().type).size = 4;
  lhs.columns.push_back({});
  lhs.columns.back().name = "hash";
  boost::get<sqldiff::Integer>(lhs.columns.back().type).size = 4;

  sqldiff::Table rhs;
  rhs.name = "Toto";
  rhs.columns.push_back({});
  rhs.columns.back().name = "ID";
  boost::get<sqldiff::Integer>(rhs.columns.back().type).size = 4;

  auto result = sqldiff::diff(lhs, rhs);
  size_t count{0};
  for (const auto& add: std::get<0>(result))
  {
    ++count;
    (void) add;
  }
  ASSERT_EQ(0ul, count);

  count = 0;
  for (const auto& drop: std::get<1>(result))
  {
    ++count;
    ASSERT_STREQ("hash", drop.name.c_str());
    ASSERT_EQ(4ul, boost::get<sqldiff::Integer>(drop.type).size);
  }
  ASSERT_EQ(1ul, count);

#if 0
  for (const auto& modifiy: std::get<2>(result))
  {
  }
#endif
}
