def render(self, players, track):
        print("Rendering Track and Players...", flush=True)
        for player in players:
            print(f"Player at position: {player.position}", flush=True)