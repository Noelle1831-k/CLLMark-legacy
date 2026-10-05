def update_sync_status(self, task_id, status):
        self.sync_status[task_id] = status
        print(f"Sync status for task ID {task_id} updated to '{status}'.")