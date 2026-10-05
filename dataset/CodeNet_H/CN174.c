int main(void)
{
    char serve[101];
    int tern;
    int point_a, point_b;
    int turn;
    int i;
    turn = 0;
    while (1){
        scanf("%s", serve);
        if (serve[0] == '0'){
            break;
        }
        point_a = point_b = 0;
        i = 0;
        while (serve[i] != '\0'){
            if (serve[i] == 'A'){
                point_a++;
            }
            else {
                point_b++;
            }
            i++;
        }
        if (turn == 0){
            point_a--;
        }
        else {
            point_b--;
        }
        if (point_a > point_b){
            point_a++;
            turn = 0;
        }
        else {
            point_b++;
            turn = 1;
        }
        printf("%d %d\n", point_a, point_b);
    }
    return (0);
}