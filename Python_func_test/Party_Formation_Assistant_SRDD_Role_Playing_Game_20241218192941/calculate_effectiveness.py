def calculate_effectiveness(character):
    # Calculate effectiveness based on character's abilities
    return character.evaluate_strength() - character.evaluate_weakness()