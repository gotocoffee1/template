#ifndef _TYPE_HPP_
#define _TYPE_HPP_
#include <cstddef>
#include <cstdint>
#include <filesystem>

#ifdef CHECK_TODO
#define TODO(x) static_assert(false, "Missing TODO: " x)
#else
#define TODO(x)
#endif

namespace
{
using std::int16_t;
using std::int32_t;
using std::int64_t;
using std::int8_t;
using std::size_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
using std::uint8_t;
namespace fs = std::filesystem;

template<class... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};
template<class... Ts>
overloaded(Ts...)->overloaded<Ts...>;

} 
#endif
