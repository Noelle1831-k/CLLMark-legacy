def get_skill_input(self):
        while True:
            try:
                name = input("Enter skill name: ")
                value = int(input("Enter skill value: "))
                return {name: value}
            except ValueError:
                print("Invalid input! Skill value must be an integer.")