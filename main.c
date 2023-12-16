#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/stat.h>

extern char *optarg; //???

// macros operate on replacement
#define IS_STR_EQUAL(str1, str2) (strcmp(str1, str2) == 0)
#define ALPHABET "abc" //decoupling(?) --> offers flexibility
#define KEYFILE "key.txt"

//will take char from each file (key and plaintex) and return an encoded char aka 'x'
char encode_char(char plaintext_char, char key_char) {
    assert(plaintext_char);
    assert(key_char);
    return 'x';
}

unsigned int get_key_file_length(const char* path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == 0) {
        return statbuf.st_size;
    }
    printf("failure\n");
    return -1;
}

void encode(FILE* key_fd) { //TODO
    assert(key_fd);
    //fprintf(stderr, "encoding message");
    //get length of key file --> need to create mem space for full text
    unsigned int key_length = get_key_file_length(KEYFILE);
    printf("key length is: %d\n", key_length);
    //read key file into an array


    //read streaming input from user keyboard/STDIN
    // char ch;
    // while (read(STDIN_FILENO, &ch, 1) > 0) {
    //     char returned_char = encode_char(ch);
    // }
    printf("success\n");
    //readin key file
    //readin from stdin (in a loop) --> its a stream and you don't know when it ends
        //for each plaintext char, encode using char from key file
    //write each encoded char to stdout

    // three 1. read in the key or pass in the key (use stat to get the size of the key file), 2. plaintext chars from stdin (read until end of file), 3. encode each char (encode_char)

    //return;
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