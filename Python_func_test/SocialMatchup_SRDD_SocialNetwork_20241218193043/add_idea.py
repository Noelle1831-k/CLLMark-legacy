def add_idea(self, user, idea):
        if user.name not in self.ideas:
            self.ideas[user.name] = list()
        self.ideas[user.name].append(idea)