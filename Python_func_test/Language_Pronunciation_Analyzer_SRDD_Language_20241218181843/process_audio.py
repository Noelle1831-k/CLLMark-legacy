def process_audio(self):
        self.processed_audio = utils.normalize_audio(self.audio_data)
        self.features = utils.extract_features(self.processed_audio, self.audio_rate)