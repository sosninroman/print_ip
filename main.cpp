#include "printip.h"

int main()
{
    print_ip(char(-1));
    std::cout << std::endl;
    print_ip(short(0));
    std::cout << std::endl;
    print_ip(2130706433);
    std::cout << std::endl;
    print_ip((long long)(8875824491850138409));
    std::cout << std::endl;
    std::cout << "string(192.12.12.12) -> ";
    std::string str("192.12.12.12");
    print_ip(str);
    std::cout << std::endl;
    std::cout << "vector<int>{2,5,7,3} -> ";
    std::vector<int> vint{2,5,7,3};
    print_ip(vint);
    std::cout << std::endl;
    std::cout << "list<unsigned char>{1,192,0,13} -> ";
    std::list<unsigned char> lch{1,192,0,13};
    print_ip(lch);
    std::cout << std::endl;
    //print_ip(2.1);
    return 0;
}
