#include "otp.h"
#include "munit/munit.h"

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

bool encode(FILE* fd_key, char* plaintext_ptr) { 
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

<<<<<<< HEAD
int get_random_numb() { //maybe take alpha length as parameter 
    int alpha_len = strlen(ALPHABET);

    //initialize random number generator using time
    //srand(0); //time(NULL)); //almost never wanna call srand in worker function
    int numb = rand() % alpha_len + 1;
    printf("numb is: %d\n", numb);
   
    return numb;
=======
//get a random number to pick 
void get_random_numb(int length) {
    assert(length);
    printf("length is: %d\n", length);

    //initialize random number generator using time
    srand(time(0));

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
>>>>>>> da0b89e3e94f52bb4e5356dec0825eb6aa2f7615
}

void usage() { //TODO
// void usage(int exit_code) { //TODO
    // assert(exit_code == EXIT_FAILURE || exit_code == EXIT_SUCCESS); //validate not using usage in incorrect way
    printf("usage: ./otp... \n"); //will have all the values available
    exit(EXIT_FAILURE);
}

static MunitResult
encode_one_char(const MunitParameter params[], void* data) {
    (void) params;
    (void) data;
    //arrange
    char plaintext_char = 'A';
    char key_char = 'Z';
    char expected_char = 'Q';   //expected answer
    //action
    char encoded_char = encode_char(plaintext_char, key_char);
    //assert
    munit_assert_char(encoded_char, ==, expected_char);

    return MUNIT_OK; 
}


//key generation
static MunitResult
generate_numb(const MunitParameter params[], void* data) {
    (void) params;
    (void) data;
    //arrange
    //srand(0); //time(NULL));
    int static_num = 27;
    //action
    int num_from_fx = get_random_numb();
    //assert
    munit_assert_int(num_from_fx, <=, static_num);

    return MUNIT_OK;
}

static MunitResult
test_get_random(const MunitParameter params[], void* data) {
    //arrange
    srand(0);
    // int alpha_len = 28;
    int expected[] = {14, 11, 19, 8, 17};
    
    for (int i = 0; i < (int)(sizeof(expected)/sizeof(expected[0])); i++) {
        //action
        int r = get_random_numb();
        //assert
        munit_assert_int(expected[i], ==, r);
    }

    return MUNIT_OK;    
}
//expect to be positive
//can it be zero

//encode
static MunitResult
is_returned_char_in_alphabet(const MunitParameter params[], void* data) {
    return MUNIT_OK;
}

static MunitResult
demitrus_test_compare(const MunitParameter params[], void* data) {
  /* We'll use these later */
  const unsigned char val_uchar = 'b';
  const short val_short = 1729;
  double pi = 3.141592654;
  char* stewardesses = "stewardesses";
  char* most_fun_word_to_type;

  /* These are just to silence compiler warnings about the parameters
   * being unused. */
  (void) params;
  (void) data;

  /* Let's start with the basics. */
  munit_assert(0 != 1);

  /* There is also the more verbose, though slightly more descriptive
     munit_assert_true/false: */
  munit_assert_false(0);

  /* You can also call munit_error and munit_errorf yourself.  We
   * won't do it is used to indicate a failure, but here is what it
   * would look like: */
  /* munit_error("FAIL"); */
  /* munit_errorf("Goodbye, cruel %s", "world"); */

  /* There are macros for comparing lots of types. */
  munit_assert_char('a', ==, 'a');

  /* Sure, you could just assert('a' == 'a'), but if you did that, a
   * failed assertion would just say something like "assertion failed:
   * val_uchar == 'b'".  µnit will tell you the actual values, so a
   * failure here would result in something like "assertion failed:
   * val_uchar == 'b' ('X' == 'b')." */
  munit_assert_uchar(val_uchar, ==, 'b');

  /* Obviously we can handle values larger than 'char' and 'uchar'.
   * There are versions for char, short, int, long, long long,
   * int8/16/32/64_t, as well as the unsigned versions of them all. */
  munit_assert_short(42, <, val_short);

  /* There is also support for size_t.
   *
   * The longest word in English without repeating any letters is
   * "uncopyrightables", which has uncopyrightable (and
   * dermatoglyphics, which is the study of fingerprints) beat by a
   * character */
  munit_assert_size(strlen("uncopyrightables"), >, strlen("dermatoglyphics"));

  /* Of course there is also support for doubles and floats. */
  munit_assert_double(pi, ==, 3.141592654);

  /* If you want to compare two doubles for equality, you might want
   * to consider using munit_assert_double_equal.  It compares two
   * doubles for equality within a precison of 1.0 x 10^-(precision).
   * Note that precision (the third argument to the macro) needs to be
   * fully evaluated to an integer by the preprocessor so µnit doesn't
   * have to depend pow, which is often in libm not libc. */
  munit_assert_double_equal(3.141592654, 3.141592653589793, 9);

  /* And if you want to check strings for equality (or inequality),
   * there is munit_assert_string_equal/not_equal.
   *
   * "stewardesses" is the longest word you can type on a QWERTY
   * keyboard with only one hand, which makes it loads of fun to type.
   * If I'm going to have to type a string repeatedly, let's make it a
   * good one! */
  munit_assert_string_equal(stewardesses, "stewardesses");

  /* A personal favorite macro which is fantastic if you're working
   * with binary data, is the one which naïvely checks two blobs of
   * memory for equality.  If this fails it will tell you the offset
   * of the first differing byte. */
  munit_assert_memory_equal(7, stewardesses, "steward");

  /* You can also make sure that two blobs differ *somewhere*: */
  munit_assert_memory_not_equal(8, stewardesses, "steward");

  /* There are equal/not_equal macros for pointers, too: */
  most_fun_word_to_type = stewardesses;
  munit_assert_ptr_equal(most_fun_word_to_type, stewardesses);

  /* And null/not_null */
  munit_assert_null(NULL);
  munit_assert_not_null(most_fun_word_to_type);

  /* Lets verify that the data parameter is what we expected.  We'll
   * see where this comes from in a bit.
   *
   * Note that the casting isn't usually required; if you give this
   * function a real pointer (instead of a number like 0xdeadbeef) it
   * would work as expected. */
//   munit_assert_ptr_equal(data, (void*)(uintptr_t)0xdeadbeef); //TODO

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  {
    /* The name is just a unique human-readable way to identify the
     * test. You can use it to run a specific test if you want, but
     * usually it's mostly decorative. */
    (char*) "demitrus_test_compare", 

    /* You probably won't be surprised to learn that the tests are
     * functions. */
    // test_compare,
    demitrus_test_compare, 
    /* If you want, you can supply a function to set up a fixture.  If
     * you supply NULL, the user_data parameter from munit_suite_main
     * will be used directly.  If, however, you provide a callback
     * here the user_data parameter will be passed to this callback,
     * and the return value from this callback will be passed to the
     * test function.
     *
     * For our example we don't really need a fixture, but lets
     * provide one anyways. */
    NULL, //test_compare_setup, //run before every UT, then teardown would run after execution of UT !!!!!!!!!!!
    /* If you passed a callback for the fixture setup function, you
     * may want to pass a corresponding callback here to reverse the
     * operation. */
    NULL, //test_compare_tear_down,
    /* Finally, there is a bitmask for options you can pass here.  You
     * can provide either MUNIT_TEST_OPTION_NONE or 0 here to use the
     * defaults. */
    MUNIT_TEST_OPTION_NONE,
    NULL
  },
  { (char*) "encode_one_char", encode_one_char, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  {"generate_numb", generate_numb, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  {"test_get_random", test_get_random, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  /* Usually this is written in a much more compact format; all these
   * comments kind of ruin that, though.  Here is how you'll usually
   * see entries written: */
//   { (char*) "/example/rand", test_rand, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  /* To tell the test runner when the array is over, just add a NULL
   * entry at the end. */
//   { (char*) "/example/parameters", test_parameters, NULL, NULL, MUNIT_TEST_OPTION_NONE, test_params },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
  /* This string will be prepended to all test names in this suite;
   * for example, "/example/rand" will become "/µnit/example/rand".
   * Note that, while it doesn't really matter for the top-level
   * suite, NULL signal the end of an array of tests; you should use
   * an empty string ("") instead. */
  (char*) "/otp/",
  /* The first parameter is the array of test suites. */
  test_suite_tests,
  /* In addition to containing test cases, suites can contain other
   * test suites.  This isn't necessary in this example, but it can be
   * a great help to projects with lots of tests by making it easier
   * to spread the tests across many files.  This is where you would
   * put "other_suites" (which is commented out above). */
  NULL,
  /* An interesting feature of µnit is that it supports automatically
   * running multiple iterations of the tests.  This is usually only
   * interesting if you make use of the PRNG to randomize your tests
   * cases a bit, or if you are doing performance testing and want to
   * average multiple runs.  0 is an alias for 1. */
  1,
  /* Just like MUNIT_TEST_OPTION_NONE, you can provide
   * MUNIT_SUITE_OPTION_NONE or 0 to use the default settings. */
  MUNIT_SUITE_OPTION_NONE
};


int main(int argc, char *argv[]) {
    // srand(0);
    // for(int i =0; i < 5; i++) {
    //     int r = rand();
    //     printf("%d, %d\n", r, r % 28);
    // }
    // return 0;
    int opt = 0;
    FILE* fd = NULL;
    // int char_count = 0;
    char* app_name = NULL;
    srand(time(NULL)); //almost never wanna call srand in worker function

    if (argc == 1) {
        return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
    }

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
    
    //here is the client/program split
    //beginning to run alogirthm 
    char* plaintext_ptr = argv[4];
    if (app_name == NULL) {
        usage(); 
    }
    if ((IS_STR_EQUAL(app_name, "key"))) {
        int plaintext_len = strlen(argv[4]);
        if (plaintext_len) { //, argv[4])) {
            FILE* fd = fopen("key.txt", "w");
            char* ptr_to_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
            for (int i = 0; i < plaintext_len; i++) {
                int rand_num = get_random_numb();
                //sleep(1);
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
        fd = fopen(argv[optind], "r"); //account for when no key.txt file created, aka use read and write mode 
        if (IS_STR_EQUAL("encode", app_name)) {
            encode(fd, plaintext_ptr); 
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