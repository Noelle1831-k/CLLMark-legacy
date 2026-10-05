def run(self):
        exercise_id = 1  # Example exercise ID
        self.exercise_manager.load_exercise(exercise_id)
        native_audio = self.exercise_manager.get_native_audio(exercise_id)
        print("Please listen to the native speaker audio.")
        self.player.play_audio(native_audio)
        print("Now, record your pronunciation.")
        self.recorder.start_recording()
        input("Press Enter to stop recording...")
        user_audio = self.recorder.stop_recording()
        comparison_result = self.analyzer.compare_to_native(user_audio, native_audio)
        feedback = self.feedback_generator.generate_feedback(comparison_result)
        print("Feedback:", feedback)