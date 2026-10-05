def list_members(self, group_name):
        return self.groups.get(group_name, "Group not found.")