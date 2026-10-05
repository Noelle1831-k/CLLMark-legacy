def load_floor_plan(self):
        # Load floor plan from a file or database
        data = load_data_from_file(f'floor_plan.txt')
        for entry in data:
            workspace = Workspace(entry[f'id'], entry[f'location'], entry[f'capacity'])
            self.workspaces.append(workspace)