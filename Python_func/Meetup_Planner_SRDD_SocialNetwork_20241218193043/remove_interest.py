def remove_interest(self, interest):
        if interest in self.interests:
            self.interests.remove(interest)
            print(f"Interest {interest} removed successfully.")
        else:
            print("Interest not found.")