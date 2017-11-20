/*!
 * \author: Armand Leclercq
 * \file: column.hh
 * \date: Sat 22 Jul 2017 02:53:19 PM UTC
 */
#ifndef COLUMN_HH
# define COLUMN_HH

# include "integer.hh"
# include "character.hh"

# include <boost/variant.hpp>

# include <string>

namespace sqldiff
{
typedef
  boost::variant
  <
    sqldiff::Integer
    , sqldiff::Character
  >
Type;

struct Column
{
  std::string name;
  Type type;
}; // struct Column
} /* namespace sqldiff */

#endif /* !COLUMN_HH */
