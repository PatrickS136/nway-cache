#pragma once
#include "CacheElement.hpp"

template<typename K, typename V, typename M>
class EvictionPolicy {
public:
    virtual int compare(const CacheElement<K, V, M>& current, const CacheElement<K, V, M>& candidate) const = 0;
    virtual void onPut(CacheElement<K, V, M>& element) = 0;
    virtual void onGet(CacheElement<K, V, M>& element) = 0;
};