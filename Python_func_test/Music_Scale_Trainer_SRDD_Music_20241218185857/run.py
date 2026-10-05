def run(self):
        self.load_resources()
        self.user_manager.create_profile()
        while True:
            exercise = self.exercise_manager.generate_exercise()
            response = self.get_user_response()
            feedback = self.exercise_manager.evaluate_response(exercise, response)
            print(feedback)
            self.user_manager.track_progress()