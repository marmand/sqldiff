/*!
 * \author: Armand Leclercq
 * \file: sql.hh
 * \date: Sat 22 Jul 2017 02:56:05 PM UTC
 */
#ifndef SQL_HH
# define SQL_HH

# include "statement.hh"

# include <vector>

namespace sqldiff
{
  struct SQL
  {
    std::vector<Statement> statements;
  }; // struct SQL
} /* namespace sqldiff */

#endif /* !SQL_HH */
