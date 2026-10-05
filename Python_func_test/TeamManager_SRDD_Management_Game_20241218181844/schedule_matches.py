def schedule_matches(self):
        for i in range(0, len(self.teams)):
            for j in range(i+1, len(self.teams)):
                self.matches.append(match.Match(self.teams[i], self.teams[j]))