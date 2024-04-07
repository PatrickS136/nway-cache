#pragma once

template<typename K, typename V, typename M>
class CacheElement {
private:
    K key;
    V data;
    M metadata;

public:
    K getKey() const;
    V getData() const;
    M getMetadata() const;
    void setMetadata(M metadata);
    void setKeyValue(K key, V value);
};