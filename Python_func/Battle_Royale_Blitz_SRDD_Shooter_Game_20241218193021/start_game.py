def start_game(self):
        self.is_running = True
        self.arena.spawn_items()
        self.initialize_players()
        print("Game started!")