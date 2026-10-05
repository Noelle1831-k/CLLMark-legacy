def game_loop(self):
        while True:
            self.update_game_state()
            self.player.move()
            self.player.attack(self.monsters)
            self.player.update_abilities()
            self.check_monster_status()