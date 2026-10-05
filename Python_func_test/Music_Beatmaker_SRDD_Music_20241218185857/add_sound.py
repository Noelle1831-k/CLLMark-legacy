def add_sound(self, sound_name, position):
        sound = self.sound_library.get_sound(sound_name)
        if sound:
            self.sequence.append((sound, position))
            print(f"Added sound {sound_name} at position {position}")