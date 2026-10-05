def update_profile(self, email, new_name=None, new_info=None):
        if email in self.users:
            if new_name:
                self.users[email]['name'] = new_name
            if new_info:
                self.users[email]['profile'].update(new_info)
            print("Profile updated.")
        else:
            print("User not found.")