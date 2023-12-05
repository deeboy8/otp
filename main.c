#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char *optarg; //???

int main(int argc, char* argv[]) {
    int opt;
    FILE* fd;
    int char_count;
    char* app_name;

    while ((opt = getopt(argc, argv, "a:mv")) != -1) { //16 - 38 is setting up state
        switch (opt) {
            case 'a':
                printf("yup, got a\n");
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
                exit(EXIT_FAILURE); //better to return -1?
        }
    }
    //test if app name = key --> go do all the key stuff
    //if app name == encode or decode, then better have access to key file
        // where do we get teh keyfile name (look at getopt)
    if (optarg == "key") {
        char_count = atoi(argv[3]);
        //generate_key_file(char_count)--> we need plaintext char count? how come up with char_count? 
    } 
    else if (app_name == "encode") {
        fd = argv[4]; //key.key
        //encode_message()
    }
    
    else if (app_name == "decode") {
        fd = argv[4]; //key.key
        //decode_message()
    }
    exit(EXIT_SUCCESS);
}