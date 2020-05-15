#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define size 3

int check(char match[size][size]){
    int sum = 0,i,j,alreadyChecked = 0;
    for(i = 0;i < size;i++){
        sum = 0;
        for(j = 0;j < size;j++){
            sum += match[i][j];
            if(sum == 333 && alreadyChecked != 1){
                return 1;
                alreadyChecked = 1;
                break;
            }else if (sum == 360 && alreadyChecked != 1){
                return 2;
                alreadyChecked = 1;
                break;
            }
        }
    }
    for(i = 0;i < size;i++){
        sum = 0;
        for(j = 0;j < size;j++){
            sum += match[j][i];
            if(sum == 333 && alreadyChecked != 1){
                return 1;
                alreadyChecked = 1;
                break;
            }else if (sum == 360 && alreadyChecked != 1){
                return 2;
                alreadyChecked = 1;
                break;
            }
        }
    }

    sum = 0;
    if(alreadyChecked != 1){
        sum = match[0][0] + match[1][1] + match[2][2];
        if(sum == 333 && alreadyChecked != 1){
            return 1;
            alreadyChecked = 1;
        }else if (sum == 360 && alreadyChecked != 1){
            return 2;
            alreadyChecked = 1;        
        }else{
            sum = 0;
            sum = match[0][2] + match[1][1] + match[2][0];
            if(sum == 333 && alreadyChecked != 1){
                return 1;
                alreadyChecked = 1;
            }else if (sum == 360 && alreadyChecked != 1){
                return 2;
                alreadyChecked = 1;        
            }else{
                return 3;
            }
        }
    }

}

void display(char match[size][size]){
    int i,j;
    system("cls");
    printf("Current Board : \n");
    for(i = 0; i < size;i++){
        printf("| ");
        for(j = 0; j < size;j++){
            printf("%c | ", match[i][j]);
        }
        printf("\n-------------\n");
    }
    printf("\t\b\bEnter Values Like This : Row Column\n");
}

void main(){
    char match[size][size];
    int xin,yin,matchover = 0,currentPlayer = 1,i,j,checkFunction;
    int totalAttemps = 0;
    system("cls");
    for(i = 0; i < size;i++){
        for(j = 0; j < size;j++){
            match[i][j] = ' ';
        }
    }

    do{
        display(match);

        if(currentPlayer == 1){
            printf("\nEnter Value For Player 1 (o) : ");
            scanf("%d %d",&xin,&yin);
            xin - 1 < size && yin - 1 < size && match[xin - 1][yin - 1] == ' ' ? match[xin - 1][yin - 1] = 'o',currentPlayer = 2,totalAttemps += 1 : (printf("Invalid Value Entered.\nEnter Values Again."),sleep(1));
        }else{
            printf("\nEnter Value For Player 2 (x) : ");
            scanf("%d %d",&xin,&yin);
            xin - 1 < size && yin - 1 < size && match[xin - 1][yin - 1] == ' ' ? match[xin - 1][yin - 1] = 'x',currentPlayer = 1,totalAttemps += 1 : (printf("Invalid Value Entered.\nEnter Values Again."),sleep(1));
        }

        checkFunction = check(match);

        if(checkFunction == 1){
            display(match);
            printf("\n\nPlayer 1 Won !");
            matchover = 1;
        }else if(checkFunction == 2){
            display(match);
            printf("\n\nPlayer 2 Won !");
            matchover = 1;
        }else if(checkFunction == 3 && totalAttemps >= 9){
            display(match);
            printf("\n\nNo One Won :(");
            matchover = 1;
        }

    }while(matchover != 1);
    getch();
}
