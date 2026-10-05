def get_equipment_input(self):
        while True:
            try:
                name = input("Enter equipment name: ")
                value = int(input("Enter equipment value: "))
                return {name: value}
            except ValueError:
                print("Invalid input! Equipment value must be an integer.")