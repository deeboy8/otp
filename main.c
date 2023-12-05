#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char *optarg; //???

int main(int argc, char* argv[]) {
    int opt;

    while ((opt = getopt(argc, argv, "a:")) != -1) { //16 - 38 is setting up state
        switch (opt) {
            case 'a':
                printf("yup, got a\n");
                // where the argument for a is held
                char* app_name = optarg;
                // validate that app_name is valid --> key, encode, decode
                break;
            // case 'k':
            //     printf("yup, got k\n");
                
            //     break;
            // case 'e':
            //     printf("yup, got e\n");
            //     break;
            // case 'd':
            //     printf("yup, got d\n");
            //     break;
            default:
                fprintf(stderr, "Usage: %s\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    //test if app name = key --> go do all the key stuff
    //if app name == encode or decode, then better have access to key file
        // where do we get teh keyfile name (look at getopt)
    exit(EXIT_SUCCESS);
}