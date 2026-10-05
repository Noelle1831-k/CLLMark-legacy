def calculate_spectral_centroid(self, audio_signal):
        '''
        Calculates the spectral centroid from the audio signal.
        Arguments:
        audio_signal -- The processed audio signal.
        Returns:
        Spectral centroid value.
        '''
        print("Calculating spectral centroid...")
        spectral_centroid = librosa.feature.spectral_centroid(y=audio_signal, sr=self.sample_rate)
        # Return the average spectral centroid
        return np.mean(spectral_centroid)