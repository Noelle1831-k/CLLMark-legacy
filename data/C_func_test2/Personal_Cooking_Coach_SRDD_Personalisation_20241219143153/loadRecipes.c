void loadRecipes(RecipeDatabase *db) {
    strcpy(db->recipes[0], "Vegan Salad");
    strcpy(db->recipes[1], "Gluten-Free Bread");
    strcpy(db->recipes[2], "Vegetarian Curry");
    strcpy(db->recipes[3], "Vegan Smoothie");
    db->recipeCount = 4;
}