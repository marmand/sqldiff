/*!
 * \author: Armand Leclercq
 * \file: integer.cc
 * \date: Wed 30 Aug 2017 08:16:45 PM UTC
 */
#include "integer.hh"
namespace sqldiff
{
  Integer::Integer(const size_t size)
    : Type()
    , size_(size)
  {
  }

  bool
  Integer::has_size() const
  {
    return true;
  }

  size_t
  Integer::size() const
  {
    return size_;
  }
} /* sqldiff */
