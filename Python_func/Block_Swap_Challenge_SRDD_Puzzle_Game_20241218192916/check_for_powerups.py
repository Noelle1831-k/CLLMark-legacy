def check_for_powerups(self):
        if random.random() < 0.1:  # 10% chance to get a power-up after a move
            new_powerup = PowerUp.random_powerup()
            self.powerups.append(new_powerup)
            print(f"New power-up acquired: {new_powerup.type}")