def shoot(self):
        print(f"Player shooting from position {self.position}")
        return Bullet(self.position)