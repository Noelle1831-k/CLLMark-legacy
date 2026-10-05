def create_workout_plan(self, username):
        user = self.login_user(username)
        workout_plan = WorkoutPlan(user, self.exercise_library)
        workout_plan.generate_plan()
        return workout_plan