void suggestSubstitution(const char *ingredient) {
    if (strcmp(ingredient, "Ground Beef") == 0) {
        printf("Consider using ground turkey or lentils as a substitute for %s.\n", ingredient);
    } else {
        printf("No substitution suggestions available for %s.\n", ingredient);
    }
}