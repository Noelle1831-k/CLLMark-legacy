def export_report():
    with open("vacation_report.json", "w") as file:
        json.dump(vacation.vacation_requests, file)
    print("Report Exported to vacation_report.json")