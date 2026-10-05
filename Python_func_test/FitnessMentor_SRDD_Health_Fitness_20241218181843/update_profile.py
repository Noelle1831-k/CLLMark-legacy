def update_profile(self, fitness_goals=None, current_fitness_level=None, available_equipment=None, preferred_workout_duration=None):
        if fitness_goals:
            self.fitness_goals = fitness_goals
        if current_fitness_level:
            self.current_fitness_level = current_fitness_level
        if available_equipment:
            self.available_equipment = available_equipment
        if preferred_workout_duration:
            self.preferred_workout_duration = preferred_workout_duration