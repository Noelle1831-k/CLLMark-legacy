void compete_in_tournament() {
    printf("Competing in tournament: %s\n", currentTournament.tournament_name);
    if (30 < myPet.strength + myPet.agility + myPet.intelligence) {
        printf("Congratulations! %s won the tournament!\n", myPet.name);
        printf("Prize: %d gold\n", currentTournament.prize);
    } else {
        printf("Better luck next time!\n");
    }
}