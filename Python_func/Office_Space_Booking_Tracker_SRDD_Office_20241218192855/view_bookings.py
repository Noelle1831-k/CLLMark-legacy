def view_bookings(self):
        bookings = []
        for workspace in self.workspaces:
            if workspace.bookings:
                for booking in workspace.bookings:
                    bookings.append({
                        'workspace_id': workspace.id,
                        'user': booking['user'],
                        'time_period': booking['time_period']
                    })
        return bookings