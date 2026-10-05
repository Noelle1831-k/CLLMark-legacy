def add_goal(self, name, target_amount):
        '''
        Adds a new goal to the system with a specified target amount.
        '''
        if name not in self.goals:
            self.goals[name] = {'target': target_amount, 'current': 0, 'milestones': []}
            print(f"Goal '{name}' added with target amount {target_amount}.")
        else:
            print(f"Goal '{name}' already exists.")