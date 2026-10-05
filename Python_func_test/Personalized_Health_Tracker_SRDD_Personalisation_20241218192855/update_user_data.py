def update_user_data(user):
    '''
    Function to update user health data with input validation.
    '''
    try:
        weight = float(input("Enter new weight (kg): ").strip())
        if weight <= 0:
            raise ValueError("Weight must be a positive number.")
        height = float(input("Enter new height (cm): ").strip())
        if height <= 0:
            raise ValueError("Height must be a positive number.")
        activity_level = input("Enter activity level (low, moderate, high): ").strip().lower()
        if activity_level not in ['low', 'moderate', 'high']:
            raise ValueError("Invalid activity level.")
        nutrition_intake = input("Enter nutrition intake (balanced, high-protein, low-carb): ").strip().lower()
        if nutrition_intake not in ['balanced', 'high-protein', 'low-carb']:
            raise ValueError("Invalid nutrition intake.")
        user.update_data(weight, height, activity_level, nutrition_intake)
        print("User data updated successfully.")
    except ValueError as e:
        print(f"Error: {e}")