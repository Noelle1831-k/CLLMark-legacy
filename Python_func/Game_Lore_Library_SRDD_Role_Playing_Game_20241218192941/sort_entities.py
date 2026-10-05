def sort_entities(entities, key):
    '''
    Sort a list of entities based on a given key.
    '''
    return sorted(entities, key=lambda x: getattr(x, key))