def check_integer(text):
    try:
        int(text)
        return True
    except ValueError:
        return False