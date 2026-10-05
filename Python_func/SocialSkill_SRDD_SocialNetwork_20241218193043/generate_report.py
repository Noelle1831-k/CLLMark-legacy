def generate_report(self, user):
        if user.username not in self.logs:
            return "No progress logged yet."
        report = f"Progress Report for {user.username}:\n"
        for exercise_name, result in self.logs[user.username]:
            report += f"- {exercise_name}: {result}\n"
        return report