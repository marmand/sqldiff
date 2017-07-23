/*!
 * \author: Armand Leclercq
 * \file: diff.hh
 * \date: Sun 23 Jul 2017 05:08:49 PM UTC
 */

#ifndef DIFF_HH
# define DIFF_HH

# include <string>

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
} /* namespace sqldiff */

#endif /* !DIFF_HH */
