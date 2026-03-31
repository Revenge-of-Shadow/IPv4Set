#ifndef IPV4PREFIXSET
#define IPV4PREFIXSET

#include "IPv4Prefix.h"
#include "Set.h"


class IPv4PrefixSet : public Set<IPv4Prefix>{
public:

    bool add(const uint32_t& base, const uint8_t maskLength){
        if(maskLength > 32) return false;

        return Set::add(IPv4Prefix(base, maskLength));
    }
    bool del(const uint32_t& base, const uint8_t maskLength){
        if(maskLength > 32) return false;

        return Set::del(IPv4Prefix(base, maskLength));
    }

    int check(const uint32_t& ip){
        int max_mask = -1;

        for(int i = 0; i < size; ++i)
            if((elements[i].base & elements[i].getMask())
                == (ip & elements[i].getMask()))  
                if(elements[i].maskLength > max_mask) 
                    max_mask = elements[i].maskLength;

        return max_mask;
    }
    
};
#endif
