def get_random_words(count):
    '''
    Retrieves random words for games.
    '''
    word_list = WordList().words
    return random.sample(word_list, count)