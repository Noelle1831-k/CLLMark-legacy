def __init__(self, goal_manager):
        '''
        Initializes ProgressTracker with access to GoalManager. 
        This ensures progress data is synchronized with goal data.
        '''
        self.goal_manager = goal_manager