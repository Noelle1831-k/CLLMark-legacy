void request_mentorship() {
    char mentorEmail[50];
    printf("Enter the email of the mentor to request mentorship: ");
    scanf("%s", mentorEmail);
    validate_email(mentorEmail);
    send_mentorship_request(mentorEmail);
    printf("Mentorship request sent successfully.\n");
}