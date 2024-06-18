#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define PAGE_SIZE 4
#define PHYSICAL_MEMORY_SIZE 16
#define VIRTUAL_MEMORY_SIZE 32
#define TOTAL_PAGES VIRTUAL_MEMORY_SIZE / PAGE_SIZE
#define PHYSICAL_MEMORY_FRAMES PHYSICAL_MEMORY_SIZE / PAGE_SIZE

typedef struct {
    int frame_number;
    bool valid;
} PageTableEntry;

void initialize(PageTableEntry page_table[]) {
    for (int i = 0; i < TOTAL_PAGES; i++) {
        page_table[i].frame_number = -1;
        page_table[i].valid = false;
    }
}

void display_memory(PageTableEntry page_table[]) {
    printf("\nPage Table\n");
    for (int i = 0; i < TOTAL_PAGES; i++) {
        if (page_table[i].valid) {
            printf("Page %d is in Physical Memory Frame %d\n", i, page_table[i].frame_number);
        } else {
            printf("Page %d is not in Physical Memory\n", i);
        }
    }
    printf("----------------------------\n");
}

int main() {
    PageTableEntry page_table[TOTAL_PAGES];
    initialize(page_table);

    int page_sequence_size;
    printf("Enter the number of pages in the sequence: ");
    scanf("%d", &page_sequence_size);

    int *page_sequence = (int *)malloc(page_sequence_size * sizeof(int));
    printf("Enter the page sequence: ");
    for (int i = 0; i < page_sequence_size; i++) {
        scanf("%d", &page_sequence[i]);
    }

    int page_faults = 0;
    int next_frame_number = 0;

    for (int i = 0; i < page_sequence_size; i++) {
        int page_number = page_sequence[i];
        bool page_found = false;

        // Check if the page is already in physical memory
        for (int j = 0; j < TOTAL_PAGES; j++) {
            if (page_table[j].valid && page_table[j].frame_number == page_number) {
                page_found = true;
                break;
            }
        }

        // Page not found in physical memory, handle page fault
        if (!page_found) {
            page_faults++;
            if (page_table[page_number].valid) {
                printf("Page %d is replaced by Page %d\n", page_table[page_number].frame_number, page_number);
            } else {
                printf("Page %d is loaded into Physical Memory\n", page_number);
            }
            page_table[page_number].frame_number = page_number;
            page_table[page_number].valid = true;
            next_frame_number = (next_frame_number + 1) % PHYSICAL_MEMORY_FRAMES;
        }
        if(page_found)
        {
            printf("page %d is already present in the page table\n",page_number);
        }

        display_memory(page_table);
    }

    printf("\nTotal Page Faults: %d\n", page_faults);

    free(page_sequence);
    return 0;
}
