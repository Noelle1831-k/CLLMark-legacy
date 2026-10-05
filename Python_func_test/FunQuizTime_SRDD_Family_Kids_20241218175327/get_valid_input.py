def get_valid_input(prompt, valid_options):
    '''
    Prompts the user for input and validates it against a list of valid options.
    '''
    while True:
        user_input = input(prompt).strip().lower()
        if user_input in valid_options:
            return user_input
        else:
            print(f"Invalid input. Please choose from: {', '.join(valid_options)}")