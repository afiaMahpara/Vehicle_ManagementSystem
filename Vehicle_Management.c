
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void head_message();
void print_message_in_center();
void login();
void welcome_message();
int is_Name_Valid(char x[]);
int is_Date_Valid(int date, int month, int year);
void choice();
void menu();
void menu_details( );
void addVehicleInDataBase();
void searchVehicles();
void viewVehicles();
void deleteVehicles();
void updateCredential();
struct extra
{
    char center_message[100];
    int a;
    int ch;
};
struct login
{
    char username[20];
    char password[20];
    char validUsername[100] ;
    char validPassword[100] ;
};
struct vehicle_information
{
    int vehicle_id;
    char vehicle_name[50];
    char vehicle_manufacturer_name[50];
    int date,month,year;
};

struct vehicle_information temp[100];
struct login pass;
struct extra ex;
int main()
{
    int ch;
    system("COLOR 02");
    char center_message[100]="CSE 103 Mini Project";
    struct login *ptr=&pass;
    strcpy(pass.validUsername,"CSE103");
    strcpy(pass.validPassword,"CSE103");
    ex.a=0;
    head_message(center_message);
    welcome_message();
    login();
    return 0;
}
int validateLogin(char username[], char password[])
{
    return (strcmp(username, pass.validUsername) == 0 && strcmp(password, pass.validPassword) == 0);
}

void login()
{
    struct login lo;
    char valid_username[50],valid_pass[50];
    char center_message[]="Login";
log:
    head_message(center_message);
    printf("Please log in:\n");
    printf("Username: ");
    gets(lo.username);
    printf("Password: ");
    int i=0;
    while(1)
    {
        lo.password[i]= getch();
        printf ("*");
        if(lo.password[i]==13)
        {
            lo.password[i]='\0';
            break;
        }
        i++;
    }
    if (validateLogin(lo.username, lo.password))
    {
        printf("\nLogin successful!\n\n\n");
        menu();
        choice();
        menu_details();
    }
    else
    {
        printf("\nInvalid login credentials. Access denied.Please try again.\n");
        printf("Press any key to continue.......");
        getche();
        goto log;
    }
}

void menu()
{
    char center_message[] = "Menu";
    head_message(center_message);
    printf("1.Add vehicles\n2.Search vehicles\n3.View vehicles\n4.Delete Vehicles\n5.Update password\n6.Exit\n");
}
void menu_details()
{
    switch(ex.ch)
    {
    case 1:

        addVehicleInDataBase();
        break;

    case 2:

        searchVehicles();
        break;

    case 3:

        viewVehicles();
        break;
    case 4:
        deleteVehicles();
        break;
    case 5:
        updateCredential();
        break;
    case 6:
        printf("Thank You");
        exit (0);

    default:
        printf("\nEnter the wrong button.Enter Right KEY\n\n");
        printf("Press any key to continue.......");
        getche();

        break;
    }

    menu();
    choice();
    menu_details();

}
void choice()
{

    printf("\nEnter choice:");
    scanf("%d",&ex.ch);
    scanf("%*c");

}
void addVehicleInDataBase()

{
    int a=ex.a;
    char center_message[]="Add Vehicles";
    head_message(center_message);
    printf("\nEnter Vehicles Details Below:\n\n");
    printf("Vehicle id no= ");
    scanf("%d",&temp[a].vehicle_id);
    scanf("%*c");
name:
    printf("Vehicle name= ");
    gets(temp[a].vehicle_name);

    if(is_Name_Valid(temp[a].vehicle_name)==0)
    {
        printf("\n\nYou have given invalid name......Try again by pressing any key.....\n\n");
        goto name;
    }
manufacture:
    printf("Vehicle  Manufacturer name=");
    gets(temp[a].vehicle_manufacturer_name);

    if(is_Name_Valid(temp[a].vehicle_manufacturer_name)==0)
    {
        printf("\n\nYou have given invalid name......Try again by pressing any key.....\n\n");
        goto manufacture;
    }
date:
    printf("Vehicle issued date by Manufacture(date/month/year):");
    scanf("%d%*c%d%*c%d",&temp[a].date,&temp[a].month,&temp[a].year);

    is_Date_Valid(temp[a].date,temp[a].month,temp[a].year);
    if(is_Date_Valid(temp[a].date,temp[a].month,temp[a].year)==0)
    {
        printf("\n\nYou have given invalid date......Try again by pressing any key.....\n\n");
        goto date;

    }

    ex.a++;

}

void searchVehicles()

{

    char vehicle_search[100];
    char center_message[]="Search Vehicles";
    head_message(center_message);
    int i,flag=0;
    int t[100],j=0;
    printf("\nSearch vehicles:\n\n");
    if(ex.a>0)
    {
        printf("\nEnter vehicles name to search:");
        gets(vehicle_search);


        for(i=0; i<ex.a; i++)
        {
            if(strcmp(temp[i].vehicle_name,vehicle_search) == 0 )
            {
                t[j]=i;
                j++;
                flag=1;

            }

        }
        if(flag==1)
        {
            printf("Number of times found = %d\n\n",j);
            for(i=0; i<j; i++)
                printf("Vehicle ID no: %d\nVehicle Name: %s\nVehicle Manufacturer Name: %s\nIssued date by Manufacturer(date/month/year): %d/%d/%d\n\n\n",temp[t[i]].vehicle_id,temp[t[i]].vehicle_name,temp[t[i]].vehicle_manufacturer_name,temp[t[i]].date,temp[t[i]].month,temp[t[i]].year);

        }

        else
            printf("\nNo record\n\n");

    }
    else
        printf("\nNo data\n\n");

    printf("Please press any key to continue.......");
    getche();

}

void deleteVehicles()
{

    char center_message[]="Delete Vehicles";
    head_message(center_message);
    int vehicle_id_no,delete_vehicle_id_no;
    int flag = 0;
    printf("\nDELETE VEHICLE DETAILS\n");
    printf("\nEnter Vehicle ID NO for Delete:");

    scanf("%d", &delete_vehicle_id_no);
    for (int i = 0; i < ex.a; i++)
    {
        if (temp[i].vehicle_id == delete_vehicle_id_no)
        {
            for (int j = i; j < ex.a - 1; j++)
            {
                temp[j] = temp[j + 1];
            }
            ex.a--;
            flag = 1;
            printf("Record deleted successfully.\n");
            printf("Please press any key to continue.......");
            getche();
            break;
        }
    }

    if (flag==0)
    {
        printf("Record not found.\n");
        printf("Please press any key to continue.......");
        getche();
    }
}

void viewVehicles()
{


    char center_message[]="View Vehicles";
    head_message(center_message);
    int i;

    if(ex.a>0)
    {
        for(i=0; i<ex.a; i++)
        {

            printf("\nCount: %d\n\n",i+1);
            printf("Vehicle ID no: %d\nVehicle Name: %s\nVehicle Manufacturer Name: %s\nIssued date by Manufacturer(date/month/year): %d/%d/%d\n",temp[i].vehicle_id,temp[i].vehicle_name,temp[i].vehicle_manufacturer_name,temp[i].date,temp[i].month,temp[i].year);

        }



    }

    else
        printf("No Data....\n\n\n");
    printf("Please press any key to continue.......");
    getche();

}
void  updateCredential()
{
    char center_message[]="Update Password";
    head_message(center_message);
    char str1[50],str2[50];
    printf("Enter new Username: ");
    scanf("%s",str1);
    printf("\nEnter new Password: ");
    int i=0;
    while(1)
    {
        str2[i]= getch();
        printf ("*");
        if(str2[i]==13)
        {
            str2[i]='\0';
            break;
        }
        i++;
    }
    strcpy(pass.validUsername,str1);
    strcpy(pass.validPassword,str2);
    scanf("%*c");
    login();
}
void head_message(char center_message[])
{
    system("cls");
    int i,j,k;
    for(i=1; i<6; i++)
    {
        for(j=1; j<25; j++)
        {
            if(i==3)
            {
                for(k=j; k<2; k++)





                    printf("<~><~><~><~>\t                                            <~><~><~><~>\n");
                printf("<~><~><~><~>\t      Vehicle Management System\t\t    <~><~><~><~>\n");
                printf("<~><~><~><~>\t                                	    <~><~><~><~>");
                break;

            }
            else printf("<~>");
        }



        printf("\n");
    }
    printf("\n");
    print_message_in_center(center_message);


}
void welcome_message()
{
    int i,j,k,u;



    printf("\n");

    printf("\n\t");
    for(i=1; i<7; i++)
    {



        for(int j=1; j<=15; j++)
        {


            if(i==1 )
            {
                printf("<~>");
            }
            else if(i == 2)
            {
                printf("\t<~>               WELCOME                 <~>");
                break;
            }
            else if(i == 3)
            {
                printf("\t<~>                 TO                    <~>");
                break;
            }
            else if(i == 4)
            {
                printf("\t<~>               VEHICLE                 <~>");
                break;
            }
            else if(i == 5)
            {
                printf("\t<~>              MANAGEMENT               <~>");
                break;
            }
            else if(i == 6)
            {
                printf("\t<~>                SYSTEM                 <~>");


                break;
            }


        }
        printf("\n");


    }


    printf("\t");
    for(int k=1; k<=15; k++)
        printf("<~>");
    printf("\n");
    printf("Please press any key to continue.......");
    getche();
    system("cls");
    printf("\n");



}
void print_message_in_center(char center_message[])
{


    int i,j,space,len=strlen(center_message)-1;
    for(i = 1; i <6 ; i++)
    {

        if(i == 1 || i == 4)
        {
            for(j = 1; j <= 24; j++)

                printf("<~>");

        }


        else if(i == 3)
        {

            for(space=0; space<=(72-len)/2; space++)
                printf(" ");
            printf(center_message);

        }

        printf("\n");


    }

}
int is_Name_Valid(char x[])
{
    int i;
    for(i=0; i< strlen(x) ; i++)
    {
        if ((x[i]>='a' && x[i] <= 'z') || (x[i]>='A' && x[i] <= 'Z') || (x[i]>= '0' && x[i]<= '9')||(x[i]== ' '))
            return 1;

        return 0;
    }


}

int is_Date_Valid(int date, int month, int year)
{
    int is_leap=0;
    if (year >= 1800 && year <= 2030)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            is_leap=1;
        else is_leap = 0;
        if (month >= 1 && month <= 12)
        {
            if ((date >= 1 && date <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
                return 1;
            else if ((date >= 1 && date <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
                return 1;
            else if ((is_leap==0 && (date >= 1 && date <= 28) && month == 2))
                return 1;
            else if (is_leap==1 && (date >= 1 && date <= 29) && month == 2)
                return 1;
            else
                return 0;
        }


    }
    return 0;



}


