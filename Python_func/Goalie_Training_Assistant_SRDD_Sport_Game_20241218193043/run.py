def run(self):
        '''
        Starts the application loop, continuously simulating shots, tracking positions,
        calculating reaction times, and providing feedback and training drills.
        '''
        print("Starting Ice Hockey Goalie Training Assistance Program...")
        try:
            while True:
                shot = self.shot_simulator.simulate_shot()
                position = self.position_tracker.track_position()
                reaction_time = self.position_tracker.calculate_reaction_time(shot, position)
                self.feedback_system.provide_feedback(shot, position, reaction_time)
                self.feedback_system.generate_training_drills()
                time.sleep(1)
        except KeyboardInterrupt:
            print("Training session ended.")