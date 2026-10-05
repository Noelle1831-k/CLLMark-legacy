def format_report(results):
    # Simulate formatting a report
    report = "Security Analysis Report\n"
    report += "=" * 30 + "\n"
    report += f"Date: {datetime.datetime.now()}\n"
    report += "=" * 30 + "\n"
    for result in results:
        report += result + "\n"
    return report