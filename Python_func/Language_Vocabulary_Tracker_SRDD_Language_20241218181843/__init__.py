def __init__(self):
        '''
        Initialize the Vocabulary Tracker with an empty word dictionary, flashcards list,
        quiz object, and progress tracker.
        '''
        self.words = {}
        self.flashcards = []
        self.quiz = None
        self.progress_tracker = ProgressTracker()