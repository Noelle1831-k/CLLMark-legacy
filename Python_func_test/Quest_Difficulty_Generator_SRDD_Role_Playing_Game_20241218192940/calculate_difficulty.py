def calculate_difficulty(player):
        base_difficulty = sum(player.skill_levels.values()) / len(player.skill_levels)
        difficulty = base_difficulty + random.uniform(-2, 2)
        return max(1, min(10, difficulty))