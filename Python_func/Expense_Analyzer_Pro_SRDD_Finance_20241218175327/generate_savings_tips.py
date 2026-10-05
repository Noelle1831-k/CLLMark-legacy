def generate_savings_tips(self, expenses_by_category):
        tips = {}
        for category, amounts in expenses_by_category.items():
            total = sum(amounts)
            if total > 200:
                tips[category] = "You are spending a lot in this category. Look for discounts or cheaper alternatives."
            else:
                tips[category] = "Good job keeping expenses low in this category!"
        return tips