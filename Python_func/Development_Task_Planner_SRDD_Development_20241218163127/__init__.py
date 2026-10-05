def __init__(self, name, description):
        '''
        Initializes a new project with a given name and description.
        Parameters:
        - name: Name of the project.
        - description: Detailed description of the project.
        '''
        self.name = name
        self.description = description
        self.tasks = []
        self.id = None  # Will be assigned when stored in ProjectManager