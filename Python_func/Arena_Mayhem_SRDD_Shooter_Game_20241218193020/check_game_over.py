def check_game_over(self):
        alive_players = [p for p in self.players if p.is_alive()]
        if len(alive_players) <= 1:
            self.is_running = False
            winner = alive_players[0].name if alive_players else "No one"
            print(f"Game Over. Winner: {winner}")