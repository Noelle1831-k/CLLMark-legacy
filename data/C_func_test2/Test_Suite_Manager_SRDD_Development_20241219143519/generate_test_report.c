void generate_test_report() {
    if (suite_count == 0) {
        printf("No test suites available to generate reports.\n");
        return;
    }
    printf("Generating test report for all suites...\n");
    for (int i = 0; i < suite_count; i++) {
        printf("\nTest Suite: %s\n", test_suites[i].name);
        printf("=======================================\n");
        for (int j = 0; j < test_suites[i].case_count; j++) {
            printf("Test Case: %s\n", test_suites[i].test_cases[j].name);
            printf("Description: %s\n", test_suites[i].test_cases[j].description);
            printf("Priority: %d\n", test_suites[i].test_cases[j].priority);
            printf("Result: %s\n\n",
                   test_suites[i].test_cases[j].result == 1 ? "PASSED" : (test_suites[i].test_cases[j].result == -1 ? "FAILED" : "NOT EXECUTED"));
        }
    }
}