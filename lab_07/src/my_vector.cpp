#include "my_vector.h"
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cstdio>

class MyVector{
public:
    size_t size(){
        return _size;
    }

    size_t capacity(){
        return _capacity;
    }

    void set (size_t i, int value){
        if(i < _size && i > 0)
            _arr[i] = value;
    }

    int get(size_t index){
        return _arr[index];
    }

    void resize(size_t new_size){
        _capacity = 2 * new_size;
        int *new_arr = new int[_capacity];
        for (size_t i = 0; i < std::min( _size, new_size ); ++i )
            new_arr[i] = _arr[i];

        delete [] _arr;
        _size = new_size;
        _arr = new_arr;
    }

    MyVector(size_t capacity){
        _size = 0;
        _capacity = capacity;
        _arr = new int[_capacity];
    }

    MyVector(){
        _size = 0;
        _capacity = 2;
        int _arr[_capacity];
    }

    ~MyVector(){
        delete []_arr;
    }

    void push_back(int value){
        if ( _size == _capacity ){
            resize( _size + 1 );
            --_size;
        }

        _arr[_size++] = value;
    }
    void pop_back(){
        if(_size > 0)
            _size--;
    }
    void erase(size_t index){
        for(int i = index; i < _size; i++){
            _arr[i] = _arr[i + 1];
        }
        _size--;
    }


    void insert(size_t i, int value){
        if(_size + 1 > _capacity){
            resize(_size + 1);
        }
        else{
            _size += 1;
        }
        for(size_t j = _size - 1; j > i; j--){
            _arr[i] = _arr[i - 1];
        }
        _arr[i] = value;
    }
private:
    int *_arr;
    size_t _size;
    size_t _capacity;
};
