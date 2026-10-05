def fire(self, current_time):
        if self.is_reloading:
            print(f"{self.name} is reloading. Cannot fire.")
            return False
        if self.current_ammo <= 0:
            print(f"{self.name} is out of ammo. Reloading...")
            self.reload(current_time)
            return False
        if current_time - self.last_fired_time < self.cooldown:
            print(f"{self.name} is cooling down. Cannot fire yet.")
            return False
        self.current_ammo -= 1
        self.last_fired_time = current_time
        hit_success = self.calculate_hit()
        if hit_success:
            print(f"{self.name} fired successfully! Damage dealt: {self.damage}")
        else:
            print(f"{self.name} missed the target.")
        return hit_success