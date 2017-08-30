/*!
 * \author: Armand Leclercq
 * \file: column.hh
 * \date: Sat 22 Jul 2017 02:53:19 PM UTC
 */
#ifndef COLUMN_HH
# define COLUMN_HH

# include "integer.hh"

# include <string>

namespace sqldiff
{
  struct Column
  {
    std::string name;
    Integer type;
  }; // struct Column
} /* namespace sqldiff */

#endif /* !COLUMN_HH */
