def display_team_info(self):
        print(f"Team: {self.name}")
        print("Players:")
        for p in self.players:
            print(f"  {p.name} - Stats: {p.stats.get_stats()}")
        print(f"Strategy: {self.strategy}")