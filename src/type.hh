/*!
 * \author: Armand Leclercq
 * \file: type.hh
 * \date: Wed 30 Aug 2017 06:03:33 AM UTC
 */
#ifndef TYPE_HH
# define TYPE_HH

namespace sqldiff
{
  class Type
  {
  public:
    Type() = default;
    ~Type() = default;

  public:
    size_t size() const;

  private:
    size_t size_;
  }; // class Type
} /* namespace sqldiff */

#endif /* !TYPE_HH */
