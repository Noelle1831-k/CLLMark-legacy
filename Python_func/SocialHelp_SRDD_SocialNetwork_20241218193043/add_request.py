def add_request(self, request_type, description):
        request = Request(request_type, description)
        self.requests.append(request)