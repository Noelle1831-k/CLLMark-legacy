def input_user_progress(self, user_name, category, progress):
        '''
        Inputs daily progress for a specific user and category.
        Parameters:
        - user_name: The name of the user.
        - category: The category for which progress is input.
        - progress: The progress value to input.
        '''
        user = self.get_user(user_name)
        if user:
            user.input_progress(category, progress)
        else:
            print(f"User '{user_name}' not found.")