#ifndef SORTEDSET
#define SORTEDSET
#include "Set.h"


template <typename T> class SortedSet : public Set<T>{
protected:
    uint32_t getNewInd(const T& val, uint32_t begin, uint32_t end){
        if(end - begin <= 1){    //  One or two elements left.
            if(!Set<T>::size) return 0;
            if(val < Set<T>::elements[begin])   //  val < first
                return begin;
            if(val > Set<T>::elements[end])   //  val > last
                return end+1;
            return end;
        }
        else{   //  Continue splitting.
            uint32_t avg = begin + (end - begin)/2;
            return (val > Set<T>::elements[avg])? 
                getNewInd(val, avg, end):
                getNewInd(val, begin, avg);
        }
    }

    uint32_t find(const T& val, uint32_t begin, uint32_t end){
        if(end - begin < 1){    //  One or two elements left.
            if(Set<T>::elements[begin] == val)   //  val == first
                return begin;
            if(Set<T>::elements[end] == val)   //  val == last
                return end;
            return -1;
        }
        else{   //  Continue splitting.
            uint32_t avg = begin + (end - begin)/2;
            return (val < Set<T>::elements[avg])? 
                getNewInd(val, avg, end):
                getNewInd(val, begin, avg);
        }
    }
public:
    bool add(const T& val){
        return Set<T>::insertAt(val, 
            Set<T>::size?
                getNewInd(val, 0, Set<T>::size-1):
                0);

    }
    bool del(const T& val){
        int ind = check(val);
        if(ind == -1) return false;

        Set<T>::removeAt(ind);
        return true;
        
    }
    bool check(const T& val) const{
        return find(val, 0, Set<T>::size-1);
    }
};

#endif
