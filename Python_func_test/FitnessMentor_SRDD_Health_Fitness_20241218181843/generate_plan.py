def generate_plan(self):
        # Generate a workout plan based on user preferences
        for exercise in self.exercise_library:
            if self.user.current_fitness_level == "Beginner" and exercise.muscle_group in ["Chest", "Legs"]:
                self.exercises.append(exercise)
            elif self.user.current_fitness_level == "Intermediate" and exercise.muscle_group in ["Back", "Arms"]:
                self.exercises.append(exercise)
            elif self.user.current_fitness_level == "Advanced":
                self.exercises.append(exercise)
        random.shuffle(self.exercises)