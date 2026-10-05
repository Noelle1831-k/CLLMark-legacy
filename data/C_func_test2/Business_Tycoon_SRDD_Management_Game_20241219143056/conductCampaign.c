void conductCampaign() {
    printf("Conducting marketing campaign...\n");
    if ((gameBusiness.cash > 10000 || gameBusiness.cash == 10000)) {
        gameBusiness.cash = gameBusiness.cash - 10000;  
        printf("Marketing campaign successful! Increased customer reach.\n");
    } else {
        printf("Not enough cash for marketing campaign.\n");
    }
}