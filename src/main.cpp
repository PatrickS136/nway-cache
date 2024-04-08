#include <bits/stdc++.h>

#include "Cache.hpp"
#include "CacheSet.hpp"
#include "LRU.cpp"
#include "MRU.cpp"
#include "NWaySetAssociativeCache.cpp"

using namespace std;

int main(){
    NWaySetAssociativeCache<string, int, MRU<string, int>> * a = new NWaySetAssociativeCache<string, int, MRU<string, int>>(1, 5);
    cout << "Hello World\n";
    a->put("a", 12);
    a->put("b", 13);
    a->put("c", 14);
    a->put("d", 15);
    a->put("e", 16);
    a->visualizeCacheSets();
    a->get("a");
    a->visualizeCacheSets();
    a->put("f", 17);
    a->get("a");
    a->get("b");
    a->visualizeCacheSets();
    a->get("a");

    return 0;
}