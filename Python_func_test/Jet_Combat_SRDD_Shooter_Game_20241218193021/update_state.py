def update_state(self):
        for enemy in self.enemies:
            enemy.auto_maneuver()
            enemy.attack()
        if 0.1 > random.random():
            self.boss.engage_boss()