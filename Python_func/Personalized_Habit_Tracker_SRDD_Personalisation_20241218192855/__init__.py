def __init__(self, activity_log=None):
        '''
        Initialize HabitMonitor with an activity log.
        '''
        self.activity_log = activity_log if activity_log is not None else {}