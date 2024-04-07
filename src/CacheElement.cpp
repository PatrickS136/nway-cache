// CacheElement.cpp
#include "CacheElement.hpp"

template<typename K, typename V, typename M>
K CacheElement<K, V, M>::getKey() const {
    return key;
}

template<typename K, typename V, typename M>
V CacheElement<K, V, M>::getData() const {
    return data;
}

template<typename K, typename V, typename M>
M CacheElement<K, V, M>::getMetadata() const {
    return metadata;
}

template<typename K, typename V, typename M>
void CacheElement<K, V, M>::setMetadata(M metadata) {
    this->metadata = metadata;
}

template<typename K, typename V, typename M>
void CacheElement<K, V, M>::setKeyValue(K key, V value) {
    this->key = key;
    this->data = value;
}
