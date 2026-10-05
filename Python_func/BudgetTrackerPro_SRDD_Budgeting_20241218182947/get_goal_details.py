def get_goal_details(self):
        return {
            "goal_name": self.goal_name,
            "goal_description": self.goal_description,
            "goal_amount": self.goal_amount,
            "current_amount": self.current_amount,
            "goal_deadline": self.goal_deadline,
            "goal_progress": self.goal_progress
        }