def __str__(self):
        members_names = ', '.join([member.name for member in self.members])
        return f"IndustryGroup(industry={self.industry}, members=[{members_names}])"