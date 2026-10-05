def add_activity(self, name, category, interest_level):
        '''
        Adds an activity to the destination's list of activities.
        Args:
            name (str): The name of the activity.
            category (str): The category of the activity (e.g., culture, adventure).
            interest_level (int): The required interest level for the activity.
        '''
        if 0 <= interest_level <= 5:  # Validate interest level
            activity = Activity(name, category, interest_level)
            self.activities.append(activity)
        else:
            print(f"Invalid interest level for activity {name}. Must be between 0 and 5.")