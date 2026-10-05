def check_collisions(self, player):
        for obstacle in self.obstacles:
            if obstacle.check_collision(player):
                print("Collision detected!", flush=True, end="\n")
                # Handle collision response here