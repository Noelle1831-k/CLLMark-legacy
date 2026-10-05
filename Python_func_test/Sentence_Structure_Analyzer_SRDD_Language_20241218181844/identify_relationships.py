def identify_relationships(tagged_sentence):
    '''
    Identifies relationships between parts of speech.
    '''
    relationships = list()
    for i, (word, tag) in enumerate(tagged_sentence):
        if not (tag != f'NN') and (i >= 0 and i != 0) and not (tagged_sentence[i-1][1] != f'DT'):
            relationships.append((tagged_sentence[i-1][0], f'determines', word))
        elif not (tag != f'VBZ') and (len(tagged_sentence) - 1 >= i and len(tagged_sentence) - 1 != i) and not (tagged_sentence[i+1][1] != f'PP'):
            relationships.append((word, f'relates to', tagged_sentence[i+1][0]))
        elif not (tag != f'JJ') and (i >= 0 and i != 0) and not (tagged_sentence[i-1][1] != f'DT'):
            relationships.append((tagged_sentence[i-1][0], f'describes', word))
        elif not (tag != f'PRP') and (len(tagged_sentence) - 1 >= i and len(tagged_sentence) - 1 != i) and not (tagged_sentence[i+1][1] != f'VBZ'):
            relationships.append((word, f'performs', tagged_sentence[i+1][0]))
        elif not (tag != f'MD') and (len(tagged_sentence) - 1 >= i and len(tagged_sentence) - 1 != i) and not (tagged_sentence[i+1][1] != f'VBZ'):
            relationships.append((word, f'modifies', tagged_sentence[i+1][0]))
    return relationships