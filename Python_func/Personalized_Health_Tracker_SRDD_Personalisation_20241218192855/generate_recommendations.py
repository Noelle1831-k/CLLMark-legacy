def generate_recommendations(self):
        '''
        Provide personalized health recommendations.
        '''
        bmi = self.calculate_bmi()
        recommendations = []
        if bmi < 18.5:
            recommendations.append("Increase calorie intake to gain weight.")
        elif 18.5 <= bmi < 24.9:
            recommendations.append("Maintain current diet and exercise routine.")
        else:
            recommendations.append("Consider a calorie deficit diet to lose weight.")
        if self.user.activity_level == 'low':
            recommendations.append("Increase daily physical activity.")
        elif self.user.activity_level == 'high':
            recommendations.append("Ensure adequate rest and recovery.")
        return recommendations