def collect_user_data(self):
        self.fitness_level = input(f"Enter your current fitness level (beginner/intermediate/advanced): ")
        self.target_goals = input(f"Enter your target goals (e.g., weight loss, muscle gain): ")
        self.preferred_exercises = input(f"Enter your preferred exercises (comma-separated): ").split(f",")
        self.time_availability = input(f"Enter your time availability per week (in hours): ")