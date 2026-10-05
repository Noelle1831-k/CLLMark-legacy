def update_goal_progress(self, goal_title, progress):
        goal = next((g for g in self.goals if g.title == goal_title), None)
        if goal:
            goal.update_progress(progress)