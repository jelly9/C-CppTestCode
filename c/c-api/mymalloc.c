/**
 * @file 
 *  * @author xiaoguodong 1799553128@qq.com
 *   * @date 
 *    * @brief
 *     **/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


#if 1
#define BLOCK_SIZE 24

struct block {
    size_t size;
    struct block *next;
    int free;
    int padding;
    char data[1];
};

void *first_block;

// first fit
struct block *find_blcok ( struct block **last, size_t size ) {
    struct block *b = (struct block*)first_block;
    while ( b && !b->free && b->size < size ) {
        *last = b;
        b = b->next;
    } 

    return b;
}

struct block *expend_heap ( struct block *last, size_t size ) {
    struct block *b;
    b = (struct block*)sbrk(0);
    if ( sbrk(BLOCK_SIZE + size) == (void*)-1 )
        return NULL;

    b->size = size;
    b->next = NULL;
    if ( last )
        last->next = b;
    b->free = 0;
    return b;
}

void split_block ( struct block *b, size_t size ) {
    struct block *new_b;
    new_b = (struct block*)b->data + size;
    new_b->size = b->size - size - BLOCK_SIZE;
    new_b->next = b->next;
    new_b->free = 1;
    b->size = size;
    b->next = new_b;
}

size_t align8 ( size_t size ) {
    return (size+7) & 0xf8;
}

void *my_malloc(size_t size){
    struct block *b, *last;
    size_t s = align8(size);

    if ( first_block ) {
        last = (struct block*)first_block;
        b = find_blcok(&last, s);
        if ( b ) {
            if ( (b->size-s) >= (BLOCK_SIZE+8) )
                split_block(b, s);
            b->free = 0;
        } else {
            b = expend_heap(last, s);
            if(!b)
                return NULL;
        }
    } else {
        b = expend_heap(NULL, s);
        if(!b)
            return NULL;
        first_block = b;
    }

    return b->data;
}

#else
void *my_malloc(size_t size)
{
    void *ret;
    ret = sbrk(0);
    if(sbrk(size)==(void*)-1)
        return NULL;

    return ret;
}
#endif


int main()
{
    int *p = (int*)my_malloc(sizeof(int));
    *p = 10;
    printf("p = %p, *p = %d\n", p, *p);
    return 0;
}
