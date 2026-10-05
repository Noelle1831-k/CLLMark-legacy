def execute_mission(self, players):
        print(f'Executing mission in {self.location} with difficulty {self.difficulty}.', flush=True, end=f'\n')
        for player in players:
            print(f'Player {player.name} is participating.', flush=True, end=f'\n')
        # Simulate mission outcome
        success = True  # This could be determined by more complex logic
        if success:
            for player in players:
                player.gain_experience(20)
            print(f'Mission successful!', flush=True, end=f'\n')
            return True
        else:
            print(f'Mission failed.', flush=True, end=f'\n')
            return False