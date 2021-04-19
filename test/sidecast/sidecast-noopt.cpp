struct cat {
    virtual ~cat()=default;
};

struct dog {
    virtual ~dog()=default;
};


dog& get_dog(cat& c){
    return dynamic_cast<dog&>(c);
}
