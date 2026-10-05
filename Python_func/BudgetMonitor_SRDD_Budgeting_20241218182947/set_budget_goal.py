def set_budget_goal(self, goal):
        self.user_data['budget_goal'] = goal
        print(f"Budget goal set to: {format_currency(goal)}")