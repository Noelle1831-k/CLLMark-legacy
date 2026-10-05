def is_decimal(num):
    try:
        parts = num.split('.')
        if len(parts) == 2 and parts[0].isdigit() and parts[1].isdigit():
            return len(parts[1]) == 2
        return False
    except:
        return False