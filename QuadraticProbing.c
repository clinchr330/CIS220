// Rafael Clinch
// Chpt6 PA
#include <stdio.h>
#include <stdbool.h>

#define HASH_TABLE_SIZE 16
#define EMPTY_SINCE_START -1
#define EMPTY_AFTER_REMOVAL -2

int hashTable[HASH_TABLE_SIZE];

int hash(int key) { // This function computes the hash value for a given key
    return key % HASH_TABLE_SIZE;
}

bool hashInsert(int item) { // This function inserts an item into the hash table
    int h = hash(item);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        int j = (h + i + i * i) % HASH_TABLE_SIZE;
        if (hashTable[j] == EMPTY_SINCE_START || hashTable[j] == EMPTY_AFTER_REMOVAL) {
            hashTable[j] = item;
            return true;
        }
    }
    return false;
}

bool hashRemove(int item) { // This function removes an item from the hash table
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (hashTable[i] == item) {
            hashTable[i] = EMPTY_AFTER_REMOVAL;
            return true;
        }
    }
    return false;
}

int hashSearch(int item) { // This functions searches for an item in the hash table and return the index if found
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (hashTable[i] == item) {
            return i;
        }
    }
    return -9;
}

void displayHashTable() { // This function displays tje contents of the hash table
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        printf("Hashtable[%d] is %d\n", i, hashTable[i]);
    }
}

int main() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable[i] = EMPTY_SINCE_START;
    }

    
    int items[] = {32, 63, 16, 3, 23, 11, 64, 99, 42, 49, 48, 21}; // Insert items into the hash table and display a message if the insert was successful or not successful.
    for (int i = 0; i < sizeof(items) / sizeof(int); i++) {
        printf("Item %d was inserted %s\n", items[i], hashInsert(items[i]) ? "Successfuly" : "Unsuccessfuly");
    }

    displayHashTable(); // Display the hash table's contents

    
    int removeItems[] = {32, 11}; // Remove items from the hash table and display a message if the insert was successful or not successful
    for (int i = 0; i < sizeof(removeItems) / sizeof(int); i++) {
        printf("Item %d was removed %s\n", removeItems[i], hashRemove(removeItems[i]) ? "Successfuly" : "Unsuccessfuly");
    }

    
    int searchItems[] = {64, 48, 32}; // Search for items in the hash table, display the bucket it was found in or that it was not found
    for (int i = 0; i < sizeof(searchItems) / sizeof(int); i++) {
        int bucket = hashSearch(searchItems[i]);
        if (bucket != -9) {
            printf("Item %d was found in bucket %d\n", searchItems[i], bucket);
        } else {
            printf("Item %d was not found\n", searchItems[i]);
        }
    }

    printf("Item 9 was inserted %s\n", hashInsert(9) ? "Successfuly" : "Unsuccessfuly");    // Insert item 9 into the hash table, display a message if the insert was successful or not successful

    int removeItems2[] = {64, 99}; // Remove items from the hash table and display a message if successful or not successful
    for (int i = 0; i < sizeof(removeItems2) / sizeof(int); i++) {
        printf("Item %d was removed %s\n", removeItems2[i], hashRemove(removeItems2[i]) ? "Successfuly" : "Unsuccessfuly");
    }

    
    displayHashTable(); // Display the hash table’s contents

    return 0;
}