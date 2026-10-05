def generate_feedback(self):
        username = input("Enter username for feedback: ")
        if username in self.user_manager.users:
            progress = self.user_manager.users[username]['progress']
            goals = self.user_manager.users[username]['goals']
            feedback = f"Progress: {progress}%. Goals: {', '.join(goals)}. Keep up the good work!"
            print(f"Feedback for {username}: {feedback}")
        else:
            print("User not found.")