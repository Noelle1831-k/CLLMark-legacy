def calculate_confidence(self, probabilities):
        '''
        Calculates the confidence score of the genre prediction.
        Parameters:
            probabilities (np.ndarray): Array of probabilities for each genre.
        Returns:
            confidence_score (float): Confidence score as a percentage.
            confidence_level (str): Description of confidence level.
        '''
        max_prob = np.max(probabilities)
        confidence_score = max_prob * 100  # Convert to percentage
        confidence_level = self._determine_confidence_level(max_prob)
        return confidence_score, confidence_level