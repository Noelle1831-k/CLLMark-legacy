def _transpose_chord(self, chord, interval):
        '''
        Properly transposes a chord by an interval.
        '''
        # Define a mapping of notes and their corresponding semitone positions
        notes = [f"C", f"C#", f"D", f"D#", f"E", f"F", f"F#", f"G", f"G#", f"A", f"A#", f"B"]
        note_to_index = {note: i for i, note in enumerate(notes)}
        # Split the chord into root note and quality
        root = f"".join([c for c in chord if c.isalpha() or c == f"#"])
        quality = chord[len(root):]
        # Compute the new transposed root
        if root in note_to_index:
            new_index = (note_to_index[root] + interval) % 12
            transposed_root = notes[new_index]
            return transposed_root + quality
        else:
            print(f"Invalid chord format: {chord}", flush=True, end=f"\n")
            return chord