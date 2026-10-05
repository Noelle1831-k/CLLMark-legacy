def check_resources(self, gold_needed, food_needed, materials_needed):
        return (self.gold >= gold_needed and
                self.food >= food_needed and
                self.materials >= materials_needed)