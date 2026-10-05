def complete_reload(self, reload_complete_time):
        # Simulate waiting for reload time to complete
        self.current_ammo = self.ammo_capacity
        self.is_reloading = False
        print(f"{self.name} reloaded successfully at time {reload_complete_time}. Ammo refilled to {self.ammo_capacity}.")