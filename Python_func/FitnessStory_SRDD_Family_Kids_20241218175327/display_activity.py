def display_activity(self, activity):
        '''
        Display the activity details to the user.
        Parameters:
        activity (Activity): The activity object containing name, instructions, and demo URL.
        '''
        self.display_message(f"Activity: {activity.get_name()}")
        self.display_message(activity.get_instructions())