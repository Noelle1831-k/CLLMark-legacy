def parse_date(self, date_string):
        return datetime.strptime(date_string, "%Y-%m-%d %H:%M")