def generate_progress_bar(self, goal_name, progress_percentage):
        '''
        Generates and displays a progress bar based on the current progress percentage.
        '''
        bar_length = 50  # Length of the progress bar
        filled_length = int(progress_percentage / 2)  # Calculate how many blocks should be filled
        bar = '#' * filled_length + '-' * (bar_length - filled_length)  # Create the progress bar
        print(f"Progress bar for '{goal_name}': [{bar}] {progress_percentage:.2f}%")