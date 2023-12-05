#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int opt;
    FILE* fd;
    int char_count;

    while ((opt = getopt(argc, argv, "a:mv")) != -1) { //16 - 38 is setting up state
        switch (opt) {
            case 'a':
                printf("yup, got a\n");
                // where the argument for a is held
                char* app_name = optarg;
                // validate that app_name is valid --> key, encode, decode
                if (optarg == "key") {
                    char_count = atoi(argv[3]) 
                } 
                else if (app_name == "encode" || app_name == "decode") {
                    fd = argv[4]
                }
                break;
            case 'm':
                printf("yup, got m\n");
                break;
            case 'v':
                printf("yup, got v\n");
                break;
            default:
                fprintf(stderr, "Usage: %s requires the use of of a keyword: key, encode or decode\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    //test if app name = key --> go do all the key stuff
    //if app name == encode or decode, then better have access to key file
        // where do we get teh keyfile name (look at getopt)
    exit(EXIT_SUCCESS);
}