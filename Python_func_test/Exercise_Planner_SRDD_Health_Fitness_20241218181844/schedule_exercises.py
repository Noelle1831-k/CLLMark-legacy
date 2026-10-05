def schedule_exercises(self):
        for i, exercise in enumerate(self.exercise_plan.get_plan()):
            self.schedule.append(f'Day {i+1}: {exercise.get_exercise_info()}')