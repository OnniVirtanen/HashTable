#include <iostream>
#include "HashTable.h"
#include "cassert"


void testInsertion()
{
    HashTable<int, std::string> table;
    table.insert(1, "one");
    assert(table.search(1).value() == "one");
    std::cout << "Test Insertion Passed\n";
}

void testUpdate() {
    HashTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(1, "uno");
    assert(table.search(1).value() == "uno");
    std::cout << "Test Update Passed\n";
}

void testRemoval()
{
    HashTable<int, std::string> table;
    table.insert(1, "one");
    assert(table.remove(1) == true);
    assert(table.search(1) == std::nullopt);
    std::cout << "Test Removal Passed\n";
}

void testSearch()
{
    HashTable<int, std::string> table;
    assert(table.search(42) == std::nullopt);
    std::cout << "Test Search Passed\n";
}

void testCollisionHandling()
{
    HashTable<int, std::string> table;
    int keys[] = {101, 202, 303};  // These keys should all hash to the same index if using modulo 101 as the hash function.
    std::string values[] = {"one", "two", "three"};

    for (int i = 0; i < 3; ++i) {
        table.insert(keys[i], values[i]);
    }

    for (int i = 0; i < 3; ++i) {
        assert(table.search(keys[i]).value() == values[i]);
    }

    std::cout << "Test Collision Handling Passed\n";
}

void runAllTest()
{
    testInsertion();
    testUpdate();
    testRemoval();
    testSearch();
    testCollisionHandling();
    std::cout << "All Tests Passed\n";
}

int main()
{
    runAllTest();
    return 0;
}
