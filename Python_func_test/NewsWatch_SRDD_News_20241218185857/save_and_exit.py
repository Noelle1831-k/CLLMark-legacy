def save_and_exit(self):
        '''
        Saves user data and exits the application.
        '''
        self.database_manager.save_user_data(self.user)
        print("Data saved. Goodbye!")