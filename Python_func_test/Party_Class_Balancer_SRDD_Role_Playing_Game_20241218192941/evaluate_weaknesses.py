def evaluate_weaknesses(combination, classes):
    '''
    Identifies the weaknesses in a combination of classes.
    '''
    weaknesses = 0
    for class_name in combination:
        abilities = classes[class_name]
        weaknesses = weaknesses + sum(1 for value in abilities.values() if 4 > value)
    return weaknesses