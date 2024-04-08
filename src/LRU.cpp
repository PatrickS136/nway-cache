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
        CacheSetItem<K, V>* lastNode = this->last->before;
        removeNode(lastNode);
        this->cacheMap.erase(lastNode->content->getKey());
        delete lastNode->content;
        delete lastNode;
    }
public:
    LRU(int size) : CacheSet<K, V>(size) {}

    // Override the get method
    V get(const K& key) override {
        if (this->cacheMap.find(key) == this->cacheMap.end()) {
            std::cout<<"Not found for key : "<< key <<"\n";
            return V(); // Key not found, return default value for type V
        }

        CacheSetItem<K, V>* node = this->cacheMap[key];
        V value = node->content->getValue();
        moveToFront(node); // Move the accessed node to the front
        std::cout<<"Found for key : "<< key <<" value : "<< value <<"\n";
        return value;
    }

    // Override the put method
    void put(const K& key, const V& value) override {
        if (this->cacheMap.find(key) != this->cacheMap.end()) {
            // If key already exists, update its value and move it to the front
            CacheSetItem<K, V>* node = this->cacheMap[key];
            node->content->setValue(value);
            moveToFront(node);
        } else {
            // If key doesn't exist, create a new cache block and add it to the front
            if (this->cacheMap.size() == (unsigned long)this->getCapacity()) {
                // If cache is full, evict the least recently used item
                evict();
            }

            CacheSetItem<K, V>* node = new CacheSetItem<K, V>(key, value);
            addToFront(node);
            this->cacheMap[key] = node;
        }
    }
};