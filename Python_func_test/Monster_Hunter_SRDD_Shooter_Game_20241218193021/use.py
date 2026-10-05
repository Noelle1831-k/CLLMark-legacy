def use(self, monsters):
        for mon in monsters:
            mon.take_damage(self.power)