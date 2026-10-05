def calculate_synergy(combo):
    '''
    Calculates the synergy between classes.
    '''
    synergy_score = 0
    for cls in combo:
        strengths = cls.get_strengths()
        weaknesses = cls.get_weaknesses()
        synergy_score += len(strengths) - len(weaknesses)
    return synergy_score