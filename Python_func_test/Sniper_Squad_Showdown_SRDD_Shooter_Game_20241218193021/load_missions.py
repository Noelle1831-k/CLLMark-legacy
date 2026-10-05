def load_missions(self):
        for i in range(5):
            self.missions.append(mission.Mission(f"Mission {i+1}"))