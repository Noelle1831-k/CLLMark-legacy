def find_group(self, group_name):
        for group in self.groups:
            if group.name == group_name:
                return group
        return None