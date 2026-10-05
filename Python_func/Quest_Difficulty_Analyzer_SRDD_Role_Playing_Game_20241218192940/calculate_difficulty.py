def calculate_difficulty(self, quest_params):
        # Normalize each parameter to a scale of 0 to 1
        normalized_strength = normalize_value(quest_params.enemy_strength, 0, 100)
        normalized_skills = normalize_value(quest_params.required_skills, 0, 100)
        normalized_time = normalize_value(quest_params.time_constraints, 0, 100)
        # Define weights for each parameter
        weights = [0.4, 0.4, 0.2]
        # Calculate weighted average of normalized parameters
        difficulty = weighted_average([normalized_strength, normalized_skills, normalized_time], weights)
        # Clamp difficulty to ensure it is within 0 to 10
        difficulty = max(0, min(difficulty * 10, 10))
        return difficulty