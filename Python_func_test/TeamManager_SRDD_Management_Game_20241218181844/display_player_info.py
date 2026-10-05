def display_player_info(self):
        print(f"Player: {self.name}")
        print(f"Stats: {self.stats.get_stats()}")
        print(f"Contract: Salary - {self.contract.salary}, Duration - {self.contract.duration}")