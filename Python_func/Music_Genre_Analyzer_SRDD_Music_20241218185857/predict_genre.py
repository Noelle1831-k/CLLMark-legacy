def predict_genre(self, features):
        features_scaled = self.scaler.transform([features])
        probabilities = self.model.predict_proba(features_scaled)[0]
        genre_index = np.argmax(probabilities)
        genre = self.model.classes_[genre_index]
        return genre, probabilities