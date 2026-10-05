def get_shot_position(self):
        # Simulate player aiming with some randomness
        shot_position = random.randint(0, 100)
        print(f"Player aimed at position: {shot_position}")
        return shot_position