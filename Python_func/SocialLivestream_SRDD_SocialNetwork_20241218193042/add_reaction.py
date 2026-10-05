def add_reaction(self, livestream, user, reaction):
        if livestream.is_live:
            self.reactions.append({"user": user.name, "reaction": reaction})
            print(f"{user.name} reacted with: {reaction}")