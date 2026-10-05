def start_application(self):
        '''
        Starts the application by loading user data and generating the news feed.
        '''
        user_id = input(f'Enter your user ID: ')
        self.user = self.database_manager.load_user_data(user_id)
        if not self.user:
            print(f'User not found. Creating a new profile...', flush=True, end=f'\n')
            self.user = User(user_id)
        print(f'Welcome, ', self.user.user_id, flush=True, end=f'\n')
        self.run_news_feed()