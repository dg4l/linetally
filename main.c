#include <stdio.h>
#include <stddef.h>
#include "bytearray/bytearray.h"

int main(int argc, char** argv){
    ByteArray* files[argc - 1];
    size_t line_count = 0;
    for (size_t i = 0; i < (argc - 1); ++i){
        files[i] = file_to_byte_array(argv[i + 1]);
        if (files[i]){
            for (size_t j = 0; j < files[i]->bufsize; ++j){
                if (files[i]->buf[j] == '\n'){
                    ++line_count;
                }
            }
        }
        else{
            fprintf(stderr, "error: file %s does not exist\n", argv[i + 1]);
            return -1;
        }
    }
    for (size_t i = 0; i < (argc - 1); ++i){
        cleanup_bytearray(&files[i]);
    }
    printf("TOTAL LINES: %zu\n", line_count);
    return 0;
}
