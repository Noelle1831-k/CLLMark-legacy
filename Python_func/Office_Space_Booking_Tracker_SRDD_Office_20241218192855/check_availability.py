def check_availability(self, workspace_id, time_period):
        for workspace in self.workspaces:
            if workspace.id == workspace_id:
                return workspace.is_available(time_period)
        return False