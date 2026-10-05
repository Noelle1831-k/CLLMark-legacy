def validate_input(prompt, valid_options):
    '''
    Validate user input against a set of valid options.
    '''
    while True:
        user_input = input(prompt)
        if user_input in valid_options:
            return user_input
        print("Invalid input. Please try again.")