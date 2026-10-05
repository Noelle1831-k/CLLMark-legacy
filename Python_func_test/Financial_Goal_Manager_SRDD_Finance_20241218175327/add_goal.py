def add_goal(self, name, amount, deadline):
        goal = {'name': name, 'amount': amount, 'deadline': deadline, 'progress': 0}
        self.goals.append(goal)