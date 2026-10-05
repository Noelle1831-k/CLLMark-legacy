def check_goal(self):
        for goal in self.goals:
            if goal.is_achieved():
                print(f"Goal achieved: {goal.target_amount} by {goal.deadline}")