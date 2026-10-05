def is_due(self):
        due = datetime.now() >= self.deadline
        logging.info(f"Task '{self.name}' is_due check: {due}.")
        return due