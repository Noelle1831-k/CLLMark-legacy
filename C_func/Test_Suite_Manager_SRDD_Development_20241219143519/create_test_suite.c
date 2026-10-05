void create_test_suite() {
    if (suite_count >= MAX_SUITES) {
        printf("Maximum number of test suites reached.\n");
        return;
    }
    printf("Enter Test Suite Name: ");
    char name[50];
    get_string_input(name, 50);
    TestSuite new_suite;
    strcpy(new_suite.name, name);
    new_suite.case_count = 0;
    test_suites[suite_count++] = new_suite;
    printf("Test suite '%s' created successfully.\n", name);
}