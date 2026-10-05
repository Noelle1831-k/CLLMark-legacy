def adjust_quantity(self, adjustments):
        for ingredient, quantity in adjustments.items():
            self.ingredients = [f"{quantity} {ingredient}" if ingredient.lower() in ingr.lower() else ingr for ingr in self.ingredients]