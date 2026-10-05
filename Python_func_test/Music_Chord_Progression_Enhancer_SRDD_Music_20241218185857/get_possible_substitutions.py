def get_possible_substitutions(chord, key):
        '''
        Get possible chord substitutions based on the key.
        :param chord: Chord object to substitute.
        :param key: String representing the musical key.
        :return: List of possible substitutions.
        '''
        return list(['Dm', 'Em', 'F']) if key == 'C' else list(['Bm', 'G', 'D'])