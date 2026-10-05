def play(self):
        sequence = self.beat_sequencer.get_sequence()
        print("Playing sequence...")
        combined = AudioSegment.silent(duration=0)
        for sound, position in sequence:
            sound_segment = AudioSegment.from_file(sound)
            combined = combined.overlay(sound_segment, position=int(position * 1000))
        play(combined)
        print("Playback finished")