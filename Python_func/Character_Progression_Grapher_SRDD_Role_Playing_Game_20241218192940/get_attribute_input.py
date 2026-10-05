def get_attribute_input(self):
        while True:
            try:
                name = input("Enter attribute name: ")
                value = int(input("Enter attribute value: "))
                return {name: value}
            except ValueError:
                print("Invalid input! Attribute value must be an integer.")