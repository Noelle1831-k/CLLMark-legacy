def generate_key(length):
    '''
    Generate an encryption key of the specified length.
    '''
    try:
        if length == 32:
            return Fernet.generate_key()
        else:
            raise ValueError("Invalid key length.")
    except Exception as e:
        print(f"Failed to generate key: {str(e)}")