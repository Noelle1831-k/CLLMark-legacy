void select_variables() {
    printf("Selecting variables for analysis...\n");
    if (!prompt_variable_selection()) {
        fprintf(stderr, "Error: Variable selection failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Variables selected successfully.\n");
}