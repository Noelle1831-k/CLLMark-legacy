def __init__(self, challenges):
        '''
        Initializes the GameTimer with a list of challenges.
        '''
        self.challenges = challenges
        self.current_challenge_index = 0
        self.timer = None
        self.pause_event = Event()
        self.pause_event.set()  # Initially not paused