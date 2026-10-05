def __init__(self, dictionary_manager):
        '''
        Initializes the WordFinder with a dictionary manager.
        :param dictionary_manager: DictionaryManager instance to check valid words.
        '''
        self.dictionary_manager = dictionary_manager
        self.word_validator = WordValidator()