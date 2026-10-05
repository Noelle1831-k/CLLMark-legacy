def wants_hint(self):
        response = input("Do you want a hint? (yes/no): ").strip().lower()
        return response == 'yes'