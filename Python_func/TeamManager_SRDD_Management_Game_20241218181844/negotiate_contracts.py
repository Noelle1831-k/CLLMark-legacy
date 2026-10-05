def negotiate_contracts(self):
        for team in self.teams:
            for player in team.players:
                if input(f"Do you want to negotiate contract for {player.name}? (yes/no): ").lower() == "yes":
                    player.negotiate_contract()