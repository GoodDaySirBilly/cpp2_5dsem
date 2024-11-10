//
// Created by user on 11/10/2024.
//

#ifndef CPP2_5DSEM_CONTAINER_H
#define CPP2_5DSEM_CONTAINER_H
#include "SIGN.h"
class Container{

private:
    SIGN** arr;
    unsigned size, real_size;
protected:
    void sort();
public:
    explicit Container();
    explicit Container(unsigned);
    Container(const Container&);
    virtual ~Container();


    void add(SIGN*);
    void remove(unsigned);
    void swap(unsigned ,unsigned );
    bool isEmpty() const;
    int length();
    void clear();

    SIGN* operator[](unsigned index);
    std::ostream& operator<<(std::ostream&);

};

#endif //CPP2_5DSEM_CONTAINER_H
