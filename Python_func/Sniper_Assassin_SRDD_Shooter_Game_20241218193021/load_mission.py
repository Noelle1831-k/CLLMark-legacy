def load_mission(self):
        print(f"Loading Mission {self.id}...")
        self.objectives = {
            "eliminate_target": False,
            "avoid_detection": False,
            "complete_within_time_limit": False
        }
        self.time_taken = 0