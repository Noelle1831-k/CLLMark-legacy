def create_post(self, user_email, content):
        if user_email not in self.posts:
            self.posts[user_email] = []
        self.posts[user_email].append({'content': content, 'likes': 0, 'comments': []})
        print(f"Post created by {user_email}.")