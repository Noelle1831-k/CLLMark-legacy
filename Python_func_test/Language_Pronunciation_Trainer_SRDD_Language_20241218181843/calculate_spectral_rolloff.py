def calculate_spectral_rolloff(self, audio_signal):
        '''
        Calculates the spectral roll-off from the audio signal.
        Arguments:
        audio_signal -- The processed audio signal.
        Returns:
        Spectral roll-off value.
        '''
        print("Calculating spectral roll-off...")
        spectral_rolloff = librosa.feature.spectral_rolloff(y=audio_signal, sr=self.sample_rate, rolloff=0.85)
        # Return the average spectral roll-off
        return np.mean(spectral_rolloff)