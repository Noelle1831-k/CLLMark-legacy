def generate_calendar(self):
        calendar = CalendarView(self.incomes, self.expenses)
        return calendar.render_calendar()