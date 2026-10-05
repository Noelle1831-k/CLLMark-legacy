def track_goals(self):
        progress = self.user.income - sum([cat.budget for cat in self.categories])
        if progress < self.user.savings_goal:
            self.notification_system.send_alert("You are on track with your savings goal.")
        else:
            self.notification_system.send_alert("You need to adjust your spending to meet your savings goal.")