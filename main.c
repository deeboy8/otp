#include "otp.h"
#include "munit/munit.h"

char decode_char(char cipher_char, char key_char) {
    assert(cipher_char);
    assert(key_char);
    return 'm';
}

int get_char_index(char text_char, const char* alphabet, size_t alpha_length) {
    int value;

    for (int i = 0; i < (int)alpha_length; i++) {
        if (IS_STR_EQUAL(&text_char, &alphabet[i])) {
            value = i;
        }
    }
    // fprintf(stderr, "error: no value for char\n");

    return value;
}

//will take char from each file (key and plaintext) and the corresponding encoded char aka 'x'
//should I make this function one that can encode and decode --> seems wise
//UT -> use example in PDF, write UTs around that-> null character pass -> diff alphabet 
char encode_char(char key_char, char plaintext_char, const char* alphabet, size_t alpha_length) { //pure fx in TDD sense; parameterize ALPHABET
    // assert(key_char); assert are typically used for boolean expression or ptrs
    assert(alphabet); //-> assert alphabet not equal to null; assert its not zero
    assert(alpha_length == strlen(alphabet));
    // assert(alphabet[0] <= plaintext_char && plaintext_char >= alphabet[26]); //no -1 to ensure it's a char; alphabet[alpah_length -1] == ' ' aka ascii 32
    // char x = key_char;
    //encode_char will sum both indexes and return single char to be added to memory space
    
    int key_index = get_char_index(key_char, alphabet, alpha_length);
    int plaintext_index = get_char_index(plaintext_char, alphabet, alpha_length);
    
    int sum_of_indexes = (key_index + plaintext_index) % alpha_length;
    char cipher_char = alphabet[sum_of_indexes]; //not a pure fx, CAN'T USE WITH ANOTEHR ALPHABET, pass ptr to alphabet (const char*)
    return cipher_char;
}

off_t get_file_length(const char* path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == 0) {
        return statbuf.st_size;
    }
    fprintf(stderr, "failure to access file\n");
    
    return -1;
}

char* encode(const char* key, const char* plaintext, const char* alphabet, size_t alpha_length) { //should return char* of malloc'd space holding ciphertext to be senet to stdout
    //putting IO in fx intended for computation makes useless for any other user
    //use fprintf(stderr, ....)
    // VARIABLE LENGTH ARGUMENTS -> FUTURE DISCUSSION
    //add macro asserts to test parameters
    size_t i = 0;
    //memory space to hold ciphertext
    char* cipher = malloc(sizeof(char) * strlen(plaintext) + 1); //ec[strlen(ALPHABET) + 1];
    //for loop passing each char of key and plaintext to encode char
    for (i = 0; i < strlen(plaintext); i++) {
        cipher[i] = encode_char(key[i], plaintext[i], alphabet, alpha_length);
    }
    cipher[i] = '\0';
    printf("ciphertext: %s\n", cipher);

    return cipher;
}

//create ciphertext --> original message
bool decode(FILE* key_fd) {
    assert(key_fd);
    printf("decode successful\n");
    //use fopen to create a document each time or rewrite to a document the ciphertext
        //this message needs to be the same as original message entered in stdin by user  
    // fprintf(stderr, "decode successfully working!\n");
    return true;
}

//obtain random number to pull random letter from alphabet to create key 
int get_random_numb(int alpha_len) {
    int numb = rand() % alpha_len; //added -1 to get letter 'A'
        //this should not be involved with the implementation of how the result of the fx gets used 
    return numb;
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
    // int char_count = 0;
    char* app_name = NULL;
    srand(0); 

    //why can't it see the test_suite fx in the other file 
    if (argc == 1) {
        return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
    }
     
    while ((opt = getopt(argc, argv, "a:mvh")) != -1) { 
        switch (opt) {
        case 'h':
            printf("detailed help goes here\n"); //FIXME 
            exit(EXIT_SUCCESS);
        case 'a':
            app_name = optarg;
            break;
        //provide count of characters passed on CL for key generation
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
    
    char* plaintext_ptr = argv[4];
    assert(plaintext_ptr);
    if (app_name == NULL) {
        usage(); 
    }
    if ((IS_STR_EQUAL(app_name, "key"))) {
        int plaintext_len = strlen(argv[4]);
        if (plaintext_len) { //, argv[4])) {
            FILE* fd = fopen("key.txt", "w");
            char* ptr_to_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
            for (int i = 0; i < plaintext_len; i++) {
                int rand_num = get_random_numb(ALPHA_LEN);
                char rand_char = ptr_to_alphabet[rand_num];
                fputc(rand_char, fd);
            }
        }
        else {
            fprintf(stderr, "error generating key\n"); //TODO fix error handling flow
            exit(EXIT_FAILURE);
        }    
        fclose(fd);
    } else {
        fd = fopen("key.txt", "r"); //account for when no key.txt file created, aka use read and write mode 
        int key_len = get_file_length("key.txt");
        if (IS_STR_EQUAL("encode", app_name)) {
            //read in entire key file and save to buffer
            char key_ptr[key_len + 1]; // = {'\0'};
            assert(key_ptr);
            size_t key_chars = fread(key_ptr, sizeof(char), key_len, fd); //register rdi is not available
            // key_ptr[key_len + 1] = '\0';
            assert(key_chars);
            encode(key_ptr, plaintext_ptr, ALPHABET, ALPHA_LEN); 
                        
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

    //usage(); //why do we have this here
}

/*
make a simple shell script
allow execute ./otp with diff combo of cl arguments to validate its working
extra fancy:
run ./otp capture output > otp.txt , file with expected output then diff both files*/

// // FILE* fd = fopen("key.txt", "w");
//     for (int i = 0; i < plaintext_count; i++) {
//         //create random number generator to obtain characters from alphabet
//         int rand_num = get_random_numb(strlen(ALPHABET));
//         printf("random_num is: %d\n", rand_num);
//         assert(rand_num >= 0);
//         //use rand_num to get random alphabet letter
//         char random_char = ALPHABET[rand_num];
//         assert(random_char);
//         //write letter to file
//         // fputc(random_char, fd);
        
//     }
//     // fclose(fd);

//2/25
    // read in key directly into main, and pass ptr around
    // key has to be equal to or greater than length of plaintext
        // use modulo of 