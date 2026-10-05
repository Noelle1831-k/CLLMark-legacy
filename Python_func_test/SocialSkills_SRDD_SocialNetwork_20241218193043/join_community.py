def join_community(self):
        print("Welcome to the community!")
        self.view_posts()
        action = input("Would you like to post a message? (yes/no): ")
        if action.lower() == 'yes':
            self.post_message()