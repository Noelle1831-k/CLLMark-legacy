def is_date(self, value):
        '''
        Check if a value is a date.
        '''
        date_formats = ["%Y-%m-%d", "%d/%m/%Y", "%m/%d/%Y"]
        for date_format in date_formats:
            try:
                datetime.strptime(value, date_format)
                return True
            except ValueError:
                continue
        return False