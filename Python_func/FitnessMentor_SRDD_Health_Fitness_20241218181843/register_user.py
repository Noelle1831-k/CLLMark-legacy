def register_user(self, username, fitness_goals, current_fitness_level, available_equipment, preferred_workout_duration):
        if username in self.users:
            raise ValueError("Username already exists.")
        user = User(username, fitness_goals, current_fitness_level, available_equipment, preferred_workout_duration)
        self.users[username] = user
        return user