// LFU.cpp
#include "LFU.hpp"
#include "CacheElement.hpp"

template<typename K, typename V>
int LFU<K, V>::compare(const CacheElement<K, V, unsigned long>& current, const CacheElement<K, V, unsigned long>& candidate) const {
    return (current.metadata < candidate.metadata) ? -1 : ((current.metadata > candidate.metadata) ? 1 : 0);
}

template<typename K, typename V>
void LFU<K, V>::onPut(CacheElement<K, V, unsigned long>& element) {
    onGet(element);
}

template<typename K, typename V>
void LFU<K, V>::onGet(CacheElement<K, V, unsigned long>& element) {
    if (element.metadata == 0) {
        element.metadata = 1UL;
    } else {
        element.metadata += 1UL;
    }
}
