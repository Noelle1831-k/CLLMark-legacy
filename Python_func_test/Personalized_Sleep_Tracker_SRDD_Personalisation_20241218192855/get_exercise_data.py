def get_exercise_data(self):
        exercise = input("Enter exercise duration (minutes): ")
        self.data['exercise'] = int(exercise)