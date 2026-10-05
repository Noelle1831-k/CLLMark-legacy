def add_savings(amount):
    entry = {
        'date': datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
        'amount': amount
    }
    savings_data.append(entry)