def profit_amount(actual_cost, sale_amount):
    if sale_amount < actual_cost:
        return actual_cost - sale_amount
    return None