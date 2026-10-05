def edit_post(self, user_email, post_index, new_content):
        if user_email in self.posts and 0 <= post_index < len(self.posts[user_email]):
            self.posts[user_email][post_index]['content'] = new_content
            print("Post updated.")
        else:
            print("Post not found.")