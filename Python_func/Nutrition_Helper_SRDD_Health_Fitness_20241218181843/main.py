def main():
    # Initialize the database
    db = Database()
    # Add some food items to the database
    db.add_food_item(FoodItem("Apple", 95, {"carbs": 25, "protein": 0.5, "fat": 0.3}, {"vitamin C": 8.4}))
    db.add_food_item(FoodItem("Banana", 105, {"carbs": 27, "protein": 1.3, "fat": 0.3}, {"vitamin B6": 0.5}))
    db.add_food_item(FoodItem("Chicken Breast", 165, {"carbs": 0, "protein": 31, "fat": 3.6}, {"vitamin B6": 0.6}))
    db.add_food_item(FoodItem("Broccoli", 55, {"carbs": 11, "protein": 3.7, "fat": 0.6}, {"vitamin C": 89.2}))
    # Initialize the NutritionHelper application
    app = NutritionHelper()
    # Create a user
    user = User("John Doe", 30, 180, 75, "male")
    user.set_goals(2000, {"carbs": 300, "protein": 50, "fat": 70}, {"vitamin C": 90, "vitamin B6": 1.3})
    # Add the user to the application
    app.add_user(user)
    # Create a meal
    meal = Meal("Breakfast", [db.get_food_item("Apple"), db.get_food_item("Banana")])
    app.add_meal(user, meal)
    # Create another meal
    meal2 = Meal("Lunch", [db.get_food_item("Chicken Breast"), db.get_food_item("Broccoli")])
    app.add_meal(user, meal2)
    # Get the daily summary for the user
    summary = app.get_daily_summary(user)
    print("Daily Summary:", summary)
    # Get personalized recommendations for the user
    recommendations = app.get_recommendations(user)
    print("Recommendations:", recommendations)