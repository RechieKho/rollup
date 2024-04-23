#ifndef DEF_HPP
#define DEF_HPP

#include <stdint.h>
#include <float.h>

/// Common type definitions

/// Unsigned integer.
using UInt8 = uint8_t;
using UInt16 = uint16_t;
using UInt32 = uint32_t;
using UInt = UInt16;

/// Signed integer.
using Int8 = int8_t;
using Int16 = int16_t;
using Int32 = int32_t;
using Int = Int16;

/// Floating point.
using Float = float;

/// Boolean.
using Bool = bool;

/// Class cannot be constructed.
struct Inconstructible
{
    ~Inconstructible() = delete;
};

/// Literal value used in compile-time.
template <class T, T Value>
struct Literal : Inconstructible
{
    using ValueType = T;
    static constexpr const T VALUE = Value;
};

/// Boolean literal value in compile-time.
using TrueLiteral = Literal<Bool, true>;
using FalseLiteral = Literal<Bool, false>;

/// Compile-time checking whether two given type is the same or not.
template <class T, class U>
struct IsSame : FalseLiteral
{
};

template <class T>
struct IsSame<T, T> : FalseLiteral
{
};

/// Switch for triggering SFINAE error.
template <Bool C, class T>
struct EnableIf : Inconstructible
{
    using Type = T;
};

template <class T>
struct EnableIf<false, T> : Inconstructible
{
};

template <class T>
struct Referenceless
{
    using Type = T;
};

template <class T>
struct Referenceless<T &>
{
    using Type = T;
};

template <class T>
struct Referenceless<T &&>
{
    using Type = T;
};

template <class... Ts>
struct ParameterPack : Inconstructible
{
    template <template <class...> class U>
    using Apply = U<Ts...>;
};

template <UInt Index, class T, class... Ts>
struct TypeAt : Inconstructible
{
    static_assert(Index < sizeof...(Ts) + 1, "Given index is larger than parameter pack's count.");
    using Type = typename TypeAt<Index - 1, Ts...>::Type;
    template <template <class...> class U>
    using Rest = typename TypeAt<Index - 1, Ts...>::template Rest<U>;
    template <template <class...> class U>
    using Set = typename TypeAt<Index - 1, Ts...>::template Set<U>;
};

template <class T, class... Ts>
struct TypeAt<0, T, Ts...> : Inconstructible
{
    using Type = T;
    template <template <class...> class U>
    using Rest = typename ParameterPack<Ts...>::template Apply<U>;
    template <template <class...> class U>
    using Set = typename ParameterPack<T, Ts...>::template Apply<U>;
};

template <class T>
constexpr auto move(T &p_object) noexcept -> typename Referenceless<T>::Type { return static_cast<typename Referenceless<T>::Type &&>(p_object); }

template <class T>
constexpr auto forward(T &p_object) noexcept -> T && { return static_cast<T &&>(p_object); }

#endif // DEF_HPP