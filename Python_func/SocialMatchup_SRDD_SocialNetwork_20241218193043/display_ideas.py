def display_ideas(self):
        for user, ideas in self.ideas.items():
            print(f"{user}'s Ideas:")
            for idea in ideas:
                print(f"- {idea}")