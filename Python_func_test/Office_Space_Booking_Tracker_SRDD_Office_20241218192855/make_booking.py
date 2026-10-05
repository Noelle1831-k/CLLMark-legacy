def make_booking(self, workspace_id, user, time_period):
        for workspace in self.workspaces:
            if workspace.id == workspace_id:
                workspace.book(user, time_period)
                save_data_to_file('bookings.txt', self.workspaces)
                return True
        return False