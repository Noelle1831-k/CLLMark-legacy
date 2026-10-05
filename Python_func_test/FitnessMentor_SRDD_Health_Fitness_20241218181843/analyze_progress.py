def analyze_progress(self):
        total_workouts = len(self.workout_history)
        total_exercises = sum(len(workout) for workout in self.workout_history)
        return {
            "total_workouts": total_workouts,
            "total_exercises": total_exercises,
            "average_exercises_per_workout": total_exercises / total_workouts if total_workouts > 0 else 0
        }