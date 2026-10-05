def request_service(self, service_type):
        '''
        Request a service for the customer.
        '''
        self.requests.append(service_type)
        print(f"{self.name} requested {service_type} service")