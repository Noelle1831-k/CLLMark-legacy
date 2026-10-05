def validate_input(input_value, input_type):
    try:
        if input_type == 'float':
            return float(input_value)
        elif input_type == 'int':
            return int(input_value)
    except ValueError:
        return None