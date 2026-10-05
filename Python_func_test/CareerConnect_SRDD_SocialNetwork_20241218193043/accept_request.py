def accept_request(self, request):
        self.requests.append(request)
        print(f"{self.name} accepted the request from {request.user.name}")