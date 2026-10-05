def get_progress(self, name):
        goal = self.goal_manager.find_goal(name)
        return goal['progress'] if goal else None