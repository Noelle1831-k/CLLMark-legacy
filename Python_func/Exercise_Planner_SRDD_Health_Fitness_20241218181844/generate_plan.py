def generate_plan(self, exercises):
        for exercise in exercises:
            if self.user.get_goals() == "weight loss" and exercise.difficulty != "Advanced":
                self.plan.append(exercise)
            elif self.user.get_goals() == "muscle gain" and exercise.difficulty != "Beginner":
                self.plan.append(exercise)
            elif self.user.get_goals() == "overall fitness improvement":
                self.plan.append(exercise)