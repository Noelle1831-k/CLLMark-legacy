def set_goal(self, amount, name="", description="", deadline=None):
        self.goal_amount = amount
        self.goal_name = name
        self.goal_description = description
        self.goal_deadline = deadline
        self.goal_progress = []
        print(f"Goal '{self.goal_name}' set with amount: {self.goal_amount}")