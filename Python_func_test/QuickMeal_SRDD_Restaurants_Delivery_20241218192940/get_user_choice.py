def get_user_choice(meals):
    '''
    Capture and validate user selections to ensure valid input.
    Allows the user to select a meal package or exit the application.
    '''
    while True:
        choice = input("\nEnter the number of the meal package you want to order or 'exit' to quit: ").strip()
        if choice.lower() == 'exit':  # Allow user to exit
            return 'exit'
        if choice.isdigit():  # Check if input is a digit
            choice = int(choice)
            if 1 <= choice <= len(meals):  # Ensure the choice is within range
                return choice
        print("Invalid choice. Please enter a valid meal package number.")