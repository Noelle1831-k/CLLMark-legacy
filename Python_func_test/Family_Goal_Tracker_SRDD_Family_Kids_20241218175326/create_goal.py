def create_goal(self, title, description):
        goal = Goal(title, description)
        self.goals.append(goal)