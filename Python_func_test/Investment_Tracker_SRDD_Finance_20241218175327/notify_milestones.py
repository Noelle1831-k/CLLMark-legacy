def notify_milestones(self):
        for investment in self.investments:
            if investment.check_goal_reached():
                self.notification.send_notification(investment.name)