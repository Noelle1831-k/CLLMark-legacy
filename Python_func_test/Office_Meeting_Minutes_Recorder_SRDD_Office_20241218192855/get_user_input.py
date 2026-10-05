def get_user_input(prompt):
    try:
        return input(prompt)
    except Exception as e:
        print(f"An error occurred while getting user input: {e}")
        return ""