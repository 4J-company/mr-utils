#ifndef MR_LOG_HPP
#define MR_LOG_HPP

#include <boost/container/static_vector.hpp>
#include <boost/container/small_vector.hpp>

namespace mr {
  template <typename T, size_t N>
    using InplaceVector = boost::container::static_vector<T, N>;
  template <typename T, size_t N = 16>
    using SmallVector = boost::container::small_vector<T, N>;
}

#endif
