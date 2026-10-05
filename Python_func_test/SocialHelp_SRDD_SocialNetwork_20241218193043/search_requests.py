def search_requests(self, request_type):
        return [request for request in self.requests if request_type == request.request_type]