def join_group(self, group_name, email):
        if group_name in self.groups:
            self.groups[group_name].append(email)
            print(f"{email} joined group {group_name}.")
        else:
            print("Group not found.")