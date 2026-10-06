void add_test_case() {
    if (suite_count == 0) {
        printf("No test suites available. Create a test suite first.\n");
        return;
    }
    printf("Enter Test Suite Name: ");
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
    if (suite->case_count >= MAX_CASES) {
        printf("Maximum number of test cases reached for this suite.\n");
        return;
    }
    TestCase new_case;
    printf("Enter Test Case Name: ");
    get_string_input(new_case.name, 50);
    printf("Enter Test Case Description: ");
    get_string_input(new_case.description, 200);
    printf("Enter Test Case Priority (1-5): ");
    new_case.priority = get_integer_input();
    new_case.result = 0; 
    suite->test_cases[suite->case_count++] = new_case;
    printf("Test case '%s' added to suite '%s'.\n", new_case.name, suite_name);
}