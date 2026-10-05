def parse_notation(self, notation):
        '''
        Parse a chord notation into its root note and type.
        :param notation: String representing a chord (e.g., "Cmaj7").
        :return: Tuple of (root, type).
        '''
        # Parsing logic to handle various chord formats
        root = notation[0]
        type = notation[1:] if len(notation) > 1 else 'major'
        return root, type