#pragma once
#include "EvictionPolicy.hpp"

template<typename K, typename V>
class LFU : public EvictionPolicy<K, V, unsigned long> {
public:
    int compare(const CacheElement<K, V, unsigned long>& current, const CacheElement<K, V, unsigned long>& candidate) const override;
    void onPut(CacheElement<K, V, unsigned long>& element) override;
    void onGet(CacheElement<K, V, unsigned long>& element) override;
};