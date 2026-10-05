def generate_expense_id():
    return "".join(random.choices(string.ascii_uppercase + string.digits, k=6))