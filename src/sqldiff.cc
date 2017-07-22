/*!
 * \author: Armand Leclercq
 * \file: sqldiff.cc
 * \date: Mon 10 Jul 2017 06:12:22 PM UTC
 */
#include <sqldiff.hh>

#include <fstream>

namespace sqldiff
{
  SQLDiff::SQLDiff()
  {
  }

  bool
  SQLDiff::operator()(const std::istream& /* lhs */
                      , const std::istream& /* rhs */ )
  {
    return false;
  }

  bool
  SQLDiff::operator()(const std::string&/* lhs */
                      , const std::string& /* rhs/ */ )
  {
    return false;
  }
} /* namespace sqldiff */
