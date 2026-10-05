def place_random_powerups(self, powerups):
        for powerup in powerups:
            position = (random.randint(0, 9), random.randint(0, 9))
            self.place_powerup(powerup, position)
            print(f"Placed {powerup.name} at {position}")