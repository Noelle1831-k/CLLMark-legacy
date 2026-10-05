void ingredientSubstitutionMenu() {
        string ingredient;
        cout << "Enter the ingredient to find a substitution for: ";
        cin >> ingredient;
        string substitution = ingredientSubstitution.findSubstitution(ingredient);
        cout << "Suggested substitution: " << substitution << endl;
    }