def start_application(self):
        '''
        Starts the application by loading user data and generating the news feed.
        '''
        user_id = input("Enter your user ID: ")
        self.user = self.database_manager.load_user_data(user_id)
        if not self.user:
            print("User not found. Creating a new profile...")
            self.user = User(user_id)
        print("Welcome, ", self.user.user_id)
        self.run_news_feed()