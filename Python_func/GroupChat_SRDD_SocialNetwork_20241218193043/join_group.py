def join_group(self, group):
        if group not in self.groups:
            self.groups.append(group)
            group.add_member(self)