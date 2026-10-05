def check_collisions(self, player):
        for obstacle in self.obstacles:
            if obstacle.check_collision(player):
                print("Collision detected!")
                # Handle collision response here