/*!
 * \author: Armand Leclercq
 * \file: diff.cc
 * \date: Sun 23 Jul 2017 05:08:43 PM UTC
 */
#include "diff.hh"

#include <algorithm>
#include <vector>

namespace sqldiff
{
  size_t
  distance(const std::string& lhs
           , const std::string& rhs)
  {
    std::vector<size_t> distances((1 + lhs.size()) * (1 + rhs.size()), 0);
    size_t line = lhs.size() + 1;

    // i goes through lhs
    // j goes through rhs
    for (size_t i = 0; i <= lhs.size(); ++i)
      distances[i + 0] = i;
    for (size_t j = 0; j <= rhs.size(); ++j)
      distances[0 + j * line] = j;

    // In wikipedia article strings are 1 indexed
    // In C++ we are 0 indexed
    for (size_t i = 1; i <= lhs.size(); ++i)
      for (size_t j = 1; j <= rhs.size(); ++j)
      {
        size_t cost = 0;
        if (lhs[i - 1] != rhs[j - 1])
          cost = 1;

        distances[i + j * line]
          = std::min(
              std::min(
                // deletion
                distances[(i - 1) + j * line] + 1
                // insertion
                , distances[i + (j - 1) * line] + 1
              )
              // substitution
              , distances[(i - 1) + (j - 1) * line] + cost
            );

        // transposition
        if (i > 1
            && j > 1
            && lhs[i - 1] == rhs[j - 2]
            && lhs[i - 2] == rhs[j - 1])
        {
          distances[i + j * line]
            = std::min(
                distances[i + j * line]
                , distances[(i - 2) + (j - 2) * line] + cost
              );
        }
      }

    return distances.back();
  }

  size_t
  distance(const Integer& lhs
           , const Integer& rhs)
  {
    return std::max(lhs.size, rhs.size) - std::min(lhs.size, rhs.size);
  }

  size_t
  distance(const Column& lhs
           , const Column& rhs)
  {
    return distance(lhs.name, rhs.name) + distance(lhs.type, rhs.type);
  }

  size_t
  distance(const Table& lhs
           , const Table& rhs)
  {
    auto result = distance(lhs.name, rhs.name);
    auto min_size = std::min(lhs.columns.size()
                             , rhs.columns.size());
    result += std::max(lhs.columns.size()
                       , rhs.columns.size())
            - min_size;
    std::vector<size_t> column_distances;
    std::transform(std::begin(lhs.columns)
                   , std::begin(lhs.columns) + min_size
                   , std::begin(rhs.columns)
                   , std::back_inserter(column_distances)
                   , [](const Column& c_lhs
                        , const Column& c_rhs)
                     -> size_t
                    {
                      return distance(c_lhs, c_rhs);
                    }
                  );
    for (const auto& distance: column_distances)
      result += distance;
    return result;
  }
} /* sqldiff */
