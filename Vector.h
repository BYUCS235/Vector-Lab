//
// Created by dagor on 11/8/2022.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <string>
#include <ostream>

const size_t INITIAL_CAPACITY = 10;
const std::string OUT_OF_RANGE_MESSAGE = "Index provided is out of range";

template <class T>
class Vector{
public:
    // constructors and destructor
    Vector(size_t size = INITIAL_CAPACITY){}
    Vector(Vector<T>& other){}
    ~Vector() {}
    // data access
    const T& operator[] (size_t index) const;
    T& operator[] (size_t index);
    const T& at(size_t index) const;
    T& at(size_t index);
    // state functions
    bool empty() const;
    size_t size() const;
    void resize(size_t new_size);
    std::string toString() const;
    friend std::ostream & operator<< (std::ostream & os, Vector<T> & obj); // not sure if we should include this one
    // adding data
    void push_back(const T& value);
    void insert(size_t index, const T& value);
    // removing data
    void pop_back();
    void erase(size_t index);
    // bulk change methods
    void swap(Vector<T>& other);
    Vector<T>& operator= (const Vector<T>& other);
    // comparison operators
    bool operator== (const Vector<T>& other);
};

#endif //VECTOR_H
