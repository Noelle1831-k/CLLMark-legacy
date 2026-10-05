def load_floor_plan(self):
        # Load floor plan from a file or database
        data = load_data_from_file('floor_plan.txt')
        for entry in data:
            workspace = Workspace(entry['id'], entry['location'], entry['capacity'])
            self.workspaces.append(workspace)