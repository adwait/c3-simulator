#include<iostream>
#include <unistd.h>

using namespace std;

int main() {
    uint64_t* p1 = (uint64_t *) malloc(4);
    uint64_t* p2 = (uint64_t *) malloc(4);
    uint64_t* p3 = (uint64_t *) malloc(4);
    uint64_t* p4 = (uint64_t *) malloc(4);
    // uint32_t* q = (uint32_t *) malloc(80);
    // uint32_t* r = (uint32_t *) malloc(8);
    // uint32_t* s = (uint32_t *) malloc(8);


    p1[1] = 0xcafecaf1;
    p2[1] = 0xcafecaf2;
    p3[1] = 0xcafecaf3;
    p4[1] = 0xcafecaf4;

    p1[0] = 0xdeadbeef;
    p2[0] = (uint64_t) p1;
    p3[0] = (uint64_t) p2;
    p4[0] = (uint64_t) p3;

    free(p1);
    free(p2);
    free(p3);
    free(p4);
    
    
    // *p = 0xdeadbeef;

    // uint64_t* r = (uint64_t *) malloc(1);
    // *r = (uint64_t) p;

    // *q = 0xcafecafe;
    // *q = *p;

    // printf("%016lx\n", (uint64_t) p);
    // printf("%016lx\n", (uint64_t) q);
    
    // *r = 0xbeefcafe;
    // *s = 0xdeadcafe;
    
    // printf("%08x\n", *p);
    
    // free(p);
    // free(q);
    // free(r);
    // free(s);
    
    return 0;
}
