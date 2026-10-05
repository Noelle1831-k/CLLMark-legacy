def validate_variable(data, variable):
    if variable in data.columns:
        return True
    return False