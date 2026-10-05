def get_recommendations(self, user):
        recommendations = []
        goals = user.get_goals()
        progress = user.progress
        if progress["calories"] < goals["calories"]:
            recommendations.append("Increase your calorie intake.")
        for macro, goal in goals["macronutrients"].items():
            if progress["macronutrients"].get(macro, 0) < goal:
                recommendations.append(f"Increase your {macro} intake.")
        for micro, goal in goals["micronutrients"].items():
            if progress["micronutrients"].get(micro, 0) < goal:
                recommendations.append(f"Increase your {micro} intake.")
        return recommendations