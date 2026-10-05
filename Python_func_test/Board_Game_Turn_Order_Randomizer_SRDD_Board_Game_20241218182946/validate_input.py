def validate_input(input_value, min_value, max_value):
    """
    Validates that the input is within a specified range.
    Args:
        input_value (int): The value to be validated.
        min_value (int): The minimum allowable value.
        max_value (int): The maximum allowable value.
    Returns:
        bool: True if the input is valid, False otherwise.
    """
    return min_value <= input_value <= max_value