/*!
 * \author: Armand Leclercq
 * \file: table.hh
 * \date: Sat 22 Jul 2017 02:49:32 PM UTC
 */
#ifndef TABLE_HH
# define TABLE_HH

# include "column.hh"

# include <string>
# include <vector>

namespace sqldiff
{
  struct Table
  {
    std::string name;
    // std::vector<Column> columns;
  }; // struct Table
} /* namespace sqldiff */

#endif /* !TABLE_HH */
