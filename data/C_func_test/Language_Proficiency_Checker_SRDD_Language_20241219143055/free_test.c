void free_test(Test *test) {
    free(test->questions);
    free(test);
}