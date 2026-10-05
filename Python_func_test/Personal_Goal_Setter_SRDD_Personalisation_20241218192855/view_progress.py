def view_progress(self):
        '''
        Displays the progress of a specific goal.
        '''
        goal_id = input("Enter goal ID to view progress: ")
        progress = self.progress_tracker.get_progress(goal_id)
        if not progress:
            print("No progress found.")
        else:
            for update in progress:
                print(update)