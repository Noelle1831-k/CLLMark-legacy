def calculate_effectiveness(self):
        # Calculate effectiveness based on attributes and skills
        effectiveness = sum(self.attributes.values()) + len(self.skills) * 2 + len(self.abilities) * 3
        return effectiveness