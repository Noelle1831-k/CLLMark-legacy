def add_family_member(self):
        name = input("Enter family member's name: ")
        member = FamilyMember(name)
        self.family_members.append(member)
        print(f"Family member {name} added.")