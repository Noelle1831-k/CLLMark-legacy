def generate_recommendations(self, analysis):
        recommendations = []
        if analysis['average_activity'] < 5:
            recommendations.append("Increase physical activity.")
        if analysis['average_sleep'] < 7:
            recommendations.append("Improve sleep quality.")
        if analysis['average_nutrition'] < 6:
            recommendations.append("Enhance nutrition intake.")
        if analysis['average_stress'] > 5:
            recommendations.append("Reduce stress levels.")
        if analysis['average_mental_health'] < 6:
            recommendations.append("Focus on mental health improvement.")
        return recommendations