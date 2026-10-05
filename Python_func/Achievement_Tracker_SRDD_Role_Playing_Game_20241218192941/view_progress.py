def view_progress(self):
        for achievement in self.achievements:
            print(f"Achievement: {achievement.name}, Status: {achievement.status}, Deadline: {achievement.deadline}")