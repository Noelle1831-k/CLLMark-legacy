def __init__(self, name, description, deadline):
        self.name = name
        self.description = description
        try:
            self.deadline = datetime.strptime(deadline, '%Y-%m-%d %H:%M:%S')
            logging.info(f"Task '{name}' initialized with deadline {self.deadline}.")
        except ValueError as e:
            logging.error(f"Error parsing deadline for task '{name}': {e}")
            raise
        self.status = 'Pending'