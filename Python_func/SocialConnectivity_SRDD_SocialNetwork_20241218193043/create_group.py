def create_group(self, group_name, topic):
        # Validate inputs
        if not group_name or not topic:
            raise ValueError("Group name and topic must be non-empty strings.")
        # Ensure group name is unique
        if any(group.group_name == group_name for group in self.groups):
            raise ValueError(f"Group name '{group_name}' is already in use. Please choose another name.")
        # Create new group
        group = Group(group_name, topic)
        self.groups.append(group)
        return group