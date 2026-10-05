def list_goals(self):
        '''
        Lists all goals currently in the tracker, along with their progress.
        '''
        if not self.goals:
            print("No goals are currently being tracked.")
        else:
            for goal in self.goals:
                print(f"Goal: {goal.name}, Progress: {goal.progress}%")