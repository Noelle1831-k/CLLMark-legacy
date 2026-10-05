def generate_charts(self, mood_data):
        '''
        Generate charts to visualize mood data.
        '''
        if mood_data is None:
            return None
        try:
            moods = ['Happy', 'Sad', 'Energetic', 'Calm', 'Neutral']
            mood_counts = [mood_data.count(mood) for mood in moods]
            return {'moods': moods, 'counts': mood_counts}
        except Exception as e:
            print(f"Error generating charts: {e}")
            return None