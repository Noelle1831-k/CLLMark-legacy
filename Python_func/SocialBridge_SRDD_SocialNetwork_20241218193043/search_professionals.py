def search_professionals(self, field_of_study):
        professionals = [user for user in self.database.get_users() if user.role == "Professional" and user.field_of_study == field_of_study]
        print(f"Found {len(professionals)} professionals in {field_of_study}.")
        return professionals