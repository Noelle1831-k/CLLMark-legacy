def process_news_data(self, raw_data):
        processed_data = []
        for data in raw_data:
            sanitized = utilities.sanitize_text(data)
            if utilities.is_valid_data(sanitized):
                processed_data.append(sanitized)
        return processed_data