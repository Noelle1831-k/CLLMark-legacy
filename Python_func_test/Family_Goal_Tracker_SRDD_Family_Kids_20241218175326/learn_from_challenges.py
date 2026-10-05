def learn_from_challenges(self):
        for goal in self.goals:
            if not goal.is_completed():
                print(f"Reviewing challenges for goal '{goal.title}'.")