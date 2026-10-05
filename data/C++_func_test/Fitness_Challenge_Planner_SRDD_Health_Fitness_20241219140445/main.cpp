int main(void) {
    UserProfile user;
    user.setUsername("JohnDoe");
    user.setAge(25);
    Exercise pushUps("Push-Ups", 3, 15);  
    Exercise squats("Squats", 4, 20);     
    Exercise running("Running", 5.0);     
    Challenge weightLossChallenge("Weight Loss Challenge", "Weight Loss", 30, 7);
    weightLossChallenge.addExercise(pushUps);
    weightLossChallenge.addExercise(squats);
    weightLossChallenge.addExercise(running);
    user.addChallenge(weightLossChallenge);
    user.viewProgress();
    NotificationManager::sendNotification(user.getUsername(), "Don't forget to complete your exercise for today!");
    return 0;
}