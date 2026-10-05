def check_budget_limits(self):
        total_expenses = sum(item['amount'] for item in self.user_data['expenses'])
        if total_expenses > self.user_data['budget_goal']:
            self.notification_manager.send_notification(total_expenses, self.user_data['budget_goal'])