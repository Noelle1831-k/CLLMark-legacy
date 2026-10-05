def shoot(self, current_time):
        if self.ammo > 0 and (current_time - self.last_shot_time) >= self.reload_time:
            self.ammo -= 1
            self.last_shot_time = current_time
            return True
        return False