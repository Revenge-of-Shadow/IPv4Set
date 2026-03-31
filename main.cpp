

#include "Set.h"
int main(){
    Set<int> set;
    for(int i = 0; i < 10; ++i)
        set.add(i);

    set.del(5);
    for(int i = 0; i < set.getSize(); ++i)
        std::cout<<set.at(i)<<std::endl;

    return EXIT_SUCCESS;
}
