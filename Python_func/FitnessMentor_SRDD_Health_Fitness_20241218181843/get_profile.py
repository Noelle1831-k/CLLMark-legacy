def get_profile(self):
        return {
            "username": self.username,
            "fitness_goals": self.fitness_goals,
            "current_fitness_level": self.current_fitness_level,
            "available_equipment": self.available_equipment,
            "preferred_workout_duration": self.preferred_workout_duration
        }