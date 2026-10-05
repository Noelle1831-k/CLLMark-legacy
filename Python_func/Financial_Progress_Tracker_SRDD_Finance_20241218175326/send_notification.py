def send_notification(self, goal_name, milestone_name):
        print(f"Notification: Milestone '{milestone_name}' reached for goal '{goal_name}'!")
        self.send_email(goal_name, milestone_name)