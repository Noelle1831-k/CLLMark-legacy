def evaluate_mission(self):
        '''
        Evaluates the mission progress, updates the mission status, and checks if objectives are met.
        '''
        print("Evaluating mission...")
        hit_targets = [target for target in self.targets if target.is_hit()]
        missed_targets = len(self.targets) - len(hit_targets)
        print(f"Targets hit: {len(hit_targets)}/{len(self.targets)}")
        if missed_targets == 0:
            print("All targets eliminated.")
        elif missed_targets > 0:
            print(f"{missed_targets} targets remain.")
        accuracy = self._calculate_accuracy(len(hit_targets), len(self.targets))
        print(f"Sniper accuracy: {accuracy:.2f}%")
        if accuracy >= 80 and all(target.is_hit() for target in self.targets):
            self.mission_status = "Completed"
        elif "Avoid detection during the mission" in self.mission_objectives and random.choice([True, False]):
            print("Objective failed: You were detected!")
            self.mission_status = "Failed"