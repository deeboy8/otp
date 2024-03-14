#ifndef OTP_H
#define OTP_H

#include "munit/munit.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

extern char *optarg; //???
extern int optind;
/*static*/ extern const MunitSuite test_suite;
//static -> every c file will get it's own copy
    //only visible in file where static is declared --> multiple instances of variable aka test_suite
    //can be usedto not expose things externally aka root ptr of LL
//extern -> similar to declaring function signatures; every file that has "otp.h" includes will have access to it

// macros operate on replacement
#define IS_STR_EQUAL(str1, str2) (strcmp(str1, str2) == 0)
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ " //
#define KEYFILE "key.txt"
#define CIPHERTEXT "ciphertext.txt"
#define ALPHA_LEN strlen(ALPHABET)

char decode_char(char key_char, char ciphertext_char, const char* alphabet, size_t alpha_length);
char encode_char(char plaintext_char, char key_char, const char* alphabet, size_t alpha_length);
off_t get_file_length(const char* path);
char* encode(const char* key, const char* plaintext, const char* alphabet, size_t alpha_length);
bool decode(const char* key, const char* ciphertext, const char* alphabet, size_t alpha_length);
// bool generate_key(int count, const char* alphabet, const char* plaintext);
char generate_key(int plaintext_char); //, const char* alphabet); //, const char* plaintext);
int get_random_numb(int alpha_len);


#endif 