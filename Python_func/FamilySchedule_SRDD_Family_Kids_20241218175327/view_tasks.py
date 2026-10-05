def view_tasks(self):
        member_name = input("Enter family member's name: ")
        member = self.find_family_member(member_name)
        if member:
            tasks = member.get_tasks()
            if tasks:
                print(f"Tasks for {member_name}:")
                for task in tasks:
                    print(f"- {task.title} (Due: {task.due_date})")
            else:
                print(f"No tasks found for {member_name}.")
        else:
            print(f"Family member {member_name} not found.")