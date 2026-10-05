def update_spending(self):
        """
        Allow the user to input their spending data dynamically.
        """
        self.spending_data = []
        print("Enter your spending data for different categories (type 'done' when finished):")
        for category in self.categories:
            while True:
                data = input(f"Enter your spending amount for {category}: ")
                if data.lower() == 'done':
                    break
                try:
                    amount = float(data)
                    self.spending_data.append(amount)
                    break
                except ValueError:
                    print("Please enter a valid number.")
        print("Spending data updated.")