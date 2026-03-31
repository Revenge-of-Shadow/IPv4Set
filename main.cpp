

#include "Set.h"
#include "IPv4Prefix.h"
int main(){

    IPv4Prefix pref(0x23531232, 16);
    std::cout<<std::hex<<pref.base<<std::endl;
    std::cout<<std::hex<<pref.getMask()<<std::endl;
    std::cout<<std::hex<<pref.masked()<<std::endl;

    return EXIT_SUCCESS;
}
