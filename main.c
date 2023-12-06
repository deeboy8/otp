#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

extern char *optarg; //???

// macros operate on replacement
#define IS_STR_EQUAL(str1, str2) (strcmp(str1, str2) == 0)

int main(int argc, char *argv[])
{
    int opt;
    FILE *fd;
    int char_count;
    char *app_name;

    while ((opt = getopt(argc, argv, "a:mv")) != -1)
    { // 16 - 38 is setting up state
        switch (opt)
        {
        case 'a':
            printf("yup, got a\n"); // fprintf to stderr  to seperate from output of program !!!!!!!!!!!!!
            // where the argument for a is held
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
    // test if app name = key --> go do all the key stuff
    // if app name == encode or decode, then better have access to key file
    //  where do we get teh keyfile name (look at getopt)
    if (IS_STR_EQUAL("key", app_name))
    {
        char_count = atoi(argv[3]); //-----> optind!?
        assert(char_count != 0);
        // generate_key_file(char_count)--> we need plaintext char count? how come up with char_count?
    }
    else 
    {
        fd = fopen(argv[4], "r"); // key.key
        if (IS_STR_EQUAL("encode", app_name))
        {
            // code stub for encode message, implementation of encode mesg 
            // encode_message()
        }

        else if (IS_STR_EQUAL("decode", app_name))
        {
            // fd = fopen(argv[4], "r"); // key.key
            // decode_message()
        }

        fclose(fd); // BUG?
    }

    exit(EXIT_SUCCESS);
}