def update_race(self):
        '''
        Updates the race status.
        '''
        while self.race_status == "In Progress":
            for player in self.players:
                self.move_player(player)
                if self.player_positions[player.name] >= len(self.track.track):
                    self.race_status = "Finished"
                    print(f"{player.name} has won the race!")
                    break
            time.sleep(1)
            print("Race is ongoing...")