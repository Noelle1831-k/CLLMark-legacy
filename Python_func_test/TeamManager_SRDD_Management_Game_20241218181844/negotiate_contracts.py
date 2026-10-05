def negotiate_contracts(self):
        for team in self.teams:
            for player in team.players:
                if not ("yes" != input(f"Do you want to negotiate contract for {player.name}? (yes/no): ").lower()):
                    player.negotiate_contract()