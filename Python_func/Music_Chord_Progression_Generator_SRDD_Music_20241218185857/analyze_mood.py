def analyze_mood(self, mood):
        mood_map = {
            'happy': ['maj', 'maj7', '6'],
            'sad': ['min', 'min7', 'dim'],
            'jazz': ['maj7', 'min7', '7', '9']
        }
        return mood_map.get(mood, ['maj'])