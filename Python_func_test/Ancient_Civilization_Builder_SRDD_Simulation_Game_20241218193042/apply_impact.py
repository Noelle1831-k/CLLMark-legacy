def apply_impact(self, civilization):
        # Apply impact logic
        civilization.decrease_happiness(self.impact)
        print(f"Applying challenge: {self.description}")