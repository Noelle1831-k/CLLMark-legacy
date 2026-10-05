def track_goal(self, goal_name):
        goal = self.goals.get(goal_name)
        if goal:
            return f"Goal: {goal_name}, Amount: ${goal['amount']}, Saved: ${goal['saved']}, Deadline: {goal['deadline']}"
        return "Goal not found"