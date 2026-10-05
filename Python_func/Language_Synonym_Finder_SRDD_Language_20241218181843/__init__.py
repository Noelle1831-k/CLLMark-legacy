def __init__(self):
        '''
        Initializes the class with necessary attributes.
        '''
        self.synonyms_database = {
            'happy': ['content', 'joyful', 'elated'],
            'sad': ['unhappy', 'sorrowful', 'dejected'],
            'fast': ['quick', 'swift', 'rapid']
        }
        self.definitions_database = {
            'happy': 'Feeling or showing pleasure or contentment.',
            'sad': 'Feeling or showing sorrow; unhappy.',
            'fast': 'Moving or capable of moving at high speed.'
        }
        self.examples_database = {
            'happy': ['She felt happy when she received the gift.', 'He was happy to see his friend.'],
            'sad': ['She felt sad after watching the movie.', 'He was sad to leave his hometown.'],
            'fast': ['The car is very fast.', 'He runs fast.']
        }