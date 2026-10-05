def multiple_choice_quiz():
    """
    Provides a multiple-choice vocabulary quiz. The quiz will only proceed if there are at least 4 words available.
    If there are fewer than 4 words, it notifies the user and returns to the main menu.
    """
    vocab = vocabulary.load_vocabulary()
    if not vocab:
        print("No vocabulary available for the quiz.")
        return
    words = list(vocab.keys())
    if len(words) < 4:
        print("Not enough words in the vocabulary to create a quiz. Please add more words.")
        return
    score = 0
    for _ in range(5):
        word = random.choice(words)
        correct_meaning = vocab[word]["meaning"]
        incorrect_meanings = [vocab[w]["meaning"] for w in random.sample(words, 3) if w != word]
        options = incorrect_meanings + [correct_meaning]
        random.shuffle(options)
        print(f"\nWhat is the meaning of '{word}'?")
        for i, option in enumerate(options, 1):
            print(f"{i}. {option}")
        try:
            answer = int(input("Your answer: ").strip())
            if options[answer - 1] == correct_meaning:
                print("Correct!")
                score += 1
            else:
                print(f"Wrong! The correct answer is: {correct_meaning}")
        except (ValueError, IndexError):
            print("Invalid input. Skipping question.")
    print(f"\nYour score: {score}/5")