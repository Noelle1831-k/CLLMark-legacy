def generate_recommendations(self, goals):
        '''
        Generates personalized recommendations for each goal based on its type.
        '''
        recommendations = []
        for goal in goals:
            if goal['type'] == 'fitness':
                recommendation = self._generate_fitness_recommendation(goal)
            elif goal['type'] == 'career':
                recommendation = self._generate_career_recommendation(goal)
            elif goal['type'] == 'personal development':
                recommendation = self._generate_personal_development_recommendation(goal)
            else:
                recommendation = f"No specific recommendations available for {goal['name']}."
            recommendations.append(recommendation)
        return recommendations