def generate_recommendations(self, expenses_by_category):
        recommendations = {}
        for category, amounts in expenses_by_category.items():
            avg_expense = sum(amounts) / len(amounts)
            if avg_expense > 100:
                recommendations[category] = "Consider reducing expenses in this category."
            else:
                recommendations[category] = "Expenses in this category are within a reasonable range."
        return recommendations