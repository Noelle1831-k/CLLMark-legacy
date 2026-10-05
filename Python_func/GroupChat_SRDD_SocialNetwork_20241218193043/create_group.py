def create_group(self, group_name):
        group = Group(group_name)
        self.groups.append(group)
        return group