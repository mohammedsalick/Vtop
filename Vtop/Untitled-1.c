#include <stdio.h>

#define TABLE_SIZE 19

int hash_function(int x) {
    return x % TABLE_SIZE;
}

int linear_probing(int index, int i) {
    return (index + i) % TABLE_SIZE;
}

void insert(int hash_table[], int value) {
    int index = hash_function(value);
    int i = 0;

    while (hash_table[index] != 0) {
        i++;
        index = linear_probing(index, i);
    }

    hash_table[index] = value;
}

int count_free_cells(int hash_table[]) {
    int count = 0;
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int hash_table[TABLE_SIZE] = {0}; // Initialize hash table with 0s

    // Elements to be inserted
    int elements[] = {56, 78, 90, 12, 46, 33, 29, 40, 68, 4, 83};
    int num_elements = sizeof(elements) / sizeof(elements[0]);

    // Insert elements into the hash table
    for (int i = 0; i < num_elements; i++) {
        insert(hash_table, elements[i]);
    }

    // Count the number of free cells in the hash table
    int free_cells = count_free_cells(hash_table);

    // Print the hash table and number of free cells
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: %d\n", i, hash_table[i]);
    }
    printf("Number of free cells: %d\n", free_cells);

    return 0;
}