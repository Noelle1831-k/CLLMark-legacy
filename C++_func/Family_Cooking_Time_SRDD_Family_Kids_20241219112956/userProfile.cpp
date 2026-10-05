MainApp(string username) : userProfile(username) {
        recipes.push_back(Recipe("Spaghetti", {"Pasta", "Tomato Sauce", "Cheese"}, "Boil pasta, add sauce, sprinkle cheese."));
        recipes.push_back(Recipe("Salad", {"Lettuce", "Tomato", "Cucumber", "Dressing"}, "Chop ingredients and mix with dressing."));
    }