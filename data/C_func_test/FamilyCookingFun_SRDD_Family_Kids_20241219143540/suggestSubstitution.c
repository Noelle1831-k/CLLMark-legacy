void suggestSubstitution(const char *ingredient) {
    if (strcmp(ingredient, "milk") == 0) {
        printf("Substitution for milk: Almond milk, Soy milk, Coconut milk.\n");
    } else if (strcmp(ingredient, "butter") == 0) {
        printf("Substitution for butter: Margarine, Coconut oil, Olive oil.\n");
    } else {
        printf("No substitution found for %s.\n", ingredient);
    }
}