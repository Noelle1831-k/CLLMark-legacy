def calculate_synergy(self):
        # Calculate synergy score based on members' abilities
        self.synergy_score = sum(member.evaluate_strength() for member in self.members)