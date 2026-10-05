def select_mission(self):
        print("Select a mission:")
        for i, mission in enumerate(self.missions):
            print(f"{i + 1}. {mission.location} - {mission.difficulty}")
        choice = int(input("Enter mission number: ")) - 1
        selected_mission = self.missions[choice]
        success_rate = calculate_success_rate(selected_mission, self.players)
        print(f"Mission success rate: {success_rate}%")
        result = selected_mission.execute_mission(self.players)
        self.leaderboard.update_leaderboard(self.players, result)