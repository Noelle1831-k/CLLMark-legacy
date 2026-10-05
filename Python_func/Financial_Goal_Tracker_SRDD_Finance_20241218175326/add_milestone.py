def add_milestone(self, amount):
        '''
        Adds a milestone to the goal. Allows adding milestones less than or equal to the target amount.
        '''
        if amount <= self.target_amount:
            self.milestones.append(amount)
        else:
            print(f"Error: Milestone {amount} exceeds target amount of {self.target_amount}.")