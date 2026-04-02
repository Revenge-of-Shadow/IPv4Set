#ifndef SET
#define SET

#include "includes.h"
#include <cstdint>

template<typename T> class Set{
protected:
    uint32_t capacity;
    uint32_t size;
    T* elements;

    void grow(){
        T* new_elements = new T[capacity*2];
        for(int i = 0; i<capacity; ++i)
            new_elements[i] = elements[i];
        capacity *= 2;

        delete[] elements;
        elements = new_elements;
    }
    void removeAt(uint32_t ind){
        --size;
        for(int i = ind; i < size; ++i){
            elements[i] = elements[i+1];
        }
    }

public:
    Set(uint32_t capacity = 8):size(0), capacity(capacity){ 
        elements = new T[capacity];
    }
    ~Set(){delete[] elements;}

    T at(int ind) const{
        if(ind < 0 || ind >= size) 
            throw std::out_of_range("Requested index is out of range.");
        return elements[ind];
    }

    int getSize() const{ return size; }

    bool insertAt(const T& val, int ind){
        if(ind < 0 || ind > size || check(val) != -1) 
            return false;

        if(size++ == capacity) grow(); 
        for(int i = size-1; i > ind; --i){
            elements[i] = elements[i-1];
        }
        elements[ind] = val;

        return true;
    }


    bool add(const T& val){
        return insertAt(val, size);
    }

    bool del(const T& val){
        int ind = check(val);
        if(ind == -1) return false;

        removeAt(ind);
        return true;
        
    }
    
    int check(const T& val) const{
        for(int i = 0; i < size; ++i)
            if(elements[i] == val)  return i;
        return -1;
    }

};
#endif 
