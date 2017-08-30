/*!
 * \author: Armand Leclercq
 * \file: type.cc
 * \date: Wed 30 Aug 2017 06:06:15 AM UTC
 */
#include "type.hh"
namespace sqldiff
{
  size_t
  Type::size() const
  {
    return size_;
  }
} /* namespace sqldiff */
