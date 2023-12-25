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
    fprintf(stderr, "encode successfully working!");
    return true;
}
    
/*  focus on UI: function doesn't have to do anything; write minimal amount of code for the fx to compile and execute
    //in this instance, return True or False but very very very simple --> treat as black box
    //only thing know about encode is it returns a bool and takes in a FILE*
    //UI and creation of stubs is one liners ONLY to help build main fx 
    //------ FOCUS ON UI--------

    //write stubs first ensuring compile properly ---> move to TDD --> implementation (STI)

    TDD Development (pure)
    1. write a unit test
        //encode should fail with null fd()
            //have to ref encode fx
    2. create a header file for subject under test (SUT) --> declaration for the encode fx --> COMPILE
    3. write a stub (abs bare min) that implements/defines SUT aka encode (now have .C file to go with .h file) ---> LINK bc have definition/implementation
    --UNIT TEST CAN RUN AT THIS POINT --> BUT WILL FAIL BC NO IMPLEMENTATION--
    4. add code to function until unit test under question passes
    5. create another unit test, declaration, defintion, etc. --> repeat 
    --repeat each step until get the test to pass--

    DG Approach
    start with #2
        then go create unit tests
            focus: leverage tooling of IDE and intellisense
    
}*/

bool decode(FILE* key_fd) {
    assert(key_fd);
    fprintf(stderr, "decode successfully working!");
    return true;
}


bool generate_key(int count, const char* alphabet) { //TODO
    assert(count >= 0);
    assert(alphabet);
    printf("ksdfoijsdlfjskdlfji\n");
    return true; 
}

int main(int argc, char *argv[]) {
    int opt;
    FILE* fd;
    int char_count;
    char* app_name;

    //
    if (argc < 3) {
        fprintf(stderr, "Usage: %s requires '-a' flag and arguments\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((!IS_STR_EQUAL(argv[1], "-a")) && argc >= 3) {
        fprintf(stderr, "Usage: %s requires '-a' flag for processing \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //setting up command line arguments and how user will interact with the program
    while ((opt = getopt(argc, argv, "a:mv")) != -1) { 
        switch (opt) {
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
            fprintf(stderr, "Usage: %s requires the use of a keyword: key, encode or decode\n", argv[0]);
            exit(EXIT_FAILURE); // better to return -1?
        }
    }

    if ((strcmp("key", app_name) == 0)) { //(IS_STR_EQUAL("key", app_name)) { //FIXME! Error for bad memory while debugging 
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
        }

        fclose(fd); 
    }

    exit(EXIT_SUCCESS);
}

/*
make a simple shell script
allow execute ./otp with diff combo of cl arguments to validate its working
extra fancy:
run ./otp capture output > otp.txt , file with expected output then diff both files*/