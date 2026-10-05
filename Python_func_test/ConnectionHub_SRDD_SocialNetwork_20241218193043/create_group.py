def create_group(self, group_name):
        if group_name not in self.groups:
            self.groups[group_name] = []
            print(f"Group {group_name} created.")
        else:
            print("Group already exists.")