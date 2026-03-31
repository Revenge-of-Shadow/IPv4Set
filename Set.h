#include <exception>
#include <iostream>
#include <stdexcept>

template<typename T> class Set{
protected:
    int capacity;
    int size;
    T* elements;

    void grow(){
        capacity *= 2;
        T* new_elements = new T[capacity];
        for(int i = 0; i<size; ++i)
            new_elements[i] = elements[i];

        delete[] elements;
        elements = new_elements;
    }

public:
    Set():size(0), capacity(8){ elements = new T[capacity];};    
    ~Set(){delete[] elements;}

    T at(int ind) const{
        if(ind < 0 || ind >= size) 
            throw std::out_of_range("Requested index is out of range.");
        return elements[ind];
    }

    int getSize() const{ return size; }


    bool add(const T val){
        if(check(val) != -1) return false;

        if(size == capacity) grow(); 
        elements[size++] = val;

        return true;
    }

    bool del(const T val){
        int ind = check(val);
        if(ind == -1) return false;

        --size;
        for(int i = ind; i < size; ++i){
            elements[i] = elements[i+1];
        }
        return true;
        
    }
    
    int check(const T val) const{
        for(int i = 0; i < size; ++i)
            if(elements[i] == val)  return i;
        return -1;
    }

};
