def generate_report(self):
        report = {}
        for ticket in self.tickets:
            if ticket.status not in report:
                report[ticket.status] = 0
            report[ticket.status] += 1
        print("Ticket Status Report:", report)