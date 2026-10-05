def chase_player(self):
        if self.speed < self.max_speed:
            self.speed += self.acceleration
            print(f"Police chasing at speed: {self.speed}")
        else:
            print("Police at maximum speed!")