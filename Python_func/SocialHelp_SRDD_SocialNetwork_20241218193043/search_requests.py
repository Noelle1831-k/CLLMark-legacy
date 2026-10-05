def search_requests(self, request_type):
        return [request for request in self.requests if request.request_type == request_type]