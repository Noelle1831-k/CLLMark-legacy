def tie_breaker(self):
        # Enhanced tie-breaking mechanism: consider stamina and potential
        stamina1 = sum(player.stamina for player in self.team1.players)
        stamina2 = sum(player.stamina for player in self.team2.players)
        potential1 = sum(player.potential for player in self.team1.players)
        potential2 = sum(player.potential for player in self.team2.players)
        if stamina1 > stamina2:
            return self.team1
        elif stamina2 > stamina1:
            return self.team2
        elif potential1 > potential2:
            return self.team1
        elif potential2 > potential1:
            return self.team2
        else:
            # Final random choice if all else is equal
            return random.choice([self.team1, self.team2])