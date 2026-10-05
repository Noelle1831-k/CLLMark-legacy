def _determine_confidence_level(self, max_prob):
        '''
        Determines the confidence level based on the maximum probability.
        Parameters:
            max_prob (float): Maximum probability value.
        Returns:
            confidence_level (str): Description of confidence level.
        '''
        if max_prob >= self.threshold:
            return "High Confidence"
        elif max_prob >= 0.5:
            return "Moderate Confidence"
        else:
            return "Low Confidence"