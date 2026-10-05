def main():
    # Initialize components
    user = User()
    recipe = Recipe()
    search = Search(recipe.recipes)  # Pass the recipes data to Search
    community = Community()
    # Example usage
    # User creation and profile management
    user.create_profile("John Doe", "john@example.com", "password123")
    user.update_profile("john@example.com", {"bio": "Passionate home cook."})
    profile = user.get_profile("john@example.com")
    print("User Profile:", profile)
    # Recipe management
    recipe.add_recipe("john@example.com", "Spaghetti Bolognese", ["spaghetti", "tomato", "beef"], "Italian", "Cook spaghetti and mix with sauce.")
    recipe.update_recipe("john@example.com", "Spaghetti Bolognese", {"ingredients": ["spaghetti", "tomato", "beef", "garlic"]})
    recipes_by_cuisine = search.search_by_cuisine("Italian")
    print("Recipes by Cuisine:", recipes_by_cuisine)
    recipes_by_ingredient = search.search_by_ingredient("garlic")
    print("Recipes by Ingredient:", recipes_by_ingredient)
    # Community interactions
    community.post_discussion("john@example.com", "What's your favorite pasta recipe?")
    community.add_comment("john@example.com", "What's your favorite pasta recipe?", "I love Spaghetti Carbonara!")
    community.give_feedback("john@example.com", "Spaghetti Bolognese", "Delicious and easy to make!")
    print("Community Discussions:", community.get_all_discussions())
    print("Recipe Feedback:", community.get_feedback("Spaghetti Bolognese"))