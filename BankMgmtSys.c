#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

struct record{
    char firstName[10], lastName[10];
    char city[15], state[15];
    char phone[15], dob[12];
    int age, accountNo;
    float balance;
};

void MenuOrExit(){
    int choice;
    printf("\n\n\tEnter 1 for main menu, 0 for exit: ");
    scanf("%d",&choice);
    if(choice==1)
    mainMenu();
    else
    exit(1);
}

void createAcc(){
    system("cls");
    struct record create;
    int verify;
    FILE *fp;
    fp=fopen("record.dat","a+");

    printf("\n\tCREATING A NEW ACCOUNT");
    printf("\n\t_____________________________________________________________\n");
    printf("\n\t>> Create an account no.(4-digit): ");
    fscanf(stdin,"%d",&verify);
    while(!feof(fp)){
        fscanf(fp,"%d %s %s %d %s %s %s %s %f",&create.accountNo, create.firstName, create.lastName, &create.age, create.phone, create.city, create.state, create.dob, &create.balance);
        //fprintf(stdout,"%d %s %s %d %s %s %s %s %.2f",create.accountNo, create.firstName, create.lastName, create.age, create.phone, create.city, create.state, create.dob, create.balance);
        if(verify==create.accountNo){
            printf("\tAccount no. already exist, try another!\n");
            Sleep(4000);
            createAcc();
        }
    }
    create.accountNo=verify;
    printf("\n\t>> Enter your full name: ");
    fscanf(stdin,"%s %s",create.firstName, create.lastName);
    printf("\n\t>> Enter your age: ");
    fscanf(stdin,"%d",&create.age);
    printf("\n\t>> Enter your phone no.: ");
    fscanf(stdin,"%s",create.phone);
    printf("\n\t>> Enter you address(city state): ");
    fscanf(stdin,"%s %s",create.city, create.state);
    printf("\n\t>> Enter your DOB(dd/mm/yyyy): ");
    fscanf(stdin,"%s",create.dob);
    printf("\n\t>> Enter account balance(deposit): ");
    fscanf(stdin,"%f",&create.balance);

    fprintf(fp,"\n%d %s %s %d %s %s %s %s %.2f",create.accountNo, create.firstName, create.lastName, create.age, create.phone, create.city, create.state, create.dob, create.balance);
    printf("\n\n\t   Account created successfully!\n\n");
    fclose(fp);
    MenuOrExit();
}

void list(){
    struct record client;
    int choice, adminPIN;
    system("cls");
    FILE *fp;
    fp=fopen("record.dat","r");
    if(fp==NULL){
        printf("File not found!");
        exit(1);
    }
    printf("\n\tVIEW CLIENT'S LIST");
    printf("\n\t_____________________________________________________________\n");
    printf("\n\t< 1 >\tAdministration access\n\t< 2 >\tNormal access\n\t< 3 >\tExit\n");
    printf("\n\tEnter here: ");
    scanf("%d",&choice);

    if(choice==1){      //Data for Admin
    printf("\n\tEnter PIN for administration access: ");
    scanf("%d",&adminPIN);   
        if(adminPIN==6666){
            system("cls");
            printf("\n ID \t\t Full Name  \t  Age\t   Phone no.\t\tAddress\t\t\t D.O.B \t     Balance\n");
            printf(" -----------------------------------------------------------------------------------------------------------\n");
            while(!feof(fp)){
                fscanf(fp,"%d %s %s %d %s %s %s %s %f",&client.accountNo, client.firstName, client.lastName, &client.age, client.phone, client.city, client.state, client.dob, &client.balance);
                fprintf(stdout," %d %15s %-12s %d %15s %15s %-13s %s \t \033[1;32m $ %.2f\033[0m\n",client.accountNo , client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
            }
            MenuOrExit();
        }
    }
    else if(choice==2){
        system("cls");
        printf("\n ID \t\t Full Name  \t  Age\t\tAddress\n");
        printf(" ----------------------------------------------------------------\n");
        while(!feof(fp)){
            fscanf(fp,"%d %s %s %d %s %s %s %s %f",&client.accountNo, client.firstName, client.lastName, &client.age, client.phone, client.city, client.state, client.dob, &client.balance);
            fprintf(stdout," %d %15s %-12s %d %15s %-13s\n",client.accountNo , client.firstName, client.lastName, client.age, client.city, client.state);
        }
        MenuOrExit();
    }
    else if(choice==3)
    exit(1);
    else{
        printf("\n\tInvalid option!\n");
        Sleep(2000);
        list();
    }
}

void mainMenu(){
    int choice;
    system("cls");
    printf("\n\t****************[ BANKING MANAGEMENT SYSTEM ]****************\n\n\n\n");
    printf("\tMAIN MENU");
    printf("\n\t-------------------------------------------------------------\n");
    printf("\t[1] Register new account\n");
    printf("\t[2] Update existing account information\n");
    printf("\t[3] Transactions\n");
    printf("\t[4] Check your account details\n");
    printf("\t[5] Delete existing account\n");
    printf("\t[6] View client's list\n");
    printf("\t[7] Exit\n\n");
    printf("\tEnter choice here: ");
    scanf("%d",&choice);
/*
    switch(choice){
        case 1:
            createAcc();
            break;
        case 2:
            update();
            break;
        case 3:
            transactions();
            break;
        case 4:
            search();
            break;
        case 5:
            delete();
            break;
        case 6:
            list();
            break;
        case 7:
            exit(1);
        default:
            printf("\tInvalid option!\n");
            Sleep(2000);
            mainMenu();
    }
    */
}
int main(){
    list();
    /*
    char username[10], password[10];
    int choice;
    system("cls");
    printf("\t****************[ BANKING MANAGEMENT SYSTEM ]****************\n\n\n\n");
    printf("\t\t\t   --- Login required ---\n\n");
    printf("\t\tUsername: ");
    scanf("%s",username);
    printf("\t\tPassword: ");
	scanf("%s",password);

    if(strcmp(username,"naveen")==0 && strcmp(password,"abc123")==0){
        printf("\n\n\t\tPassword matched\n\t\tWelcome!");
    }
    else{
        printf("\n\n\t\tIncorrect login!");
        retry:
        printf("\n\t\tDo you want to try again?\n\t\t[1] --> Yes\n\t\t[0] --> No\n\n\t\tEnter here: ");
        scanf("%d",&choice);
        if(choice==1){
            system("cls");
            main();
        }
        else if(choice==0)
        exit(1);
        else{
            printf("\n\t\tInvalid option!");
            Sleep(2000);
        }
    }
    */

    return 0;
}
