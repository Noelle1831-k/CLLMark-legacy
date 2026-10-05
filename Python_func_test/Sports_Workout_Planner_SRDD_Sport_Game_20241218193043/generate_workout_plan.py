def generate_workout_plan(self):
        # Example workout plan generation logic based on sport and goals
        if self.sport.lower() == "basketball":
            self.workout_plan.add_exercise("Squats", 3, 12)
            self.workout_plan.add_exercise("Push-ups", 3, 15)
            self.workout_plan.add_exercise("Jumping Jacks", 3, 20)
        elif self.sport.lower() == "swimming":
            self.workout_plan.add_exercise("Flutter Kicks", 4, 15)
            self.workout_plan.add_exercise("Planks", 3, 60)  # seconds
        # Additional sports and exercises can be added here