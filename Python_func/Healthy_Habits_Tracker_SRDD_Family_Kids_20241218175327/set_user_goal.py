def set_user_goal(self, user_name, category, goal):
        '''
        Sets a goal for a specific user and category.
        Parameters:
        - user_name: The name of the user.
        - category: The category for which the goal is set.
        - goal: The goal description.
        '''
        user = self.get_user(user_name)
        if user:
            user.set_goal(category, goal)
        else:
            print(f"User '{user_name}' not found.")