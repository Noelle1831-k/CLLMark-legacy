def decline_request(self):
        self.status = "Declined"
        print(f"Mentorship request declined by {self.professional.name}.")