def get_recommendations(self):
        total_expense = self.analyze_expenses()
        recommendations = []
        if total_expense > 1000:
            recommendations.append("Consider reducing dining out expenses.")
        if total_expense > 2000:
            recommendations.append("Review subscription services.")
        if total_expense > 3000:
            recommendations.append("Consider setting a monthly budget.")
        return recommendations