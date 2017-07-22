/*!
 * \author: Armand Leclercq
 * \file: statement.hh
 * \date: Sat 22 Jul 2017 02:57:43 PM UTC
 */
#ifndef STATEMENT_HH
# define STATEMENT_HH

# include "table.hh"

# include <vector>

namespace sqldiff
{
  struct Statement
  {
    std::vector<Table> tables;
  }; // struct Statement
} /* namespace sqldiff */

#endif /* !STATEMENT_HH */
