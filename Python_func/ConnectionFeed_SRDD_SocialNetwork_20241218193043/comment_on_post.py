def comment_on_post(self, user_email, post_index, comment):
        if user_email in self.posts and 0 <= post_index < len(self.posts[user_email]):
            self.posts[user_email][post_index]['comments'].append(comment)
            print("Comment added.")
        else:
            print("Post not found.")