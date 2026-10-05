def check_goal_status(self, balance):
        if balance >= self.target_amount:
            return "Goal Achieved"
        else:
            return "Goal Not Achieved"