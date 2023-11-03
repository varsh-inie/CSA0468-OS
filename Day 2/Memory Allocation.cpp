#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 100

struct MemoryBlock {
    int size;
    int allocated;
};

struct MemoryBlock memory[MEMORY_SIZE];

void initializeMemory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i].size = 0;
        memory[i].allocated = 0;
    }
}

void allocateMemory(int requestSize) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (!memory[i].allocated && memory[i].size >= requestSize) {
            memory[i].allocated = 1;
            printf("Memory allocated at index %d\n", i);
            return;
        }
    }
    printf("Memory allocation failed for size %d\n", requestSize);
}

void deallocateMemory(int index) {
    if (index >= 0 && index < MEMORY_SIZE) {
        memory[index].allocated = 0;
        printf("Memory deallocated at index %d\n", index);
    } else {
        printf("Invalid memory index\n");
    }
}

int main() {
    initializeMemory();

    int choice, size, index;

    do {
        printf("\n1. Allocate Memory\n");
        printf("2. Deallocate Memory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter size for allocation: ");
                scanf("%d", &size);
                allocateMemory(size);
                break;
            case 2:
                printf("Enter index for deallocation: ");
                scanf("%d", &index);
                deallocateMemory(index);
                break;
            case 3:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (choice != 3);

    return 0;
}
