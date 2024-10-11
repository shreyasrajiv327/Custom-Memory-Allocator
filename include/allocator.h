#ifndef ALLOCATOR_H
#define ALLOCATOR_H

void *myalloc(int size);
void myfree(void *ptr);
void *myrealloc(void *ptr,int size);

#endif //ALLOCATOR_H


