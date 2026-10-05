def generate_plan(self, user_profile):
        user_data = user_profile.get_user_data()
        fitness_level = user_data["fitness_level"]
        preferred_exercises = user_data["preferred_exercises"]
        time_availability = int(user_data["time_availability"])
        exercises_per_day = min(5, time_availability)  # Assuming each exercise takes a fixed amount of time
        plan = {}
        for day in range(1, time_availability + 1):
            daily_exercises = random.sample(self.exercises[fitness_level], max(0, exercises_per_day - len(preferred_exercises)))
            daily_exercises.extend(preferred_exercises)
            plan[day] = daily_exercises[:exercises_per_day]  # Limit to exercises_per_day
        return plan