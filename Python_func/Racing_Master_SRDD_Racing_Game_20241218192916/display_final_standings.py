def display_final_standings(self):
        print("Final Standings:")
        for team, points in sorted(self.standings.items(), key=lambda item: item[1], reverse=True):
            print(f"{team}: {points} points")