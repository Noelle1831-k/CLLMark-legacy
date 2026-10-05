void Recipe::feedback(const string &recipeName) {
    if (recipes.find(recipeName) != recipes.end()) {
        string feedback;
        cout << "Enter your feedback for the recipe '" << recipeName << "': ";
        getline(cin, feedback);
        cout << "Feedback submitted successfully!" << endl;
    } else {
        cout << "Recipe not found!" << endl;
    }
}