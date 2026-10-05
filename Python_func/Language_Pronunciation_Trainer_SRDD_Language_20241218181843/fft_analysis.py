def fft_analysis(self, audio_signal):
        '''
        Perform Fast Fourier Transform (FFT) analysis on the audio signal.
        Arguments:
        audio_signal -- The processed audio signal.
        Returns:
        Frequency spectrum and the magnitude spectrum.
        '''
        print("Performing FFT analysis...")
        # Apply FFT on the audio signal
        n = len(audio_signal)
        fft_result = fft(audio_signal)
        # Calculate the frequency bins
        freqs = np.fft.fftfreq(n, d=1/self.sample_rate)
        # Calculate the magnitude spectrum
        magnitude_spectrum = np.abs(fft_result)
        return freqs, magnitude_spectrum