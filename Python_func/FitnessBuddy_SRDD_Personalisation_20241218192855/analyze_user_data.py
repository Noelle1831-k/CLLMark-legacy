def analyze_user_data(user):
    # Analyze user data to determine fitness needs and preferences
    analysis = {
        "bmi": calculate_bmi(user.weight, user.height),
        "caloric_needs": calculate_caloric_needs(user.weight, user.height, user.age, user.fitness_goal, user.activity_level),
        "dietary_preferences": user.dietary_preferences
    }
    return analysis