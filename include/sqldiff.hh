/*!
 * \author: Armand Leclercq
 * \file: sqldiff.hh
 * \date: Wed 19 Jul 2017 06:05:55 PM UTC
 */
#ifndef SQLDIFF_HH
# define SQLDIFF_HH

# include <iosfwd>

namespace sqldiff
{
  /**
   * \class SQLDiff
   * \brief Does some diff in SQL language
   */
  class SQLDiff
  {
  public:
    SQLDiff();

  public:
    bool operator()(const std::istream& lhs, const std::istream& rhs);
    bool operator()(const std::string& lhs, const std::string& rhs);
  }; // class SQLDiff
} /* namespace sqldiff */

#endif /* !SQLDIFF_HH */
