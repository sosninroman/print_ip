#ifndef PRINTIP_H
#define PRINTIP_H

#include <iostream>
#include <type_traits>
#include <string>
#include <list>
#include <vector>

const int BITS_IN_BYTE = 8;
const unsigned char BYTE_MASK = 255;

namespace printip
{

template<class T> struct is_container : std::false_type{};

template<class T> struct is_container<std::list<T>> : std::true_type{};

template<class T> struct is_container<std::vector<T>> : std::true_type{};

template<class T>
constexpr bool is_container_v = is_container<T>::value;

template< class T >
constexpr bool is_integral_v = std::is_integral<T>::value;

template<class T>
std::enable_if_t<is_integral_v<T>> print_ip(const T& val)
{
    const auto getByte = [val](size_t i){
         return static_cast<unsigned char>(val >> (i*BITS_IN_BYTE) );
    };
    for(size_t i = sizeof(val)-1; i > 0 ; --i)
    {
        const size_t byteVal = getByte(i);
        std::cout << byteVal;
        std::cout << ".";
    }
    size_t byteVal = getByte(0);
    std::cout << byteVal;
}

void print_ip(const std::string& val)
{
    std::cout << val;
}

template<class T>
std::enable_if_t<is_container_v<T>> print_ip(const T& val)
{
    auto itr = val.begin();
    if(itr != val.end() )
    {
        print_ip<std::remove_const_t<std::remove_reference_t<decltype(*itr)>>>(*itr++);
    }
    while(itr != val.end() )
    {
        std::cout << '.';
        print_ip<std::remove_const_t<std::remove_reference_t<decltype(*itr)>>>(*itr++);
    }
}

}
#endif
