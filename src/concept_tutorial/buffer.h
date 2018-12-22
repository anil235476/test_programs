#include <array>
#include <iterator>
#include <type_traits>

template <typename T, std::size_t sz>
requires std::is_default_constructible<T>::value &&
                std::is_copy_assignable<T>::value       &&
                std::is_copy_constructible<T>::value
class Buffer {
public:
    void push(const T& in_val);
    T    pop();
    bool empty() const;

private:
    using Container = std::array<T, sz>;
    using Iterator  = typename Container::iterator;

    Container buffer    { };
    Iterator  write     { std::begin(buffer) };
    Iterator  read      { std::begin(buffer) };
    std::size_t    num_items { 0 };
};

template <typename T, size_t sz>
void Buffer<T, sz>::push(const T& in_val)
{
    if (num_items == sz) throw std::out_of_range { "Buffer full!" };

    *write = in_val;     // <= Insert by copy
    ++num_items;
    ++write;
    if (write == std::end(buffer)) write = std::begin(buffer);
}

template <typename T, size_t sz>
T Buffer<T, sz>::pop()
{
    if (num_items == 0) throw std::out_of_range { "Buffer empty!" };

    auto temp = *read;  // <= Extract by copy
    --num_items;
    ++read;
    if (read == std::end(buffer)) read = std::begin(buffer);

    return temp;
}