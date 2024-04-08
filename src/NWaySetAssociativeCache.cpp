#include "Cache.hpp"
#include "CacheBlock.hpp"
#include "CacheSet.hpp"

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

template<typename K, typename V, typename T>
class NWaySetAssociativeCache : public Cache<K, V> {
private:
    int n, s;
    std::vector<T> cacheSets;
    int getHash(const K& key) {
        std::hash<K> hasher;
        return std::abs(static_cast<int>(hasher(key))) % this->n;
    }
public:
    NWaySetAssociativeCache(int n, int s) : n(n), s(s) {
        if (cacheSets.size() != 0) throw;

        for (int i=0; i<n; i++){
            cacheSets.push_back(T(s));
        }
    }

    V get(const K& key) override {
        int index = getHash(key);
        return cacheSets[index].get(key);
    }

    void put(const K& key, const V& value) override {
        int index = getHash(key);
        cacheSets[index].put(key, value);
    }

    // Visualize function to print the contents of each cache set
    void visualizeCacheSets() {
        for (int i = 0; i < n; ++i) {
            std::cout << "Cache Set " << i << ":\n";
            cacheSets[i].visualizeCacheSet();
            std::cout << "\n";
        }
        std::cout<<"\n";
    }
};
