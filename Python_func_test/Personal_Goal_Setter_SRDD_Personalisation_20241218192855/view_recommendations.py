def view_recommendations(self):
        '''
        Displays personalized recommendations for the user's goals.
        '''
        goals = self.goal_manager.get_goals()
        recommendations = self.recommendation_engine.generate_recommendations(goals)
        if not recommendations:
            print("No recommendations available.")
        else:
            for recommendation in recommendations:
                print(recommendation)