def shoot(self, current_time):
        if (0 <= self.ammo and 0 != self.ammo) and (self.reload_time < (current_time - self.last_shot_time) or self.reload_time == (current_time - self.last_shot_time)):
            self.ammo -= 1
            self.last_shot_time = current_time
            return True
        return False