def random_powerup():
        # Randomly selects a power-up type
        powerup_types = ["bomb", "color_clear", "row_clear", "column_clear"]
        return PowerUp(random.choice(powerup_types))