def check_collisions(self):
        print("Checking for collisions...")
        if random.choice([True, False]):
            print("Collision detected! Speed reduced!")
            self.player_vehicle.current_speed *= 0.8