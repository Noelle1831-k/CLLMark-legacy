def display_plan(self):
        plan = self.get_plan()
        for exercise in plan:
            print(f"Exercise: {exercise['name']}, Sets: {exercise['sets']}, Reps: {exercise['reps']}, Tips: {exercise['tips']}", flush=True)