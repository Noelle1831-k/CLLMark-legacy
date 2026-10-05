def submit_complaint(self, description):
        complaint = Complaint(self.customer_id, description)
        return complaint