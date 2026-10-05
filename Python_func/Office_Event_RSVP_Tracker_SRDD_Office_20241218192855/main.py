def main():
    event_manager = EventManager()
    rsvp_manager = RSVPManager()
    guest_list_manager = GuestListManager()
    report_generator = ReportGenerator()
    calendar_integration = CalendarIntegration()
    # Example usage
    event_id = event_manager.create_event("Office Party", "2023-12-25", "Main Hall")
    guest_list_manager.add_guest(event_id, "John Doe", "john@example.com")
    rsvp_manager.send_invitation(event_id, "john@example.com")
    rsvp_manager.track_response(event_id, "john@example.com", "Accepted")
    report_generator.generate_attendance_report(event_id)
    calendar_integration.sync_with_calendar(event_id)