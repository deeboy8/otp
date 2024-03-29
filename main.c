#include "otp.h"
#include "munit/munit.h"

char decode_char(char key_char, char ciphertext_char, const char* alphabet, size_t alpha_length) {
    assert(alphabet);
    
    /*
    //DG 
    ciphertext_char -= 'A'; //4 
    char plain_char = ciphertext_char - key_char; //
    
    if (plain_char < 0) {
        plain_char += alpha_length;
    }
    
    return plain_char % alpha_length;
    */
    
    
    int key_index = get_char_index(key_char, alphabet, alpha_length);
    int ciphertext_index =  get_char_index(ciphertext_char, alphabet, alpha_length);
    
    int cipher_minus_key = ciphertext_index - key_index;
    if (cipher_minus_key < 0) {
        cipher_minus_key += alpha_length;
    }
    int index = cipher_minus_key % alpha_length; //FIXME
    char plaintext_new_char = alphabet[index]; 

    return plaintext_new_char; 
}

//create ciphertext --> original message
bool decode(const char* key, const char* ciphertext, const char* alphabet, size_t alpha_length) {
    assert(key);
    assert(ciphertext);
    assert(alphabet);
    assert(alpha_length > 0);
    // assert(strlen(key) >= strlen(ciphertext));

    size_t cipher_len = strlen(ciphertext);
    size_t i = 0;
    //buffer space to hold result of ciphertext back to original plaintext message
    char* plaintext_new = malloc(sizeof(char) * cipher_len + 1);
    for (i = 0; ciphertext[i] != '\0'; i++) {
        plaintext_new[i] = decode_char(key[i], ciphertext[i], alphabet, alpha_length);
    }
    plaintext_new[i] = '\0';
    printf("new plaintext is: %s\n", plaintext_new);
    free(plaintext_new);
    return true;
}

//should I make this function one that can encode and decode --> seems wise
char encode_char(char key_char, char plaintext_char, const char* alphabet, size_t alpha_length) {
    assert(alphabet); 
    // assert(alpha_length == strlen(alphabet));
    // assert(alphabet[0] <= plaintext_char && plaintext_char >= alphabet[26]); //no -1 to ensure it's a char; alphabet[alpah_length -1] == ' ' aka ascii 32
    
    int key_index = get_char_index(key_char, alphabet, alpha_length);
    int plaintext_index = get_char_index(plaintext_char, alphabet, alpha_length);
    
    int sum_of_indexes = (key_index + plaintext_index) % alpha_length; //FIXME 
    char cipher_char = alphabet[sum_of_indexes]; 
    
    return cipher_char;
}

//generate ciphertext on heap and returned via char*
char* encode(const char* key, const char* plaintext, const char* alphabet, size_t alpha_length) { //invalid chars, strings too long, emptry strings
    assert(key);
    assert(plaintext);
    assert(alphabet);
    assert(alpha_length > 0);
    // assert(strlen(key) >= strlen(plaintext));

    FILE* fd_cipher = fopen("ciphertext.txt", "w");
    int len_plaintext = strlen(plaintext);
    size_t i = 0;
    //buffer space to hold generated ciphertext
    char* cipher = malloc(sizeof(char) * len_plaintext + 1);//TODO -> CHANGE TO STACK MEM 
    //pass each char of key and plaintext to encode_char
    for (i = 0; plaintext[i] != '\0'; i++) {
        cipher[i] = encode_char(key[i], plaintext[i], alphabet, alpha_length);
        fputc(cipher[i], fd_cipher);
    }
    cipher[i] = '\0';
    // putc('\0', fd_cipher); --> getting READ BLOCK ATTEMPTING TO PUT NEWLINE 
    // printf("ciphertext len: %lu, ciphertext:%s\n", strlen(cipher), cipher);
    fclose(fd_cipher);
    // free(cipher);

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
    char* ciphertext = NULL;
    size_t key_chars;
    // size_t cipher_chars;
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
    } else {
        fd = fopen("key.txt", "r"); 
        if (!fd) {
            fprintf(stderr, "error: must generate a key file\n");
            exit(EXIT_FAILURE);
        }
        //read in entire key file and save to buffer
        int key_len = get_file_length("key.txt");
        // char key_ptr[key_len + 1];
        char key_ptr[key_len];
        memset(key_ptr, '\0', key_len);
        key_chars = fread(key_ptr, sizeof(char), key_len - 1, fd); //-1 add because of new line char 
        assert(key_chars != 0);
        if (IS_STR_EQUAL("encode", app_name)) {
            ciphertext = encode(key_ptr, plaintext_ptr, ALPHABET, ALPHA_LEN);
        }
        else if (IS_STR_EQUAL("decode", app_name)) {
            FILE* fd_cipher = fopen("ciphertext.txt", "r");
            FILE* fd_key = fopen("key.txt", "r");
            int key_len = get_file_length("key.txt") + 1; //len = 9
            char key_ptr_2[key_len];
            memset(key_ptr_2, '\0', key_len);
            int ciphertext_len = get_file_length("ciphertext.txt") + 1; //len = 8
            char cipher_ptr[ciphertext_len];
            memset(cipher_ptr, '\0', ciphertext_len);
            key_chars = fread(key_ptr_2, sizeof(char), key_len, fd_key);
            size_t cipher_chars = fread(cipher_ptr, sizeof(char), ciphertext_len, fd_cipher);
            assert(cipher_chars > 0);
            decode(key_ptr_2, cipher_ptr, ALPHABET, ALPHA_LEN);
            fclose(fd_cipher);
            fclose(fd_key);
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
