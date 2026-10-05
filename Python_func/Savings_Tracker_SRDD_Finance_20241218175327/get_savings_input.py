def get_savings_input():
    while True:
        try:
            amount = float(input("Enter savings amount: "))
            if amount < 0:
                raise ValueError("Amount cannot be negative.")
            return amount
        except ValueError as e:
            print(f"Invalid input: {e}. Please try again.")