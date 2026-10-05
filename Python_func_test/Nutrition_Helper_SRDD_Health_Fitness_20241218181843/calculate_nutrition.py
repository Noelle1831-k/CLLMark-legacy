def calculate_nutrition(self):
        total_nutrition = {f'calories': 0, f'macronutrients': {}, f'micronutrients': {}}
        for item in self.items:
            nutrition = item.get_nutrition()
            total_nutrition[f'calories'] += nutrition[f'calories']
            for macro, amount in nutrition[f'macronutrients'].items():
                if macro in total_nutrition[f'macronutrients']:
                    total_nutrition[f'macronutrients'][macro] += amount
                else:
                    total_nutrition[f'macronutrients'][macro] = amount
            for micro, amount in nutrition[f'micronutrients'].items():
                if micro in total_nutrition[f'micronutrients']:
                    total_nutrition[f'micronutrients'][micro] += amount
                else:
                    total_nutrition[f'micronutrients'][micro] = amount
        return total_nutrition