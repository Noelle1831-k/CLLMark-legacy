def loss_amount(actual_cost, sale_amount):
    if actual_cost < sale_amount:
        return sale_amount - actual_cost
    return None