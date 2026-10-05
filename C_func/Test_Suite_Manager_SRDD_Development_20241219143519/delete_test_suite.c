void delete_test_suite() {
    if (suite_count == 0) {
        printf("No test suites to delete.\n");
        return;
    }
    printf("Enter Test Suite Name to Delete: ");
    char name[50];
    get_string_input(name, 50);
    for (int i = 0; i < suite_count; i++) {
        if (strcmp(test_suites[i].name, name) == 0) {
            for (int j = i; j < suite_count - 1; j++) {
                test_suites[j] = test_suites[j + 1];
            }
            suite_count--;
            printf("Test suite '%s' deleted successfully.\n", name);
            return;
        }
    }
    printf("Test suite '%s' not found.\n", name);
}