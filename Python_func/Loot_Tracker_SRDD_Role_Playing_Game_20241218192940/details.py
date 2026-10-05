def details(self):
        """
        Returns a detailed string representation of the item.
        """
        return (f"Name: {self.name}, Category: {self.category}, Quantity: {self.quantity}, "
                f"Description: {self.description}, Expiration Date: {self.expiration_date or 'None'}")