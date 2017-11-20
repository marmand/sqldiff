/*!
 * \author: Armand Leclercq
 * \file: diff.hh
 * \date: Sun 23 Jul 2017 05:08:49 PM UTC
 */

#ifndef DIFF_HH
# define DIFF_HH

# include "column.hh"
# include "integer.hh"
# include "table.hh"

# include <string>
# include <tuple>

namespace sqldiff
{
  /**
   * \brief Damerau-Levenshtein distance
   *
   * https: //en.wikipedia.org/wiki/Damerau%E2%80%93Levenshtein_distance
   *
   * Here we'll do the Optimal String Alignment Distance.
   */
  size_t
  distance(const std::string& lhs
           , const std::string& rhs);

  size_t
  distance(const Type& lhs
           , const Type& rhs);

  size_t
  distance(const Column& lhs
           , const Column& rhs);

  size_t
  distance(const Table& lhs
           , const Table& rhs);

  std::tuple
  <
    std::vector<Column>
    , std::vector<Column>
    , std::vector<Column>
  >
  diff(const Table& lhs
       , const Table& rhs);
} /* namespace sqldiff */

#endif /* !DIFF_HH */
