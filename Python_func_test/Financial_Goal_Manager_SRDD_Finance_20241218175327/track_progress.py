def track_progress(self, name, amount_saved):
        goal = self.goal_manager.find_goal(name)
        if goal:
            goal['progress'] = (amount_saved / goal['amount']) * 100