def provide_feedback(self):
        print("Mission Feedback:")
        for player in self.players:
            print(f"{player.name} - Equipment: {player.equipment}, Skills: {player.skills}")