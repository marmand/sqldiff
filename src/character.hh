/*!
 * \author: Armand Leclercq
 * \file: character.hh
 * \date: Sun 19 Nov 2017 04:24:05 PM UTC
 */

#ifndef CHARACTER_HH
# define CHARACTER_HH

# include <iostream>

namespace sqldiff
{
class Character
{
public:
  Character() = default;
  ~Character() = default;

public:
  bool has_size() const { return true; }
  size_t get_size() const { return size; }

public:
  size_t size;
}; // class Character

inline
std::ostream&
operator<<(std::ostream& os, const Character& c)
{
  return os << "CHARACTER(" << c.size << ")";
}
} /* sqldiff */

#endif /* !CHARACTER_HH */
