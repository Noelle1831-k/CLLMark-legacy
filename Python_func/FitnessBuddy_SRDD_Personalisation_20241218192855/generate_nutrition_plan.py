def generate_nutrition_plan(user_analysis):
    # Generate a personalized nutrition plan based on user analysis
    caloric_intake = user_analysis["caloric_needs"]
    dietary_restrictions = user_analysis["dietary_preferences"]
    if caloric_intake > 2500:
        meals = ["Chicken Breast", "Brown Rice", "Broccoli"]
    elif caloric_intake > 2000:
        meals = ["Salmon", "Quinoa", "Spinach"]
    else:
        meals = ["Tofu", "Sweet Potato", "Kale"]
    if dietary_restrictions == "vegetarian":
        meals = [meal for meal in meals if meal not in ["Chicken Breast", "Salmon"]]
    return NutritionPlan(meals, caloric_intake, dietary_restrictions)