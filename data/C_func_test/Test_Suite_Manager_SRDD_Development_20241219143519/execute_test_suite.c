void execute_test_suite() {
    if (suite_count == 0) {
        printf("No test suites available to execute.\n");
        return;
    }
    printf("Enter Test Suite Name to Execute: ");
    char suite_name[50];
    get_string_input(suite_name, 50);
    TestSuite* suite = NULL;
    for (int i = 0; i < suite_count; i++) {
        if (strcmp(test_suites[i].name, suite_name) == 0) {
            suite = &test_suites[i];
            break;
        }
    }
    if (suite == NULL) {
        printf("Test suite '%s' not found.\n", suite_name);
        return;
    }
    printf("Executing test suite '%s'...\n", suite->name);
    for (int i = 0; i < suite->case_count; i++) {
        printf("Executing test case '%s' (Priority: %d)...\n", suite->test_cases[i].name, suite->test_cases[i].priority);
        suite->test_cases[i].result = rand() % 2 == 0 ? 1 : -1;
        printf("Test case '%s': %s\n", suite->test_cases[i].name,
               suite->test_cases[i].result == 1 ? "PASSED" : "FAILED");
    }
}