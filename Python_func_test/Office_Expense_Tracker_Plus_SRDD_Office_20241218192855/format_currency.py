def format_currency(amount):
    '''
    Formats a number as currency.
    Parameters:
    amount (float): The amount of money to format.
    Returns:
    str: The formatted currency string.
    '''
    try:
        formatted_amount = "${:,.2f}".format(amount)
        return formatted_amount
    except (TypeError, ValueError) as e:
        raise ValueError("Invalid amount for currency formatting: {}".format(e))