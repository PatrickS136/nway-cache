#pragma once
#include <unordered_map>
#include <functional>
#include <iostream>
#include "CacheBlock.hpp"

template<typename K, typename V>
class CacheSetItem {
public:
    CacheBlock<K, V> * content;
    CacheSetItem<K, V> * before;
    CacheSetItem<K, V> * next;

    CacheSetItem(){
        this->content = nullptr;
    }

    CacheSetItem(const K& key, const V& value){
        this->content = new CacheBlock<K, V>(key, value);
    }
};

template<typename K, typename V>
class CacheSet {
private:
    int size, capacity;

    virtual void evict() = 0;
public:
    CacheSetItem<K, V> * first;
    CacheSetItem<K, V> * last;
    std::unordered_map<int, CacheSetItem<K, V>*> cacheMap;

    CacheSet(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->first = new CacheSetItem<K, V>();
        this->last = new CacheSetItem<K, V>();
        this->first->next = this->last;
        this->last->before = this->first;
    }

    int getSize() { 
        return this->size;
    }

    void visualizeCacheSet(){
        CacheSetItem<K, V> * current = first->next;
        while (current->content != nullptr) {
            std::cout << current->content->getKey() << " : " << current->content->getData() << " -> ";
            current = current->next;
        }
    }

    virtual V get(const K& key) = 0;
    virtual void put(const K& key, const V& value) = 0;
};