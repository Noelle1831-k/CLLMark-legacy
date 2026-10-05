def reload(self, current_time):
        if not self.is_reloading:
            self.is_reloading = True
            print(f"{self.name} is reloading. It will take {self.reload_time} seconds.")
            # Simulate reload time
            self.complete_reload(current_time + self.reload_time)