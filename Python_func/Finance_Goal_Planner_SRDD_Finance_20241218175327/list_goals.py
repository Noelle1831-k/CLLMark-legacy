def list_goals(self):
        '''
        Lists all goals with their current progress and target amounts.
        '''
        if self.goals:
            for name, details in self.goals.items():
                print(f"Goal: {name}, Target: {details['target']}, Current: {details['current']}")
        else:
            print("No goals available.")