def export_to_midi(self, chord_sequence, tempo):
        '''
        Converts the chord sequence and tempo to a MIDI file.
        '''
        midi = MidiFile()
        track = MidiTrack()
        midi.tracks.append(track)
        # Set tempo (in microseconds per beat)
        tempo_event = int(60000000 / tempo)
        track.append(Message('program_change', program=1, time=0))
        for chord, duration in chord_sequence:
            # Add MIDI events for each chord
            track.append(Message('note_on', note=60, velocity=64, time=0))  # Example note
            track.append(Message('note_off', note=60, velocity=64, time=int(duration * tempo_event)))
        midi.save('output.mid')
        print("MIDI export complete.")