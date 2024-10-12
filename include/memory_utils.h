#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

#include <stddef.h>  // for size_t

// Align size to word boundary
size_t align_size(size_t size);

// Metadata manipulation functions
void *add_offset(void *ptr);
void *remove_offset(void *ptr);
void *getFooter(void *header_ptr);
void append_to_free_list(void *ptr);
void remove_from_free_list(void *ptr);
void set_block_header(void *ptr, size_t size, int is_free);
size_t get_block_size(void *header);
void mark_as_allocated(void *ptr);
void mark_as_free(void *ptr);
void coalesce(void *ptr);

// Allocation-related utility functions
void *find_free_block(size_t size);
void split_block(void *block, size_t size);

// Externally defined variables
extern void *free_list;

#endif  // MEMORY_UTILS_H
