def send_notifications(self):
        today = datetime.date.today()
        for transaction in self.incomes + self.expenses:
            if transaction.calculate_next_due_date() == today:
                self.notification_service.send_email(transaction.name)
                self.notification_service.send_sms(transaction.name)