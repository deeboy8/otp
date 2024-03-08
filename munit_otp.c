#include "munit/munit.h"
#include "otp.h"

///////////////////////////
//encode_char
static MunitResult
test_otp_example(const MunitParameter params[], void* data) {
    (void) params;
    (void) data;
    //arrange
    char letter = 'D';
    char key_char = 'X';
    char plaintext_char = 'H';
    char* new_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    //action
    char result = encode_char(plaintext_char, key_char, new_alphabet, ALPHA_LEN);
    //assert 
    munit_assert_char(result, ==, letter);

    return MUNIT_OK;
}

//use different alphabet
static MunitResult
test_different_alphabet(const MunitParameter params[], void* data) {
    (void) params;
    (void) data;
    //arrange
    char letter = 'E';
    char key_char = 'X';
    char plaintext_char = 'H';
    char* new_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //action
    char result = encode_char(plaintext_char, key_char, new_alphabet, strlen(new_alphabet));
    //assert 
    munit_assert_char(result, ==, letter);

    return MUNIT_OK;
}

//use numbers instead of chars
static MunitResult
test_different_alpha_len(const MunitParameter params[], void* data) {
    (void) params;
    (void) data;
    //arrange
    char letter = 'E';
    char key_char = 'X';
    char plaintext_char = 'H';
    int new_alpha_len = 20;
    //action
    char result = encode_char(plaintext_char, key_char, ALPHABET, new_alpha_len);
    //assert
    munit_assert_char(result, !=, letter);

    return MUNIT_OK;
}

//test with numbers
static MunitResult
test_with_numbers_instead_of_chars(const MunitParameter params[], void* data) {
    (void) params;
    (void) data;
    //arrange
    int value1 = 12;
    int value2 = 3;
    //action
    char result = encode_char(value1, value2, ALPHABET, ALPHA_LEN);
    //assert 
    munit_assert_false(result);

    return MUNIT_OK;
}

//use negative numbers 
//









//////////////////////////

static MunitResult
encode_one_char(const MunitParameter params[], void* data) {
    (void) params;
    (void) data;
    //arrange
    char plaintext_char = 'A';
    char key_char = 'Z';
    char expected_char = 'Q'; //expected answer
    //action
    char encoded_char = encode_char(plaintext_char, key_char, ALPHABET, ALPHA_LEN);
    //assert
    munit_assert_char(encoded_char, ==, expected_char);

    return MUNIT_OK; 
}

//UT: ensure number returned is greater than 0
static MunitResult
numb_greater_than_zero(const MunitParameter params[], void* data) {
    (void) params;
    (void) data;
    //arrange
    int static_num = 0;
    int alpha_len = strlen(ALPHABET);
    //action
    int num_from_fx = get_random_numb(alpha_len);
    //assert
    munit_assert_int(num_from_fx, >=, static_num);

    return MUNIT_OK;
}

//UT: ensure number returned is less than 27
static MunitResult
numb_less_than_alpha_length(const MunitParameter params[], void* data) {
    (void) params;
    (void) data;
    //arrange
    int static_num = 27; //is this the best way?????
    int alpha_len = strlen(ALPHABET);
    //action
    int num_from_fx = get_random_numb(alpha_len);
    //assert
    munit_assert_int(num_from_fx, <=, static_num);

    return MUNIT_OK;
}

//don't remember what our intent was with this
static MunitResult
test_get_random(const MunitParameter params[], void* data) {
    //arrange
    srand(0);
    int expected[] = {6, 24, 23, 7, 7};
    int alpha_len = strlen(ALPHABET);

    for (int i = 0; i < (int)(sizeof(expected)/sizeof(expected[0])); i++) {
        //action
        int r = get_random_numb(alpha_len);
        //assert
        munit_assert_int(expected[i], ==, r);
    }

    return MUNIT_OK;    
}

//expect to be positive
static MunitResult
is_result_positive(const MunitParameter params[], void* data) {
    (void) params;
    (void) data;
    //arrange
    int alpha_len = strlen(ALPHABET);
    int value = 1;
    assert(value);
    //action
    int result = get_random_numb(alpha_len);
    //assert
    munit_assert_int(result, >=, 0);

    return MUNIT_OK;
}

//can it be zero
// static MunitResult
// can_it_be_zero(const MunitParameter params[], void* data) {
    
// }

//encode
static MunitResult
is_returned_char_in_alphabet(const MunitParameter params[], void* data) {
    return MUNIT_OK;
}

static void*
test_setup(const MunitParameter params[], void* user_data) {
    (void) params;
    
    // srand(0);
  
    return NULL; //0;
}

/* To clean up after a test, you can use a tear down function.  The
 * fixture argument is the value returned by the setup function
 * above. */
// static void
// test_compare_tear_down(void* fixture) {
//   munit_assert_ptr_equal(fixture, (void*)(uintptr_t)0xdeadbeef);
// }

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
     * usually it's mostly decorative. 
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
  }, */
  {"test_with_numbers_instead_of_chars", test_with_numbers_instead_of_chars, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  {"test_different_alpha_len", test_different_alpha_len, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  {"test_different_alphabet", test_different_alphabet, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  {"test_otp_example", test_otp_example, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL  },  
  {"numb_greater_than_zero", numb_greater_than_zero, test_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  /*{ (char*) "encode_one_char", encode_one_char, test_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },*/
  {"numb_less_than_alpha_length", numb_less_than_alpha_length, test_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  {"test_get_random", test_get_random, test_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  {"is_result_positive", is_result_positive, test_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  /* Usually this is written in a much more compact format; all these
   * comments kind of ruin that, though.  Here is how you'll usually
   * see entries written: */
//   { (char*) "/example/rand", test_rand, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  /* To tell the test runner when the array is over, just add a NULL
   * entry at the end. */
//   { (char*) "/example/parameters", test_parameters, NULL, NULL, MUNIT_TEST_OPTION_NONE, test_params },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

/*static*/ const MunitSuite test_suite = {
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

// int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
//   /* Finally, we'll actually run our test suite!  That second argument
//    * is the user_data parameter which will be passed either to the
//    * test or (if provided) the fixture setup function. */
//   return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
// }