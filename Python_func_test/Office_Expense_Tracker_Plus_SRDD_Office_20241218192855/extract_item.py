def extract_item(self, line):
        '''
        Extracts an item from a line of text.
        Parameters:
        line (str): A line of text from the receipt.
        Returns:
        dict: A dictionary containing item name and price.
        '''
        try:
            # Split the line into parts
            parts = line.split()
            # Assume the last part is the price
            price = float(parts[-1])
            # The rest is the item name
            name = ' '.join(parts[:-1])
            return {'name': name, 'price': price}
        except ValueError:
            return None