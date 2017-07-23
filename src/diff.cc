/*!
 * \author: Armand Leclercq
 * \file: diff.cc
 * \date: Sun 23 Jul 2017 05:08:43 PM UTC
 */
#include "diff.hh"

#include <algorithm>
#include <vector>

#include <iostream>

namespace sqldiff
{
  size_t
  distance(const std::string& lhs
           , const std::string& rhs)
  {
    std::vector<size_t> distances(lhs.size() * rhs.size(), 0);

    // Personnal addition to handle special case
    if (!lhs.size() || !rhs.size())
    {
      if (!lhs.size())
        return rhs.size();
      else // !rhs.size()
        return lhs.size();
    }

    // i goes through lhs
    // j goes through rhs

    for (size_t i = 0; i < lhs.size(); ++i)
      distances[0 + i] = i;
    for (size_t j = 0; j < rhs.size(); ++j)
      distances[j * lhs.size() + 0] = j;

    for (size_t i = 1; i < lhs.size(); ++i)
      for (size_t j = 1; j < rhs.size(); ++j)
      {
        size_t cost = 0;
        if (lhs[i] != rhs[j])
          cost = 1;

        distances[j * lhs.size() + i]
          = std::min(
              std::min(
                // deletion
                distances[j * lhs.size() + (i - 1)] + 1
                // insertion
                , distances[(j - 1) * lhs.size() + i] + 1
              )
              // substitution
              , distances[(j - 1) * lhs.size() + (i - 1)] + cost
            );

        // transposition
        if (i > 1
            && j > 1
            && lhs[i] == rhs[j - 1]
            && lhs[i - 1] == rhs[j])
        {
          distances[j * lhs.size() + i]
            = std::min(
                distances[j * lhs.size() + i]
                , distances[(j - 2) * lhs.size() + (i - 2)] + cost
              );
        }
      }

    // 0 indexed
    return distances[(lhs.size() * rhs.size() - 1)];
  }
} /* sqldiff */
