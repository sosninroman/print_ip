#ifndef PRINTIP_H
#define PRINTIP_H

#include <iostream>
#include <type_traits>
#include <string>
#include <list>
#include <vector>

const int BITS_IN_BYTE = 8;
const unsigned char BYTE_MASK = 255;

template<class T> struct is_string : std::false_type{};

template<> struct is_string<std::string> : std::true_type{};

template<class T> struct is_constainer : std::false_type{};

template<class T> struct is_constainer<std::list<T>> : std::true_type{};

template<class T> struct is_constainer<std::vector<T>> : std::true_type{};

template<class T>
typename std::enable_if<std::is_integral<T>::value,void>::type print_ip(const T& val)
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

template<class T>
typename std::enable_if<is_string<T>::value, void>::type print_ip(const T& val)
{
    std::cout << val;
}

template<class T>
typename std::enable_if<is_constainer<T>::value,void>::type print_ip(const T& val)
{
    auto itr = val.begin();
    if(itr != val.end() )
    {
        print_ip<typename std::remove_const<typename std::remove_reference<decltype(*itr)>::type>::type>(*itr++);
    }
    while(itr != val.end() )
    {
        std::cout << '.';
        print_ip<typename std::remove_const<typename std::remove_reference<decltype(*itr)>::type>::type>(*itr++);
    }
}

#endif
