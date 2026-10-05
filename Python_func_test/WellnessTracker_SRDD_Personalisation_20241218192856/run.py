def run(self):
        self.user_profile.add_wellness_data()
        data = self.user_profile.get_wellness_data()
        analysis = self.data_analyzer.analyze_data(data)
        recommendations = self.recommendation_engine.generate_recommendations(analysis)
        self.dashboard.display_dashboard(data, analysis, recommendations)