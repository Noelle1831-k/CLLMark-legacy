def export_to_sheet_music(self, chord_sequence):
        '''
        Simulates exporting chords and durations to a sheet music format.
        '''
        print("Exporting to sheet music...")
        for chord, duration in chord_sequence:
            print(f"Chord: {chord}, Duration: {duration}")
        print("Sheet music export complete.")