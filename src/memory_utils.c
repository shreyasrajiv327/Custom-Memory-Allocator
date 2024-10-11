#include"memory_utils.h"
#include<stddef.h> //For size_t

typedef struct block_header{
    size_t size; //Total size of the block(including the metadata)
    int is_free;   //Status  1= free, 0=allocated
    struct block_header *next; //Pointer to the next free block
}block_header;


/*Align the size to word boundary*/

size_t align_size(size_t size){
    const size_t alignment = sizeof(void *);
    return (size + alignment -1) & ~(alignment-1);
}

/*For a system where sizeof(void *) = 8 (64-bit):

If size = 13, alignment = 8.

size + alignment - 1 = 13 + 8 - 1 = 20.
~(alignment - 1) = ~7 = 0xFFFFFFF8.
20 & 0xFFFFFFF8 = 16 (which is the next multiple of 8).
Thus, if you request 13 bytes, the function will align it to 16 bytes.*/


/*Set the block header with size and free status*/
void set_block_header(void *ptr,size_t size, int is_free){
    block_header *header = (block_header*) ptr;
    header->size = size;
    header->is_free = is_free;
    header->next = NULL;
}

/*Get the size of a block from its header*/

size_t get_block_size(void *header_ptr){
    block_header *header = (block_header*) header_ptr;
    return header->size;
}

/*Mark a block as allocated*/

void mark_As_allocated(void *ptr){
    block_header *header = (block_header*)ptr;
    header->is_free = 0;//mark as allocated
}

void mark_as_free(void *ptr){
    block_header *header = (block_header*)ptr;
    header->is_free=1;
}


/*Add offset to skip the metadata (header)*/
void *add_offset(void *ptr){
    return (void*)((char*)ptr + sizeof(block_header));
}

/*Remove the offset to get back to the header*/

void *remove_offset(void *ptr){
    return (void*)((char*)ptr -sizeof(block_header));
}

void *getFooter(void *header_ptr){
    block_header *header = (block_header*)header_ptr;
    return (void*)((char*))
}