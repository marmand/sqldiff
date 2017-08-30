/*!
 * \author: Armand Leclercq
 * \file: integer.hh
 * \date: Wed 30 Aug 2017 08:15:08 PM UTC
 */
#ifndef INTEGER_HH
# define INTEGER_HH

# include "type.hh"

namespace sqldiff
{
class Integer : public Type
{
  public:
    Integer(const size_t size);
    ~Integer() = default;

  public:
    virtual bool has_size() const;
    virtual size_t size() const;

  private:
    size_t size_;
}; // class Integer
} /* namespace sqldiff */

#endif /* !INTEGER_HH */
