def add_interest(self, interest):
        if interest not in self.interests:
            self.interests.append(interest)
            print(f"Interest {interest} added successfully.")
        else:
            print(f"Interest {interest} already exists.")