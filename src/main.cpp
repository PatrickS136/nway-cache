#include <bits/stdc++.h>

#include "Cache.hpp"
#include "CacheSet.hpp"
#include "LRU.cpp"
#include "NWaySetAssociativeCache.cpp"

using namespace std;

int main(){
    NWaySetAssociativeCache<string, int, LRU<string, int>> * a = new NWaySetAssociativeCache<string, int, LRU<string, int>>(5, 5);
    cout << "Hello World\n";
    a->put("hello", 12);
    a->visualizeCacheSets();

    return 0;
}