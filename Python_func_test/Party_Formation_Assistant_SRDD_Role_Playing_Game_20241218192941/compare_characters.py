def compare_characters(char1, char2):
    # Compare two characters based on their effectiveness
    effectiveness1 = calculate_effectiveness(char1)
    effectiveness2 = calculate_effectiveness(char2)
    return effectiveness1 - effectiveness2