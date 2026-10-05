def update_status(self, status):
        self.status = status
        logging.info(f"Task '{self.name}' status updated to {status}.")