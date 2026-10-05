def __init__(self):
        '''
        Initializes the MainApp with instances of ShotSimulator, PositionTracker, and FeedbackSystem.
        '''
        self.shot_simulator = ShotSimulator()
        self.position_tracker = PositionTracker()
        self.feedback_system = FeedbackSystem()