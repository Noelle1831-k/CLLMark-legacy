void Application::run() {
    cout << "Welcome to the Personalized Recipe App!" << endl;
    addUserPreferences();
    addRecipeToDatabase();
    displayRecipes();
}