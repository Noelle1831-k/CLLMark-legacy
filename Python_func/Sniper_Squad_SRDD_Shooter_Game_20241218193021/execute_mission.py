def execute_mission(self, players):
        print(f"Executing mission in {self.location} with difficulty {self.difficulty}.")
        for player in players:
            print(f"Player {player.name} is participating.")
        # Simulate mission outcome
        success = True  # This could be determined by more complex logic
        if success:
            for player in players:
                player.gain_experience(20)
            print("Mission successful!")
            return True
        else:
            print("Mission failed.")
            return False