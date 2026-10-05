def summarize_confidence(self, confidence_score, confidence_level):
        '''
        Summarizes the confidence score and level for user interpretation.
        Parameters:
            confidence_score (float): Confidence score as a percentage.
            confidence_level (str): Description of confidence level.
        Returns:
            summary (str): Summary statement of confidence.
        '''
        return f"The prediction has a confidence score of {confidence_score:.2f}% indicating a {confidence_level} in the genre classification."