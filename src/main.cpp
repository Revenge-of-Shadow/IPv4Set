#include "IPv4PrefixSortedSet.h"

void printIPv4(IPv4Prefix i){
    std::cout<<"Address:\t"
        <<(i.base & 0xFF000000)/0x1000000<<"."
        <<(i.base & 0xFF0000)/0x10000 <<"."
        <<(i.base & 0xFF00)/0x100 <<"."
        <<(i.base & 0xFF) <<"\t\t";
    std::cout<<"Mask:\t"
        <<(i.getMask() & 0xFF000000)/0x1000000 <<"."
        <<(i.getMask() & 0xFF0000)/0x10000 <<"."
        <<(i.getMask() & 0xFF00)/0x100 <<"."
        <<(i.getMask() & 0xFF) <<"\t\t";
    std::cout<<"Masked:\t"
        <<(i.masked() & 0xFF000000)/0x1000000 <<"."
        <<(i.masked() & 0xFF0000)/0x10000 <<"."
        <<(i.masked() & 0xFF00)/0x100 <<"."
        <<(i.masked() & 0xFF) <<std::endl;
}

int main(){

    IPv4PrefixSortedSet IPset;

    //  Extra check to compare with all the possible masks.
    /*
    for(int i = 0; i<33; ++i)
        std::cout<<IPset.add(0xFFFF0000, i)<<std::endl;   
    */
    
    std::cout<<"Inserting..."<<std::endl;
    //  First two bytes the same.
    const int prefs_size = 6;
    IPv4Prefix prefs[prefs_size] = {
        IPv4Prefix(0x23531232, 16),
        IPv4Prefix(0x23531251, 8),
        IPv4Prefix(0x23534331, 24),
        IPv4Prefix(0x9881aF82, 8),
        //  These are out. 
        IPv4Prefix(0x9881aF82, 8),
        IPv4Prefix(0xFFFFFFFF, 33)
    };
    for(int i = 0; i < prefs_size; ++i)
        std::cout<<prefs[i].base<<"/"<<(int)prefs[i].maskLength<<'\t'<<
            (IPset.add(prefs[i].base, prefs[i].maskLength)?
                "Inserted":"Not inserted")<<std::endl;

    std::cout<<std::endl;
    for(int i = 0; i < IPset.getSize(); ++i)
        printIPv4(IPset.at(i));
    std::cout<<std::endl;



    //  Here first two IP are for Prefixes with 
    //  indexes 2, 0 and none respectively.    

    const int ips_size = 3;
    int ips[ips_size] = {
        0x235343AA, 0x23030055, 0x13532455
    };

    for(int i = 0; i < ips_size; ++i){ 
        std::cout<<"Checking for\t"<<ips[i]<<std::endl;
        int found = IPset.check(ips[i]);

        if(found == -1)
            std::cout<<"Not found."<<std::endl;
        else
        {
            std::cout<<"Found Prefix with mask length "<<found<<""<<std::endl;
        std::cout<<std::endl;
        }
    }
    return EXIT_SUCCESS;
}
