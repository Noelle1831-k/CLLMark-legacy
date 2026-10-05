def main():
    '''
    Entry point of the application.
    '''
    initialize_components()
    utils.log_activity("ThreatInspector started.")
    file_scanner_instance = file_scanner.FileScanner()
    detected_threats = file_scanner_instance.schedule_scan()
    if detected_threats:
        report_generator_instance = report_generator.ReportGenerator()
        report_generator_instance.generate_report(detected_threats)
        report_generator_instance.provide_recommendations(detected_threats)
    update_manager.UpdateManager().check_for_updates()