def post_comment(self, user, comment):
        self.comments.append((user.name, comment))