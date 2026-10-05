def start_training(self):
        self.training_session = training_session.TrainingSession(self.current_sport)
        while True:
            shot_result = input("Enter shot result (hit/miss) or 'exit' to finish: ").strip().lower()
            if shot_result == "exit":
                break
            elif shot_result in ["hit", "miss"]:
                shot_instance = shot.Shot(shot_result, self.current_sport)
                self.training_session.track_shot(shot_instance)
                feedback_instance = feedback.Feedback(shot_instance)
                feedback_instance.give_feedback()
            else:
                print("Invalid input. Please enter 'hit', 'miss', or 'exit'.")
        self.training_session.generate_report()