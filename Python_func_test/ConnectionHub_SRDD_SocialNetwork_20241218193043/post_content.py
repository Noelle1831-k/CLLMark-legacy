def post_content(self, email, content):
        if email not in self.content_feed:
            self.content_feed[email] = []
        self.content_feed[email].append(content)
        print(f"Content posted by {email}.")