def validate_input(input_value, expected_type):
    try:
        if expected_type == int:
            return int(input_value)
        elif expected_type == float:
            return float(input_value)
        elif expected_type == str:
            return str(input_value)
    except ValueError:
        return None