def run(self):
        user_data = self.collect_user_data()
        self.data_storage.store_data(user_data)
        mood_analysis = self.mood_analyzer.analyze_mood(user_data)
        recommendations = self.recommendation_engine.generate_recommendations(mood_analysis)
        self.display_recommendations(recommendations)