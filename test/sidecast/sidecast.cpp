#include <iostream>

struct cat {
    virtual ~cat()=default;
};

struct dog {
    virtual ~dog()=default;
};

struct dogcat : dog, cat{};

dog& get_dog(cat& c);

int main(){
    dogcat dc{};
    dog& dog = get_dog(dc);
}