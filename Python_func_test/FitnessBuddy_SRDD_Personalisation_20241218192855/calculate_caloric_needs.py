def calculate_caloric_needs(weight, height, age, fitness_goal):
    # Calculate daily caloric needs based on user data
    if fitness_goal == "muscle gain":
        return (10 * weight + 6.25 * height - 5 * age + 5) * 1.2
    elif fitness_goal == "weight loss":
        return (10 * weight + 6.25 * height - 5 * age + 5) * 0.8
    else:
        return (10 * weight + 6.25 * height - 5 * age + 5)