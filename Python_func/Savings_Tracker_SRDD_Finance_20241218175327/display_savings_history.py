def display_savings_history(history):
    print("Savings History:")
    for entry in history:
        print(f"Date: {entry['date']}, Amount: {entry['amount']}")