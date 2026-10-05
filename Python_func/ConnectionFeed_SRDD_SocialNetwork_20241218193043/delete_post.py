def delete_post(self, user_email, post_index):
        if user_email in self.posts and 0 <= post_index < len(self.posts[user_email]):
            del self.posts[user_email][post_index]
            print("Post deleted.")
        else:
            print("Post not found.")