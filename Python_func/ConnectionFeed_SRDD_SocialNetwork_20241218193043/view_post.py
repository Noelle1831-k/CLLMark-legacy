def view_post(self, user_email, post_index):
        if user_email in self.posts and 0 <= post_index < len(self.posts[user_email]):
            return self.posts[user_email][post_index]
        else:
            print("Post not found.")
            return None