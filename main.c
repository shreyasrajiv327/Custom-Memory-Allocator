// with the help of mmap we can create our own custom memory allocator,
//1st step is use the mmap system call to get a chucnk of memory lets say 4kb
//now by using our custom memory allocator function we can get memory from the 4kb chuck
//we use a linked list to keep track of the spaces being used
// there will be a header for the 4kb chunk we recieve initially and then a header for every chuck requested by the user
// mmap() returns a pointer to a chunk of free space
// node_t *head = mmap(NULL, 4096, PROT_READ|PROT_WRITE,
// MAP_ANON|MAP_PRIVATE, -1, 0);
// head->size = 4096 - sizeof(node_t);
// head->next = NULL;

int main()
{
    return 0;
}