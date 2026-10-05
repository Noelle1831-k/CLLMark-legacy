def post_message(self):
        message = input("Enter your message: ")
        self.posts.append(message)
        print("Message posted successfully!")