def calculate_zero_crossing_rate(self, audio_signal):
        '''
        Calculates the zero-crossing rate from the audio signal.
        Arguments:
        audio_signal -- The processed audio signal.
        Returns:
        Zero-crossing rate value.
        '''
        print("Calculating zero-crossing rate...")
        zero_crossing_rate = librosa.feature.zero_crossing_rate(y=audio_signal)
        # Return the average zero-crossing rate
        return np.mean(zero_crossing_rate)