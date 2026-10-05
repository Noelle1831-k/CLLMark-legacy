def collect_user_data(self):
        self.fitness_level = input("Enter your current fitness level (beginner/intermediate/advanced): ")
        self.target_goals = input("Enter your target goals (e.g., weight loss, muscle gain): ")
        self.preferred_exercises = input("Enter your preferred exercises (comma-separated): ").split(',')
        self.time_availability = input("Enter your time availability per week (in hours): ")