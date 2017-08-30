/*!
 * \author: Armand Leclercq
 * \file: type.hh
 * \date: Wed 30 Aug 2017 06:03:33 AM UTC
 */
#ifndef TYPE_HH
# define TYPE_HH

# include <cstddef>

namespace sqldiff
{
  class Type
  {
  public:
    Type() = default;
    ~Type() = default;

  public:
    virtual bool has_size() const;
    virtual size_t size() const = 0;
  }; // class Type
} /* namespace sqldiff */

#endif /* !TYPE_HH */
