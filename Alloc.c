#include "Alloc.h"

extern heap *memspace;

void *mkalloc(word words, header *hdr){
    void *ret, *bytesin;
    words wordsin;

    bytesin = (hdr - memspace);
    wordsin = (((words)bytesin)/4)+1;
    if (words > (maxwords-wordsin))
        reterr ErrNoMem;

    hdr->w = words;
    hdr->alloced = true;
    ret = ($v hdr)+4;

    return ret;
    
}

void *alloc(int32 bytes){

    word words;
    header *hdr;
    void *mem;
    int32 ret;

    words = (!(bytes % 4)) ? (bytes/4) : (bytes/4) + 1;

    mem = (void *)memspace;
    hdr = (header *)mem;
    

    (!(hdr->w)) ? ({
        if (words > Maxwords)
            reterr ErrNoMem;

        mem = mkalloc(words, hdr);
        if (!mem)
            return errno;

        return mem;
    })
    :({
        (void)0;
    });

    return NULL;
}

int main (int argc, char *argv[]){

    int8 *p;


    p = alloc(7);

    printf("0x%x\n", $i p);
    return 0;
}