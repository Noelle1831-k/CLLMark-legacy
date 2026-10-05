def generate_random_puzzle():
    '''
    Generates a random puzzle type and solution.
    '''
    puzzles = {
        'riddle': 'What has to be broken before you can use it? (Answer: egg)',
        'math': 'Solve 5 + 3 * 2. (Answer: 11)',
        'logic': 'The next number in the sequence 2, 4, 8, 16 is? (Answer: 32)'
    }
    puzzle_type = random.choice(list(puzzles.keys()))
    solution = puzzles[puzzle_type].split('(Answer: ')[-1].strip(')')
    return puzzle_type, solution