def classify_mood(self, tempo, key, instrumentation):
        '''
        Classify the mood based on specific features.
        '''
        try:
            if tempo > 120:
                if key > 5:
                    return "Energetic"
                else:
                    return "Happy"
            elif tempo < 60:
                if key < 3:
                    return "Sad"
                else:
                    return "Calm"
            else:
                return "Neutral"
        except Exception as e:
            print(f"Error classifying mood: {e}")
            return "Unknown"