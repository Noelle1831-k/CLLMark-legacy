def calculate_mfcc(self, audio_signal):
        '''
        Calculates Mel-Frequency Cepstral Coefficients (MFCCs) from the audio signal.
        Arguments:
        audio_signal -- The processed audio signal.
        Returns:
        A numpy array of MFCC features.
        '''
        print("Calculating MFCCs...")
        # Use librosa to extract MFCCs from the processed audio signal
        mfccs = librosa.feature.mfcc(y=audio_signal, sr=self.sample_rate, n_mfcc=self.n_mfcc)
        # Return the average MFCCs across the frames
        mfcc_mean = np.mean(mfccs, axis=1)
        return mfcc_mean