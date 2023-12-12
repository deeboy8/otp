#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

extern char *optarg; //???

// macros operate on replacement
#define IS_STR_EQUAL(str1, str2) (strcmp(str1, str2) == 0)

void encode(FILE* file) { //TODO
    assert(file);
    fprintf(stderr, "encoding message");
    return;
}

void decode(FILE* file) { //TODO
    assert(file);
    fprintf(stderr, "decoding message");
    return;
}
void generate_key(int count) { //TODO
    assert(count != 0);
    fprintf(stderr, "generating randomized set of characters");
    return; //vs SUCCESS vs exit(EXIT_SUCCESS)
}

int main(int argc, char *argv[]) {
    int opt;
    FILE* fd;
    int char_count;
    char* app_name;

    while ((opt = getopt(argc, argv, "a:mv")) != -1) { 
        switch (opt) {
        case 'a':
            printf("yup, got a\n"); // fprintf to stderr  to seperate from output of program !!!!!!!!!!
            app_name = optarg;
            break;
        case 'm':
            printf("total characters: , got m\n");
            break;
        case 'v':
            printf("yup, got v\n");
            break;
        default:
            fprintf(stderr, "Usage: %s requires the use of a keyword: key, encode or decode\n", argv[0]);
            exit(EXIT_FAILURE); // better to return -1?
        }
    }

    if ((strcmp("key", app_name) == 0)) { //(IS_STR_EQUAL("key", app_name)) { //FIXME! Error for bad memory while debugging 
        char_count = atoi(argv[optind]);
        assert(char_count >= 0);
        generate_key(char_count); // generate_key_file(char_count)--> we need plaintext char count? how come up with char_count?
    } else {
        fd = fopen(argv[optind], "r"); // key.key
        if (IS_STR_EQUAL("encode", app_name)) {
            encode(fd); //do I want to pass around a file descriptor???? TODO
        }
        else if (IS_STR_EQUAL("decode", app_name)) {
            decode(fd);
        }

        fclose(fd); 
    }

    exit(EXIT_SUCCESS);
}