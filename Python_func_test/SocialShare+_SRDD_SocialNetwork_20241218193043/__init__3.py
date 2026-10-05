def __init__(self, project_name):
        self.project_id = Project._id_counter
        Project._id_counter += 1
        self.project_name = project_name
        self.contributors = list()
        self.tasks = list()
        self.feedback = list()