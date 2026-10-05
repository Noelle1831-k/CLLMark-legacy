def generate_plan(self):
        '''
        Generate a workout plan based on user profile and available exercises.
        '''
        available_exercises = [exercise for exercise in self.exercises if set(exercise.equipment_needed).issubset(set(self.user.equipment))]
        self.plan = random.sample(available_exercises, min(len(available_exercises), self.user.workout_duration // 5))