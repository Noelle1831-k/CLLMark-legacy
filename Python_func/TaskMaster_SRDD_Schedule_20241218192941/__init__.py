def __init__(self, tasks):
        self.schedule = {task['name']: task for task in tasks}