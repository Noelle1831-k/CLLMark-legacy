def calculate_score(self, car):
        '''
        Calculates the score based on the car's drift angle and speed.
        The score is influenced by a multiplier that increases with successful drifts.
        '''
        drift_score = car.drift_angle * car.speed * self.multiplier
        self.score += drift_score
        self.combo_counter += 1
        self.update_multiplier()
        self.check_high_score()
        self.log_score(drift_score)