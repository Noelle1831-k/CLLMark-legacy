def compare_users_progress(self, user_name1, user_name2, category):
        '''
        Compares the progress of two users in a specific category.
        Parameters:
        - user_name1: The name of the first user.
        - user_name2: The name of the second user.
        - category: The category for which progress is compared.
        '''
        user1 = self.get_user(user_name1)
        user2 = self.get_user(user_name2)
        if user1 and user2:
            user1_data = user1.get_progress(category)
            user2_data = user2.get_progress(category)
            if user1_data and user2_data:
                self.visualization.compare_progress(user1_data, user2_data, f"{user_name1}'s {category}", f"{user_name2}'s {category}")
            else:
                print(f"Insufficient progress data for comparison in category '{category}'.")
        else:
            print(f"One or both users '{user_name1}' or '{user_name2}' not found.")