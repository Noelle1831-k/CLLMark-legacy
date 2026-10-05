def check_collision(self, target):
        collision = detect_collision(self.position, target.position)
        if collision:
            print(f"Bullet at {self.position} collided with target at {target.position}")
        return collision