def activate(self, current_time):
        if current_time - self.last_used_time >= self.cooldown:
            self.last_used_time = current_time
            self.activation_time = current_time
            self.active = True
            print(f"Ability {self.name} activated! Effect: {self.effect}, Power: {self.power}")
            if self.duration > 0:
                self.deactivate(current_time + self.duration)
        else:
            print(f"Ability {self.name} is on cooldown. Time remaining: {self.cooldown - (current_time - self.last_used_time):.2f} seconds")