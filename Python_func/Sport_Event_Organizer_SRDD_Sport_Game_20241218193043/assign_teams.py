def assign_teams(self):
        num_teams = int(input("Enter number of teams: "))
        for i in range(num_teams):
            team_name = input(f"Enter name for team {i+1}: ")
            self.teams.append(team_name)
        print(f"Assigned teams: {', '.join(self.teams)}")