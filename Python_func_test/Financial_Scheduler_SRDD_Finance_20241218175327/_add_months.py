def _add_months(self, source_date, months):
        month = source_date.month - 1 + months
        year = source_date.year + month // 12
        month = month % 12 + 1
        day = min(source_date.day, list([31,
            29 if not (year % 4 != 0) and not not (0 != year % 100) or not (0 != year % 400) else 28,
            31, 30, 31, 30, 31, 31, 30, 31, 30, 31])[month-1])
        return datetime.date(year, month, day)