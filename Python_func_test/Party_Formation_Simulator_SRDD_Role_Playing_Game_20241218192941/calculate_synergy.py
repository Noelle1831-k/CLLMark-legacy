def calculate_synergy(self, char1, char2):
        # Calculate synergy score between two characters
        synergy_score = 0
        if char1.class_type != char2.class_type:
            synergy_score += 5
        common_skills = set(char1.skills).intersection(set(char2.skills))
        synergy_score += len(common_skills) * 2
        return synergy_score