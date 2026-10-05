int main() {
    string playerName;
    cout << "Welcome to FitnessGame! Please enter your name: ";
    cin >> playerName;
    Player player(playerName);
    GameMechanics game;
    Shop shop;
    game.initializeGame(player);
    shop.addItem("Health Potion", 30, 50);
    shop.addItem("Stamina Boost", 40, 70);
    Exercise pushUp("Push-Up", "Basic bodyweight exercise", 3, 20);
    Exercise squat("Squat", "Lower body exercise", 2, 15);
    Workout workout;
    workout.addExercise(pushUp);
    workout.addExercise(squat);
    workout.startWorkout(player);
    workout.completeWorkout(player);
    shop.displayItems();
    shop.purchaseItem(player, 0); 
    game.displayGameStatus(player);
    return 0;
}