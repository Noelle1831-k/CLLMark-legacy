def visualize_progress(self, user_name, category):
        '''
        Visualizes the progress of a user in a specific category.
        Parameters:
        - user_name: The name of the user whose progress is to be visualized.
        - category: The category of the habit to visualize.
        '''
        user = self.get_user(user_name)
        if user:
            progress_data = user.get_progress(category)
            if progress_data:
                self.visualization.plot_progress(progress_data, category)
            else:
                print(f"No progress data found for category '{category}'.")
        else:
            print(f"User '{user_name}' not found.")