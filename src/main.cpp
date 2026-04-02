#include "SortedSet.h"
//  Check for checks
//  Check for requirements
int main(){

    /*
    IPv4PrefixSet IPset;

    //  First two bytes the same.
    std::cout<<IPset.add(0x23531232, 16)<<std::endl;   
    std::cout<<IPset.add(0x23534351, 24)<<std::endl;
    std::cout<<IPset.add(0x9881aF82, 8)<<std::endl;
    std::cout<<IPset.add(0x9881aF82, 8)<<std::endl;
    std::cout<<IPset.add(0xFFFFFFFF, 33)<<std::endl;


    //  This one is for prefix 1.
    std::cout<<IPset.check(0x23534315)<<std::endl;
    //  This one is for prefix 2.
    std::cout<<IPset.check(0x98534315)<<std::endl;
    //  This one should miss. 
    std::cout<<IPset.check(0x12124316)<<std::endl;

    // std::cout<<std::hex<<pref.base<<std::endl;
    // std::cout<<std::hex<<pref.getMask()<<std::endl;
    // std::cout<<std::hex<<pref.masked()<<std::endl;
    */


    SortedSet<int> set;

    set.add(1);
    set.add(2);
    set.add(2);
    set.add(5);
    set.add(4);
    set.add(6);
    set.add(3);

    for(int i = 0; i < set.getSize(); ++i)
        std::cout<<set.at(i)<<std::endl;

    return EXIT_SUCCESS;
}
