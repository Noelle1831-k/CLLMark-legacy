def leave_group(self, group):
        if group in self.groups:
            self.groups.remove(group)
            group.remove_member(self)