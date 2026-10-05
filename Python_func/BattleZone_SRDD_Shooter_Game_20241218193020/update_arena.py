def update_arena(self):
        for tank in self.tanks:
            if tank.health <= 0:
                self.remove_tank(tank)