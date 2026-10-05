def fill_in_the_blank():
    """
    Provides a fill-in-the-blank vocabulary exercise, ensuring the word can be successfully replaced in the sentence.
    """
    vocab = vocabulary.load_vocabulary()
    if not vocab:
        print("No vocabulary available for the exercise.")
        return
    word = random.choice(list(vocab.keys()))
    example_sentence = vocab[word]["example"]
    print("\nFill in the blank:")
    print(example_sentence.replace(word, "_____"))
    user_answer = input("Your answer: ").strip()
    if user_answer.lower() == word.lower():
        print("Correct!")
    else:
        print(f"Wrong! The correct answer is: {word}")