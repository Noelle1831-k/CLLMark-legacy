def generate_exercise(difficulty):
    # Generate exercise content based on difficulty
    content = f"Translate the following sentence (Difficulty: {difficulty}): 'Hello, world!'"
    return Exercise(content, difficulty)