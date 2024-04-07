#pragma once

template<typename K, typename V>
class Cache {
public:
    virtual V get(const K& key) = 0;
    virtual void put(const K& key, const V& value) = 0;
};