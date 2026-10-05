def start(self):
        self.create_teams()
        self.choose_control_mode()
        self.control_characters()
        battle = Battle(self.teams[0], self.teams[1])
        battle.simulate()
        winner = battle.determine_winner()
        print(f"The winner is: {winner}")