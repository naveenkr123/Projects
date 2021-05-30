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

//functions declaration
void mainMenu();
void MenuOrExit();
void createAcc();
void update();
void delete();
void list();
void transactions();
void transfer();
void deposit();
void deposit();
void withdraw();
void enquiry();

int main(){
    char username[10], password[10];
    int choice;
    system("cls");
    printf("\n\t****************[ BANKING MANAGEMENT SYSTEM ]****************\n\n\n\n");
    printf("\t\t\t   --- Login required ---\n\n");
    printf("\t\tUsername: ");
    scanf("%s",username);
    printf("\t\tPassword: ");
	scanf("%s",password);

    if(strcmp(username,"naveen")==0 && strcmp(password,"abc123")==0){
        printf("\n\n\t\tWelcome!");
        mainMenu();
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

    return 0;
}

void mainMenu(){
    int choice;
    system("cls");
    printf("\n\t****************[ BANKING MANAGEMENT SYSTEM ]****************\n\n\n\n");
    printf("\tMAIN MENU");
    printf("\n\t-------------------------------------------------------------\n");
    printf("\t[1] Create new account\n");
    printf("\t[2] Update existing account information\n");
    printf("\t[3] Transactions\n");
    printf("\t[4] Check your account details\n");
    printf("\t[5] Delete existing account\n");
    printf("\t[6] View client's list\n");
    printf("\t[7] Exit\n\n");

    printf("\tEnter choice here: ");
    scanf("%d",&choice);
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
            enquiry();
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
}

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

void update(){
    system("cls");
    struct record client;
    int search, found=0, choice;
    FILE *fp, *fp2;
    fp=fopen("record.dat","r");
    fp2=fopen("temp.dat","w");
    if(fp==NULL){
        printf("File not found!");
        exit(1);
    }
    printf("\n\tUPDATE INFORMATION");
    printf("\n\t_____________________________________________________________\n");
    printf("\n\tEnter your account no.: ");
    scanf("%d", &search);
    while(!feof(fp)){
        fscanf(fp,"%d %s %s %d %s %s %s %s %f",&client.accountNo, client.firstName, client.lastName, &client.age, client.phone, client.city, client.state, client.dob, &client.balance);
        if(search==client.accountNo){
            found=1;
            system("cls");
            printf("\n\tUPDATE INFORMATION");
            printf("\n\t_____________________________________________________________\n");
            printf("\n\t< 1 >    Phone no.\n\t< 2 >    Address\n\t< 3 >    D.O.B\n\t< 4 >    Exit\n");
            printf("\n\tEnter here: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    printf("\n\tEnter new Phone no.: ");
                    fscanf(stdin,"%s",client.phone);
                    fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
                    break;
                case 2:
                    printf("\n\tEnter new Address(City, State): ");
                    fscanf(stdin,"%s %s",client.city, client.state);
                    fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
                    break;
                case 3:
                    printf("\n\tEnter new D.O.B(dd/mm/yyyy): ");
                    fscanf(stdin,"%s",client.dob);
                    fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
                    break;
                case 4:
                    exit(1);
                default:
                    printf("\n\tInvalid option!");
                    Sleep(2000);
                    MenuOrExit();
                    break;
            }
        }
        else
        fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
    }
    fclose(fp);
    fclose(fp2);
    remove("record.dat");
    rename("temp.dat","record.dat");

    if(!found){
    printf("\n\tRecord not found!\n");
    Sleep(2000);
    }
    MenuOrExit();
}

void delete(){
    system("cls");
    struct record client;
    int search, found=0, choice;
    FILE *fp, *fp2;
    fp=fopen("record.dat","r");
    fp2=fopen("temp.dat","w");
    if(fp==NULL){
        printf("File not found!");
        exit(1);
    }
    printf("\n\tDELETE ACCOUNT");
    printf("\n\t_____________________________________________________________\n");
    printf("\n\tEnter the account no.: ");
    scanf("%d", &search);
    while(!feof(fp)){
        fscanf(fp,"%d %s %s %d %s %s %s %s %f",&client.accountNo, client.firstName, client.lastName, &client.age, client.phone, client.city, client.state, client.dob, &client.balance);
        if(search==client.accountNo)
            found=1;
            //searched record will be skipped to write in temp file!
        else
            fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
    }
    fclose(fp);
    fclose(fp2);
    remove("record.dat");
    rename("temp.dat","record.dat");

    if(!found){
    printf("\n\tRecord not found!\n");
    Sleep(2000);
    }
    else
    printf("\n\tAccount deleted successfully!\n");
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
    printf("\n\tEnter PIN for admin access: ");
    scanf("%d",&adminPIN);
        if(adminPIN==6666){
            system("cls");
            printf("\n ID \t\t Full Name  \t  Age\t   Phone no.\t\tAddress\t\t\t D.O.B \t     Balance\n");
            printf(" -----------------------------------------------------------------------------------------------------------\n");
            while(!feof(fp)){
                fscanf(fp,"%d %s %s %d %s %s %s %s %f",&client.accountNo, client.firstName, client.lastName, &client.age, client.phone, client.city, client.state, client.dob, &client.balance);
                fprintf(stdout," %d %15s %-12s %d %15s %15s %-13s %s \t \033[1;32m $ %.2f\033[0m\n",client.accountNo , client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
            }
        }
    fclose(fp);
    MenuOrExit();
}

void transactions(){
    system("cls");
    int choice;
    printf("\n\tTRANSACTIONS");
    printf("\n\t_____________________________________________________________\n");
    printf("\n\t< 1 >    Bank to Bank transfer\n\t< 2 >    Deposit amount    \n\t< 3 >    Withdraw amount\n\t< 4 >    Exit\n\n\n\tEnter here: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            transfer();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\n\tInvalid option!");
            MenuOrExit();
            break;
    }
}

void transfer(){
    system("cls");
    struct record client;
    int sender, receiver, found=0, found2=0;
    float money;
    FILE *fp, *fp2;
    fp=fopen("record.dat","r");
    fp2=fopen("temp.dat","w");
    if(fp==NULL){
        printf("File not found!");
        exit(1);
    }

    // DEBIT FROM SENDER'S ACCOUNT
    printf("\n\tBANK TO BANK TRANSFER");
    printf("\n\t_____________________________________________________________\n");
    printf("\n\tEnter your account no.: ");
    scanf("%d", &sender);
    while(!feof(fp)){
        fscanf(fp,"%d %s %s %d %s %s %s %s %f",&client.accountNo, client.firstName, client.lastName, &client.age, client.phone, client.city, client.state, client.dob, &client.balance);
        if(sender==client.accountNo){
            found=1;
            printf("\tEnter the receiver's account no.: ");
            scanf("%d", &receiver);
            printf("\n\t--------------------------------------------------------------");
            printf("\n\tAvailable balance \t : $ %.2f", client.balance);
            printf("\n\tEnter amount to transfer : $ ");
            scanf("%f", &money);
            client.balance-=money;
            printf("\t--------------------------------------------------------------");
            printf("\n\tNew Balance \t\t :\033[1;32m $ %.2f\033[0m\n", client.balance);
            fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
        }
        else
        fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
    }
    fclose(fp);
    fclose(fp2);
    remove("record.dat");
    rename("temp.dat","record.dat");

    //  CREDIT TO RECEIVER'S ACCOUNT
    fp=fopen("record.dat","r");
    fp2=fopen("temp.dat","w");
    while(!feof(fp)){
        fscanf(fp,"%d %s %s %d %s %s %s %s %f",&client.accountNo, client.firstName, client.lastName, &client.age, client.phone, client.city, client.state, client.dob, &client.balance);
        if(receiver==client.accountNo){
            found2=1;
            client.balance+=money;
            fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
        }
        else
        fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
    }
    fclose(fp);
    fclose(fp2);
    remove("record.dat");
    rename("temp.dat","record.dat");

    // REFUNDING DEDUCTED MONEY
    if(!found2){
        printf("\n\tReceiver's account not found!\n");
        fp=fopen("record.dat","r");
        fp2=fopen("temp.dat","w");
            while(!feof(fp)){
                fscanf(fp,"%d %s %s %d %s %s %s %s %f",&client.accountNo, client.firstName, client.lastName, &client.age, client.phone, client.city, client.state, client.dob, &client.balance);
                if(sender==client.accountNo){
                    found=1;
                    client.balance+=money;
                    printf("\tYour deduction has been refunded to your account!");
                    fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
                }
                else
                fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
            }
        fclose(fp);
        fclose(fp2);
        remove("record.dat");
        rename("temp.dat","record.dat");
    }
    else{
        printf("\n\t--------------------------------------------------------------");
        printf("\n\t              *** TRANSFERRED SUCCUSSFULLY ***                ");
        printf("\n\t--------------------------------------------------------------\n");
    }
    MenuOrExit();
}

void deposit(){
    system("cls");
    struct record client;
    int search, found=0;
    float money;
    FILE *fp, *fp2;
    fp=fopen("record.dat","r");
    fp2=fopen("temp.dat","w");
    if(fp==NULL){
        printf("File not found!");
        exit(1);
    }
    printf("\n\tDEPOSIT");
    printf("\n\t_____________________________________________________________\n");
    printf("\n\tEnter your account no.: ");
    scanf("%d", &search);
    while(!feof(fp)){
        fscanf(fp,"%d %s %s %d %s %s %s %s %f",&client.accountNo, client.firstName, client.lastName, &client.age, client.phone, client.city, client.state, client.dob, &client.balance);
        if(search==client.accountNo){
            found=1;
            printf("\n\tAvailable balance\t: $ %.2f", client.balance);
            printf("\n\tEnter amount to deposit : $ ");
            scanf("%f",&money);
            client.balance+=money;
            printf("\t-------------------------------------------------------------");
            printf("\n\tNew Balance \t\t:\033[1;32m $ %.2f\033[0m\n", client.balance);
            fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
        }
        else
        fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
    }
    fclose(fp);
    fclose(fp2);
    remove("record.dat");
    rename("temp.dat","record.dat");

    if(found!=1)
    printf("Record not found!\n");
    MenuOrExit();
}

void withdraw(){
    system("cls");
    struct record client;
    int search, found=0;
    float money;
    FILE *fp, *fp2;
    fp=fopen("record.dat","r");
    fp2=fopen("temp.dat","w");
    if(fp==NULL){
        printf("File not found!");
        exit(1);
    }
    printf("\n\tWITHDRAW");
    printf("\n\t_____________________________________________________________\n");
    printf("\n\tEnter your account no.: ");
    scanf("%d", &search);
    while(!feof(fp)){
        fscanf(fp,"%d %s %s %d %s %s %s %s %f",&client.accountNo, client.firstName, client.lastName, &client.age, client.phone, client.city, client.state, client.dob, &client.balance);
        if(search==client.accountNo){
            found=1;
            printf("\n\tAvailable balance\t : $ %.2f", client.balance);
            printf("\n\tEnter amount to withdraw : $ ");
            scanf("%f",&money);
            client.balance-=money;
            printf("\t-------------------------------------------------------------");
            printf("\n\tNew Balance \t\t :\033[1;32m $ %.2f\033[0m\n", client.balance);
            fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
        }
        else
        fprintf(fp2,"\n%d %s %s %d %s %s %s %s %.2f",client.accountNo, client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob, client.balance);
    }
    fclose(fp);
    fclose(fp2);
    remove("record.dat");
    rename("temp.dat","record.dat");

    if(found!=1)
    printf("Record not found!\n");
    MenuOrExit();
}

void enquiry(){
    system("cls");
    struct record client;
    int search, found=0;
    FILE *fp;
    fp=fopen("record.dat","r");
    if(fp==NULL){
        printf("File not found!");
        exit(1);
    }
    printf("\n\tACCOUNT DETAILS (BALANCE ENQUIRY)");
    printf("\n\t_____________________________________________________________\n");
    printf("\n\tEnter your account no.: ");
    scanf("%d",&search);
    while(!feof(fp)){
        fscanf(fp,"%d %s %s %d %s %s %s %s %f",&client.accountNo, client.firstName, client.lastName, &client.age, client.phone, client.city, client.state, client.dob, &client.balance);
        if(search==client.accountNo){
            found=1;
            system("cls");
            printf("\n\tACCOUNT DETAILS (BALANCE ENQUIRY)");
            printf("\n\t_____________________________________________________________\n");
            fprintf(stdout,"\n\tAccount no.  \t : %d\n\tName   \t\t : %s %s\n\tAge \t\t : %d\n\tPhone no.   \t : %s\n\tAddress  \t : %s, %s\n\tD.O.B \t\t : %s\n",client.accountNo , client.firstName, client.lastName, client.age, client.phone, client.city, client.state, client.dob);
            printf("\t-------------------------------------------------------------\n");
            printf("\tAvailible Balance :\033[1;32m $ %.2f\033[0m\n\n",client.balance);
        }
    }
    if(!found){
        printf("\n\tRecord not found!");
        Sleep(3000);
        enquiry();
    }
    fclose(fp);
    MenuOrExit();
}
