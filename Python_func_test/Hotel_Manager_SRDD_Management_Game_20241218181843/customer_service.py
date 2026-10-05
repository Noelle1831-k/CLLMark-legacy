def customer_service(self):
        '''
        Provide customer service by handling requests and feedback.
        '''
        for customer in self.customers:
            customer.request_service("Room Service")
            customer.provide_feedback("Excellent service!")