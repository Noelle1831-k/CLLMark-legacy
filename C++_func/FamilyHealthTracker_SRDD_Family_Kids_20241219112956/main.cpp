int main() {
    HealthTracker healthTracker;
    AppointmentScheduler appointmentScheduler;
    HealthArticles healthArticles;
    GoalManager goalManager;
    FamilyMember member1("John", 35, 70.5, 175, 120, 80);
    FamilyMember member2("Jane", 32, 60.0, 165, 110, 70);
    healthTracker.addFamilyMember(member1);
    healthTracker.addFamilyMember(member2);
    healthTracker.viewAllFamilyMembers();
    appointmentScheduler.addAppointment("2024-01-10", "Annual Check-up for John");
    appointmentScheduler.addAppointment("2024-01-15", "Dental Appointment for Jane");
    appointmentScheduler.displayAppointments();
    healthArticles.addArticle("Nutrition Tips for Healthy Living", "Eat balanced meals and stay hydrated.");
    healthArticles.addArticle("Mental Health Awareness", "Take time for self-care and stress management.");
    healthArticles.displayArticles();
    goalManager.addGoal("John", "Lose 5kg in 3 months");
    goalManager.addGoal("Jane", "Walk 10,000 steps daily");
    goalManager.displayGoals();
    return 0;
}