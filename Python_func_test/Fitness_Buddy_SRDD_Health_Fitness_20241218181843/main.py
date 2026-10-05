def main():
    '''
    Main function to run the Fitness Buddy application.
    '''
    exercise_library = load_exercise_library()
    user = User(name="John Doe", age=30, weight=70, height=175, fitness_level="Intermediate", goals="Build Muscle", equipment=["Dumbbells"], workout_duration=45)
    workout_plan = WorkoutPlan(user=user, exercises=exercise_library)
    tracker = Tracker(user=user)
    workout_plan.generate_plan()
    tracker.log_workout(workout_plan.get_plan())
    save_user_data(user)