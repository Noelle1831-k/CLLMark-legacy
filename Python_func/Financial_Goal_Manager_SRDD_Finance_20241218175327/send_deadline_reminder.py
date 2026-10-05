def send_deadline_reminder(self, name):
        goal = self.goal_manager.find_goal(name)
        if goal:
            deadline_date = datetime.strptime(goal['deadline'], '%Y-%m-%d')
            days_remaining = (deadline_date - datetime.now()).days
            if days_remaining <= 7:
                print(f"Reminder: Deadline for {name} is approaching in {days_remaining} days!")