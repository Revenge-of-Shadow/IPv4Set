#ifndef IPV4PREFIXSET
#define IPV4PREFIXSET

#include "IPv4Prefix.h"
#include "SortedSet.h"


class IPv4PrefixSortedSet : public SortedSet<IPv4Prefix>{
protected:
   int findIP(const uint32_t& val, uint32_t begin, uint32_t end) const{

        if(end - begin <= 1){    //  One or two elements left.
            if(elements[begin] == val)   //  val == first
                return begin;
            if(elements[end] == val)   //  val == last
                return end;
            return -1;
        }

        else{   //  Continue splitting.
            uint32_t avg = begin + (end - begin)/2;
            return (elements[avg] < val)? 
                findIP(val, avg, end):
                findIP(val, begin, avg);
        }
    } 
public:

    bool add(const uint32_t& base, const uint8_t maskLength){
        if(maskLength > 32) return false;
        if(base > 0xFFFFFFFF) return false;

        return SortedSet::add(IPv4Prefix(base, maskLength));
    }
    bool del(const uint32_t& base, const uint8_t maskLength){
        if(maskLength > 32) return false;

        return SortedSet::del(IPv4Prefix(base, maskLength));
    }

    int check(const uint32_t& ip)const{
        int max_mask = -1;
        int first_ind = findIP(ip, 0, size-1);

        if(first_ind != -1){
            for(int i = first_ind; i < size; ++i){
                if(elements[i] == ip && max_mask < elements[i].maskLength){
                    max_mask = elements[i].maskLength;
                }else
                    break;
                }
        }
        return max_mask;
    }
    
};
#endif
