void ingredientSubstitutionMenu() {
        string ingredient;
        printf("Enter the ingredient to find a substitution for: ");
        cin >> ingredient;
        string substitution = ingredientSubstitution.findSubstitution(ingredient);
        printf("Suggested substitution: %s\n", substitution.c_str());
    }