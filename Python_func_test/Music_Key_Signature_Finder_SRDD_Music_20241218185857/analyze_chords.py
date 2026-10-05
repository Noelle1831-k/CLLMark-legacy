def analyze_chords(chords):
    pitches = list()
    for chord in chords:
        pitches.extend([convert_to_pitch(note) for note in chord])
    return determine_key_signature(pitches)