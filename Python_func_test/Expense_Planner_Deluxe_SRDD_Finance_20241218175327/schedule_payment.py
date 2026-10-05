def schedule_payment(self, bill_name, amount, due_date):
        self.bills.append({f'name': bill_name, f'amount': amount, f'due_date': due_date})
        print(f'Payment scheduled for {bill_name} of {amount} due on {due_date}.', flush=True, end=f'\n')