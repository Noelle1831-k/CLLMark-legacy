def display_progress_bar(self, goal):
        '''
        Displays a progress bar showing the current progress of the goal.
        '''
        progress = int(goal.get_progress_percentage())
        progress_bar = f"[{'#' * progress}{'.' * (100 - progress)}] {progress}%"
        print(f"Progress for {goal.name}: {progress_bar}")