#include "printip.h"

int main()
{
    printip::print_ip(char(-1));
    std::cout << std::endl;
    printip::print_ip(short(0));
    std::cout << std::endl;
    printip::print_ip(2130706433);
    std::cout << std::endl;
    printip::print_ip((long long)(8875824491850138409));
    std::cout << std::endl;
    std::cout << "string(192.12.12.12) -> ";
    std::string str("192.12.12.12");
    printip::print_ip(str);
    std::cout << std::endl;
    std::cout << "vector<int>{2,5,7,3} -> ";
    std::vector<int> vint{2,5,7,3};
    printip::print_ip(vint);
    std::cout << std::endl;
    std::cout << "list<unsigned char>{1,192,0,13} -> ";
    std::list<unsigned char> lch{1,192,0,13};
    printip::print_ip(lch);
    std::cout << std::endl;
    //print_ip(2.1);
    std::cout << "tuple{\"1.1\", \"2.2\", \"3.3\"} -> ";
    printip::print_ip(std::make_tuple(std::string("1.1"), std::string("2.2"), std::string("3.3")));
    std::cout << std::endl;
    std::cout << "tuple{3, 2, 1} -> ";
    printip::print_ip(std::make_tuple(3, 2, 1));
    std::cout << std::endl;
    //printip::print_ip(std::make_tuple(3,2,1.1));
    //printip::print_ip(std::make_tuple(3.1,2.1,1.1));
    return 0;
}
