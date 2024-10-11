#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H
size_t align_size(size_t size);
void *add_offset(void *ptr);
void *remove_offset(void *ptr);
void *getFooter(void *header_ptr);
void append_to_free_list(void *ptr);
void remove_from_free_list(void *ptr);
void set_block_header(void *ptr, size_t size, int is_free);  // Add this declaration
size_t get_block_size(void *header);
void mark_as_allocated(void *ptr);
void mark_as_free(void *ptr);
void coalesce(void *ptr);
int align_size(int size);    // Add this
void *find_free_block(int size);  // Add this
void split_block(void *block, int size); // Add this
extern void *free_list;

#endif