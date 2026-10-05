def _calculate_similarity(self, user_data, native_data):
        min_length = min(len(user_data), len(native_data))
        user_data = user_data[:min_length]
        native_data = native_data[:min_length]
        return np.dot(user_data, native_data) / (np.linalg.norm(user_data) * np.linalg.norm(native_data))