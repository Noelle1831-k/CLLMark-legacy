def spawn_monsters(self):
        for _ in range(5):
            new_monster = monster.Monster()
            new_monster.spawn()
            self.monsters.append(new_monster)