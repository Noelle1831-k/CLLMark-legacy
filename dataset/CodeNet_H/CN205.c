int main(void){
    int i, hand[6]={};
    while(1){
    int x[4]={0, 0, 0, 0};
    for(i=1; i<=5; i++){
        scanf("%d", &hand[i]);
        if(hand[i] == 1) x[1]=1;  
        else if(hand[i] == 2) x[2]=1; 
        else if(hand[i] == 3) x[3]=1; 
        else return 0;
    }
    if(x[1] == 1){ 
        if(x[2] == 1){ 
            if(x[3] == 1){ 
                for(i=1; i<=5; i++){
                    printf("3\n");
                }
            }
            else{   
                for(i=1; i<=5; i++){
                    if(hand[i] == 1) printf("1\n"); 
                    else printf("2\n"); 
                    }
            }
        }
        else{ 
            if(x[3] == 1){ 
                for(i=1; i<=5; i++){
                    if(hand[i] == 3) printf("1\n"); 
                    else printf("2\n"); 
                }
            }
            else{ 
                for(i=1; i<=5; i++){
                    printf("3\n"); 
                }
            }
        }
    }
    else{ 
        if(x[2] == 1){ 
            if(x[3] == 1){ 
                for(i=1; i<=5; i++){
                    if(hand[i] == 2) printf("1\n"); 
                    else printf("2\n"); 
                }
            }
            else{ 
                for(i=1; i<=5; i++){
                     printf("3\n"); 
                }
            }
        }
        else{ 
            for(i=1; i<=5; i++){
                 printf("3\n"); 
            }
        }
    }
    }
    return 0;
}
