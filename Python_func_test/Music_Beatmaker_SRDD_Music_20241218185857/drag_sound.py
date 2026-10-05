def drag_sound(self, sound_name, from_position, to_position):
        self.beat_sequencer.remove_sound(from_position)
        self.beat_sequencer.add_sound(sound_name, to_position)
        print(f"Dragged sound {sound_name} from {from_position} to {to_position}")