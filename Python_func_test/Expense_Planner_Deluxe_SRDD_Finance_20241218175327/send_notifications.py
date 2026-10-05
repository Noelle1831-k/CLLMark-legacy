def send_notifications(self):
        self.bill_manager.send_reminder()
        total_expenses = self.calculate_total_expenses()
        allocated_budget = self.user.income - self.user.savings_goal
        if total_expenses > allocated_budget:
            self.notification_system.send_alert("Budget deviation detected.")
        else:
            self.notification_system.send_alert("You are within your budget.")