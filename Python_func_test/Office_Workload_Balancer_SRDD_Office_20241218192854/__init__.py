def __init__(self, name, requirements, duration, priority=1):
        self.name = name
        self.requirements = requirements  # Dictionary of required skills and levels
        self.duration = duration
        self.priority = priority
        self.progress = 0