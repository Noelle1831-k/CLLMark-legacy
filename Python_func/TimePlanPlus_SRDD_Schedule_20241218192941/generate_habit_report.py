def generate_habit_report(self):
        print("Generating habit report...")
        if not self.habit_tracker.habits:
            print("No habits to report.")
        else:
            for habit, details in self.habit_tracker.habits.items():
                print(f"Habit: {habit}, Progress: {details['progress']}%")