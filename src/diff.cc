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
      distances[i + 0] = i;
    for (size_t j = 0; j < rhs.size(); ++j)
      distances[0 + j * lhs.size()] = j;

    for (size_t i = 1; i < lhs.size(); ++i)
      for (size_t j = 1; j < rhs.size(); ++j)
      {
        size_t cost = 0;
        if (lhs[i] != rhs[j])
          cost = 1;

        distances[i + j * lhs.size()]
          = std::min(
              std::min(
                // deletion
                distances[(i - 1) + j * lhs.size()] + 1
                // insertion
                , distances[i + (j - 1) * lhs.size()] + 1
              )
              // substitution
              , distances[(i - 1) + (j - 1) * lhs.size()] + cost
            );

        // transposition
        if (i > 1
            && j > 1
            && lhs[i] == rhs[j - 1]
            && lhs[i - 1] == rhs[j])
        {
          distances[i + j * lhs.size()]
            = std::min(
                distances[i + j * lhs.size()]
                , distances[(i - 2) + (j - 2) * lhs.size()] + cost
              );
        }
      }

    // 0 indexed
    return distances[(lhs.size() * rhs.size() - 1)];
  }
} /* sqldiff */
