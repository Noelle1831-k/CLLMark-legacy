def main():
    # Initialize user data with detailed attributes
    user = User(name="John Doe", age=30, weight=70, height=175, fitness_goal="muscle gain", activity_level="moderate", dietary_preferences="vegetarian")
    # Analyze user data to extract meaningful insights
    user_analysis = analyze_user_data(user)
    # Generate a comprehensive workout plan tailored to the user's needs
    workout_plan = generate_workout_plan(user_analysis)
    # Generate a personalized nutrition plan considering user's dietary preferences
    nutrition_plan = generate_nutrition_plan(user_analysis)
    # Display the generated plans in a user-friendly format
    print("Workout Plan:", workout_plan)
    print("Nutrition Plan:", nutrition_plan)