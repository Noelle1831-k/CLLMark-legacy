def set_goals(self, investment_name, goal_amount):
        for investment in self.investments:
            if investment.name == investment_name:
                investment.set_goal(goal_amount)