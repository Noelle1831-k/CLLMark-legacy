def get_recommendations(self, user):
        return self.recommendations.get(user.name, [])