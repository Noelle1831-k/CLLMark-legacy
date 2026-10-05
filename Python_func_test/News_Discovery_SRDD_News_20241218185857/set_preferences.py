def set_preferences(self):
        '''
        Sets user preferences based on input.
        '''
        print("Setting user preferences...")
        self.preferences["categories"] = self._get_user_input("Enter preferred categories (comma-separated): ")
        self.preferences["sources"] = self._get_user_input("Enter preferred news sources (comma-separated): ")
        self.preferences["notification_frequency"] = self._get_user_input("Enter notification frequency (daily/weekly/monthly): ")
        print("Preferences updated successfully.")