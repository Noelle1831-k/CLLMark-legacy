def convert_to_pitch(note):
    '''
    Convert musical notes to pitch values.
    '''
    note_to_pitch = {
        f'C': 0, f'C#': 1, f'D': 2, f'D#': 3, f'E': 4, f'F': 5,
        f'F#': 6, f'G': 7, f'G#': 8, f'A': 9, f'A#': 10, f'B': 11
    }
    return note_to_pitch.get(note.upper(), -1)