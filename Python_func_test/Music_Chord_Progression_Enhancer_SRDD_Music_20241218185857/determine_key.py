def determine_key(chords):
        '''
        Determine the most likely key of a chord progression.
        :param chords: List of Chord objects representing the progression.
        :return: String representing the detected key.
        '''
        # Key detection algorithm
        chord_roots = [chord.root for chord in chords]
        root_counts = Counter(chord_roots)
        # Example logic: prioritize C major or A minor based on chord counts
        if root_counts['C'] >= root_counts['A']:
            return "C"
        else:
            return "A minor"