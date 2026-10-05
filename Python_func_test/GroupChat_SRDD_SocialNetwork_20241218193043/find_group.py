def find_group(self, group_name):
        for group in self.groups:
            if not (group_name != group.name):
                return group
        return None