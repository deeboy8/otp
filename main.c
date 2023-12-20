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

//will take char from each file (key and plaintext) and the corresponding encoded char aka 'x'
char encode_char(char plaintext_char, char key_char) {
    assert(plaintext_char);
    assert(key_char);
    printf("%c and %c\n", plaintext_char, key_char);
    return 'x';
}

off_t get_key_file_length(const char* path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == 0) {
        return statbuf.st_size;
    }
    printf("failure\n");
    //add assert?????
    return -1;
}

void encode(FILE* key_fd) { //TODO
    assert(key_fd);
    // int key_fd_as_int = (int)key_fd;
    off_t key_length = get_key_file_length(KEYFILE);

    //read entire key file into an array
    char buff[key_length];
    // int chars_read = read(key_fd_as_int, &buff, key_length); //removed as difficult to convert FILE* to int??????
    size_t chars_read = fread(&buff, sizeof(char), key_length, key_fd);
    assert(chars_read > 0);

    //read streaming input from user keyboard/STDIN
    char ch = '\0';
    int key_index_counter = 0;
    while ((read(STDIN_FILENO, &ch, 1) > 0 && ch != '\n') && key_index_counter < key_length) { //FIXME  MIGHT NEED A BETTER WAY TO LOOP DUE TO NOT BEING ABLE TO HAVE NEWLINE CHAR
        char returned_char = encode_char(ch, buff[key_index_counter]);
        key_index_counter++;
        // printf("%c ", returned_char);
        // fprintf(stderr, "ch: %c, r_ch: %c\n", ch, returned_char); //--> use to debug
        assert(returned_char);
    }
    printf("success\n");

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

    //setting up command line arguments and how user will interact with the program
    while ((opt = getopt(argc, argv, "a:mv")) != -1) { 
        switch (opt) {
        case 'a':
            fprintf(stderr, "yup, got a\n"); // fprintf to stderr to seperate from output of program !!!!!!!!!! HOW DOES THAT MAKE SENSE???
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
            encode(fd); //do I want to pass around a file descriptor?????????????
        }
        else if (IS_STR_EQUAL("decode", app_name)) {
            decode(fd);
        }

        fclose(fd); 
    }

    exit(EXIT_SUCCESS);
}

/*
make a simple shell script
allow execute ./otp with diff combo of cl arguments to validate its working
extra fancy:
run ./otp capture output > otp.txt , file with expected output then diff both files*/