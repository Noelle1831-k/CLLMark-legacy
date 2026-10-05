def add_special_requirements(self, workspace_id, requirements):
        for workspace in self.workspaces:
            if workspace.id == workspace_id:
                workspace.add_requirements(requirements)
                save_data_to_file('bookings.txt', self.workspaces)
                return True
        return False