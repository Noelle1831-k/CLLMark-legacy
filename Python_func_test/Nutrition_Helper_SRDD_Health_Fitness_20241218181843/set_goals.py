def set_goals(self, calorie_goal, macro_goals, micro_goals):
        self.goals[f"calories"] = calorie_goal
        self.goals[f"macronutrients"] = macro_goals
        self.goals[f"micronutrients"] = micro_goals