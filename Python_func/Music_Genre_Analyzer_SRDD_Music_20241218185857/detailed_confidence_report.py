def detailed_confidence_report(self, probabilities):
        '''
        Provides a detailed report of confidence scores for each genre.
        Parameters:
            probabilities (np.ndarray): Array of probabilities for each genre.
        Returns:
            report (dict): Dictionary containing confidence scores for each genre.
        '''
        report = {}
        for genre, prob in zip(self._get_genre_labels(), probabilities):
            report[genre] = {
                'Probability': prob,
                'Confidence Score': prob * 100,
                'Confidence Level': self._determine_confidence_level(prob)
            }
        return report