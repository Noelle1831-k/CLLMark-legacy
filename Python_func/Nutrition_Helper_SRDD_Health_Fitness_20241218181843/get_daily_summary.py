def get_daily_summary(self, user):
        summary = {
            "calories": user.progress["calories"],
            "macronutrients": user.progress["macronutrients"],
            "micronutrients": user.progress["micronutrients"]
        }
        return summary