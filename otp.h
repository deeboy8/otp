#ifndef OTP_H
#define OTP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/stat.h>

extern char *optarg; //???

// macros operate on replacement
#define IS_STR_EQUAL(str1, str2) (strcmp(str1, str2) == 0)
#define ALPHABET "abc" //decoupling(?) --> offers flexibility
#define KEYFILE "key.txt"
#define CIPHERTEXT "ciphertext.txt"

char decode_char(char cipher_char, char key_char);
char encode_char(char plaintext_char, char key_char);
off_t get_file_length(const char* path);
bool encode(FILE* fd_key);
bool decode(FILE* key_fd);
bool generate_key(int count, const char* alphabet);



#endif 