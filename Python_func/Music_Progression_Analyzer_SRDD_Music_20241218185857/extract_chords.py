def extract_chords(self, midi_data):
        chords = []
        for track in midi_data.tracks:
            for msg in track:
                if msg.type == 'note_on' and msg.velocity > 0:
                    chords.append(msg.note)
        print(f"Extracted chords: {chords}")
        return chords