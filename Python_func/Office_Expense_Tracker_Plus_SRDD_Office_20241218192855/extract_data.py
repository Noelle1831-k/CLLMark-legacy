def extract_data(self, text):
        '''
        Extracts data from a scanned receipt text.
        Parameters:
        text (str): The text extracted from the receipt image.
        Returns:
        dict: A dictionary containing extracted data such as total amount, date, and items.
        '''
        try:
            # Initialize a dictionary to store extracted data
            data = {
                'total': None,
                'date': None,
                'items': []
            }
            # Regular expressions for extracting total amount and date
            total_regex = r"total\s*[:\-]?\s*\$?(\d+\.\d{2})"
            date_regex = r"(\d{2}[\/\-]\d{2}[\/\-]\d{4})"
            # Find total amount
            total_match = re.search(total_regex, text, re.IGNORECASE)
            if total_match:
                data['total'] = float(total_match.group(1))
            # Find date
            date_match = re.search(date_regex, text)
            if date_match:
                data['date'] = date_match.group(1)
            # Extract items (this is a simplified example)
            lines = text.split('\n')
            for line in lines:
                if re.search(r'\d+\.\d{2}', line):
                    item = self.extract_item(line)
                    if item:
                        data['items'].append(item)
            return data
        except Exception as e:
            print(f"Error extracting data: {e}")
            return {}