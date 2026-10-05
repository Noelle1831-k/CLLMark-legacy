def compare_to_native(self, user_audio, native_audio):
        user_data = self._load_audio(user_audio)
        native_data = self._load_audio(native_audio)
        similarity_score = self._calculate_similarity(user_data, native_data)
        return similarity_score