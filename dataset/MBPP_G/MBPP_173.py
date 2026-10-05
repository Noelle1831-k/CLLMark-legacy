def remove_splchar(text):
    return ''.join((char for char in text if char.isalnum()))