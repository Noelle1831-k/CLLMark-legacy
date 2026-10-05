def update_goal(self, name, target_amount):
        '''
        Updates an existing goal's target amount.
        '''
        if name in self.goals:
            self.goals[name]['target'] = target_amount
            print(f"Goal '{name}' updated with new target amount {target_amount}.")
        else:
            print(f"Goal '{name}' does not exist.")