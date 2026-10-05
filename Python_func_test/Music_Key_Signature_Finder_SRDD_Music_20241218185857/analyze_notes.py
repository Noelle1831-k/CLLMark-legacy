def analyze_notes(notes):
    pitches = [convert_to_pitch(note) for note in notes]
    return determine_key_signature(pitches)