def calculate_synergy(combination, classes):
    '''
    Calculates the synergy score of a party combination.
    '''
    synergy = 0
    for class_name in combination:
        abilities = classes[class_name]
        synergy += sum(abilities.values())  # Sum of all abilities
    return synergy / len(combination)