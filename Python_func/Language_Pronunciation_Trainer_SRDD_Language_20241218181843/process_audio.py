def process_audio(self, audio_data):
        '''
        Processes the raw audio data by applying a bandpass filter.
        Arguments:
        audio_data -- The raw audio data as a byte string or array of integers.
        Returns:
        Processed audio data after applying bandpass filtering.
        '''
        print("Processing audio data...")
        # Convert byte data to numpy array (assuming 16-bit PCM)
        audio_signal = np.frombuffer(audio_data, dtype=np.int16)
        # Normalize audio data to float
        audio_signal = audio_signal / 32768.0
        # Apply bandpass filter to the audio signal
        processed_audio = self.bandpass_filter(audio_signal)
        return processed_audio