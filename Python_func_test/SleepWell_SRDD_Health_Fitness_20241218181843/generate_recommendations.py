def generate_recommendations(self, user):
        recommendations = []
        if user.caffeine_intake > 1:
            recommendations.append("Reduce caffeine intake")
        if user.screen_time > 60:
            recommendations.append("Reduce screen time before bed")
        if user.age > 30:
            recommendations.append("Consider a consistent sleep schedule")
        self.recommendations[user.name] = recommendations
        return recommendations