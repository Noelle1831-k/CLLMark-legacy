def delete_group(self, group_name):
        self.groups = [group for group in self.groups if group.name != group_name]