def update_profile(self, email, new_name=None, new_password=None):
        for user in self.users:
            if user['email'] == email:
                if new_name:
                    user['name'] = new_name
                if new_password:
                    user['password'] = new_password
                print(f"Profile updated for {email}.")
                return
        print("User not found.")