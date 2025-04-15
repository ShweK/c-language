
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool rb_init(int size);
bool rb_push(char c);
bool rb_pop(char* out);
bool rb_peek(char* out);
void rb_free();
int rb_size =0;
char *ring = NULL; 
int head =0, tail =0;

bool rb_init(int size)
{
    if(size <= 0){
        return false;
    }
    ring = (char*)malloc(size*sizeof(char));
    if(!ring) return false;
    rb_size = size;
    head =0;
    tail =0;
    return true;
}

bool rb_push(char c){

    int next = (head +1)%rb_size;
    if(next == tail)
    {
        return false;
    }
    ring[head] = c;
    head = next;
    return true;
}

bool rb_pop(char *out){

    if(head == tail)
    {
        return false;
    }
    *out = ring[tail];
    tail = (tail+1)%rb_size;
    return true;
}


void rb_free() {
    if (ring) {
        free(ring);
        ring = NULL;
    }
}

void main()
{
    int size;
    printf("Ring buffer logic\n");
    printf("Enter the size of RingBuffer:");
    scanf("%d",&size);

    printf("Size init: %s\n", rb_init(size) ? "true" : "false");
    printf("Push: 'A', %s, head:%d \n", rb_push('A') ? "Success" : "failed", head);
    printf("Push: 'B', %s, head:%d \n", rb_push('B') ? "Success" : "failed", head);
    printf("Push: 'C', %s, head:%d \n", rb_push('C') ? "Success" : "failed", head);

    char out;
    if (rb_pop(&out))
    printf("Pop: %c, tail now at: %d\n", out, tail);
    else
        printf("Pop failed (empty)\n");

    if (rb_pop(&out))
        printf("Pop: %c, tail now at: %d\n", out, tail);
    else
        printf("Pop failed (empty)\n");

    rb_free();
}