void compete_in_tournament() {
    printf("Competing in tournament: %s\n", currentTournament.tournament_name);
    if (myPet.strength + myPet.agility + myPet.intelligence > 30) {
        printf("Congratulations! %s won the tournament!\n", myPet.name);
        printf("Prize: %d gold\n", currentTournament.prize);
    } else {
        printf("Better luck next time!\n");
    }
}