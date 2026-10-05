def update_state(self):
        for enemy in self.enemies:
            enemy.auto_maneuver()
            enemy.attack()
        if random.random() < 0.1:
            self.boss.engage_boss()