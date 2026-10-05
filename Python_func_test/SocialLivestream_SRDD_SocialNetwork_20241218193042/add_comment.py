def add_comment(self, livestream, user, comment):
        if livestream.is_live:
            self.comments.append({"user": user.name, "comment": comment})
            print(f"{user.name} commented: {comment}")