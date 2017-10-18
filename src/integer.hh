/*!
 * \author: Armand Leclercq
 * \file: integer.hh
 * \date: Wed 30 Aug 2017 08:15:08 PM UTC
 */
#ifndef INTEGER_HH
# define INTEGER_HH

# include "type.hh"

# include <iostream>

namespace sqldiff
{
class Integer : public Type
{
  public:
    Integer() = default;
    virtual ~Integer() = default;

  public:
    virtual bool has_size() const;

  public:
    size_t size;
}; // class Integer

inline
std::ostream&
operator<<(std::ostream& oss, const Integer& integer)
{
  switch (integer.size)
  {
    case 1:
      oss << "TINYINT";
      break;
    case 2:
      oss << "SMALLINT";
      break;
    case 3:
      oss << "MEDIUMINT";
      break;
    case 4:
      oss << "INTEGER";
      break;
    case 8:
      oss << "BIGINT";
      break;
    default:
      std::cerr << "Error: Unhandled INTEGER size" << std::endl;
      break;
  }
  return oss;
}

} /* namespace sqldiff */

#endif /* !INTEGER_HH */
