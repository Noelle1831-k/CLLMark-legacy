def generate_report(anomalies):
    try:
        if anomalies is not None and not anomalies.empty:
            print("Generating report for anomalies...")
            # Placeholder for report generation logic
            # Example: save_report_to_file(anomalies)
        else:
            print("No anomalies to report.")
    except Exception as e:
        print(f"Error generating report: {e}")