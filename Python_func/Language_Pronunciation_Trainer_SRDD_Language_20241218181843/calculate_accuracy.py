def calculate_accuracy(self, feature_value, ideal_value):
        '''
        Calculates the accuracy of a given feature compared to its ideal value.
        Arguments:
        feature_value -- The actual feature value extracted from the user's audio.
        ideal_value -- The ideal feature value for comparison.
        Returns:
        An accuracy score between 0 and 1.
        '''
        print(f"Calculating accuracy for feature value: {feature_value} against ideal value: {ideal_value}")
        # Use a simple similarity measure (e.g., inverse of Euclidean distance)
        if isinstance(feature_value, np.ndarray):
            distance = np.linalg.norm(feature_value - ideal_value)
        else:
            distance = abs(feature_value - ideal_value)
        # Normalize distance to an accuracy score
        accuracy = max(0, 1 - distance / (np.linalg.norm(ideal_value) + 1e-5))
        print(f"Calculated accuracy: {accuracy:.2f}")
        return accuracy