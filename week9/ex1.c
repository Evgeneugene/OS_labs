#include <stdlib.h>
#include <stdio.h>

typedef struct page {
    unsigned short age;
    unsigned short id;
} page;

int main() {
    page *pages;
    unsigned int n;
    printf("Enter the number of page frames: ");
    scanf("%i", &n);
    pages = malloc(n * sizeof(page));
    for (int i = 0; i < n; i++) {
        pages[i].age = 0;
        pages[i].id = -1;
    }
    int misses = 0, hits = 0;
    FILE *file = fopen("input.txt", "r");
    unsigned short page_ref;
    while (fscanf(file, "%hu", &page_ref) != EOF) {
        int pageFault = 1;
        unsigned short min_age = -1;
        unsigned short min_age_N = -1;
        for (int i = 0; i < n; i++) {
            if (pages[i].id == page_ref) {
                pageFault = 0;
                min_age_N = i;
                break;
            }
            if (min_age > pages[i].age) min_age_N = i;
            if (min_age > pages[i].age) min_age = pages[i].age;
        }
        for (int i = 0; i < n; i++) {
            pages[i].age >>= 1;
        }
        if (pageFault == 1) {
            pages[min_age_N].id = page_ref;
            pages[min_age_N].age = 32768;
            misses++;
        } else {
            pages[min_age_N].age += 32768;
            hits++;
        }
    }
    printf("hit = %i : miss = %i\nhit ratio: %f", hits, misses, ((double) hits) / (double)misses);
    fclose(file);
    return 0;
}