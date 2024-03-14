#include "otp.h"
#include "munit/munit.h"

char decode_char(char key_char, char ciphertext_char, const char* alphabet, size_t alpha_length) {
    assert(alphabet);
    
    int key_index = get_char_index(key_char, alphabet, alpha_length);
    int ciphertext_index =  get_char_index(ciphertext_char, alphabet, alpha_length);

    int sum_of_indexes = (key_index + ciphertext_index) % alpha_length;
    char plaintext_new_char = alphabet[sum_of_indexes]; 

    return plaintext_new_char;
}

//create ciphertext --> original message
bool decode(const char* key, const char* ciphertext, const char* alphabet, size_t alpha_length) {
    assert(key);
    assert(ciphertext);
    assert(alphabet);
    assert(alpha_length > 0);

    size_t i = 0;
    //buffer space to hold result of ciphertext back to original plaintext message
    char* plaintext_new = malloc(sizeof(char) * strlen(ciphertext) + 1);
    for (i = 0; i < strlen(ciphertext); i++) {
        plaintext_new[i] = decode_char(key[i], ciphertext[i], alphabet, alpha_length);
    }
    
    return true;
}

//should I make this function one that can encode and decode --> seems wise
char encode_char(char key_char, char plaintext_char, const char* alphabet, size_t alpha_length) {
    assert(alphabet); 
    // assert(alpha_length == strlen(alphabet));
    // assert(alphabet[0] <= plaintext_char && plaintext_char >= alphabet[26]); //no -1 to ensure it's a char; alphabet[alpah_length -1] == ' ' aka ascii 32
    
    int key_index = get_char_index(key_char, alphabet, alpha_length);
    int plaintext_index = get_char_index(plaintext_char, alphabet, alpha_length);
    
    int sum_of_indexes = (key_index + plaintext_index) % alpha_length;
    char cipher_char = alphabet[sum_of_indexes]; 
    
    return cipher_char;
}

//generate ciphertext on heap and returned via char*
char* encode(const char* key, const char* plaintext, const char* alphabet, size_t alpha_length) { //invalid chars, strings too long, emptry strings
    assert(key);
    assert(plaintext);
    assert(alphabet);
    assert(alpha_length > 0);

    size_t i = 0;
    //buffer space to hold generated ciphertext
    char* cipher = malloc(sizeof(char) * strlen(plaintext) + 1);
    //pass each char of key and plaintext to encode_char
    for (i = 0; i < strlen(plaintext); i++) {
        cipher[i] = encode_char(key[i], plaintext[i], alphabet, alpha_length);
    }
    cipher[i] = '\0';
    // printf("ciphertext len: %lu, ciphertext:%s\n", strlen(cipher), cipher);

    return cipher;
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
    char* app_name = NULL;
    srand(0);

    //run unit tests 
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

    if (app_name == NULL) {
        usage(); 
    }

    char* plaintext_ptr = argv[3];
    assert(plaintext_ptr);
    int plaintext_len = strlen(argv[3]);
    // char* rand_char[plaintext_len];
    if ((IS_STR_EQUAL(app_name, "key"))) {
        // int plaintext_len = strlen(argv[3]);
        if (plaintext_ptr) {
            FILE* fd = fopen("key.txt", "w");
            char* ptr_to_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
            for (int i = 0; i < plaintext_len; i++) {
                //obtain random number between 0 and length of plaintext messsage
                int rand_num = get_random_numb(ALPHA_LEN);
                //index random char from alphabet to create key.txt 
                char rand_char = ptr_to_alphabet[rand_num];
                fputc(rand_char, fd);
            }
            fputc('\n', fd); 
        }
        else {
            fprintf(stderr, "error generating key\n"); //TODO fix error handling flow
            exit(EXIT_FAILURE);
        }    
        // fclose(fd);
        // for (int i = 0; i < plaintext_len; i++) {
            // fprintf(stdout, "%s\n", *rand_char);
        // }
        
    } else {
        fd = fopen("key.txt", "r"); 
        if (!fd) {
            fprintf(stderr, "error: must generate a key file\n");
            exit(EXIT_FAILURE);
        }
        //read in entire key file and save to buffer
        int key_len = get_file_length("key.txt");
        char key_ptr[key_len + 1]; // = {'\0'}; ////////////////////CAN I NOT DO THIS BECAUSE THE SPACE IS COMPUTATED AT COMPILE TIME? ----> USE MEMSET!
        assert(key_ptr); //////////THIS ISN'T VALID YES?
        size_t key_chars = fread(key_ptr, sizeof(char), key_len, fd);
        // key_ptr[key_len + 1] = '\0';
        assert(key_chars);
        char* ciphertext;
        if (IS_STR_EQUAL("encode", app_name)) {
            // //read in entire key file and save to buffer
            // char key_ptr[key_len + 1]; // = {'\0'}; ////////////////////CAN I NOT DO THIS BECAUSE THE SPACE IS COMPUTATED AT COMPILE TIME? ----> USE MEMSET!
            // assert(key_ptr); //////////THIS ISN'T VALID YES?
            // size_t key_chars = fread(key_ptr, sizeof(char), key_len, fd);
            // // key_ptr[key_len + 1] = '\0';
            // assert(key_chars);
            ciphertext = encode(key_ptr, plaintext_ptr, ALPHABET, ALPHA_LEN);
            printf("cipher is: %s\n", ciphertext);            
        }
        else if (IS_STR_EQUAL("decode", app_name)) {
            decode(key_ptr, ciphertext, ALPHABET, ALPHA_LEN);
        } else {
            fclose(fd); 
            usage();
        }
        free(ciphertext);
        fclose(fd); 
        exit(EXIT_SUCCESS);
    } 

    //usage(); //why do we have this here
}
