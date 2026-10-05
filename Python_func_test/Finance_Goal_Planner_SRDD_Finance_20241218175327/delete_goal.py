def delete_goal(self, name):
        '''
        Deletes a goal from the system.
        '''
        if name in self.goals:
            del self.goals[name]
            print(f"Goal '{name}' deleted.")
        else:
            print(f"Goal '{name}' does not exist.")