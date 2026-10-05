def get_tips(self, exercise_name):
        return self.exercise_tips.get(exercise_name, f'No tips available for this exercise.')