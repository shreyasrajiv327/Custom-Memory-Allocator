#include "headers.h"
#include "allocator.h"
#include "memory_utils.h"

#define POOL_SIZE 1024*1024

void *memory_pool = NULL; // Removed static keyword
void *free_list = NULL;   // Removed static keyword

void init_memory_pool(){
    if(!memory_pool) {
        memory_pool = mmap(NULL,POOL_SIZE,PROT_READ | PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
        if(memory_pool==MAP_FAILED)
        {
            perror("mmap failed");
            exit(1);
        }

        free_list = memory_pool;

        set_block_header(free_list,POOL_SIZE,1);
    }
}

void *myalloc(int size)
{
    if(size <= 0)
    {
        return NULL;
    }

    size = align_size(size);

    void *block = find_free_block(size);

    if(!block)
    {
        return NULL;
    }

    split_block(block, size);

    mark_as_allocated(block);

    return add_offset(block);  // Return block with offset
}

void myfree(void *ptr)
{
    if(!ptr)
    {
        return;
    }

    void *header = remove_offset(ptr);

    mark_as_free(header);

    append_to_free_list(header);

    coalesce(header);
}

void *myrealloc(void *ptr, int size)
{
    if(!ptr)
    {
        return myalloc(size);
    }

    if(size <= 0)
    {
        myfree(ptr);
        return NULL;
    }

    void *header = remove_offset(ptr);
    size_t current_size = get_block_size(header);

    if(current_size >= size)
    {
        return ptr;
    }

    void *new_block = myalloc(size);

    if(new_block)
    {
        memcpy(new_block, ptr, current_size);  // Use current size for copy
        myfree(ptr);
    }

    return new_block;
}
