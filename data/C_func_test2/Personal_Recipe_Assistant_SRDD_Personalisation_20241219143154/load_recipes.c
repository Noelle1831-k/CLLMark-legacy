int load_recipes(Recipe **recipes) {
    static Recipe recipe_list[] = {
        {"Vegetarian Pasta", {"pasta", "tomato", "cheese"}, 3},
        {"Gluten-Free Pancakes", {"gluten-free flour", "milk", "egg"}, 3},
        {"Spicy Tofu Stir-Fry", {"tofu", "chili", "soy sauce"}, 3},
        {"Lactose-Free Smoothie", {"almond milk", "banana", "honey"}, 3}
    };
    int count = sizeof(recipe_list) / sizeof(recipe_list[0]);
    *recipes = malloc(count * sizeof(Recipe));
    memcpy(*recipes, recipe_list, count * sizeof(Recipe));
    return count;
}