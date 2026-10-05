def generate_recommendations(self, user):
        recommendations = []
        balance = user.get_balance()
        if balance < 100:
            recommendations.append("Consider reducing discretionary spending.")
        elif balance < 500:
            recommendations.append("You are doing well, but keep an eye on your expenses.")
        else:
            recommendations.append("Great job! You have a healthy balance.")
        return recommendations