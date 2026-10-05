def update_progress(self, amount):
        '''
        Updates the current progress of the financial goal. Calculates progress percentage 
        and checks if any milestones are reached.
        '''
        if amount < 0:
            print("Error: Cannot update with negative progress.")
            return
        self.current_amount += amount
        self.progress = self.get_progress_percentage()
        self.check_milestones()