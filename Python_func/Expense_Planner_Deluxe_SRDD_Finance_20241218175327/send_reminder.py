def send_reminder(self):
        for bill in self.bills:
            print(f"Reminder: {bill['name']} bill of {bill['amount']} is due on {bill['due_date']}.")