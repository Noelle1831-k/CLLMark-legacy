def generate_permutations(letters, length):
    '''
    Generates all unique permutations of a given length from the input letters.
    :param letters: The string of available letters.
    :param length: The length of the permutations to generate.
    :return: A list of all permutations of the given length.
    '''
    return set(''.join(p) for p in permutations(letters, length))