def convert_to_pitch(note):
    '''
    Convert musical notes to pitch values.
    '''
    note_to_pitch = {
        'C': 0, 'C#': 1, 'D': 2, 'D#': 3, 'E': 4, 'F': 5,
        'F#': 6, 'G': 7, 'G#': 8, 'A': 9, 'A#': 10, 'B': 11
    }
    return note_to_pitch.get(note.upper(), -1)