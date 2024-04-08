#pragma once

template<typename K, typename V>
class CacheBlock {
private:
    K key;
    V data;

public:
    CacheBlock(const K& key, const V& data) : key(key), data(data) {}

    K getKey() const {
        return key;
    }

    V getValue() const {
        return data;
    }

    void setKey(K key) {
        this->key = key;
    }

    void setValue(V value) {
        this->data = value;
    }
};

#include "CacheBlock.hpp"