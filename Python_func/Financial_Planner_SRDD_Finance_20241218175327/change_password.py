def change_password(self, old_password, new_password):
        if self.authenticate(old_password):
            self.password = new_password
            return True
        return False