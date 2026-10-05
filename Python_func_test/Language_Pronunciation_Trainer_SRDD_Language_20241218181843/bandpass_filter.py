def bandpass_filter(self, audio_signal):
        '''
        Applies a bandpass filter to the audio signal.
        Arguments:
        audio_signal -- The raw audio signal to filter.
        Returns:
        Filtered audio signal.
        '''
        print(f"Applying bandpass filter with lowcut {self.lowcut} Hz and highcut {self.highcut} Hz...")
        nyquist = 0.5 * self.sample_rate
        low = self.lowcut / nyquist
        high = self.highcut / nyquist
        b, a = signal.butter(self.filter_order, [low, high], btype='band')
        filtered_signal = signal.lfilter(b, a, audio_signal)
        return filtered_signal