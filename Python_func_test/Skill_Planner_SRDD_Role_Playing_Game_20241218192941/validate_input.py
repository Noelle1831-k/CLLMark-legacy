def validate_input(prompt, expected_type):
    while True:
        try:
            return expected_type(input(prompt))
        except ValueError:
            print("Invalid input. Please try again.")