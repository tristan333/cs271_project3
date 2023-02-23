#ifndef hash_table_H
#define hash_table_H

#include <list>

template<typename T>
class Element {
public:
    Element(T data, int key);
    int get_key();
    T get_data();
private:
    T data;
    int key;
};

template<typename T>
class HashTable {
public:
    HashTable(int size);
    ~HashTable();
    void insert(T data, int key);
    void remove(int key);
    Element<T>* find(int key);
private:
    std::list<Element<T> >* table;
    int table_size;
};

#include "hash_table.cpp"

#endif // MYPROGRAM_H
