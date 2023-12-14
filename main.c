#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

extern char *optarg; //???

// macros operate on replacement
#define IS_STR_EQUAL(str1, str2) (strcmp(str1, str2) == 0)
#define ALPHABET "abc" //decoupling(?) --> offers flexibility

char encode_char(char plaintext_char, char key_char) {
    return 'x';
}

void encode(FILE* key_file) { //TODO
    assert(key_file);
    fprintf(stderr, "encoding message");
    //readin key file
    //readin from stdin (in a loop) --> its a stream and you don't know when it ends
        //for each plaintext char, encode using char from key file
    //write each encoded char to stdout

    // three 1. read in the key or pass in the key (use stat to get the size of the key file), 2. plaintext chars from stdin (read until end of file), 3. encode each char

    return;
}

void decode(FILE* file) { //TODO
    assert(file);
    fprintf(stderr, "decoding message");
    return;
}

bool generate_key(int count, const char* alphabet) { //TODO
    assert(count >= 0);
    assert(alphabet);
    //fprintf(stderr, "generating randomized set of characters\n");
    printf("ksdfoijsdlfjskdlfji\n");
    return true; 
}

int main(int argc, char *argv[]) {
    int opt;
    FILE* fd;
    int char_count;
    char* app_name;

    while ((opt = getopt(argc, argv, "a:mv")) != -1) { 
        switch (opt) {
        case 'a':
            fprintf(stderr, "yup, got a\n"); // fprintf to stderr  to seperate from output of program !!!!!!!!!!
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
        if (!generate_key(char_count, ALPHABET)) {
            fprintf(stderr, "error generating key\n");
            exit(EXIT_FAILURE);
        }
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