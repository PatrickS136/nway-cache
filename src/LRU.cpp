#include "CacheSet.hpp"

template<typename K, typename V>
class LRU : public CacheSet<K, V> {
private:
    // Function to remove a node from the cache set
    void removeNode(CacheSetItem<K, V>* node) {
        node->before->next = node->next;
        node->next->before = node->before;
    }

    // Function to add a node to the front of the cache set
    void addToFront(CacheSetItem<K, V>* node) {
        node->next = this->first->next;
        node->before = this->first;
        this->first->next->before = node;
        this->first->next = node;
    }

    // Function to move a node to the front of the cache set
    void moveToFront(CacheSetItem<K, V>* node) {
        removeNode(node);
        addToFront(node);
    }

    // Function to evict the least recently used item from the cache set
    void evict() override {
        // CacheSetItem<K, V>* lastNode = this->last->before;
        // removeNode(lastNode);
        // cacheMap.erase(lastNode->content->getKey());
        // delete lastNode->content;
        // delete lastNode;
    }
public:
    LRU(int size) : CacheSet<K, V>(size) {}

    // Override the get method
    V get(const K& key) override {
        return V();
        // if (cacheMap.find(key) == cacheMap.end()) {
        //     return V(); // Key not found, return default value for type V
        // }

        // CacheSetItem<K, V>* node = cacheMap[key];
        // V value = node->content->getValue();
        // moveToFront(node); // Move the accessed node to the front
        // return value;
    }

    // Override the put method
    void put(const K& key, const V& value) override {
        CacheSetItem<K, V> * newNode = new CacheSetItem<K, V>(key, value);
        auto temp = this->first->next;
        this->first->next = newNode;
        newNode->next = temp;
        // if (cacheMap.find(key) != cacheMap.end()) {
        //     // If key already exists, update its value and move it to the front
        //     CacheSetItem<K, V>* node = cacheMap[key];
        //     node->content->setValue(value);
        //     moveToFront(node);
        // } else {
        //     // If key doesn't exist, create a new cache block and add it to the front
        //     if (this->cacheMap.size() == this->getSize()) {
        //         // If cache is full, evict the least recently used item
        //         evict();
        //     }

        //     CacheBlock<K, V>* block = new CacheBlock<K, V>(key, value);
        //     CacheSetItem<K, V>* node = new CacheSetItem<K, V>();
        //     node->content = block;
        //     addToFront(node);
        //     cacheMap[key] = node;
        // }
    }
};