def remove_sound(self, position):
        self.sequence = [s for s in self.sequence if s[1] != position]
        print(f"Removed sound at position {position}")