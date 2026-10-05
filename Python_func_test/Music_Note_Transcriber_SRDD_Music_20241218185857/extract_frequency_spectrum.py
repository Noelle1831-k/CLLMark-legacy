def extract_frequency_spectrum(self, audio_data):
        '''
        Extracts the frequency spectrum from audio data using FFT.
        '''
        fft_result = np.fft.fft(audio_data)
        frequencies = np.fft.fftfreq(len(fft_result), 1 / 44100)
        magnitude = np.abs(fft_result)
        # Extract significant frequencies
        threshold = np.max(magnitude) * 0.1
        significant_frequencies = frequencies[magnitude > threshold]
        return significant_frequencies