def cal_electbill(units):
    if units <= 100:
        amount = units * 3.5
    elif units <= 200:
        amount = 100 * 3.5 + (units - 100) * 5
    else:
        amount = 100 * 3.5 + 100 * 5 + (units - 200) * 7
    fixed_charge = 50
    total = amount + fixed_charge
    return total