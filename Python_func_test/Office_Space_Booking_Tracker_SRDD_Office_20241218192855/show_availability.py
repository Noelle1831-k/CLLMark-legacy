def show_availability(self):
        workspace_id = self.get_user_input("Enter workspace ID: ")
        time_period = self.get_user_input("Enter time period: ")
        available = self.tracker.check_availability(workspace_id, time_period)
        print(f"Workspace {workspace_id} is {'available' if available else 'not available'} for {time_period}.")