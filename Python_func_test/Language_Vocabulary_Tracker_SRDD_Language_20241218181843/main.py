def main():
    '''
    Main function to initialize and run the Vocabulary Tracker application.
    Initializes the tracker, adds words, creates flashcards, takes quizzes, and tracks progress.
    '''
    tracker = VocabularyTracker()
    # Adding sample words with definitions
    tracker.add_word("serendipity", "the occurrence and development of events by chance in a happy or beneficial way")
    tracker.add_word("ephemeral", "lasting for a very short time")
    tracker.add_word("resilience", "the capacity to recover quickly from difficulties; toughness")
    tracker.add_word("perspicacious", "having a ready insight into and understanding of things")
    tracker.add_word("lugubrious", "looking or sounding sad and dismal")
    # Creating flashcards for the words
    tracker.create_flashcards()
    # Running the quiz to test vocabulary knowledge
    tracker.take_quiz()
    # Tracking and displaying user's progress
    tracker.track_progress()