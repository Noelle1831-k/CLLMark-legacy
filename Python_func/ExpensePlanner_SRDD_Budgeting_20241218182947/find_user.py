def find_user(self, name):
        for user_obj in self.users:
            if user_obj.name == name:
                return user_obj
        return None