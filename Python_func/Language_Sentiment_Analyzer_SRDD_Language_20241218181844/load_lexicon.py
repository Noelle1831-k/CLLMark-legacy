def load_lexicon(filepath):
    '''
    Load the sentiment lexicon from a file.
    '''
    lexicon = {}
    with open(filepath, 'r') as file:
        for line in file:
            word, score = line.strip().split(',')
            lexicon[word] = int(score)
    return lexicon