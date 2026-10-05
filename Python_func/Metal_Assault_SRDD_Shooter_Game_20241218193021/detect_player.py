def detect_player(self, player_position):
        # Simple detection logic
        return self.position[0] - player_position[0] < 5