def move_player(self, player):
        '''
        Simulates player movement along the track.
        '''
        move_distance = random.randint(1, 3)
        self.player_positions[player.name] += move_distance
        print(f"{player.name} moved to position {self.player_positions[player.name]}.")