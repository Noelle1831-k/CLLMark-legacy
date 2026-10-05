def identify_relationships(tagged_sentence):
    '''
    Identifies relationships between parts of speech.
    '''
    relationships = []
    for i, (word, tag) in enumerate(tagged_sentence):
        if tag == 'NN' and i > 0 and tagged_sentence[i-1][1] == 'DT':
            relationships.append((tagged_sentence[i-1][0], 'determines', word))
        elif tag == 'VBZ' and i < len(tagged_sentence) - 1 and tagged_sentence[i+1][1] == 'PP':
            relationships.append((word, 'relates to', tagged_sentence[i+1][0]))
        elif tag == 'JJ' and i > 0 and tagged_sentence[i-1][1] == 'DT':
            relationships.append((tagged_sentence[i-1][0], 'describes', word))
        elif tag == 'PRP' and i < len(tagged_sentence) - 1 and tagged_sentence[i+1][1] == 'VBZ':
            relationships.append((word, 'performs', tagged_sentence[i+1][0]))
        elif tag == 'MD' and i < len(tagged_sentence) - 1 and tagged_sentence[i+1][1] == 'VBZ':
            relationships.append((word, 'modifies', tagged_sentence[i+1][0]))
    return relationships