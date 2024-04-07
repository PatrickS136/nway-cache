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

    V getData() const {
        return data;
    }

    void setKeyValue(K key, V value) {
        this->key = key;
        this->data = value;
    }
};

#include "CacheBlock.hpp"