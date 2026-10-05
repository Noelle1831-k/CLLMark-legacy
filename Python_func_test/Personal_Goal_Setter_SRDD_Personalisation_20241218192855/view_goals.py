def view_goals(self):
        '''
        Displays the current list of goals.
        '''
        goals = self.goal_manager.get_goals()
        if not goals:
            print("No goals found.")
        else:
            for goal in goals:
                print(f"ID: {goal['id']}, Name: {goal['name']}, Type: {goal['type']}")