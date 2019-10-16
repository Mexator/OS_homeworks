#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_PAGES_AMOUNT 4;
//Just for convenience
typedef unsigned int uint;

//Struct for page table entry
typedef struct
{
    //number of page frame
    int page_frame;
    /*
     * Present/absent 'bit'
     * 0-absent, 1-present
     */
    int present_absent;
    /*
     * R 'bit'
     * 0-not read, 1-read
     */
    int r;
    uint counter;
} PTE;

int main(int argc, char *argv[])
{
    //Opening file
    FILE *file;
    char filename[80];
    if (argc >= 3)
        strcpy(filename, argv[2]);
    else
        strcpy(filename, "Lab 09 input.txt");

    if ((file = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    //Retrieving amount of pages in main memory
    uint pages_amount;
    if (argc >= 2)
        sscanf(argv[1], "%d", &pages_amount);
    else
        pages_amount = DEFAULT_PAGES_AMOUNT;

    //Initializing page table
    PTE page_table[pages_amount];
    for (uint i = 0; i < pages_amount; i++)
    {
        page_table[i].page_frame = 0;
        page_table[i].present_absent = 0;
        page_table[i].r = 0;
        page_table[i].counter = 0;
    }

    uint hits = 0;
    uint counter = 0;
    //Starting reading
    int requested_page = -1;
    fscanf(file, "%d", &requested_page);
    while (requested_page != -1)
    {
        int need_to_evict = 1;
        PTE *evictable = &page_table[0];
        uint lowest_counter_value = page_table[0].counter;
        for (int i = 0; i < pages_amount; i++)
        {
            /*If there is an empty entry, insert in in and then break
            (It is assumed that all empty pages in the bottom of memory)
            */
            if (page_table[i].present_absent == 0)
            {
                page_table[i].present_absent = 1;
                page_table[i].page_frame = requested_page;
                page_table[i].r = 1;
                need_to_evict = 0;
                break;
            }
            //If page already in memory, set R bit to 1 and break
            if (page_table[i].page_frame == requested_page)
            {
                hits++;
                page_table[i].r = 1;
                need_to_evict = 0;
                break;
            }
            //Searching for lowest counter
            if (lowest_counter_value > page_table[i].counter || lowest_counter_value == 0)
            {
                lowest_counter_value = page_table[i].counter;
                evictable = &page_table[i];
            }
        }
        if (need_to_evict)
        {
            evictable->counter = 0;
            evictable->page_frame = requested_page;
            evictable->r = 1;
            evictable->present_absent = 1;
        }

        //Simulating clock interrupt
        if (counter % (3 * pages_amount) == 0)
        {
            //Setting counters
            for (int i = 0; i < pages_amount; i++)
            {
                page_table[i].counter >= 2;
                int mask = 0x80000000;
                mask *= page_table[i].r;
                page_table[i].counter |= mask;
                //Setting R
                page_table[i].r = 0;
            }
        }

        //Reading next page address to process
        counter++;
        requested_page = -1;
        fscanf(file, "%d", &requested_page);
    }
    //Printing out statistics and closing file
    fprintf(stdout, "Hits: %d, Misses: %d, Total: %d\n Hit/Miss ratio: %f\n", hits,
            counter - hits, counter, ((double)hits) / (counter - hits));
    fclose(file);
    return 0;
}