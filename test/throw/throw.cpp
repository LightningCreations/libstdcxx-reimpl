#include <exception>
#include <cstdlib>



int main(){
    try{
        throw std::exception{};
    }catch(...){
        return 0;
    }
}