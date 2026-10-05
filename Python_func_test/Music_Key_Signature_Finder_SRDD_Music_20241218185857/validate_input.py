def validate_input(input_data):
    '''
    Validate the input data to ensure it is in the correct format.
    '''
    return all(isinstance(item, str) for item in input_data)