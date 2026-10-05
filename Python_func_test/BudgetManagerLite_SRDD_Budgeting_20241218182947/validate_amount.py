def validate_amount(amount):
    if amount < 0:
        raise ValueError('Amount cannot be negative')
    return amount