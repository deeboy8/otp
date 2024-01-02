#include "otp.h"

char decode_char(char cipher_char, char key_char) {
    assert(cipher_char);
    assert(key_char);
    return 'm';
}

//will take char from each file (key and plaintext) and the corresponding encoded char aka 'x'
//should I make this function one that can encode and decode --> seems wise
char encode_char(char plaintext_char, char key_char) {
    assert(plaintext_char);
    assert(key_char);
    return 'x';
}

off_t get_file_length(const char* path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == 0) {
        return statbuf.st_size;
    }
    fprintf(stderr, "failure to access file\n");
    
    return -1;
}

bool encode(FILE* fd_key) { 
    assert(fd_key);
    fprintf(stderr, "encode successfully working!\n");
    return true;
}

//create ciphetext --> original message
bool decode(FILE* key_fd) {
    assert(key_fd);
    printf("decode successful\n");
    //use fopen to create a document each time or rewrite to a document the ciphertext
        //this message needs to be the same as original message entered in stdin by user  
    // fprintf(stderr, "decode successfully working!\n");
    return true;
}


bool generate_key(int count, const char* alphabet) { //TODO
    assert(count >= 0);
    assert(alphabet);
    printf("ksdfoijsdlfjskdlfji\n");
    return true; 
}

void usage() { //TODO
// void usage(int exit_code) { //TODO
    // assert(exit_code == EXIT_FAILURE || exit_code == EXIT_SUCCESS); //validate not using usage in incorrect way
    printf("usage: ./otp... \n"); //will have all the values available
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int opt = 0;
    FILE* fd = NULL;
    int char_count = 0;
    char* app_name = NULL;

//error checking here redundent
    //not smart -> if add another flag world of problems
    //one usage error -> this is how hte cmd line shuld be used 
        //1. very terse usage
        //2. help flag very detailed reporting of program -> then exit 
    // if (argc < 4) {
    //     if (argc == 1) {
    //         fprintf(stderr, "Usage: %s requires more commands for processing\n", argv[0]);
    //     }
    //     else if (argc == 3) {
    //         fprintf(stderr, "Usage: %s requires a key file or a processing command: encode or decode\n", argv[0]);
    //     }
    //     //if not -a flag is passed
    //     else if ((!IS_STR_EQUAL(argv[1], "-a"))) {
    //         fprintf(stderr, "Usage: %s currently requires '-a' flag for processing\n", argv[0]);
    //     }
    //     else if (argc == 3 && (!(IS_STR_EQUAL(argv[3], "key.txt") || IS_STR_EQUAL(argv[3], "encode") || IS_STR_EQUAL(argv[3], "decode")))) {
    //         fprintf(stderr, "Usage: %s requires passing of a key file or processing command\n", argv[0]);
    //     }
    //     exit(EXIT_FAILURE);
    // }
        
    //setting up command line arguments and how user will interact with the program
    //setting up state -> then do processing
    // while eloop will be 90% of UI 
    while ((opt = getopt(argc, argv, "a:mvh")) != -1) { 
        switch (opt) {
        case 'h':
            printf("detailed help goes here\n"); //FIXME 
            exit(EXIT_SUCCESS);
        case 'a':
            //QUESTION: fprintf to stderr to seperate from output of program !!!!!!!!!! HOW DOES THAT MAKE SENSE??? --> stderr to screen, stdout to "next file"
            app_name = optarg;
            break;
        case 'm':
            //if argv[2] == encode, print argv[3]
            //else break
            printf("total characters: %s\n", argv[optind]);
            break;
        case 'v': //what is verbose? --> key gen print each value as it's discovered, e/d each character as processed --> enable more output
            printf("yup, got v\n"); //notify still running, notify of each step is excuted and terminated
            break;
        default:
            // fprintf(stderr, "Usage: %s requires the use of a keyword: key, encode or decode\n", argv[0]); --> can use for usage fx 
            // exit(EXIT_FAILURE); // better to return -1?
            usage();
        }
    }
    
    //here is hte client/program split
    //beginning to run alogirthm 
    if (app_name == NULL) {
        usage();  //
    }
    if ((IS_STR_EQUAL("key", app_name))) {
        char_count = atoi(argv[optind]);
        assert(char_count > 0);
        if (!generate_key(char_count, ALPHABET)) {
            fprintf(stderr, "error generating key\n");
            exit(EXIT_FAILURE);
        }
    } else {
        fd = fopen(argv[optind], "r"); // key.key
        if (IS_STR_EQUAL("encode", app_name)) {
            encode(fd); 
        }
        else if (IS_STR_EQUAL("decode", app_name)) {
            decode(fd);
        } else {
            fclose(fd); 
            usage();
        }
        fclose(fd); 
        exit(EXIT_SUCCESS);
    } 

    usage();
}

/*
make a simple shell script
allow execute ./otp with diff combo of cl arguments to validate its working
extra fancy:
run ./otp capture output > otp.txt , file with expected output then diff both files*/