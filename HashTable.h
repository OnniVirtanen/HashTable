//
// Created by Onni on 01/11/2023.
//

#pragma once
#include <vector>
#include <list>
#include <optional>

template<typename K, typename V>
class HashTable
{
public:
    /**
     * Insert key and value
     * @param key
     * @param value
     */
    void insert(K key, V value);

    /**
     * Remove pair of key and value
     * @param key
     * @return true if key exists and operation was successful
     */
    bool remove(K key);

    /**
     * Search value by key
     * @param key
     * @return optional of value
     */
    std::optional<V> search(K key) const;

    explicit HashTable(size_t size = 101) : buckets(size) {}
private:
    int hash(K key) const;
    std::vector<std::list<std::pair<K, V>>> buckets;
};

template<typename K, typename V>
int HashTable<K, V>::hash(K key) const {
    return std::hash<K>{}(key) % buckets.size();
}

template<typename K, typename V>
void HashTable<K,V>::insert(K key, V value)
{
    int index = hash(key);
    std::list<std::pair<K,V>>& bucket = buckets[index];
    for (std::pair<K,V>& pair : bucket)
    {
        if (pair.first == key)
        {
            pair.second = value;
            return;
        }
    }
    bucket.push_back({key, value});
}

template<typename K, typename V>
bool HashTable<K,V>::remove(K key)
{
    int index = hash(key);
    std::list<std::pair<K,V>>& bucket = buckets[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it)
    {
        if (it->first == key)
        {
            bucket.erase(it);
            return true;
        }
    }
    return false;
}

template<typename K, typename V>
std::optional<V> HashTable<K,V>::search(K key) const
{
    int index = hash(key);
    const std::list<std::pair<K,V>>& bucket = buckets[index];
    for (const std::pair<K,V>& pair : bucket)
    {
        if (pair.first == key)
        {
            return pair.second;
        }
    }
    return std::nullopt;
}