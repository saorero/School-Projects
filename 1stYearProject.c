
//This is a hospital based program that consists of services a regular hospital offers
//The aim of the program is to ease the burden that hospitals have in keeping track of their patients records and also
//helping people to access hospital services more easily through the patient /random user option
//Through this  program one will be able to book appointments,purchase medicine,check progress among others
//It will also allow doctors to write down their patients medical reports and keep track of their visitations systematically instead of doing a write up
//The doctor will also have a form of diary whereby they can write their scheduled appointments
//It will also have an interactive session where users can play a game to relax their mind
//Patients will be able to get their medical history easily instead of going to the hospital physically by checking the patients details file

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void catalogue()//A function that consists of what the program has
{
    int choice;
printf("\n\nChoose the option that best fits you from the catalogue.\n");
 printf("\n\t\t#############\n");
    printf("\t\t##CATALOGUE##\n");
     printf("\t\t#############\n");
printf("\t1.A doctor at Afya Bora\n\t2.Patient/Random user\n\t3.Games Corner\n\t4.Exit\n");
printf("~Enter either 1,2,3 or 4:");
scanf("%d",&choice);

   switch(choice)//Based on the user inputs other functions are called;
    {
    case 1:
        doctor();//write up their patients details and scheduled appointments
        break;
    case 2:
        user();//Allows patients to check on their appointments,book for services ,purchase drugs
        break;
    case 3:
        game();//an interactive game to keep people busy when idle in the system
        break;
    case 4:
        Exit();
        break;
    default:
        printf("Please enter a valid choice");
     }
}
/**************************************************/
void Exit()
{
    printf("\n\t\tThank you for choosing Afya Bora ");
}

/***************************************/
void doctor()//Doctors function that carries out all the activities involving a doctor

{
system("cls");

char option;
        char name[80];
    int wish,number,password[5];


    printf("\n\t############\n\tD O C T O R'S####\n\tS E C T I O N####\n\t############\n");
    printf("\n-~Enter your details first to begin.\n");
        printf("Doctor's Name:");
        scanf(" %[^\n]s",name);
        printf("Doctor's Number:");
        scanf("%d",&number);


    printf("\n~~~Hello Dr.%s choose what you would like to do(Enter a/b)::",name);
    printf("\n\n\t\ta)Write up your appointments in a diary\n\t\tb)Enter a patient details\n ");
    printf("OPTION:");
    scanf("%s",&option);
    system("cls");
      if(option=='a')
      {
          printf("\t!!!!!!!!!!!!!!!\n\t!DOCTORS DIARY!\n\t!!!!!!!!!!!!!!!\n");
          printf("Welcome to Afya Bora doctors diary\nwrite up all your scheduled appointments.\n");

          appointments(name);//Calls the function that carries out appointment writting

          printf("\nYour appointments have been successfully stored in the doctors diary file\n");

          printf("\nDo you wish to go back to the catalogue(press 1) or exit the program(press 2) \n");
          scanf("%d",&wish);
                //a switch case that decides the action of the doctor
                 system("cls");
                switch(wish)
                {
                case 1:
                    catalogue();//calls back catalogue again for the user to choose another option
                case 2:
                    Exit(1);//will exit the program immediately

                }

    }
      else if(option=='b')
      {
       patient(); //calls the patients function to enter patients details
      }
      else{
            printf("OOPS!!!Please enter a valid choice\n");
        catalogue();
      }


}
/*******************************************************/
void appointments(char name[])//Afunction that inputs all the doctors appointment
{
     FILE *doctors_diary;
        doctors_diary=fopen("doctors_diary.txt","a");
        if(doctors_diary==NULL)
        {
            printf("File does not exist");
            exit(1);
        }


    //After the doctor has written up all his appointments they will
    //be stored in a file known as doctors_appointment
       char date[20],namep[30],time[20],edate[20],opt;
       char description[200];
       int i,count=0;//helps in counting the number of appointments entered by the doctor

printf("\n\n\t\t####DR.%s Appointments####",name);
       printf("\nDate of entry(DD/MM/YY):");
        scanf("%s",&edate);
        fprintf(doctors_diary,"\n\t\t****DOCTORS DIARY AFYA BORA****\n");
        fprintf(doctors_diary,"\n\t##DR.%s Appointments##\n",name);
        fprintf(doctors_diary,"\t\tDate of Entry:%s\n",edate);
        do
        {
            printf("\n\t!!!Appointment %d!!!\n",count+1);
            printf("Scheduled date:");
            scanf("%s",date);


            printf("Patient's name:");
            scanf(" %[^\n]s",namep);
             printf("Time:(in the format HH:MM)");
            scanf("%s",time);
             printf("Brief Description:\n");

             scanf(" %[^\n]s",description);
            printf("Do you wish to enter another appointment(y/n)\n");
            scanf("%s",&opt);
            count++;
            fflush(stdin);
        //what would be printed in the diary

        fprintf(doctors_diary,"\n!!!Appointment %d!!!\nScheduled Date:%s\nPatients Name:%s\n",count,date,namep);
        fprintf(doctors_diary,"Description:%s\n",description);

        }while(opt=='y');


fprintf(doctors_diary,"\tThe total number of appointments entered by DR.%s is %d \n",name,count);
fclose(doctors_diary);
}
/**************************************/
struct patients//A user defined structure that consists of all variables used in the patients category
{
char namep2[30];
int age;
char illness[30],docname[35],drugs[40],daten[10],dates[10];
int op;

}details;
void patient()//This will work when the doctor enters b as the option (patients details)

{

    FILE *patients_file;
        patients_file=fopen("patients_details.txt","a");//opens the file that stores the patients details
        if(patients_file==NULL)
        {
            printf("File does not exist");
            exit(1);
        }

    printf("\t!!!!!!!!!!!!!!!\n\t!PATIENTS DETAILS AFYA BORA!\n\t!!!!!!!!!!!!!!!\n");
    printf("\nEnter the patients details to be saved in the hospital database\n");
    fprintf(patients_file,"\n****AFYA BORA PATIENTS DETAILS****\n");
    do
    {
        printf("\tPatients Name:");
        scanf(" %[^\n]s",details.namep2);
        printf("\tServed by Dr:");
        scanf(" %[^\n]s",details.docname);
        printf("\tDate of Visit:");
        scanf(" %s",details.dates);
        printf("\tIllness:");
        scanf(" %[^\n]s",details.illness);
        printf("\tPrescription:(brief)");
        scanf(" %[^\n]s",details.drugs);
        printf("\tNext Appointment(date):");
        scanf(" %s",details.daten);

        printf("Do you wish to enter another patients details(y/n)\n");
            scanf("%s",&details.op);

            fprintf(patients_file,"Patients Name:%s\nServed by Dr.%s\nDate of Visit:%s\n",details.namep2,details.docname,details.dates);
            fprintf(patients_file,"Illness:%s\nPrescription:%s\nNext Appointment:%s\n",details.illness,details.drugs,details.daten);


    }while(details.op=='y');
    printf("****The patients details have been successfully saved in the system****\n");
    fclose(patients_file);
    catalogue();//goes back to the catalogue


}

/***************************************************/
void user()//A function that carries out patient's services that can be offered in a hospital
{
    int option,doses,type=0;
    int total=0;
    char drug[20],wish;
    system("cls");
    printf("\n**************************************\n");
    printf("WELCOME TO AFYA BORA PATIENT/USER SECTION\n");
    printf("**************************************\n");
    printf("\nChoose which service you would like to access:\n");
    printf("1.Book an appointment/ambulance\n2.Purchase Drugs\n3.Check your progress\n");
    printf("Service choice:");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
         booking2();
        printf("\n\t\t****Congratulations****\n\tYour appointment has been booked successfully\n");
        printf("\nYou will be contacted as soon as your appointment is confirmed\n");
        printf("Or keep on checking the patients booking file for confirmation\n");
        catalogue();
        break;
    case 2://For purchasing drugs
        //A do while statement that allows the user enter as many drugs
        //as they wish
        system("cls");
        do
        {
        printf("\n\tPHARMACEUTICAL STORE::\n");
        printf("Enter the drug you wish to purchase-");
        scanf(" %[^\n]s",drug);
         printf("How many doses do you wish to purchase-");
        scanf("%d",&doses);
        srand(time(0));
        int price=(rand()%800+500);//used to generate random prices for the drugs entered by the patient
        printf("The price for one dose is %d\n",price);
        int cost=(doses*price);
        printf("The total amount to be paid for the drug is**KSHs.%d\n",cost);

        total=total+cost;
        printf("Wish to enter another drug(y/n)?");
        scanf("%s",&wish);
        type++;
        fflush(stdin);
        }while(wish=='y');
        printf("\nYou have ordered %d types of drugs\n",type);
        printf("The total cost of order=KSHs.%d\n",total);
        printf("\t#Kindly pick your drugs at the counter.\n");
        printf("\n");
        catalogue();

    break;
    case 3://Checking the ^patients progresss in terms of bookings
     printf("\nPlease open the patients booking file to check whether your appointments have been confirmed\n");
     catalogue();
     break;
    default:
        printf("Please enter a valid option\n");
        user();//Calls back the menu again for the user to choose

    }


}

int booking1()//Takes in the choice from the user
{
    system("cls");
    int choice;
    printf("\nAFYA BORA BOOKING SERVICES.\n");
    printf("Do you wish to book an appointment or an ambulance\n");
    printf("#HINT:Enter 1 for appointment or 2 for  ambulance\n");
    scanf("%d",&choice);
    return choice;
}

void booking2()//A function that deals with the patient's bookings
{
    char name[40],service[25],date[20],location[20],time[15],describe[200];
    int numberp,choice;
FILE *patients_booking;//A file that saves the appointments booked by patients
        patients_booking=fopen("patients_booking.txt","a");//opens the file that stores the patients bookings
        if(patients_booking==NULL)
        {
            printf("File does not exist");
            exit(1);
        }

choice=booking1();  //  Gets the choice that the user has selected from booking function

//Depending on the input gotten from the user an if statement is used
    if (choice==1)
    {

    //choice 1 for booking an appointment
   printf("\nWe are so happy you are booking an appointment with Afya Bora Hospital\n");
   printf("Enter the details below for your booking:\n");
   printf("\t*Name:");
   scanf(" %[^\n]s",name);
   printf("\t*What service are you intrested in (general,dental etc.):");
   scanf(" %[^\n]s",service);
   printf("\t*Give a brief description of your condition:");
   scanf(" %[^\n]s",describe);

   printf("\t*Preferred date:");
   scanf(" %[^\n]s",date);
   printf("\t*Phone number:");
   scanf("%d",&numberp);
   fprintf(patients_booking,"\t!!!!!!!!!!!!!!!!!\n\tPATIENTS'S BOOKING\n\t!!!!!!!!!!!!!!!!!!\n");
   fprintf(patients_booking,"\n*Patients Name:%s\n*Category:%s\n* Brief Description:%s\n*Date:%s\n",name,service,describe,date);
   fprintf(patients_booking,"*Phone Number:+254%d\n",numberp);
    }
    else if(choice==2)
    {
        //Ambulance booking
        printf("\tAMBULANCE BOOKING\n");
        printf("Enter the details\n");
         printf("\t*Name:");
        scanf(" %[^\n]s",name);
        printf("\t*Phone number:");
   scanf("%d",&numberp);
   printf("\t*Location:");
   scanf(" %[^\n]s",&location);
   printf("\t*Date:");
   scanf("%s",&date);
   printf("\t*Time(HH:MM):");
   scanf("%s",&time);
        fprintf(patients_booking,"\t!!!!!!!!!!!!!!!!!\n\tAMBULANCE BOOKING\n\t!!!!!!!!!!!!!!!!!\n");
        fprintf(patients_booking,"\n*Patients Name:%s\n*Phone Number:+254%d\n*Location:%s\n",name,numberp,location);
        fprintf(patients_booking,"*Date:%s\tTime:%s\n",date,time);
    }
    else
    {
        //in case the user enters an invalid option
        printf("\nPlease enter a valid option\n");
        booking1();//calls back the other function so as to select a valid option
    }
    fclose(patients_booking);

}



/**************************************************/
void game()

{

    system("cls");//clears the previous section
    printf("\t\t*******************\n");//Design for the interface
printf("\t\t ******GAMING******\n\t\t   ****CORNER****\n");
 printf("\t\t     **********\n");
    printf("\n");
    printf("Games are believed to help ones mental health through distraction\n");
    printf("^Are you good in guessing?\n^Then prove yourself by playing this guessing game:\n");
    guess();

}
 struct game//A user defined structure to hold all the variables used in the game function
{
    int guess;
    char wish;
    int round,i;
    int attempt;
};
void guess()

{
    struct game play;

play.round=0;//Sets the round to 0
printf("\n\nHow many rounds do you wish to play in this game:");
scanf("%d",&play.round);

    for(play.i=0;play.i<play.round;play.i++)
    {

srand(time(NULL));
    int num=(rand()%60)+1;//allows users to guess numbers between 1 and 60


    printf("\n\t\t##########\n");
    printf("\t\t@@ROUND%d##\n",play.i+1);
     printf("\t\t##########\n");
    play.attempt=0;
            do{//do while loop that deals with  the number guess

                   printf("\nEnter a number guess:\n");
                   scanf("%d",&play.guess);
                   if (num==play.guess)
                   printf("Your guess is right\n");
                   else if(play.guess<num)
                    printf("OOPS!!guess a higher number\n");
                   else if(play.guess>num)
                   printf("OOPS!!guess a lower number\n");
                  play.attempt++;

                    }while(play.guess!=num);
        printf("The total attempts in @@Round %d is %d\n",play.i+1,play.attempt);

   play.attempt=0; //resets the number of attempts to 0 in the other round


}

        printf("\nTotal number of rounds played is: %d\n",play.round);
        printf("I hope you had fun\n");
        catalogue();

}

void main()
{
printf("\t\t*******************\n");//Design for the interface that includes hospitals name
printf("\t\t ******AFYA******\n\t\t   ****BORA****\n");
printf("\t\t    *HOSPITAL*\n\t\t      ******\n");
printf("\t\t        ***\n\t\t\t *\n\t\t\t !\n\t****WELCOME TO AFYA BORA SYSTEM****\n\n\n");
printf("~This system allows you to book appointments,purchase drugs online\n~make enquiries,relaxing mind games among others\n");
printf("~If you are a doctor then this is it ,keep track of your patients health with ease\n\n");
catalogue();//Calls the catalogue function that prompts a decision from the user




}

