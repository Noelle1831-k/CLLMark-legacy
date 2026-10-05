def give_feedback(self, email, recipe_title, feedback):
        if recipe_title not in self.feedback:
            self.feedback[recipe_title] = []
        self.feedback[recipe_title].append({"author": email, "feedback": feedback})
        print(f"Feedback given on recipe '{recipe_title}' by {email}.")