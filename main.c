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

void get_random_numb(int length) {
    // int i;
    
    assert(length);
    printf("length is: %d\n", length);

    //initialize random number generator using time
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        printf("i is: %d\n", rand() % length + 1);
    }
}

//generation of key to be used to encode and decode plaintext
bool generate_key(int count, const char* alphabet, const char* plaintext) { //TODO
    assert(count >= 0);
    assert(alphabet);
    printf("plaintext is: %s\n", plaintext);
    
    //create random number generator to obtain characters from alphabet
    //int rand_numb = 
    get_random_numb(strlen(ALPHABET));
   // char rand_char = get_random_numb(rand_numb);
    // printf("ksdfoijsdlfjskdlfji\n");
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
        
    //setting up command line arguments and how user will interact with the program
    //setting up state -> then do processing
    // while eloop will be 90% of UI 
    while ((opt = getopt(argc, argv, "a:mvh")) != -1) { 
        switch (opt) {
        case 'h':
            printf("detailed help goes here\n"); //FIXME 
            exit(EXIT_SUCCESS);
        case 'a':
            app_name = optarg;
            break;
        case 'm':
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
    
    //here is the client/program split
    //beginning to run alogirthm 
    if (app_name == NULL) {
        usage(); 
    }
    if ((IS_STR_EQUAL(app_name, "key"))) {
        char_count = atoi(argv[optind]);
        assert(char_count > 0);
        if (!generate_key(char_count, ALPHABET, argv[4])) {
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