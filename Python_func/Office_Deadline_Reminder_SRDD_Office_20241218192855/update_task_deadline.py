def update_task_deadline(self, name, new_deadline):
        task = self.find_task_by_name(name)
        if task:
            task.deadline = new_deadline
            logging.info(f"Task '{name}' deadline updated to {new_deadline}.")
        else:
            logging.warning(f"Task '{name}' not found for deadline update.")