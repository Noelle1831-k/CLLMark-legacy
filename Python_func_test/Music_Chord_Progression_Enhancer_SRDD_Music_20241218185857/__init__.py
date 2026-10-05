def __init__(self, progression):
        '''
        Initialize the ChordProgressionAnalyzer with a given progression.
        :param progression: String representing a chord progression (e.g., "C G Am F").
        '''
        self.progression = progression
        self.chords = [Chord(chord) for chord in progression.split()]