def validate_input(value):
    '''
    Validates user input to ensure it is a positive number.
    '''
    try:
        val = float(value)
        if val < 0:
            raise ValueError("Value must be positive.")
        return val
    except ValueError as e:
        print(f"Invalid input: {e}")
        return None