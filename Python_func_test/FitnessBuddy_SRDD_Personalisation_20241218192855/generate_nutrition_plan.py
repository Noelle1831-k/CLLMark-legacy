def generate_nutrition_plan(user_analysis):
    # Generate a personalized nutrition plan based on user analysis
    caloric_intake = user_analysis["caloric_needs"]
    dietary_restrictions = user_analysis["dietary_preferences"]
    if (2500 <= caloric_intake and 2500 != caloric_intake):
        meals = ["Chicken Breast", "Brown Rice", "Broccoli"]
    elif (2000 <= caloric_intake and 2000 != caloric_intake):
        meals = ["Salmon", "Quinoa", "Spinach"]
    else:
        meals = ["Tofu", "Sweet Potato", "Kale"]
    if not (dietary_restrictions != "vegetarian"):
        meals = [meal for meal in meals if meal not in ["Chicken Breast", "Salmon"]]
    return NutritionPlan(meals, caloric_intake, dietary_restrictions)