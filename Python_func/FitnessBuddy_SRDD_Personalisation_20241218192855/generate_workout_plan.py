def generate_workout_plan(user_analysis):
    # Generate a personalized workout plan based on user analysis
    if user_analysis["bmi"] < 18.5:
        exercises = ["Push-ups", "Squats", "Lunges"]
        duration = "30 minutes"
        intensity = "Moderate"
    elif user_analysis["bmi"] < 25:
        exercises = ["Running", "Cycling", "Swimming"]
        duration = "45 minutes"
        intensity = "High"
    else:
        exercises = ["Walking", "Yoga", "Pilates"]
        duration = "60 minutes"
        intensity = "Low"
    return WorkoutPlan(exercises, duration, intensity)