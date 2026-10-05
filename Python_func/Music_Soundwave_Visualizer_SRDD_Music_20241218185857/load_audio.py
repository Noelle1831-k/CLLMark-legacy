def load_audio(self, file_path):
        try:
            audio = AudioSegment.from_file(file_path)
            samples = np.array(audio.get_array_of_samples())
            self.audio_data = samples / (2**15)  # Normalize audio data
        except Exception as e:
            print(f"Error loading audio file: {e}")
            self.audio_data = None