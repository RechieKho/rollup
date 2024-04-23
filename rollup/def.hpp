#ifndef DEF_HPP
#define DEF_HPP

/// Common type definitions

/// Unsigned integer.
using UInt8 = __UINT8_TYPE__;
using UInt16 = __UINT16_TYPE__;
using UInt = UInt8;

/// Signed integer.
using Int8 = __INT8_TYPE__;
using Int16 = __INT16_TYPE__;
using Int = Int8;

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

#endif // DEF_HPP