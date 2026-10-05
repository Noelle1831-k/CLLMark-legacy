def auto_maneuver(self):
        directions = ["left", "right", "up", "down"]
        direction = random.choice(directions)
        print(f"Enemy {self.model} maneuvers {direction}.")