def visualize_audio_features(self, audio_signal, features):
        '''
        Visualizes the audio signal and its extracted features.
        Arguments:
        audio_signal -- The processed audio signal.
        features -- The dictionary containing extracted features.
        Returns:
        None
        '''
        print("Visualizing audio features...")
        plt.figure(figsize=(12, 8))
        # Plot the audio waveform
        plt.subplot(2, 1, 1)
        librosa.display.waveshow(audio_signal, sr=self.sample_rate)
        plt.title("Audio Waveform")
        # Plot the MFCCs
        plt.subplot(2, 1, 2)
        librosa.display.specshow(features['mfcc'], x_axis='time', sr=self.sample_rate)
        plt.title("MFCCs")
        plt.colorbar()
        plt.tight_layout()
        plt.show()