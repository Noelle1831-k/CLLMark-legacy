def view_family_members(self):
        if self.family_members:
            print("Family Members:")
            for member in self.family_members:
                print(f"- {member.name}")
        else:
            print("No family members found.")