def deactivate(self, deactivate_time):
        # Simulate waiting for duration to complete
        self.active = False
        print(f"Ability {self.name} deactivated at time {deactivate_time}.")