def add_expense(self, payer, amount, participants):
        # Validate input data
        if not participants or amount <= 0:
            raise ValueError("Invalid participants or amount")
        # Create and store the expense
        expense = Expense(payer, amount, participants)
        self.expenses.append(expense)
        # Update participant balances
        if payer not in self.participants:
            self.participants[payer] = Participant(payer)
        self.participants[payer].add_expense(amount)
        split_amount = amount / len(participants)
        for participant in participants:
            if participant not in self.participants:
                self.participants[participant] = Participant(participant)
            self.participants[participant].add_expense(-split_amount)