def validate_positive_number(value):
    '''
    Validates that a number is positive.
    Returns the validated number or None if the validation fails.
    '''
    try:
        val = float(value)
        if val < 0:
            raise ValueError("Number must be positive.")
        return val
    except ValueError as e:
        print(f"Invalid input: {e}")
        return None