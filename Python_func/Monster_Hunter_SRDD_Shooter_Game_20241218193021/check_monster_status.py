def check_monster_status(self):
        for mon in self.monsters:
            if not mon.is_alive():
                self.monsters.remove(mon)