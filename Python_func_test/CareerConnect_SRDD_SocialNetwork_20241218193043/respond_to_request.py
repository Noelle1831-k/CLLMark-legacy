def respond_to_request(self, response):
        if response == "accept":
            print(f"{self.professional.name} accepted the request")
        else:
            print(f"{self.professional.name} declined the request")