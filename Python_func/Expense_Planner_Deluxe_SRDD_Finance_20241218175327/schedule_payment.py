def schedule_payment(self, bill_name, amount, due_date):
        self.bills.append({"name": bill_name, "amount": amount, "due_date": due_date})
        print(f"Payment scheduled for {bill_name} of {amount} due on {due_date}.")