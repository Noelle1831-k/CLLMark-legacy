def display_tutorials(self, workout_plan):
        for day, exercises in workout_plan.items():
            print(f"Day {day} Video Tutorials:")
            for exercise in exercises:
                if exercise in self.video_library:
                    print(f"Watch {exercise} tutorial: {self.video_library[exercise]}")