def run(self):
        '''
        Runs the main loop of the application.
        '''
        self.exercise_manager.load_exercises()
        while True:
            exercise = self.exercise_manager.get_exercise()
            if not exercise:
                break
            exercise.start()
            self.audio_recorder.start_recording()
            # Simulate user speaking
            self.audio_recorder.stop_recording()
            audio_data = self.audio_recorder.save_audio()
            processed_audio = self.audio_processor.process_audio(audio_data)
            features = self.audio_processor.extract_features(processed_audio)
            analysis = self.feedback_analyzer.analyze(features)
            self.feedback_analyzer.provide_feedback(analysis)