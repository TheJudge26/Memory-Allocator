#include "Alloc.h"

extern heap *memspace;

int main (int argc, char *argv[]){

    int8 *p;

    p=memspace;
    *p = 'x';
    
    return 0;
}