def get_plan_summary(self):
        summary = f"Exercise Plan for {self.user.name}:\n"
        for exercise in self.plan:
            summary += exercise.get_exercise_info() + "\n"
        return summary