#ifndef TUPLE_HPP
#define TUPLE_HPP

#include "def.hpp"

/// Compile-time set of data.

/// Element in the set of data.
template <class T, class... Ts>
class TupleNode : public TupleNode<Ts...>
{
public:
    using ValueType = T;

private:
protected:
    ValueType value;

public:
    constexpr TupleNode(ValueType p_value, Ts... p_values) : value(p_value), TupleNode<Ts...>(p_values...) {}
};

template <class T>
class TupleNode<T>
{
public:
    using ValueType = T;

private:
protected:
    ValueType value;

public:
    constexpr TupleNode(ValueType p_value) : value(p_value) {}
};

/// Compile-time set of data.
template <class... Ts>
class Tuple : public TupleNode<Ts...>
{
public:
    template <UInt Index>
    using ValueType = typename TypeAt<Index, Ts...>::Type;

private:
public:
    constexpr Tuple(Ts... p_values) : TupleNode<Ts...>(p_values...) {}

    template <UInt Index>
    constexpr auto get() const -> ValueType<Index> { return TypeAt<Index, Ts...>::template Set<TupleNode>::value; }
};

#endif // TUPLE_HPP