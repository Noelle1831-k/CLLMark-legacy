def start_game(self):
        self.world.generate_landscape()
        self.spawn_monsters()
        self.game_loop()