//Finalized
#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>

#include<windows.h>

#include<MMsystem.h>

#include<time.h>

#include<ctype.h>

/*#include<graphics.h>*/

void prisoneraddrecord();

void prisonereditrecord();

void prisonersearchrecord();

void prisonerdeleterecord();

void prisonerviewrecord();

void staffmemberaddrecord();

void staffmembereditrecord();

void staffmemberviewrecord();

void staffmembersearchrecord();

void staffmemberdeleterecord();

void prisonaddrecord();

void prisoneditrecord();

void prisonsearchrecord();

void prisonviewrecord();

void prisondeleterecord();

void login();

void main_menu();

void prisoner_records_menu();

void staff_records_menu();

void prison_records_menu();

void reports_menu();

void reports_one();

void reports_two();

void reports_three();

void reports_four();

void reports_five();

void settings_menu();

int remaining_punishment_time();

void printHistogram();

int age_calculator();

int valid_mobile_number();

int valid_prisoner_id_or_staff_member_id();

int valid_weight();

int valid_height();

int valid_date();

int valid_name();

int valid_condition();

int valid_gender();

int valid_national_id();

int valid_number_of_cells();

int valid_prison_capacity();

int valid_prison_or_cell_number();

int valid_mobile_number();

void system_reset_menu();

void credit();




typedef struct prisoner_record

{

                char id[10];
                char full_name[50];
                char name_with_initials[30];
                char national_id[30];
                char gender[12];
                int prisoner_birth_date;
                int prisoner_birth_month;
                int prisoner_birth_year;
                int age;
                int weight;
                int height;
                char physical_health[10];
                char mental_health[10];
                char specific_illnesses[40];
                char haircolor[20];
                char eyecolor[20];
                char crime[150];
                char court[20];
                char nationality[20];
                int penalty_type;
                char punishment[150];
                int punishment_start_date;
                int punishment_start_month;
                int punishment_start_year;
                int punishment_end_date;
                int punishment_end_month;
                int punishment_end_year;
                char emergencyc[20];
                char emergencyr[20];
                char emergencyn[20];
                int prisoner_prison_id;
                int prisoner_cell_number;

}pr;

typedef struct staff_member_record{
                char id[10];
                char name[50];
                char name_with_initials[40];
                char national_id[30];
                char occupation[30];
                char gender[20];
                int staff_member_birth_date;
                int staff_member_birth_month;
                int staff_member_birth_year;
                int age;
                char staff_member_phone_number[30];
                int staff_member_prison_id;
}sr;

typedef struct prison_record{
                int id;
                char name[30];
                int capacity;
                int cells;
                char prison_phone_number[30];

}prr;

typedef struct users{
                       int user_id;
                       char uname[50];
                       char pword[50];
                       char admin_status[10];
}ur;

//char user_name[20];
//char password[20];
char audio[20];

char audio_switch[10];

char uname[100];

char pword[100];

char user_type[40]="NO USER";

char death_penalty[20];


int main()
{
    system("cls");

    int ch;
    FILE *fp4;
    FILE *fp8;
    FILE *fp9;

    fp4 = fopen( "DATA\\records\\audio" , "r");
    while (fscanf(fp4, "%s", audio_switch)!=EOF)
    fp9 = fopen( "DATA\\records\\Death penalty" , "r");
    fscanf(fp9, "%s", death_penalty)!=EOF;

    login();
    main_menu();

     fclose(fp4);
     fclose(fp8);
     fclose(fp9);
    return 0;
}

void main_menu()
{
fflush(stdin);
int ch=0,count=0,size=0;
char choice='Y';
system("cls");
pr s1;
prr p1;

FILE *fp4,*fp,*fp3;

         if(strcmp(audio_switch,"on")==0)
    {

    mciSendString("close mp3", NULL, 0, NULL);
    mciSendString("open \"DATA\\audio\\a1-main menu.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("play mp3", NULL, 0, NULL);

    }


do{
        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mMAIN MENU\033[1;31m\t\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mPRISONER RECORDS\t\033[1;37m[1]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mSTAFF RECORDS\t\t\033[1;37m[2]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mPRISON RECORDS\t\t\033[1;37m[3]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mREPORTS\t\t\t\033[1;37m[4]\033[1;31m\t\t\t\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mSETTINGS\t\t\033[1;37m[5]\033[1;31m\t\t\t\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mLOG OUT\t\t\t\033[1;37m[6]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEXIT\t\t\t\033[1;37m[7]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
         fp=fopen("DATA\\records\\prisoner records","r");
      while(fread(&s1,sizeof(pr),1,fp))
      {
          if(old_date_finder(s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year))
          {
              count++;
          }
      }
    if(count)
      {
         printf("\n \t\t\033[1;31m|\033[1;36m*  \033[1;37m%d\033[1;36m outdated prisoner record/records.Press \033[1;37m[8]\033[1;36m to check.\t\033[1;31m|",count);
         printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
      }

       fp3 = fopen("DATA\\records\\prison records", "r");

            if (fp3!=NULL)
                {
                    fseek (fp3, 0, SEEK_END);
                    size = ftell(fp3);

                }

            if (size == 0){
               printf("\n \t\t\033[1;31m|\033[1;36m*\033[1;31m There are no prison details in this system.\t\t\t|\n \t\t|  Press\033[1;37m[8]\033[1;31m to add prisons.\t\t\t\t\t|\033[1;31m");
               printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
            }

        printf("\n\n\n\tENTER YOUR CHOICE:");

        scanf("%d",&ch);

        switch(ch)
        {

        case 1:
            prisoner_records_menu();
            break;

        case 2:
            staff_records_menu();
            break;

        case 3:
            prison_records_menu();
            break;

        case 4:
            reports_menu();
            break;

        case 5:
            settings_menu();
            break;
        case 6:
            main();
            break;
        case 7:
            exit_screen();
            break;
        case 8:
            if(count)
                {
                  outdated_prisoner_records();
                }
            if (size == 0)
                {
                    prisonaddrecord();
                }
            break;

        default:
            if(count)
            {
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 8.");
            }
            else
            {
             printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 7.");
            }
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");

            fflush(stdin);
            scanf(" %c",&choice);

        }

}while(choice=='y'||choice=='Y');

}

void prisoner_records_menu()
{

system("cls");
FILE *fp3;
int size=0;

fp3 = fopen("DATA\\records\\prison records", "r");

if (fp3!=NULL)
	{
		fseek (fp3, 0, SEEK_END);
		size = ftell(fp3);
	}

if (size == 0){

    printf("\n\t\033[1;31m-------------------------------------------------------------------------------------------\033[1;31m");
    printf("\n\t*Before adding prisoner records,You have to add prison details to this system.\n\t Go to the \"prison records\" in the main menu and add prison details to the system");
    printf("\n\t\033[1;31m-------------------------------------------------------------------------------------------\033[1;33m");
    printf("\n\n\tPRESS ANY KEY TO GO BACK TO THE MAIN MENU....");
    getch();
    main_menu();
}

char choice='Y';
int ch;
   FILE *fp4;

          if(strcmp(audio_switch,"on")==0)
    {

    mciSendString("close mp3", NULL, 0, NULL);
    mciSendString("open \"DATA\\audio\\a2-prisoner records menu.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("play mp3", NULL, 0, NULL);
    }

do{

        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mPRISONER RECORDS MENU\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mSEARCH PRISONER RECORDS\t\t\033[1;37m[1]\033[1;31m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mPRISONER REGISTRATION\t\t\033[1;37m[2]\033[1;31m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEDIT PRISONER RECORDS\t\t\033[1;37m[3]\033[1;31m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mDELETE PRISONER RECORDS\t\t\033[1;37m[4]\033[1;31m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mVIEW PRISONER RECORDS\t\t\033[1;37m[5]\033[1;31m\t\t\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\t\033[1;37m[6]\033[1;31m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEXIT\t\t\t\t\033[1;37m[7]\033[1;31m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:
            prisonersearchrecord();
            break;

        case 2:
            prisoneraddrecord();
            break;

        case 3:
            prisonereditrecord();
            break;

        case 4:
            prisonerdeleterecord();
            break;
        case 5:
            prisonerviewrecord();
            break;

        case 6:
            main_menu();
            break;

        case 7:
            exit_screen();
            break;

        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 7.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);

        }

}while(choice=='y'||choice=='Y');

}


void staff_records_menu()
{
int ch;
system("cls");
FILE *fp3;
int size=0;

fp3 = fopen("DATA\\records\\prison records", "r");

if (fp3!=NULL)
	{
		fseek (fp3, 0, SEEK_END);
		size = ftell(fp3);
		//printf("Size of the file in bytes: &#37;lu\n", size);
	}


if (size == 0){
    printf("\n\t\033[1;31m-------------------------------------------------------------------------------------------\033[1;31m");
    printf("\n\t*Before adding staff member records,You have to add prison details to this system.\n\t Go to the \"prison records\" in the main menu and add prison details to the system");
    printf("\n\t\033[1;31m-------------------------------------------------------------------------------------------\033[1;33m");
    printf("\n\n\tPRESS ANY KEY TO GO BACK TO THE MAIN MENU....");
    getch();
    main_menu();
}

char choice='Y';

   FILE *fp4;

        if(strcmp(audio_switch,"on")==0)
                {

                mciSendString("close mp3", NULL, 0, NULL);
                mciSendString("open \"DATA\\audio\\a4-staff records menu.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
                mciSendString("play mp3", NULL, 0, NULL);
                }

do{

        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37m STAFF RECORDS MENU\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mSEARCH STAFF MEMBER RECORDS\t\033[1;37m[1]\033[1;31m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mSTAFF MEMBER REGISTRATION\t\033[1;37m[2]\033[1;31m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEDIT STAFF MEMBER RECORDS\t\033[1;37m[3]\033[1;31m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mDELETE STAFF MEMBER RECORDS\t\033[1;37m[4]\033[1;31m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mVIEW STAFF MEMBER RECORDS\t\033[1;37m[5]\033[1;31m\t\t\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\t\033[1;37m[6]\033[1;31m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEXIT\t\t\t\t\033[1;37m[7]\033[1;31m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:
            staffmembersearchrecord();

            break;

        case 2:
            staffmemberaddrecord();
            break;

        case 3:
            staffmembereditrecord();
            break;

        case 4:
            staffmemberdeleterecord();
            break;

        case 5:
            staffmemberviewrecord();
            break;

        case 6:
            main_menu();
            break;

        case 7:
            exit_screen();
            break;

        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 7.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);

        }
       }while(choice=='y'||choice=='Y');

    fclose(fp3);

}


void prison_records_menu()
{
int ch;
system("cls");

char choice='Y';

   FILE *fp4;

     if(strcmp(audio_switch,"on")==0)
                {
                mciSendString("close mp3", NULL, 0, NULL);
                mciSendString("open \"DATA\\audio\\a3-prison records menu.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
                mciSendString("play mp3", NULL, 0, NULL);
                }
do{

        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mPRISON RECORDS MENU\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mSEARCH PRISON RECORDS\t\033[1;37m[1]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mADD NEW PRISON\t\t\033[1;37m[2]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEDIT PRISON RECORDS\t\033[1;37m[3]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mDELETE PRISON RECORDS\t\033[1;37m[4]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mVIEW PRISON LIST \t\033[1;37m[5]\033[1;31m\t\t\t\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\033[1;37m[6]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEXIT\t\t\t\033[1;37m[7]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch);

        switch(ch)
        {

         case 1:
            prisonsearchrecord();
            break;

        case 2:
            prisonaddrecord();
            break;

        case 3:
            prisoneditrecord();
            break;

        case 4:
            prisondeleterecord();
            break;
        case 5:
            prisonviewrecord();
            break;

        case 6:
            main_menu();
            break;

        case 7:
            exit_screen();
            break;

        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 7.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);

        }
       }while(choice=='y'||choice=='Y');


}


void reports_menu()
{
int ch=0;
system("cls");

char choice='Y';

   FILE *fp4;

         if(strcmp(audio_switch,"on")==0)
            {
                mciSendString("close mp3", NULL, 0, NULL);
                mciSendString("open \"DATA\\audio\\a7-reports menu.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
                mciSendString("play mp3", NULL, 0, NULL);
            }

do{

        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mREPORTS MENU\033[1;31m\t\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mLIST OF PRISONERS WHO ARE ON DEATH PENALTY\t\033[1;37m[1]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mLIST OF PRISONERS WHO WILL BE RELEASED SOON\t\033[1;37m[2]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mLIST OF PRISONERS ACCORDING TO AN AGE GAP\t\033[1;37m[3]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mHEALTH REPORTS OF PRISONERS\t\t\t\033[1;37m[4]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mCOMPARISON REPORTS WITH GRAPHS\t\t\t\033[1;37m[5]\033[1;31m\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\t\t\t\033[1;37m[6]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEXIT\t\t\t\t\t\t\033[1;37m[7]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:
            report_one();
            break;

        case 2:
            report_two();
            break;

        case 3:
            report_three();
            break;

        case 4:
            report_four();
            break;
        case 5:
            report_five();
            break;

        case 6:
            main_menu();
            break;

        case 7:
        	system("cls");
            exit_screen();

        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 6.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);

        }

}while(choice=='y'||choice=='Y');

}


void prisoneraddrecord( )

{
/*********************************************************
**This function is used to add prisoner details
*********************************************************/

    system("cls");
    pr s1;
    prr p1;
    FILE *fp,*fp3,*fp4 ;
    char another = 'Y' ,id[10],add_or_not= 'k';
    int prison_ID;
    int choice;


         if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a9.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    fp = fopen ("DATA\\records\\prisoner records", "ab+" ) ;

    if ( fp == NULL )
    {
        fp=fopen("DATA\\records\\prisoner records","w");
        if(fp==NULL)
        {

            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return ;

        }
    }

    while ( another == 'Y'|| another=='y' )

    {

        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37m PRISONER REGISTRATION \033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");


                 //filter admins
  int k=0;
   if (strcmp(user_type,"\033[1;34mUSER MODE")==0)
    {

	printf("\033[1;31m\n\t\t");
	for (k = 0; k < 70; k++){
	printf("%c",205);}
	printf("  \n\t\t%c                                                                    %c",186,186);

	printf("  \n\t\t%c  ONLY SUPER ADMIN OR ANOTHER ADMIN CAN ADD,EDIT OR DELETE RECORDS. %c",186,186);
	printf("  \n\t\t%c                                                                    %c",186,186);
	printf("  \n\t\t");
	for (k = 0; k < 70; k++){
    printf("%c",205);}

     printf("\033[1;33m");

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

     getch();
     return 0;

    }
   if (strcmp(user_type,"\033[1;34mUSER MODE")!=0)
   {
       while(add_or_not!='y'&&add_or_not!='Y'&&add_or_not!='n'&&add_or_not!='N')
       {
       printf ( "\033[1;33m");
       printf("\n\n\tDO YOU WANT TO ADD NEW PRISONER?(Y/N)");
       fflush(stdin);
       printf ( "\033[1;37m");
       scanf("%c",&add_or_not);
       }
       if(add_or_not=='n'||add_or_not=='N')
       {
           return 0;
       }
        printf("\n\n\t\ ENTER NEW DETAILS");
        printf("\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
   }
        choice=0;
        fflush(stdin);
        printf ( "\033[1;33m");
		printf("\n\n\t\tENTER PRISONER ID:");
        printf ( "\033[1;37m");
        gets(id);
        rewind(fp);
      while(!valid_prisoner_id_or_staff_member_id(id))
        {
          fflush(stdin);
          printf ( "\033[1;33m");
          printf ( "\n\t\tENTER PRISONER ID:\t");
           printf ( "\033[1;37m");
          gets(id);
          rewind(fp);
        }
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");

        while(fread( &s1,sizeof(pr),1,fp)==1)
        {

            if(strcmp(s1.id,id)==0)
            {
                printf ( "\033[1;31m");
                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                choice=1;
                printf ( "\033[1;33m");

            }
        }

        if(choice==0)
        {

            strcpy(s1.id,id);
            fflush(stdin);

              fp3 = fopen ("DATA\\records\\prison records", "rb" ) ;

              int prisoner_count=0;

                    printf("\n\n\t*PLEASE SELECT A PRISON FOR THE PRISONER");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\t\t***AVAILABLE PRISON LIST OF THE SYSTEM***");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\tPRISON ID\tPRISON NAME\t\t\t\tNUMBER OF CELLS  ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3)==1)
                {

                   rewind(fp);
                    while(fread(&s1,sizeof(pr),1,fp)==1)
                    {
                        if(p1.id==s1.prisoner_prison_id)
                        {
                            prisoner_count++;
                        }
                    }
                 printf("\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                 if(prisoner_count>=p1.capacity)
                    {
                     printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;31mCAPACITY : %d/%d\033[1;33m\t\t\t  %d\033[1;33m",p1.id,p1.name,prisoner_count,p1.capacity,p1.cells);
                    }
                printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;32mCAPACITY : %d/%d\033[1;33m\t\t\t  %d\033[1;33m",p1.id,p1.name,prisoner_count,p1.capacity,p1.cells);

                prisoner_count=0;

               }
                printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");

                        printf ( "\033[1;33m");
                        printf("\n\tENTER PRISON ID NUMBER: ");
                        printf ( "\033[1;37m");
                        scanf("%d",&prison_ID);
                        fflush(stdin);

                         while(!valid_prison_ID_selecter(prison_ID))
                    {
                        printf ( "\033[1;33m");
                        printf("\tENTER PRISON ID NUMBER: ");
                        printf ( "\033[1;37m");
                        scanf("%d",&prison_ID);
                        fflush(stdin);
                    }

            s1.prisoner_prison_id=prison_ID;
            fflush(stdin);

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
 char cell_number[10];

             FILE *fp3;
            prr p1;
            fp3 =fopen("DATA\\records\\prison records","r");

        while(fread(&p1,sizeof(prr),1,fp3))
        {
          if(s1.prisoner_prison_id==p1.id)
            {
              printf("\n\tTHIS PRISON HAS %d CELLS.THEREFORE PLEASE ENTER A CELL NUMBER WITHIN 1 TO %d",p1.cells,p1.cells);

            }
        }

                        printf("\n\n\tENTER CELL NUMBER:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%s",&cell_number);
                        printf("\033[1;33m");

        while(!valid_cell_number_selecter(s1.prisoner_prison_id,cell_number) )
        {

           printf("\n\tENTER CELL NUMBER:");
           fflush(stdin);
           printf("\033[1;37m");
           scanf("%s",&cell_number);
           printf("\033[1;33m");
        }
            fflush(stdin);
            s1.prisoner_cell_number=valid_cell_number(cell_number);
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf ( "\033[1;33m");
            printf("\n\tENTER PRISONER FULL NAME: ");
            printf ( "\033[1;37m");
            gets(s1.full_name);
            fflush(stdin);

            while(!valid_name(s1.full_name))
        {
            printf ( "\033[1;33m");
            printf("\n\tENTER PRISONER FULL NAME: ");
            printf ( "\033[1;37m");
            gets(s1.full_name);
            fflush(stdin);
        }

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf ( "\033[1;33m");
            printf("\n\tENTER PRISONER NAME WITH INITIALS: ");
            printf ( "\033[1;37m");
            gets(s1.name_with_initials);
            fflush(stdin);

                while(!valid_name(s1.name_with_initials))
        {

            printf ( "\033[1;33m");
            printf("\n\tENTER PRISONER NAME WITH INITIALS: ");
            printf ( "\033[1;37m");
            gets(s1.name_with_initials);
            fflush(stdin);
        }

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");

printf ( "\033[1;33m");
 printf("\n\tENTER NATIONALITY: ");
 printf ( "\033[1;37m");
            gets(s1.nationality);
            fflush(stdin);

                          while(!valid_name(s1.nationality))
        {

            printf ( "\033[1;33m");
            printf("\tENTER NATIONALITY: ");
            printf ( "\033[1;37m");
            gets(s1.nationality);
            fflush(stdin);
        }

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf ( "\033[1;33m");
            printf("\n\tENTER PRISONER NATIONAL ID: ");
            printf ( "\033[1;37m");
            gets(s1.national_id);
            fflush(stdin);

             while(!valid_national_id(s1.national_id))
        {
          printf ( "\033[1;33m");
          printf("\n\tENTER PRISONER NATIONAL ID: ");
          printf ( "\033[1;37m");
          gets(s1.national_id);
          fflush(stdin);
        }
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
		    printf ( "\033[1;33m");
		    printf("\n\tENTER GENDER(male/female): ");
		    printf ( "\033[1;37m");
            gets(s1.gender);
            fflush(stdin);

                 while(!valid_gender(s1.gender))
        {
          printf ( "\033[1;33m");
          printf("\n\tENTER GENDER(male/female): ");
          printf ( "\033[1;37m");
          gets(s1.gender);
          fflush(stdin);
        }

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf ( "\033[1;33m");
            printf("\n\tENTER DATE OF BIRTH: ");
            printf ( "\033[1;33m");
            printf("\n\t\tENTER DATE: ");
            printf ( "\033[1;37m");
            scanf("%02d",&s1.prisoner_birth_date);
            fflush(stdin);

            printf ( "\033[1;33m");
            printf("\n\t\tENTER MONTH: ");
            printf ( "\033[1;37m");
            scanf("%02d",&s1.prisoner_birth_month);
            fflush(stdin);
            printf ( "\033[1;33m");
            printf("\n\t\tENTER YEAR: ");
            printf ( "\033[1;37m");
            scanf("%04d",&s1.prisoner_birth_year);
            fflush(stdin);

            while(!valid_date(s1.prisoner_birth_date,s1.prisoner_birth_month,s1.prisoner_birth_year))

    {
        printf("\033[1;31m");
        printf("\n*Date is invalid.please enter valid date,month,year\n\n");
         printf ( "\033[1;33m");
            printf("\n\tENTER DATE OF BIRTH: ");
            printf ( "\033[1;33m");
            printf("\n\t\tENTER DATE: ");
            printf ( "\033[1;37m");
            scanf("%02d",&s1.prisoner_birth_date);
            fflush(stdin);

            printf ( "\033[1;33m");
            printf("\n\t\tENTER MONTH: ");
            printf ( "\033[1;37m");
            scanf("%02d",&s1.prisoner_birth_month);
            fflush(stdin);
            printf ( "\033[1;33m");
            printf("\n\t\tENTER YEAR: ");
            printf ( "\033[1;37m");
            scanf("%04d",&s1.prisoner_birth_year);
            fflush(stdin);
    }

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
        printf("\033[1;32m");
            s1.age = age_calculator(s1.prisoner_birth_date,s1.prisoner_birth_month,s1.prisoner_birth_year);
            fflush(stdin);
            printf("\n\t--------------------------------------------------------------------------------------",s1.age);
            printf("\n\tACCORDING TO THE DATE OF BIRTH,SYSTEM HAS DETECTED PRISONER'S AGE.\n\tPRISONER'S AGE IS %d",s1.age);
            printf("\n\t--------------------------------------------------------------------------------------\n",s1.age);
        printf("\033[1;33m");
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            char weight[30];
            printf("\n\tENTER WEIGHT(in kilograms): ");
            printf("\033[1;37m");
            scanf("%s",&weight);
            fflush(stdin);

                     while(!valid_weight(weight))
        {

          printf("\033[1;33m");
          printf("\n\tENTER WEIGHT(in kilograms): ");
          printf("\033[1;37m");
            scanf("%s",&weight);
            fflush(stdin);
        }
            s1.weight= valid_weight(weight);
            fflush(stdin);
        printf("\033[1;32m");
            printf("\tweight= %d kilograms",s1.weight);
        printf("\033[1;33m");
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
             char height[30];
             printf("\033[1;33m");
            printf("\n\n\tENTER HEIGHT(in centimeters): ");
            printf("\033[1;37m");
            scanf("%s",&height);
            fflush(stdin);

                     while(!valid_height(height))
        {

            printf("\033[1;33m");
            printf("\n\tENTER HEIGHT(in centimeters): ");
            printf("\033[1;37m");
            scanf("%s",&height);
            fflush(stdin);
        }
            s1.height= valid_height(height);
            fflush(stdin);
            printf("\033[1;32m");
            printf("\theight= %d centimeters",s1.height);
            printf("\033[1;33m");
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf("\n\n\tENTER PRISONER PHYSICAL HEALTH CONDITION(good/bad): ");
            printf("\033[1;37m");
            gets(s1.physical_health);
 			fflush(stdin);

 				             while(!valid_condition(s1.physical_health))
        {

            printf("\033[1;33m");
            printf("\tENTER PRISONER PHYSICAL HEALTH CONDITION(good/bad): ");
            printf("\033[1;37m");
            gets(s1.physical_health);
 			fflush(stdin);
        }

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
 			printf("\n\tENTER PRISONER MENTAL HEALTH CONDITION(good/bad) : ");
 			printf("\033[1;37m");
            gets(s1.mental_health);
 			fflush(stdin);

 					             while(!valid_condition(s1.mental_health))
        {

            printf("\033[1;33m");
            printf("\tENTER PRISONER MENTAL HEALTH CONDITION(good/bad) : ");
            printf("\033[1;37m");
            gets(s1.mental_health);
 			fflush(stdin);
        }
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf("\033[1;33m");
            printf("\n\tENTER SPECIFIC ILLNESSES : ");
            printf("\033[1;37m");
            gets(s1.specific_illnesses);
 			fflush(stdin);

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf("\n\tENTER HAIRCOLOR: ");
            printf("\033[1;37m");
            gets(s1.haircolor);
            fflush(stdin);

                     while(!valid_colour(s1.haircolor))
        {
            printf("\033[1;31m");
            printf("\n*Colour name is invalid.Please enter a valid colour name.\n\n");
            printf("\033[1;33m");
            printf("\tENTER HAIRCOLOR: ");
            printf("\033[1;37m");
            gets(s1.haircolor);
            fflush(stdin);
        }

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf("\n\tENTER EYECOLOR: ");
            printf("\033[1;37m");
            gets(s1.eyecolor);
            fflush(stdin);

                     while(!valid_colour(s1.eyecolor))
        {
           printf("\033[1;31m");
           printf("\n*Eye colour name is invalid.please enter valid eye colour\n\n");
            printf("\033[1;33m");
           printf("\tENTER EYECOLOR: ");
           printf("\033[1;37m");
           gets(s1.eyecolor);
           fflush(stdin);
        }

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf("\n\tENTER CRIME: ");
            printf("\033[1;37m");
            gets(s1.crime);
            fflush(stdin);

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf("\n\tENTER COURT NAME: ");
            printf("\033[1;37m");
            gets(s1.court);
            fflush(stdin);
                              while(!valid_name(s1.court))
        {

            printf("\033[1;33m");
            printf("\tENTER COURT NAME: ");
            printf("\033[1;37m");
            gets(s1.court);
            fflush(stdin);
        }

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");

            if(strcmpi(death_penalty,"AVAILABLE")==0)
                {
                 printf("\n\t\tPLEASE SELECT THE TYPE OF THE CONVICTION.");
                 printf("\n\t\t(1)\033[1;37mIMPRISONMENT\033[1;33m");
                 printf("\n\t\t(2)\033[1;31mDEATH PENALTY\033[1;33m");
                 printf("\n\n\t\tENTER THE NUMBER OF THE COVICTION TYPE:");
                 fflush(stdin);
                 scanf("%d",&s1.penalty_type);
                 while(s1.penalty_type!=1&&s1.penalty_type!=2)
                 {
                      printf("\033[1;31m\n\t\t*Invalid input.Please enter a valid choice.\n\033[1;33m");
                       printf("\n\t\tPLEASE SELECT THE TYPE OF THE CONVICTION.");
                        printf("\n\t\t(1)\033[1;37mIMPRISONMENT\033[1;33m");
                        printf("\n\t\t(2)\033[1;31mDEATH PENALTY\033[1;33m");
                         printf("\n\n\t\tENTER THE NUMBER OF THE COVICTION TYPE:");
                         fflush(stdin);
                         scanf("%d",&s1.penalty_type);
                 }
                 if(s1.penalty_type==1)
                    {
                         printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\n\t CONVICTION TYPE = \033[1;37mIMPRISONMENT\033[1;33m");
                         printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                 if(s1.penalty_type==2)
                    {
                         printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\n\t CONVICTION TYPE = \033[1;31mDEATH PENALTY\033[1;33m");
                         printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                  printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                }
            else
                {
                 s1.penalty_type=1;
                }

            printf("\n\n\tENTER CONVICTION DETAILS: ");
            printf("\033[1;37m");
            fflush(stdin);
            gets(s1.punishment);


printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");

            printf("\033[1;33m");
            printf("\n\tSTARTING DATE OF THE PUNISHMENT: ");
            printf("\n\t\tENTER DATE: ");
            printf("\033[1;37m");
            fflush(stdin);
            scanf("%02d",&s1.punishment_start_date);

            printf("\033[1;33m");
            printf("\n\t\tENTER MONTH: ");
            printf("\033[1;37m");
            fflush(stdin);
            scanf("%02d",&s1.punishment_start_month);

            printf("\033[1;33m");
            printf("\n\t\tENTER YEAR: ");
            printf("\033[1;37m");
            fflush(stdin);
            scanf("%04d",&s1.punishment_start_year);

    while(!valid_date(s1.punishment_start_date,s1.punishment_start_month,s1.punishment_start_year))
    {
            printf("\033[1;31m");
            printf("\n*Date is invalid.please enter valid date,month,year\n\n");
            printf("\033[1;33m");
            printf("\n\tSTARTING DATE OF THE PUNISHMENT: ");
            printf("\n\t\tENTER DATE: ");
            printf("\033[1;37m");
            scanf("%02d",&s1.punishment_start_date);
            fflush(stdin);

            printf("\033[1;33m");
            printf("\n\t\tENTER MONTH: ");
            printf("\033[1;37m");
            scanf("%02d",&s1.punishment_start_month);
            fflush(stdin);

            printf("\033[1;33m");
            printf("\n\t\tENTER YEAR: ");
            printf("\033[1;37m");
            scanf("%04d",&s1.punishment_start_year);
            fflush(stdin);

    }
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");

           printf("\033[1;33m");
            printf("\n\tENDING DATE OF THE PUNISHMENT: ");
            printf("\n\t\tENTER DATE: ");
            printf("\033[1;37m");
            scanf("%02d",&s1.punishment_end_date);
            fflush(stdin);

            printf("\033[1;33m");
            printf("\n\t\tENTER MONTH: ");
            printf("\033[1;37m");
            scanf("%02d",&s1.punishment_end_month);
            fflush(stdin);

            printf("\033[1;33m");
            printf("\n\t\tENTER YEAR: ");
            printf("\033[1;37m");
            scanf("%04d",&s1.punishment_end_year);
            fflush(stdin);

    while(!remaining_punishment_time(s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year))
     {
           printf("\033[1;31m");
           printf("\n*Date is invalid.please enter valid date,month,year\n\n");
           printf("\033[1;33m");

         printf("\033[1;33m");
            printf("\n\tENDING DATE OF THE PUNISHMENT: ");
            printf("\n\t\tENTER DATE: ");
            printf("\033[1;37m");
            scanf("%02d",&s1.punishment_end_date);
            fflush(stdin);

            printf("\033[1;33m");
            printf("\n\t\tENTER MONTH: ");
            printf("\033[1;37m");
            scanf("%02d",&s1.punishment_end_month);
            fflush(stdin);

            printf("\033[1;33m");
            printf("\n\t\tENTER YEAR: ");
            printf("\033[1;37m");
            scanf("%04d",&s1.punishment_end_year);
            fflush(stdin);
    }

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");


            printf("\033[1;33m");
            printf("\n\n\tENTER NAME OF EMERGENCY CONTACT: ");
            printf("\033[1;37m");
            gets(s1.emergencyc);
            fflush(stdin);

                         while(!valid_name(s1.emergencyc))
        {
            printf("\033[1;33m");
            printf("\tENTER NAME OF EMERGENCY CONTACT: ");
            printf("\033[1;37m");
            gets(s1.emergencyc);
            fflush(stdin);
        }

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");

            printf("\033[1;33m");
            printf("\n\tENTER THE RELATION OF EMERGENCY CONTACT WITH PRISONER: ");
            printf("\033[1;37m");
            gets(s1.emergencyr);
            fflush(stdin);

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf("\033[1;33m");
            printf("\n\tENTER PHONE NUMBER OF EMERGENCY CONTACT: ");
            printf("\033[1;37m");
            gets(s1.emergencyn);
            fflush(stdin);
                                  while(!valid_mobile_number(s1.emergencyn))
        {
            printf("\033[1;33m");
            printf("\tENTER PHONE NUMBER OF EMERGENCY CONTACT: ");
            printf("\033[1;37m");
            gets(s1.emergencyn);
            fflush(stdin);
        }
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");


            fwrite ( &s1, sizeof ( pr ), 1, fp ) ;
            printf("\033[1;32m");
            printf("\n\n\tYOUR RECORD IS ADDED...\n");
            printf("\033[1;33m");

            printf("\n\n\tHERE IS THE COMPLETE RECORD, YOU HAVE ADDED...\n");

                printf("\n");
                printf("\n");
                printf("\n\t\033[1;31m********************************************************");
                printf("\n\t********* \033[1;33mRECORD OF THE PRISONER ID:\033[1;37m %s\033[1;31m *********",s1.id);
                printf("\n\t\033[1;31m********************************************************\033[1;33m");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NAME : \t\t\t\t\033[1;37m %s  \033[1;33m   ",s1.full_name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NAME WITH INITIALS :\t\t\t \033[1;37m%s \033[1;33m",s1.name_with_initials);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NATIONALITY :\t\t\t \033[1;37m%s\033[1;33m",s1.nationality);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NATIONAL ID :\t\t\t\033[1;37m %s \033[1;33m",s1.national_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S GENDER :\t\t\t\t\033[1;37m %s\033[1;33m ",s1.gender);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S AGE :\t\t\t\t\033[1;37m %d \033[1;33m",s1.age);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S DATE OF BIRTH :\t\t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.prisoner_birth_date,s1.prisoner_birth_month,s1.prisoner_birth_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S WEIGHT :\t\t\t\t\033[1;37m %d kg\033[1;33m ",s1.weight);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S HEIGHT :\t\t\t\t\033[1;37m %d cm\033[1;33m",s1.height);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S HAIRCOLOR :\t\t\t\t\033[1;37m %s \033[1;33m",s1.haircolor);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S EYECOLOR :\t\t\t\t\033[1;37m %s\033[1;33m",s1.eyecolor);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S PHYSICAL HEALTH CONDITION :\t\t\033[1;37m %s\033[1;33m",s1.physical_health);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S MENTAL HEALTH CONDITION :\t\t\033[1;37m %s\033[1;33m",s1.mental_health);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S SPECIFIC ILLNESSES :\t\t\t\033[1;37m %s\033[1;33m",s1.specific_illnesses);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S CRIME :\t\t\t\t\033[1;37m %s\033[1;33m",s1.crime);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nCOURT : \t\t\t\t\t\033[1;37m %s\033[1;33m",s1.court);

                if(strcmpi(death_penalty,"AVAILABLE")==0)
                {
                 if(s1.penalty_type==1)
                    {
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\nCONVICTION TYPE :\t\t\t\t \033[1;37mIMPRISONMENT\033[1;33m");
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                 if(s1.penalty_type==2)
                    {
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\nCONVICTION TYPE :\t\t\t\t \033[1;31mDEATH PENALTY\033[1;33m");
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                }
                else
                {
                   printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                   printf("\nCONVICTION TYPE :\t\t\t\t \033[1;37mIMPRISONMENT\033[1;33m");
                   printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                }
                printf("\nPRISONER'S CONVICTION DETAILS :\t\t\t\033[1;37m %s\033[1;33m",s1.punishment);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTARTING DATE OF THE PUNISHMENT : \t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.punishment_start_date,s1.punishment_start_month,s1.punishment_start_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nENDING DATE OF THE PUNISHMENT :\t\t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);

                remaining_punishment_time(s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);

                printf("\nPRISONER'S EMERGENCY CONTACT :\t\t\t \033[1;37m%s\033[1;33m",s1.emergencyc);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nRELATION OF EMERGENCY CONTACT WITH PRISONER : \t\033[1;37m %s\033[1;33m",s1.emergencyr);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nEMERGENCY CONTACT'S PHONE NUMBER :\t\t\033[1;37m %s\033[1;33m",s1.emergencyn);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S PRISON ID NUMBER :\t\t\t\033[1;37m %04d\033[1;33m",s1.prisoner_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                valid_prison_name_finder(s1.prisoner_prison_id);

                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S CELL NUMBER :\t\t\t\033[1;37m %04d\033[1;33m",s1.prisoner_cell_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");

        }

        printf ( "\n\tADD ANOTHER RECORD...(Y/N) \t" ) ;
        fflush ( stdin ) ;
        another = getch() ;

    }

    fclose ( fp ) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
    return 0;

}


void prisonersearchrecord( )
{
/***********************************************************
**This function is used to search prisoners
***********************************************************/

	system("cls");
	pr s1;
    FILE *fp ;
    FILE *fp4;
	char id[10],choice;
	char name[50],string1[100],string2[100];
	int search_results=0;
    int ch,found=0;

         if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a8.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

 do
	{

        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mSEARCH PRISONER RECORDS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");


		/*printf("\n\tENTER THE PRISONER NAME TO BE SEARCHED:");
        fflush(stdin);
        gets(prisoner records);*/

        fp = fopen ( "DATA\\records\\prisoner records", "rb" ) ;


         printf("\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\033[1;31m\n\t\t|\t\033[1;35mSearch by prisoner ID\t\t[1]\t\t\t\033[1;31m|\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\033[1;31m\n\t\t|\t\033[1;35mSearch by prisoner Name\t\t[2]\t\t\t\033[1;31m|\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\033[1;31m\033[1;31m\n\t\t|\t\033[1;37mBack\t\t\t\t[3]\t\t\t\033[1;31m|\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\n\t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\033[1;33m\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        printf("\033[1;37m");
        scanf("%d",&ch);
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
        switch(ch)
        {
         case 1:
            found=0;
            printf("\033[1;33m");
    		printf("\n\n\tENTER PRISONER ID : ");
    		printf("\033[1;37m");
            fflush(stdin);
            scanf("%s",&id);
            system("cls");

            while ( fread ( &s1, sizeof ( pr ), 1, fp ))
          {
  if(strcmpi(s1.id,id)==0)
               {
                found=1;
              printf("\n");
                printf("\n");
                printf("\n\t\033[1;31m********************************************************");
                printf("\n\t********* \033[1;33mRECORD OF THE PRISONER ID:\033[1;37m %s\033[1;31m *********",s1.id);
                printf("\n\t\033[1;31m********************************************************\033[1;33m");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NAME : \t\t\t\t\033[1;37m %s  \033[1;33m   ",s1.full_name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NAME WITH INITIALS :\t\t\t \033[1;37m%s \033[1;33m",s1.name_with_initials);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NATIONALITY :\t\t\t \033[1;37m%s\033[1;33m",s1.nationality);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NATIONAL ID :\t\t\t\033[1;37m %s \033[1;33m",s1.national_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S GENDER :\t\t\t\t\033[1;37m %s\033[1;33m ",s1.gender);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S AGE :\t\t\t\t\033[1;37m %d \033[1;33m",s1.age);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S DATE OF BIRTH :\t\t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.prisoner_birth_date,s1.prisoner_birth_month,s1.prisoner_birth_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S WEIGHT :\t\t\t\t\033[1;37m %d kg\033[1;33m ",s1.weight);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S HEIGHT :\t\t\t\t\033[1;37m %d cm\033[1;33m",s1.height);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S HAIRCOLOR :\t\t\t\t\033[1;37m %s \033[1;33m",s1.haircolor);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S EYECOLOR :\t\t\t\t\033[1;37m %s\033[1;33m",s1.eyecolor);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S PHYSICAL HEALTH CONDITION :\t\t\033[1;37m %s\033[1;33m",s1.physical_health);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S MENTAL HEALTH CONDITION :\t\t\033[1;37m %s\033[1;33m",s1.mental_health);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S SPECIFIC ILLNESSES :\t\t\t\033[1;37m %s\033[1;33m",s1.specific_illnesses);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S CRIME :\t\t\t\t\033[1;37m %s\033[1;33m",s1.crime);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nCOURT : \t\t\t\t\t\033[1;37m %s\033[1;33m",s1.court);

                if(strcmpi(death_penalty,"AVAILABLE")==0)
                {
                 if(s1.penalty_type==1)
                    {
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\nCONVICTION TYPE :\t\t\t\t \033[1;37mIMPRISONMENT\033[1;33m");
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                 if(s1.penalty_type==2)
                    {
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\nCONVICTION TYPE :\t\t\t\t \033[1;31mDEATH PENALTY\033[1;33m");
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                }
                else
                {
                   printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                   printf("\nCONVICTION TYPE :\t\t\t\t \033[1;37mIMPRISONMENT\033[1;33m");
                   printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                }
                printf("\nPRISONER'S CONVICTION DETAILS :\t\t\t\033[1;37m %s\033[1;33m",s1.punishment);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTARTING DATE OF THE PUNISHMENT : \t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.punishment_start_date,s1.punishment_start_month,s1.punishment_start_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nENDING DATE OF THE PUNISHMENT :\t\t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);

                remaining_punishment_time(s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);

                printf("\nPRISONER'S EMERGENCY CONTACT :\t\t\t \033[1;37m%s\033[1;33m",s1.emergencyc);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nRELATION OF EMERGENCY CONTACT WITH PRISONER : \t\033[1;37m %s\033[1;33m",s1.emergencyr);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nEMERGENCY CONTACT'S PHONE NUMBER :\t\t\033[1;37m %s\033[1;33m",s1.emergencyn);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S PRISON ID NUMBER :\t\t\t\033[1;37m %04d\033[1;33m",s1.prisoner_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                valid_prison_name_finder(s1.prisoner_prison_id);

                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S CELL NUMBER :\t\t\t\033[1;37m %04d\033[1;33m",s1.prisoner_cell_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");

            }

          }
              if(!found){
                 printf("\033[1;31m");
                 printf("\nTHE RECORD DOES NOT EXIST.\n");
                 printf("\033[1;33m");
               }
                found=0;
                  break;

         case 2:
                        found=0;
                        printf("\033[1;33m");
                        printf("\n\n\tENTER PRISONER NAME : ");
                        printf("\033[1;37m");
                        fflush(stdin);
                        scanf("%s",&name);

                        for(int i = 0;i<50; i++)
            {
           string2[i] = tolower(name[i]);
            }


                  printf("\n\n\t\t HERE IS THE SEARCH RESULT");
          printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;32m");
                 printf("\n\t\tPrisoner ID\t\tPrisoner name");
          printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;37m");
            while ( fread ( &s1, sizeof ( pr ), 1, fp ))
          {

          for(int i = 0;i<50; i++)
            {
           string1[i] = tolower(s1.full_name[i]);
            }

          if(strstr(string1,string2)!=0)
               {


                 search_results++;
                 printf("\n\t\t %04d\t\t%s",s1.id,s1.full_name);
                printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;37m");
               }
            }
            printf("\n\tThere are %d search results",search_results);

           if(search_results>0){
            printf("\033[1;33m");
    		printf("\n\n\tSelect and enter prisoner ID from above search results: ");
    		printf("\033[1;37m");
            fflush(stdin);
            scanf("%s",&id);
            system("cls");
            }
            search_results=0;
               rewind(fp);
            while ( fread ( &s1, sizeof ( pr ), 1, fp ))
          {
  if(strcmpi(s1.id,id)==0)
               {
                found=1;
              printf("\n");
                printf("\n");
                printf("\n\t\033[1;31m********************************************************");
                printf("\n\t********* \033[1;33mRECORD OF THE PRISONER ID:\033[1;37m %s\033[1;31m *********",s1.id);
                printf("\n\t\033[1;31m********************************************************\033[1;33m");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NAME : \t\t\t\t\033[1;37m %s  \033[1;33m   ",s1.full_name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NAME WITH INITIALS :\t\t\t \033[1;37m%s \033[1;33m",s1.name_with_initials);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NATIONALITY :\t\t\t \033[1;37m%s\033[1;33m",s1.nationality);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NATIONAL ID :\t\t\t\033[1;37m %s \033[1;33m",s1.national_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S GENDER :\t\t\t\t\033[1;37m %s\033[1;33m ",s1.gender);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S AGE :\t\t\t\t\033[1;37m %d \033[1;33m",s1.age);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S DATE OF BIRTH :\t\t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.prisoner_birth_date,s1.prisoner_birth_month,s1.prisoner_birth_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S WEIGHT :\t\t\t\t\033[1;37m %d kg\033[1;33m ",s1.weight);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S HEIGHT :\t\t\t\t\033[1;37m %d cm\033[1;33m",s1.height);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S HAIRCOLOR :\t\t\t\t\033[1;37m %s \033[1;33m",s1.haircolor);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S EYECOLOR :\t\t\t\t\033[1;37m %s\033[1;33m",s1.eyecolor);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S PHYSICAL HEALTH CONDITION :\t\t\033[1;37m %s\033[1;33m",s1.physical_health);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S MENTAL HEALTH CONDITION :\t\t\033[1;37m %s\033[1;33m",s1.mental_health);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S SPECIFIC ILLNESSES :\t\t\t\033[1;37m %s\033[1;33m",s1.specific_illnesses);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S CRIME :\t\t\t\t\033[1;37m %s\033[1;33m",s1.crime);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nCOURT : \t\t\t\t\t\033[1;37m %s\033[1;33m",s1.court);

                if(strcmpi(death_penalty,"AVAILABLE")==0)
                {
                 if(s1.penalty_type==1)
                    {
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\nCONVICTION TYPE :\t\t\t\t \033[1;37mIMPRISONMENT\033[1;33m");
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                 if(s1.penalty_type==2)
                    {
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\nCONVICTION TYPE :\t\t\t\t \033[1;31mDEATH PENALTY\033[1;33m");
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                }
                else
                {
                   printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                   printf("\nCONVICTION TYPE :\t\t\t\t \033[1;37mIMPRISONMENT\033[1;33m");
                   printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                }
                printf("\nPRISONER'S CONVICTION DETAILS :\t\t\t\033[1;37m %s\033[1;33m",s1.punishment);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTARTING DATE OF THE PUNISHMENT : \t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.punishment_start_date,s1.punishment_start_month,s1.punishment_start_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nENDING DATE OF THE PUNISHMENT :\t\t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);

                remaining_punishment_time(s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);

                printf("\nPRISONER'S EMERGENCY CONTACT :\t\t\t \033[1;37m%s\033[1;33m",s1.emergencyc);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nRELATION OF EMERGENCY CONTACT WITH PRISONER : \t\033[1;37m %s\033[1;33m",s1.emergencyr);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nEMERGENCY CONTACT'S PHONE NUMBER :\t\t\033[1;37m %s\033[1;33m",s1.emergencyn);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S PRISON ID NUMBER :\t\t\t\033[1;37m %04d\033[1;33m",s1.prisoner_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                valid_prison_name_finder(s1.prisoner_prison_id);

                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S CELL NUMBER :\t\t\t\033[1;37m %04d\033[1;33m",s1.prisoner_cell_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");

            }

          }
            if(!found){
                 printf("\033[1;31m");
                 printf("\nTHE RECORD DOES NOT EXIST.\n");
                 printf("\033[1;33m");

               }

               found=0;
               break;
        case 3:
            prisoner_records_menu();
        default:
            printf("\033[1;31m");
            printf("\n\t\t*You have entered an invalid choice. Please choose between 1 to 3");
            printf("\033[1;33m");
        }


        printf("\n\nWOULD YOU LIKE TO CONTINUE SEARCHING...(Y/N):");
        fflush(stdin);

        scanf(" %c",&choice);
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp) ;
    return ;

}

void prisonereditrecord()

{
/***********************************************************
**This function is used to edit prisoner details
***********************************************************/
    system("cls");
    pr s1;
    prr p1;
    FILE *fp,*fp3 ;
    char id[20],choice;
    int num,count=0,prison_id;
    char weight[30],height[30],cell_number[30];


     FILE *fp4;


         if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a10.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }


    do
    {
 system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mEDIT PRISONER RECORDS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");


 //filter admins
  int k=0;
   if (strcmp(user_type,"\033[1;34mUSER MODE")==0)
    {

	printf("\033[1;31m\n\t\t");
	for (k = 0; k < 70; k++){
	printf("%c",205);}
	printf("  \n\t\t%c                                                                    %c",186,186);

	printf("  \n\t\t%c  ONLY SUPER ADMIN OR ANOTHER ADMIN CAN ADD,EDIT OR DELETE RECORDS. %c",186,186);
	printf("  \n\t\t%c                                                                    %c",186,186);
	printf("  \n\t\t");
	for (k = 0; k < 70; k++){
    printf("%c",205);}

     printf("\033[1;33m");

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();


     return 0;

    }

        fp = fopen ( "DATA\\records\\prisoner records", "rb+" ) ;

        printf("\033[1;31m");
        fflush(stdin);
        printf("\n\n\t\tENTER PRISONER ID:");
        printf("\033[1;33m");
    	gets(id);


        while ( fread ( &s1, sizeof ( pr ), 1, fp ) == 1 )
        {

            if(strcmp(s1.id,id)==0)
        {

                printf("\n");
                printf("\n");
                printf("\n\t\033[1;31m********************************************************");
                printf("\n\t********* \033[1;33mRECORD OF THE PRISONER ID:\033[1;37m %s\033[1;31m *********",s1.id);
                printf("\n\t\033[1;31m********************************************************\033[1;33m");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NAME : \t\t\t\t\033[1;37m %s  \033[1;33m   ",s1.full_name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NAME WITH INITIALS :\t\t\t \033[1;37m%s \033[1;33m",s1.name_with_initials);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NATIONALITY :\t\t\t \033[1;37m%s\033[1;33m",s1.nationality);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NATIONAL ID :\t\t\t\033[1;37m %s \033[1;33m",s1.national_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S GENDER :\t\t\t\t\033[1;37m %s\033[1;33m ",s1.gender);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S AGE :\t\t\t\t\033[1;37m %d \033[1;33m",s1.age);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S DATE OF BIRTH :\t\t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.prisoner_birth_date,s1.prisoner_birth_month,s1.prisoner_birth_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S WEIGHT :\t\t\t\t\033[1;37m %d kg\033[1;33m ",s1.weight);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S HEIGHT :\t\t\t\t\033[1;37m %d cm\033[1;33m",s1.height);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S HAIRCOLOR :\t\t\t\t\033[1;37m %s \033[1;33m",s1.haircolor);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S EYECOLOR :\t\t\t\t\033[1;37m %s\033[1;33m",s1.eyecolor);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S PHYSICAL HEALTH CONDITION :\t\t\033[1;37m %s\033[1;33m",s1.physical_health);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S MENTAL HEALTH CONDITION :\t\t\033[1;37m %s\033[1;33m",s1.mental_health);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S SPECIFIC ILLNESSES :\t\t\t\033[1;37m %s\033[1;33m",s1.specific_illnesses);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S CRIME :\t\t\t\t\033[1;37m %s\033[1;33m",s1.crime);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nCOURT : \t\t\t\t\t\033[1;37m %s\033[1;33m",s1.court);

                if(strcmpi(death_penalty,"AVAILABLE")==0)
                {
                 if(s1.penalty_type==1)
                    {
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\nCONVICTION TYPE :\t\t\t\t \033[1;37mIMPRISONMENT\033[1;33m");
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                 if(s1.penalty_type==2)
                    {
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\nCONVICTION TYPE :\t\t\t\t \033[1;31mDEATH PENALTY\033[1;33m");
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                }
                else
                {
                   printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                   printf("\nCONVICTION TYPE :\t\t\t\t \033[1;37mIMPRISONMENT\033[1;33m");
                   printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                }
                printf("\nPRISONER'S CONVICTION DETAILS :\t\t\t\033[1;37m %s\033[1;33m",s1.punishment);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTARTING DATE OF THE PUNISHMENT : \t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.punishment_start_date,s1.punishment_start_month,s1.punishment_start_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nENDING DATE OF THE PUNISHMENT :\t\t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);

                remaining_punishment_time(s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);

                printf("\nPRISONER'S EMERGENCY CONTACT :\t\t\t \033[1;37m%s\033[1;33m",s1.emergencyc);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nRELATION OF EMERGENCY CONTACT WITH PRISONER : \t\033[1;37m %s\033[1;33m",s1.emergencyr);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nEMERGENCY CONTACT'S PHONE NUMBER :\t\t\033[1;37m %s\033[1;33m",s1.emergencyn);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S PRISON ID NUMBER :\t\t\t\033[1;37m %04d\033[1;33m",s1.prisoner_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                valid_prison_name_finder(s1.prisoner_prison_id);

                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S CELL NUMBER :\t\t\t\033[1;37m %04d\033[1;33m",s1.prisoner_cell_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..\n\n");


                printf("\n\t\033[1;31m1.\033[1;37mID\t\t\t\t\t\033[1;31m14.\033[1;37mPHYSICAL MENTAL CONDITION");
                printf("\n\t\033[1;31m2.\033[1;37mNAME\t\t\t\t\t\033[1;31m15.\033[1;37mSPECIFIC ILLNESSES");
                printf("\n\t\033[1;31m3.\033[1;37mNAME WITH INITIALS\t\t\t\033[1;31m16.\033[1;37mCRIME");
                printf("\n\t\033[1;31m4.\033[1;37mNATIONALITY\t\t\t\t\033[1;31m17.\033[1;37mCOURT");
                printf("\n\t\033[1;31m5.\033[1;37mNATIONAL ID\t\t\t\t\033[1;31m18.\033[1;37mCONVICTION TYPE & DETAILS");
                printf("\n\t\033[1;31m6.\033[1;37mGENDER\t\t\t\t\033[1;31m29.\033[1;37mSTARTING DATE OF PUNISHMENT");
                printf("\n\t\033[1;31m7.\033[1;37mDATE OF BIRTH\t\t\t\t\033[1;31m20.\033[1;37mENDING DATE OF PUNISHMENT");
                printf("\n\t\033[1;31m8.\033[1;37mAGE\t\t\t\t\t\033[1;31m21.\033[1;37mEMERGENCY CONTACT NAME");
                printf("\n\t\033[1;31m9.\033[1;37mWEIGHT\t\t\t\t\033[1;31m22.\033[1;37mRELATION OF EMERGENCY CONTACT");
                printf("\n\t\033[1;31m10.\033[1;37mHEIGHT\t\t\t\t\033[1;31m23.\033[1;37mEMERGENCY CONTACT'S PHONE NUMBER");
                printf("\n\t\033[1;31m11.\033[1;37mHAIRCOLOR\t\t\t\t\033[1;31m24.\033[1;37mPRISON ID NUMBER");
                printf("\n\t\033[1;31m12.\033[1;37mEYECOLOR\t\t\t\t\033[1;31m25.\033[1;37mCELL NUMBER");
                printf("\n\t\033[1;31m13.\033[1;37mPHYSICAL HEALTH CONDITION\t\t\033[1;31m26.\033[1;34mWHOLE RECORD");


                printf("\n\n\t\t\033[1;31m27.\033[1;32mGO BACK TO PRISONER RECORDS MENU.\033[1;33m");

                do
                {

                    printf("\n\n\n\tENTER YOUR CHOICE:");
                    fflush(stdin);
                    scanf("%d",&num);
                    fflush(stdin);


                    switch(num)
                    {

                    case 1:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA: ");
                        printf("\n\n\tID:");
                        printf("\033[1;37m");
                        gets(s1.id);
                        printf("\033[1;33m");

                       while(!valid_prisoner_id_or_staff_member_id(s1.id))
                            {
                              printf("\n\tID:");
                              printf("\033[1;37m");
                              fflush(stdin);
                              gets(s1.id);
                              printf("\033[1;33m");

                            }

                        break;

                    case 2:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tNAME:");
                        printf("\033[1;37m");
                        gets(s1.full_name);
                        printf("\033[1;33m");

                             while(!valid_name(s1.full_name))
                            {
                                printf("\n\tNAME: ");
                                printf("\033[1;37m");
                                fflush(stdin);
                                gets(s1.full_name);
                                printf("\033[1;33m");
                            }

                        break;

                    case 3:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tNAME WITH INITIALS:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(s1.name_with_initials);
                        printf("\033[1;33m");
                        while(!valid_name(s1.name_with_initials))
                            {
                                printf("\n\tNAME WITH INITIALS:");
                                printf("\033[1;37m");
                                fflush(stdin);
                                gets(s1.name_with_initials);
                                printf("\033[1;33m");
                            }
                        break;

                    case 4:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tNATIONALITY:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.nationality);
                        printf("\033[1;33m");
                     while(!valid_name(s1.nationality))
                            {
                                printf("\n\n\tNATIONALITY:");
                                fflush(stdin);
                                printf("\033[1;37m");
                                gets(s1.nationality);
                                printf("\033[1;33m");
                            }

                        break;

                    case 5:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tNATIONAL ID:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.national_id);
                        printf("\033[1;33m");
                             while(!valid_national_id(s1.national_id))
                                {
                                  printf("\n\tNATIONAL ID:");
                                  fflush(stdin);
                                  printf("\033[1;37m");
                                  gets(s1.national_id);
                                  printf("\033[1;33m");
                                }

                        break;

                    case 6:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tGENDER(male/female):");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.gender);
                        printf("\033[1;33m");

                                  while(!valid_gender(s1.gender))
                                {
                                  printf("\n\tGENDER(male/female):");
                                  fflush(stdin);
                                  printf("\033[1;37m");
                                  gets(s1.gender);
                                  printf("\033[1;33m");
                                }
                        break;

                    case 7:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\tDATE OF BIRTH: ");
                        printf("\n\t\tENTER DATE: ");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%d",&s1.prisoner_birth_date);
                        printf("\033[1;33m");

                        printf("\n\t\tENTER MONTH: ");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%d",&s1.prisoner_birth_month);
                        printf("\033[1;33m");

                        printf("\n\t\tENTER YEAR: ");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%d",&s1.prisoner_birth_year);
                        printf("\033[1;33m");

                            while(!valid_date(s1.prisoner_birth_date,s1.prisoner_birth_month,s1.prisoner_birth_year))

                             {
                                  printf("\033[1;31m");
                                  printf("\n*Date is invalid.please enter valid date,month,year\n\n");
                                  printf("\033[1;33m");

                                  printf("\tDATE OF BIRTH: ");
                                  printf("\n\t\tENTER DATE: ");
                                  fflush(stdin);
                                  printf("\033[1;37m");
                                  scanf("%d",&s1.prisoner_birth_date);
                                  printf("\033[1;33m");

                                   printf("\n\t\tENTER MONTH: ");
                                   fflush(stdin);
                                   printf("\033[1;37m");
                                   scanf("%d",&s1.prisoner_birth_month);
                                   printf("\033[1;33m");

                                    printf("\n\t\tENTER YEAR: ");
                                    fflush(stdin);
                                    printf("\033[1;37m");
                                    scanf("%d",&s1.prisoner_birth_year);
                                    printf("\033[1;33m");

                               }
                        break;


                    case 8:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                       printf("\033[1;32m");
            s1.age=age_calculator(s1.prisoner_birth_date,s1.prisoner_birth_month,s1.prisoner_birth_year);
            printf("\n\t--------------------------------------------------------------------------------------",s1.age);
            printf("\n\tACCORDING TO THE DATE OF BIRTH,SYSTEM HAS DETECTED PRISONER'S AGE.\n\tAGE IS %d",s1.age);
            printf("\n\t--------------------------------------------------------------------------------------\n",s1.age);

                        break;

                     printf("\033[1;33m");
                    case 9:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tWEIGHT(in kilograms):");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%s",&weight);
                        printf("\033[1;33m");

            while(!valid_weight(weight))
        {

          printf("\n\tWEIGHT(in kilograms):");
          fflush(stdin);
          printf("\033[1;37m");
          scanf("%s",&weight);
          printf("\033[1;33m");

        }
s1.weight=valid_weight(weight);
                        break;

                    case 10:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tHEIGHT(in centimeters):");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%s",&height);
                        printf("\033[1;33m");
            while(!valid_height(height))
        {

            printf("\n\tHEIGHT(in centimeters):");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%s",&height);
            printf("\033[1;33m");
        }

s1.height=valid_height(height);
                        break;

                    case 11:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tHAIRCOLOR:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(s1.haircolor);
                        printf("\033[1;33m");

            while(!valid_colour(s1.haircolor))
        {
            printf("\033[1;31m");
            printf("\n*Colour name is invalid.Please enter a valid colour name.\n\n");
            printf("\033[1;33m");
            printf("\n\tHAIRCOLOR:");
            printf("\033[1;37m");
            fflush(stdin);
            gets(s1.haircolor);
            printf("\033[1;33m");
        }

                        break;

                    case 12:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tEYECOLOR:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.eyecolor);
                        printf("\033[1;33m");
                  while(!valid_colour(s1.eyecolor))
        {
            printf("\n*Colour name is invalid.Please enter a valid colour name without numbers\n\n");
            printf("\n\tEYECOLOR:");
            fflush(stdin);
            printf("\033[1;37m");
            gets(s1.eyecolor);
            printf("\033[1;33m");
        }

                        break;

                    case 13:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tPHYSICAL HEALTH CONDITION(good/bad):");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.physical_health);
                        printf("\033[1;33m");


            while(!valid_condition(s1.physical_health))
        {
            printf("\n*Condition is invalid.Please enter a valid condition(good/bad)\n\n");
            printf("\n\tPHYSICAL HEALTH CONDITION(good/bad):");
            fflush(stdin);
            printf("\033[1;37m");
            gets(s1.physical_health);
            printf("\033[1;33m");
        }

                        break;

                    case 14:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tMENTAL HEALTH CONDITION(good/bad):");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.mental_health);
                        printf("\033[1;33m");

            while(!valid_condition(s1.mental_health))
        {
            printf("\n*Condition is invalid.Please enter a valid condition(good/bad)\n\n");
            printf("\nMENTAL HEALTH CONDITION(good/bad):");
            fflush(stdin);
            printf("\033[1;37m");
            gets(s1.mental_health);
            printf("\033[1;33m");
        }

                        break;

                    case 15:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tSPECIFIC ILLNESSES:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.specific_illnesses);
                        printf("\033[1;33m");
                        break;

                    case 16:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tCRIME:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.crime);
                        printf("\033[1;33m");
                        break;

                    case 17:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tCOURT:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.court);
                        printf("\033[1;33m");
                    while(!valid_name(s1.court))
        {

            printf("\n\tENTER COURT NAME: ");
            fflush(stdin);
            printf("\033[1;37m");
            gets(s1.court);
            printf("\033[1;33m");

        }
                        break;

                    case 18:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        if(strcmpi(death_penalty,"AVAILABLE")==0)
                {
                 printf("\n\t\tPLEASE SELECT THE TYPE OF THE CONVICTION.");
                 printf("\n\t\t(1)\033[1;37mIMPRISONMENT\033[1;33m");
                 printf("\n\t\t(2)\033[1;31mDEATH PENALTY\033[1;33m");
                 printf("\n\n\t\tENTER THE NUMBER OF THE COVICTION TYPE:");
                 fflush(stdin);
                 scanf("%d",&s1.penalty_type);
                 while(s1.penalty_type!=1&&s1.penalty_type!=2)
                 {
                      printf("\033[1;31m\n\t\t*Invalid input.Please enter a valid choice.\n\033[1;33m");
                       printf("\n\t\tPLEASE SELECT THE TYPE OF THE CONVICTION.");
                        printf("\n\t\t(1)\033[1;37mIMPRISONMENT\033[1;33m");
                        printf("\n\t\t(2)\033[1;31mDEATH PENALTY\033[1;33m");
                         printf("\n\n\t\tENTER THE NUMBER OF THE COVICTION TYPE:");
                         fflush(stdin);
                         scanf("%d",&s1.penalty_type);
                 }
                 if(s1.penalty_type==1)
                    {
                         printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\n\t CONVICTION TYPE = \033[1;37mIMPRISONMENT\033[1;33m");
                         printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                 if(s1.penalty_type==2)
                    {
                         printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\n\t CONVICTION TYPE = \033[1;31mDEATH PENALTY\033[1;33m");
                         printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                  printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                }
            else
                {
                 s1.penalty_type=1;
                }

                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tCONVICTION DETAILS:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.punishment);
                        printf("\033[1;33m");
                        break;

                    case 19:
 printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tSTARTING DATE OF THE PUNISHMENT:");
                        printf("\n\t\tENTER DATE:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_start_date);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER MONTH:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_start_month);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER YEAR:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%04d",&s1.punishment_start_year);
                        printf("\033[1;33m");

    while(!valid_date(s1.punishment_start_date,s1.punishment_start_month,s1.punishment_start_year))
    {
        printf("\033[1;31m");
        printf("\n*Date is invalid.please enter valid date,month,year\n\n");
        printf("\033[1;33m");
        printf("\n\n\tSTARTING DATE OF THE PUNISHMENT:");
                        printf("\n\t\tENTER DATE:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_start_date);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER MONTH:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_start_month);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER YEAR:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%04d",&s1.punishment_start_year);
                        printf("\033[1;33m");
    }


                        break;

                    case 20:
 printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tENDING DATE OF THE PUNISHMENT:");
                        printf("\n\t\tENTER DATE:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_end_date);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER MONTH:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_end_month);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER YEAR:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%04d",&s1.punishment_end_year);
                        printf("\033[1;33m");


    while(!remaining_punishment_time(s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year))
     {

         printf("\033[1;31m");
         printf("\n*Date is invalid.please enter valid date,month,year\n\n");
         printf("\033[1;33m");
         printf("\n\n\tENDING DATE OF THE PUNISHMENT:");
                        printf("\n\t\tENTER DATE:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_end_date);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER MONTH:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_end_month);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER YEAR:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%04d",&s1.punishment_end_year);
                        printf("\033[1;33m");

    }

                        break;

                    case 21:
 printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tEMERGENCY CONTACT NAME:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.emergencyc);
                        printf("\033[1;33m");
                            while(!valid_name(s1.emergencyc))
                        {

                            printf("\n\tEMERGENCY CONTACT NAME:");
                            fflush(stdin);
                            printf("\033[1;37m");
                            gets(s1.emergencyc);
                            printf("\033[1;33m");
                        }

                        break;

                    case 22:
 printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tRELATION OF EMERGENCY CONTACT:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.emergencyr);
                        printf("\033[1;33m");
                        break;

                    case 23:
 printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tPHONE NUMBER OF EMERGENCY CONTACT:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.emergencyn);
                        printf("\033[1;33m");
                            while(!valid_mobile_number(s1.emergencyn))
                        {
                            printf("\n*Contact number is invalid.Please enter a valid contact number\n\n");
                            printf("\n\tPHONE NUMBER OF EMERGENCY CONTACT:");
                            fflush(stdin);
                            printf("\033[1;37m");
                            gets(s1.emergencyn);
                            printf("\033[1;33m");
                        }

                        break;

                     case 24:
 printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");


                          printf("\nENTER THE NEW DATA:");
			             fp3 = fopen ("DATA\\records\\prison records", "rb" ) ;

              int prisoner_count=0;


                    printf("\n\n\t*PLEASE SELECT A PRISON FOR THE PRISONER");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\t\t***AVAILABLE PRISON LIST OF THE SYSTEM***");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\tPRISON ID\tPRISON NAME\t\t\t\tNUMBER OF CELLS  ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3)==1)
                {

                   rewind(fp);
                    while(fread(&s1,sizeof(pr),1,fp)==1)
                    {
                        if(p1.id==s1.prisoner_prison_id)
                        {
                            prisoner_count++;
                        }
                    }
                 printf("\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                 if(prisoner_count>=p1.capacity)
                    {
                     printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;31mCAPACITY : %d/%d\033[1;33m\t\t\t  %d\033[1;33m",p1.id,p1.name,prisoner_count,p1.capacity,p1.cells);
                    }
                printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;32mCAPACITY : %d/%d\033[1;33m\t\t\t  %d\033[1;33m",p1.id,p1.name,prisoner_count,p1.capacity,p1.cells);

                prisoner_count=0;

               }
                printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");


                        printf("\n\n\tPRISON ID NUMBER:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%s",&prison_id);
                        printf("\033[1;33m");

                            while(!valid_prison_ID_selecter(prison_id))
                        {

                            printf("\n\tPRISON ID NUMBER:");
                            fflush(stdin);
                            printf("\033[1;37m");
                            scanf("%s",&prison_id);
                            printf("\033[1;33m");
                        }
                    fflush(stdin);
                    s1.prisoner_prison_id=prison_id;
                        break;

                     case 25:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
            FILE *fp3;
            prr p1;

            fp3 =fopen("DATA\\records\\prison records","r");

        while(fread(&p1,sizeof(prr),1,fp3))
        {
          if(s1.prisoner_prison_id==p1.id)
            {
              printf("\n\tTHIS PRISON HAS %d CELLS.THEREFORE PLEASE ENTER A CELL NUMBER WITHIN 1 TO %d",p1.cells,p1.cells);

            }
        }

          printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tCELL NUMBER:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%s",&cell_number);
                        printf("\033[1;33m");

        while(!valid_cell_number_selecter(s1.prisoner_prison_id,cell_number) )
        {

           printf("\n\tCELL NUMBER:");
           fflush(stdin);
           printf("\033[1;37m");
           scanf("%s",&cell_number);
           printf("\033[1;33m");
        }
            fflush(stdin);
            s1.prisoner_cell_number=valid_cell_number(cell_number);


fclose(fp3);
                     break;

                    case 26:
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA: ");
                        printf("\n\n\tID:");
                        printf("\033[1;37m");
                        gets(s1.id);
                        printf("\033[1;33m");

                                       while(!valid_prisoner_id_or_staff_member_id(s1.id))
                        {
                          printf("\n\tID:");
                          printf("\033[1;37m");
                          fflush(stdin);
                          gets(s1.id);
                          printf("\033[1;33m");

                        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");


			     printf("\nENTER THE NEW DATA:");
			             fp3 = fopen ("DATA\\records\\prison records", "rb" ) ;

                    printf("\n\n\t*PLEASE SELECT A PRISON FOR THE PRISONER");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\t\t***AVAILABLE PRISON LIST OF THE SYSTEM***");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\tPRISON ID\tPRISON NAME\t\t\t\tNUMBER OF CELLS  ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3)==1)
                {

                   rewind(fp);
                    while(fread(&s1,sizeof(pr),1,fp)==1)
                    {
                        if(p1.id==s1.prisoner_prison_id)
                        {
                            prisoner_count++;
                        }
                    }
                 printf("\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                 if(prisoner_count>=p1.capacity)
                    {
                     printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;31mCAPACITY : %d/%d\033[1;33m\t\t\t  %d\033[1;33m",p1.id,p1.name,prisoner_count,p1.capacity,p1.cells);
                    }
                printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;32mCAPACITY : %d/%d\033[1;33m\t\t\t  %d\033[1;33m",p1.id,p1.name,prisoner_count,p1.capacity,p1.cells);

                prisoner_count=0;

               }
                printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\n\n\tPRISON ID NUMBER:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%d",&prison_id);
                        printf("\033[1;33m");

            while(!valid_prison_ID_selecter(prison_id))
        {

            printf("\n\tPRISON ID NUMBER:");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%d",&prison_id);
            printf("\033[1;33m");
        }
fflush(stdin);
s1.prisoner_prison_id=prison_id;
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                    	printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tNAME:");
                        printf("\033[1;37m");
                        gets(s1.full_name);
                        printf("\033[1;33m");

                             while(!valid_name(s1.full_name))
        {
            printf("\n\tNAME: ");
            printf("\033[1;37m");
            fflush(stdin);
            gets(s1.full_name);
            printf("\033[1;33m");
        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
			             printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tNAME WITH INITIALS:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(s1.name_with_initials);
                        printf("\033[1;33m");
                        while(!valid_name(s1.name_with_initials))
        {
            printf("\n\tNAME WITH INITIALS:");
            printf("\033[1;37m");
            fflush(stdin);
            gets(s1.name_with_initials);
            printf("\033[1;33m");
        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
          printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tNATIONALITY:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.nationality);
                        printf("\033[1;33m");
             while(!valid_name(s1.nationality))
        {
                        printf("\n\n\tNATIONALITY:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.nationality);
                        printf("\033[1;33m");
        }


printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                       printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tNATIONAL ID:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.national_id);
                        printf("\033[1;33m");
                             while(!valid_national_id(s1.national_id))
        {

          printf("\n\tNATIONAL ID:");
          fflush(stdin);
          printf("\033[1;37m");
          gets(s1.national_id);
          printf("\033[1;33m");
        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
			            printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tGENDER(male/female):");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.gender);
                        printf("\033[1;33m");

                                  while(!valid_gender(s1.gender))
        {

          printf("\n\tGENDER(male/female):");
          fflush(stdin);
          printf("\033[1;37m");
          gets(s1.gender);
          printf("\033[1;33m");
        }

printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                       printf("\nENTER THE NEW DATA:");
                        printf("\n\tDATE OF BIRTH: ");
                        printf("\n\t\tENTER DATE: ");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%d",&s1.prisoner_birth_date);
                        printf("\033[1;33m");

                        printf("\n\t\tENTER MONTH: ");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%d",&s1.prisoner_birth_month);
                        printf("\033[1;33m");

                        printf("\n\t\tENTER YEAR: ");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%d",&s1.prisoner_birth_year);
                        printf("\033[1;33m");

                            while(!valid_date(s1.prisoner_birth_date,s1.prisoner_birth_month,s1.prisoner_birth_year))

                             {
                                  printf("\033[1;31m");
                                  printf("\n*Date is invalid.please enter valid date,month,year\n\n");
                                  printf("\033[1;33m");

                                  printf("\tDATE OF BIRTH: ");
                                  printf("\n\t\tENTER DATE: ");
                                  fflush(stdin);
                                  printf("\033[1;37m");
                                  scanf("%d",&s1.prisoner_birth_date);
                                  printf("\033[1;33m");

                                   printf("\n\t\tENTER MONTH: ");
                                   fflush(stdin);
                                   printf("\033[1;37m");
                                   scanf("%d",&s1.prisoner_birth_month);
                                   printf("\033[1;33m");

                                    printf("\n\t\tENTER YEAR: ");
                                    fflush(stdin);
                                    printf("\033[1;37m");
                                    scanf("%d",&s1.prisoner_birth_year);
                                    printf("\033[1;33m");

                               }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

printf("\033[1;32m");
            s1.age=age_calculator(s1.prisoner_birth_date,s1.prisoner_birth_month,s1.prisoner_birth_year);
            printf("\n\t--------------------------------------------------------------------------------------",s1.age);
            printf("\n\tACCORDING TO THE DATE OF BIRTH,SYSTEM HAS DETECTED PRISONER'S AGE.\n\tAGE IS %d",s1.age);
            printf("\n\t--------------------------------------------------------------------------------------\n",s1.age);



printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tWEIGHT(in kilograms):");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%s",&weight);
                        printf("\033[1;33m");

            while(!valid_weight(weight))
        {

          printf("\n\tWEIGHT(in kilograms):");
          fflush(stdin);
          printf("\033[1;37m");
          scanf("%s",&weight);
          printf("\033[1;33m");

        }
s1.weight=valid_weight(weight);

printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
			            printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tHEIGHT(in centimeters):");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%s",&height);
                        printf("\033[1;33m");
            while(!valid_height(height))
        {

            printf("\n\tHEIGHT(in centimeters):");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%s",&height);
            printf("\033[1;33m");
        }

s1.height=valid_height(height);
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
			           printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tHAIRCOLOR:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(s1.haircolor);
                        printf("\033[1;33m");

            while(!valid_colour(s1.haircolor))
        {
            printf("\033[1;31m");
            printf("\n*Colour name is invalid.Please enter a valid colour name.\n\n");
            printf("\033[1;33m");
            printf("\n\tHAIRCOLOR:");
            printf("\033[1;37m");
            fflush(stdin);
            gets(s1.haircolor);
            printf("\033[1;33m");
        }


printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tEYECOLOR:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.eyecolor);
                        printf("\033[1;33m");
                  while(!valid_colour(s1.eyecolor))
        {
            printf("\n*Colour name is invalid.Please enter a valid colour name without numbers\n\n");
            printf("\n\tEYECOLOR:");
            fflush(stdin);
            printf("\033[1;37m");
            gets(s1.eyecolor);
            printf("\033[1;33m");
        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
			            printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tPHYSICAL HEALTH CONDITION(good/bad):");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.physical_health);
                        printf("\033[1;33m");


            while(!valid_condition(s1.physical_health))
        {
            printf("\n*Condition is invalid.Please enter a valid condition(good/bad)\n\n");
            printf("\n\tPHYSICAL HEALTH CONDITION(good/bad):");
            fflush(stdin);
            printf("\033[1;37m");
            gets(s1.physical_health);
            printf("\033[1;33m");
        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
			           printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tMENTAL HEALTH CONDITION(good/bad):");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.mental_health);
                        printf("\033[1;33m");

            while(!valid_condition(s1.mental_health))
        {
            printf("\n*Condition is invalid.Please enter a valid condition(good/bad)\n\n");
            printf("\nMENTAL HEALTH CONDITION(good/bad):");
            fflush(stdin);
            printf("\033[1;37m");
            gets(s1.mental_health);
            printf("\033[1;33m");
        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
			           printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tSPECIFIC ILLNESSES:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.specific_illnesses);
                        printf("\033[1;33m");

printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
			            printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tCRIME:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.crime);
                        printf("\033[1;33m");
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tCOURT:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.court);
                        printf("\033[1;33m");
                    while(!valid_name(s1.court))
        {

            printf("\n\tENTER COURT NAME: ");
            fflush(stdin);
            printf("\033[1;37m");
            gets(s1.court);
            printf("\033[1;33m");

        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                        if(strcmpi(death_penalty,"AVAILABLE")==0)
                {
                 printf("\n\t\tPLEASE SELECT THE TYPE OF THE CONVICTION.");
                 printf("\n\t\t(1)\033[1;37mIMPRISONMENT\033[1;33m");
                 printf("\n\t\t(2)\033[1;31mDEATH PENALTY\033[1;33m");
                 printf("\n\n\t\tENTER THE NUMBER OF THE COVICTION TYPE:");
                 fflush(stdin);
                 scanf("%d",&s1.penalty_type);
                 while(s1.penalty_type!=1&&s1.penalty_type!=2)
                 {
                      printf("\033[1;31m\n\t\t*Invalid input.Please enter a valid choice.\n\033[1;33m");
                       printf("\n\t\tPLEASE SELECT THE TYPE OF THE CONVICTION.");
                        printf("\n\t\t(1)\033[1;37mIMPRISONMENT\033[1;33m");
                        printf("\n\t\t(2)\033[1;31mDEATH PENALTY\033[1;33m");
                         printf("\n\n\t\tENTER THE NUMBER OF THE COVICTION TYPE:");
                         fflush(stdin);
                         scanf("%d",&s1.penalty_type);
                 }
                 if(s1.penalty_type==1)
                    {
                         printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\n\t CONVICTION TYPE = \033[1;37mIMPRISONMENT\033[1;33m");
                         printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                 if(s1.penalty_type==2)
                    {
                         printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\n\t CONVICTION TYPE = \033[1;31mDEATH PENALTY\033[1;33m");
                         printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                  printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                }
            else
                {
                 s1.penalty_type=1;
                }
			            printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tCONVICTION DETAILS:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.punishment);
                        printf("\033[1;33m");

printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
			           printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tSTARTING DATE OF THE PUNISHMENT:");
                        printf("\n\t\tENTER DATE:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_start_date);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER MONTH:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_start_month);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER YEAR:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%04d",&s1.punishment_start_year);
                        printf("\033[1;33m");

    while(!valid_date(s1.punishment_start_date,s1.punishment_start_month,s1.punishment_start_year))
    {
        printf("\033[1;31m");
        printf("\n*Date is invalid.please enter valid date,month,year\n\n");
        printf("\033[1;33m");
        printf("\n\n\tSTARTING DATE OF THE PUNISHMENT:");
                        printf("\n\t\tENTER DATE:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_start_date);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER MONTH:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_start_month);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER YEAR:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%04d",&s1.punishment_start_year);
                        printf("\033[1;33m");
    }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                       printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tENDING DATE OF THE PUNISHMENT:");
                        printf("\n\t\tENTER DATE:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_end_date);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER MONTH:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_end_month);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER YEAR:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%04d",&s1.punishment_end_year);
                        printf("\033[1;33m");


    while(!remaining_punishment_time(s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year))
     {

         printf("\033[1;31m");
         printf("\n*Date is invalid.please enter valid date,month,year\n\n");
         printf("\033[1;33m");
         printf("\n\n\tENDING DATE OF THE PUNISHMENT:");
                        printf("\n\t\tENTER DATE:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_end_date);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER MONTH:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%02d",&s1.punishment_end_month);
                        printf("\033[1;33m");
                        printf("\n\t\tENTER YEAR:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%04d",&s1.punishment_end_year);
                        printf("\033[1;33m");

    }

printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                        printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tEMERGENCY CONTACT NAME:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.emergencyc);
                        printf("\033[1;33m");
            while(!valid_name(s1.emergencyc))
        {

            printf("\n\tEMERGENCY CONTACT NAME:");
            fflush(stdin);
            printf("\033[1;37m");
            gets(s1.emergencyc);
            printf("\033[1;33m");
        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
			           printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tRELATION OF EMERGENCY CONTACT:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.emergencyr);
                        printf("\033[1;33m");

printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
			            printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tPHONE NUMBER OF EMERGENCY CONTACT:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(s1.emergencyn);
                        printf("\033[1;33m");
            while(!valid_mobile_number(s1.emergencyn))
        {
            printf("\n*Contact number is invalid.Please enter a valid contact number\n");
            printf("\n\tPHONE NUMBER OF EMERGENCY CONTACT:");
            fflush(stdin);
            printf("\033[1;37m");
            gets(s1.emergencyn);
            printf("\033[1;33m");
        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");



            fp3 =fopen("DATA\\records\\prison records","r");

        while(fread(&p1,sizeof(prr),1,fp3))
        {
          if(s1.prisoner_prison_id==p1.id)
            {
              printf("\n\tTHIS PRISON HAS %d CELLS.THEREFORE PLEASE ENTER A CELL NUMBER WITHIN 1 TO %d",p1.cells,p1.cells);

            }


        }

          printf("\nENTER THE NEW DATA:");
                        printf("\n\n\tCELL NUMBER:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        scanf("%s",&cell_number);
                        printf("\033[1;33m");

        while(!valid_cell_number_selecter(s1.prisoner_prison_id,cell_number) )
        {

           printf("\n\tCELL NUMBER:");
           fflush(stdin);
           printf("\033[1;37m");
           scanf("%s",&cell_number);
           printf("\033[1;33m");
        }
            fflush(stdin);
            s1.prisoner_cell_number=valid_cell_number(cell_number);


fclose(fp3);


printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        break;

                    case 27:

                        return ;
                        break;

                    default:
 printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nYOU HAVE ENTERD SOMETHING ELSE...PLEASE ENTER A CORRECT CHOICE\n");
                        break;

                    }
                }
                while(num<1||num>27);

                fseek(fp,-sizeof(pr),SEEK_CUR);

                fwrite(&s1,sizeof(pr),1,fp);

                fseek(fp,-sizeof(pr),SEEK_CUR);

                fread(&s1,sizeof(pr),1,fp);

                choice=5;

                break;
           }
        }


if(choice==5)
    {

            system("cls");

            printf("\n\t\t\033[1;32mEDITING HAS COMPLETED...\033[1;33m\n");
            printf("--------------------\n");
            printf("THE NEW RECORD IS:\n");
            printf("\n");
                printf("\n");
                printf("\n\t\033[1;31m********************************************************");
                printf("\n\t********* \033[1;33mRECORD OF THE PRISONER ID:\033[1;37m %s\033[1;31m *********",s1.id);
                printf("\n\t\033[1;31m********************************************************\033[1;33m");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NAME : \t\t\t\t\033[1;37m %s  \033[1;33m   ",s1.full_name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NAME WITH INITIALS :\t\t\t \033[1;37m%s \033[1;33m",s1.name_with_initials);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NATIONALITY :\t\t\t \033[1;37m%s\033[1;33m",s1.nationality);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S NATIONAL ID :\t\t\t\033[1;37m %s \033[1;33m",s1.national_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S GENDER :\t\t\t\t\033[1;37m %s\033[1;33m ",s1.gender);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S AGE :\t\t\t\t\033[1;37m %d \033[1;33m",s1.age);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S DATE OF BIRTH :\t\t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.prisoner_birth_date,s1.prisoner_birth_month,s1.prisoner_birth_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S WEIGHT :\t\t\t\t\033[1;37m %d kg\033[1;33m ",s1.weight);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S HEIGHT :\t\t\t\t\033[1;37m %d cm\033[1;33m",s1.height);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S HAIRCOLOR :\t\t\t\t\033[1;37m %s \033[1;33m",s1.haircolor);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S EYECOLOR :\t\t\t\t\033[1;37m %s\033[1;33m",s1.eyecolor);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S PHYSICAL HEALTH CONDITION :\t\t\033[1;37m %s\033[1;33m",s1.physical_health);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S MENTAL HEALTH CONDITION :\t\t\033[1;37m %s\033[1;33m",s1.mental_health);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
				printf("\nPRISONER'S SPECIFIC ILLNESSES :\t\t\t\033[1;37m %s\033[1;33m",s1.specific_illnesses);
				printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S CRIME :\t\t\t\t\033[1;37m %s\033[1;33m",s1.crime);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nCOURT : \t\t\t\t\t\033[1;37m %s\033[1;33m",s1.court);

                if(strcmpi(death_penalty,"AVAILABLE")==0)
                {
                 if(s1.penalty_type==1)
                    {
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\nCONVICTION TYPE :\t\t\t\t \033[1;37mIMPRISONMENT\033[1;33m");
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                 if(s1.penalty_type==2)
                    {
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\nCONVICTION TYPE :\t\t\t\t \033[1;31mDEATH PENALTY\033[1;33m");
                         printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    }
                }
                else
                {
                   printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                   printf("\nCONVICTION TYPE :\t\t\t\t \033[1;37mIMPRISONMENT\033[1;33m");
                   printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                }
                printf("\nPRISONER'S CONVICTION DETAILS :\t\t\t\033[1;37m %s\033[1;33m",s1.punishment);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTARTING DATE OF THE PUNISHMENT : \t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.punishment_start_date,s1.punishment_start_month,s1.punishment_start_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nENDING DATE OF THE PUNISHMENT :\t\t\t\033[1;37m %02d/%02d/%04d \033[1;33m",s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);

                remaining_punishment_time(s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);

                printf("\nPRISONER'S EMERGENCY CONTACT :\t\t\t \033[1;37m%s\033[1;33m",s1.emergencyc);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nRELATION OF EMERGENCY CONTACT WITH PRISONER : \t\033[1;37m %s\033[1;33m",s1.emergencyr);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nEMERGENCY CONTACT'S PHONE NUMBER :\t\t\033[1;37m %s\033[1;33m",s1.emergencyn);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S PRISON ID NUMBER :\t\t\t\033[1;37m %04d\033[1;33m",s1.prisoner_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                valid_prison_name_finder(s1.prisoner_prison_id);

                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISONER'S CELL NUMBER :\t\t\t\033[1;37m %04d\033[1;33m",s1.prisoner_cell_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");

            fclose(fp);



            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);
            count++;


          }

        else
        {

            printf("\nTHE RECORD DOES NOT EXIST::\n");
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
            fflush(stdin);
        	scanf(" %c",&choice);

        }
    }

    while(choice=='Y'||choice=='y');

    fclose ( fp ) ;
    printf("\n\tPRESS ENTER TO EXIT EDITING MENU.");
    getch();


}


void prisonerviewrecord()

{

 /*********************************************************
This function is used for viewing prisoner records in each prison(As a summary)
*********************************************************/


    system("cls");
    pr s1;
    prr p1;
    FILE *fp,*fp3,*fp4;;

    char another = 'Y';
    int count=0,found=0,prison_ID=0,found_p=0,total_prisoners=0;

         if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a22.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    fp=fopen("DATA\\records\\prisoner records","rb");
    rewind(fp);
    fp3=fopen("DATA\\records\\prison records","rb");
    rewind(fp3);
 while ( another == 'Y' || another == 'y' )
{

   system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mLIST OF PRISONERS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");


   printf("\n\n*Please select a prison ID to get the list of prisoners of the selected prison.");
   fp3 = fopen ("DATA\\records\\prison records", "rb" ) ;

              int prisoner_count=0;

               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\t\t***AVAILABLE PRISON LIST OF THE SYSTEM***");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\tPRISON ID\tPRISON NAME\t\t\t\tNUMBER OF CELLS  ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3)==1)
                {

                   rewind(fp);
                    while(fread(&s1,sizeof(pr),1,fp)==1)
                    {
                        if(p1.id==s1.prisoner_prison_id)
                        {
                            prisoner_count++;
                            total_prisoners++;
                        }
                    }
                 printf("\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                 if(prisoner_count>=p1.capacity)
                    {
                     printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;31mCAPACITY : %d/%d\033[1;33m\t\t\t  %d\033[1;33m",p1.id,p1.name,prisoner_count,p1.capacity,p1.cells);
                    }
                printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;32mCAPACITY : %d/%d\033[1;33m\t\t\t  %d\033[1;33m",p1.id,p1.name,prisoner_count,p1.capacity,p1.cells);

                prisoner_count=0;

               }
                printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");

  if(total_prisoners>0){
   printf("\n\n\033[1;33m");
   printf("\n\n\tENTER PRISON ID :");
    printf("\033[1;37m");
    fflush(stdin);
   scanf("%d",&prison_ID);
    rewind(fp3);

   while(fread(&p1,sizeof(prr),1,fp3)){

if(p1.id==prison_ID)
    {
       found_p=1;
       system("cls");
   printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
    printf("\n\t%04d         %s",p1.id,p1.name);
    printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");

    rewind(fp);
    while(fread(&s1,sizeof(pr),1,fp))
    {

        if(s1.prisoner_prison_id==prison_ID)
        {
            printf("\n(%d)",count+1);
            printf("\tID : %s",s1.id);
            printf("\n\tNAME : %s",s1.full_name);
            printf("\n");
            count++;
            found=1;

        printf("\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
        }
   }

   if(found){
    printf("\033[1;32m");
    printf("\n*There are \033[1;37m%d\033[1;32m prisoner record/records under prison ID:%04d.\n\n\n",count,p1.id);
    printf("\033[1;33m");
   }
   if(!found){
              printf("\033[1;31m");
               printf("\n*There are no prisoner record/records under prison ID:%04d.\n\n\n",p1.id);
               printf("\033[1;33m");
             }

             }

   }

   if(!found_p){
          printf("\033[1;31m");
          printf("\n\t*This prison ID is not available in the system.  ");
          printf("\033[1;33m");

         }

   count=0;
   prison_ID=0;
   printf("\nDO YOU WANT TO CHECK ANOTHER PRISONER LIST?(Y/N)");
   scanf(" %c",&another);
  }
  else{
    another='N';
  }
}

    fclose(fp);
    fclose(fp3);
    printf("\n\n\nPRESS ANY KEY TO EXIT");
	getch();

}


void prisonerdeleterecord( )

{
/*********************************************************
This function is used to delete prisoner records
*********************************************************/
    system("cls");
    pr s1;
    FILE *fp,*ft,*fp6 ;

    char another = 'Y' ,id[10];
    int choice,check;
    int j=0,found=0;

     FILE *fp4;


         if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a11.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }


    system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mDELETE PRISONER RECORDS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");

    //filter admins
  int k=0;
   if (strcmp(user_type,"\033[1;34mUSER MODE")==0)
    {

	printf("\033[1;31m\n\t\t");
	for (k = 0; k < 70; k++){
	printf("%c",205);}
	printf("  \n\t\t%c                                                                    %c",186,186);

	printf("  \n\t\t%c  ONLY SUPER ADMIN OR ANOTHER ADMIN CAN ADD,EDIT OR DELETE RECORDS. %c",186,186);
	printf("  \n\t\t%c                                                                    %c",186,186);
	printf("  \n\t\t");
	for (k = 0; k < 70; k++){
    printf("%c",205);}

     printf("\033[1;33m");

    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
    return 0;

    }

    char input_pword[50],c;

   fp6 = fopen( "DATA\\records\\password" , "r");
   while (fscanf(fp6, "%s", pword)!=EOF)

 printf("\033[1;33m");
 printf("\n\tENTER PASSWORD : ");
 printf("\033[1;37m");
    int i=0;
    while(i<50)
	{
	    input_pword[i]=getch();
	    c=input_pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	input_pword[i]='\0';

	i=0;

//Getting access for the super admin & other admins
int match=0;

ur u1;

	FILE *fp7;
fp7 = fopen( "DATA\\records\\userslist" , "r");

	while(fread(&u1,sizeof(ur),1,fp7)){

		if(strcmp(pword,input_pword)==0||strcmp(input_pword,u1.pword)==0)
        {
           if(strcmpi(u1.admin_status,"yes")==0)
            {
               match=1;
            }
        }
	}

if(match)
{
printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;32m");

     printf("\n\t\t*ACCESS GRANTED*");
printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;33m");
printf("\n\tPress any key to contnue...");
getch();

   while ( another == 'Y' || another == 'y' )

    {
   system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mDELETE PRISONER RECORDS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");




        fp = fopen ("DATA\\records\\prisoner records", "r" ) ;
        if ( fp == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXIST");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getch();
                    return ;
				}
				ft=fopen("DATA\\records\\temp","w");

				if(ft==NULL)
                {
                	printf("\nSYSTEM ERROR");
                    printf("\nPRESS ANY KEY TO GO BACK");
                    getch();
                    return ;
                }
                printf("\033[1;33m");
                printf("\n\n\t\tENTER THE ID OF THE PRISONER TO BE DELETED:");
                fflush(stdin);
                printf("\033[1;37m");
                scanf("%s",&id);
                rewind(fp);

        		while(fread(&s1,sizeof(pr),1,fp)==1)
                {

                    if(strcmp(s1.id,id)==0)
                        {
                            found=1;
                        }
                    else

                     fwrite(&s1,sizeof(pr),1,ft);
                }

        fclose(fp);
        fclose(ft);
        fclose(fp6);

        if(found)
            {
                ft=fopen("DATA\\records\\temp","r");
                fp=fopen("DATA\\records\\prisoner records","w");
                while(fread(&s1,sizeof(pr),1,ft))
                {
                    fwrite(&s1,sizeof(pr),1,fp);
                }
        fclose(fp);
        fclose(ft);


printf("\n\033[1;32m--------------------------------------------------------------------------------------------------");
        printf("\n\tDELETED SUCCESFULLY...");
printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;33m");
                   getch();

            }


       else{
             printf("\033[1;31m");
             printf("ID IS INCORRECT");
             printf("\033[1;33m");
             getch();

             }

        remove("DATA\\records\\temp");
        printf("\033[1;33m");
        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        fflush(stdin);
        scanf(" %c",&another);


               }


    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();

     }
	else
	{
		printf("\033[1;31m");
		printf("\nSorry!Invalid password\n");
		printf("\033[1;33m");
		printf("\n\n\tPRESS ANY KEY TO EXIT...");
        getch();


    }


}

void staffmemberaddrecord( )
{
/*********************************************************
This function is used to add staff member records
*********************************************************/

    system("cls");
    sr sm1;
    prr p1;
    FILE *fp2,*fp3,*fp4;
    char another = 'Y' ,id[10],add_or_not='k';
    int choice;

         if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a14.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }


    fp2 = fopen ("DATA\\records\\staff member records", "ab+" ) ;

    if ( fp2 == NULL )
    {
        fp2=fopen("DATA\\records\\staff member records","w");
        if(fp2==NULL)
        {

            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return ;
        }
    }

    while ( another == 'Y'|| another=='y' )

    {
         system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37m STAFF MEMBER REGISTRATION \033[1;31m\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");


 int k=0;
   if (strcmp(user_type,"\033[1;34mUSER MODE")==0)
    {

	printf("\033[1;31m\n\t\t");
	for (k = 0; k < 70; k++){
	printf("%c",205);}
	printf("  \n\t\t%c                                                                    %c",186,186);

	printf("  \n\t\t%c  ONLY SUPER ADMIN OR ANOTHER ADMIN CAN ADD,EDIT OR DELETE RECORDS. %c",186,186);
	printf("  \n\t\t%c                                                                    %c",186,186);
	printf("  \n\t\t");
	for (k = 0; k < 70; k++){
    printf("%c",205);}

    printf("\033[1;33m");
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
    return 0;

    }
if (strcmp(user_type,"\033[1;34mUSER MODE")!=0)
   {
       while(add_or_not!='y'&&add_or_not!='Y'&&add_or_not!='n'&&add_or_not!='N')
       {
       printf ( "\033[1;33m");
       printf("\n\n\tDO YOU WANT TO ADD NEW STAFF MEMBER?(Y/N)");
       fflush(stdin);
       printf ( "\033[1;37m");
       scanf("%c",&add_or_not);
       }
       if(add_or_not=='n'||add_or_not=='N')
       {
           return 0;
       }
        printf("\n\n\t\ ENTER NEW DETAILS");
        printf("\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
   }

        choice=0;
        fflush(stdin);
        printf ( "\033[1;33m");
		printf ( "\n\n\tENTER STAFF MEMBER ID:\t");
		printf ( "\033[1;37m");
        scanf(" %s",&id);
        rewind(fp2);

        while(!valid_prisoner_id_or_staff_member_id(id))
        {
          printf ( "\033[1;33m");
          printf ( "\n\tENTER STAFF MEMBER ID:\t");
          fflush(stdin);
          printf ( "\033[1;37m");
          scanf("%s",&id);
          rewind(fp2);
        }
        while(fread(&sm1,sizeof(sr),1,fp2)==1)
        {
            if(strcmp(sm1.id,id)==0)
            {
                printf ( "\033[1;31m");
                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                printf ( "\033[1;33m");
                choice=1;

            }
        }

        if(choice==0)
        {

            strcpy(sm1.id,id);
            fflush(stdin);
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
fp3 = fopen ("DATA\\records\\prison records", "rb" ) ;
pr s1;
FILE *fp;
fp =fopen("DATA\\records\\prison records", "rb");

              int staff_count=0;

                 printf ( "\033[1;33m");
                    printf("\n\n\t*PLEASE SELECT THE PRISON OF THIS STAFF MEMBER");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\t\t***AVAILABLE PRISON LIST OF THE SYSTEM***");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\tPRISON ID\tPRISON NAME  ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3)==1)
                {
                   rewind(fp2);
                    while(fread(&sm1,sizeof(sr),1,fp2)==1)
                    {
                        if(p1.id==sm1.staff_member_prison_id)
                        {
                            staff_count++;
                        }
                    }
                 printf("\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;32m*Number of staff members : %d\033[1;33m",p1.id,p1.name,staff_count);

                staff_count=0;
               }
                printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");

            int prison_ID;
            printf ( "\033[1;33m");
            printf("\n\tENTER PRISON ID NUMBER: ");
            fflush(stdin);
            printf ( "\033[1;37m");
            scanf(" %d",&prison_ID);

            while(!valid_prison_ID_selecter(prison_ID))
        {
            printf ( "\033[1;33m");
            printf("\n\tENTER PRISON ID NUMBER: ");
            fflush(stdin);
            printf ( "\033[1;37m");
            scanf(" %d",&prison_ID);

        }
sm1.staff_member_prison_id=prison_ID;
fflush(stdin);
printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");

            printf ( "\033[1;33m");
            printf("\n\tENTER STAFF MEMBER FULL NAME: ");
            fflush(stdin);
            printf ( "\033[1;37m");
            gets(sm1.name);
            while(!valid_name(sm1.name))
        {
            printf ( "\033[1;33m");
            printf("\tENTER STAFF MEMBER FULL NAME: ");
            fflush(stdin);
            printf ( "\033[1;37m");
            gets(sm1.name);
        }
printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf ( "\033[1;33m");
            printf("\n\tENTER STAFF MEMBER NAME WITH INITIALS: ");
            printf ( "\033[1;37m");
            gets(sm1.name_with_initials);
            fflush(stdin);
            while(!valid_name(sm1.name_with_initials))
        {
            printf ( "\033[1;33m");
            printf("\tENTER STAFF MEMBER NAME WITH INITIALS: ");
            printf ( "\033[1;37m");
            gets(sm1.name_with_initials);
            fflush(stdin);
        }

printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf ( "\033[1;33m");
            printf("\n\tENTER STAFF MEMBER NATIONAL ID: ");
            printf ( "\033[1;37m");
            gets(sm1.national_id);
            fflush(stdin);
            while(!valid_national_id(sm1.national_id))
        {
          printf ( "\033[1;33m");
          printf("\tENTER STAFF MEMBER NATIONAL ID: ");
          printf ( "\033[1;37m");
          gets(sm1.national_id);
          fflush(stdin);
        }

printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf ( "\033[1;33m");
            printf("\n\tENTER STAFF MEMBER OCCUPATION: ");
            printf ( "\033[1;37m");
            gets(sm1.occupation);
            fflush(stdin);
printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
			printf ( "\033[1;33m");
			printf("\n\tENTER GENDER(male/female): ");
			fflush(stdin);
			printf ( "\033[1;37m");
            gets(sm1.gender);


            while(!valid_gender(sm1.gender))
        {
          printf ( "\033[1;33m");
          printf("\tENTER GENDER(male/female): ");
          fflush(stdin);
          printf ( "\033[1;37m");
          gets(sm1.gender);

        }

printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf ( "\033[1;33m");
            printf("\n\tENTER STAFF MEMBER'S DATE OF BIRTH: ");
            printf("\n\t\tENTER DATE: ");
            printf ( "\033[1;37m");
            scanf("%02d",&sm1.staff_member_birth_date);
            fflush(stdin);
            printf ( "\033[1;33m");
            printf("\n\t\tENTER MONTH: ");
            printf ( "\033[1;37m");
            scanf("%02d",&sm1.staff_member_birth_month);
            fflush(stdin);

            printf ( "\033[1;33m");
            printf("\n\t\tENTER YEAR: ");
            printf ( "\033[1;37m");
            scanf("%04d",&sm1.staff_member_birth_year);
            fflush(stdin);

            while(!valid_date(sm1.staff_member_birth_date,sm1.staff_member_birth_month,sm1.staff_member_birth_year))

    {
        printf("\033[1;31m");
        printf("\n*Date is invalid.please enter valid date,month,year\n\n");
        printf("\033[1;33m");
         printf ( "\033[1;33m");
            printf("\n\tENTER STAFF MEMBER'S DATE OF BIRTH: ");
            printf("\n\t\tENTER DATE: ");
            printf ( "\033[1;37m");
            scanf("%02d",&sm1.staff_member_birth_date);
            fflush(stdin);
            printf ( "\033[1;33m");
            printf("\n\t\tENTER MONTH: ");
            printf ( "\033[1;37m");
            scanf("%02d",&sm1.staff_member_birth_month);
            fflush(stdin);

            printf ( "\033[1;33m");
            printf("\n\t\tENTER YEAR: ");
            printf ( "\033[1;37m");
            scanf("%04d",&sm1.staff_member_birth_year);
            fflush(stdin);
    }

printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
          printf("\033[1;32m");
            sm1.age = age_calculator(sm1.staff_member_birth_date,sm1.staff_member_birth_month,sm1.staff_member_birth_year);
            printf("\n\t--------------------------------------------------------------------------------------");
            printf("\n\t ACCORDING TO THE DATE OF BIRTH,SYSTEM HAS DETECTED STAFF MEMBER'S AGE.\n\t STAFF MEMBER'S AGE= %d",sm1.age);
            printf("\n\t--------------------------------------------------------------------------------------");
            fflush(stdin);
        printf("\033[1;33m");
printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf ( "\033[1;33m");
            printf("\n\tENTER CONTACT NUMBER OF THE STAFF MEMBER: ");
            printf ( "\033[1;37m");
            gets(sm1.staff_member_phone_number);
            fflush(stdin);
            while(!valid_mobile_number(sm1.staff_member_phone_number))
        {
            printf ( "\033[1;33m");
            printf("\tENTER CONTACT NUMBER OF THE STAFF MEMBER: ");
            printf ( "\033[1;37m");
            gets(sm1.staff_member_phone_number);
            fflush(stdin);
        }
printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");

            fwrite ( &sm1, sizeof ( sr ), 1, fp2 ) ;
            printf("\033[1;32m");
            printf("\n\tYOUR RECORD IS ADDED...\n");
            printf("\033[1;33m");
            printf("\n\n\tHERE IS THE COMPLETE RECORD, YOU HAVE ADDED...\n");

             printf("\n");
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\t\tRECORD OF THE STAFF MEMBER ID:\033[1;37m %s\033[1;33m",sm1.id);
                printf("\n\t\033[1;31m*****************************************************\033[1;33m\n");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NAME :\t\t\t\t\033[1;37m %s\033[1;33m",sm1.name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NAME WITH INITIALS :\t\t\033[1;37m %s\033[1;33m",sm1.name_with_initials);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NATIONAL ID :\t\t\t\033[1;37m %s\033[1;33m",sm1.national_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S OCCUPATION :\t\t\t\033[0;92m %s\033[1;33m",sm1.occupation);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S GENDER :\t\t\t\t\033[1;37m %s\033[1;33m",sm1.gender);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S DATE OF BIRTH :\t\t\t\033[1;37m %02d/%02d/%04d\033[1;33m",sm1.staff_member_birth_date,sm1.staff_member_birth_month,sm1.staff_member_birth_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S AGE :\t\t\t\t\033[1;37m %d\033[1;33m",sm1.age);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S CONTACT NUMBER :\t\t\t\033[1;37m %s\033[1;33m",sm1.staff_member_phone_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S PRISON ID NUMBER:\t\t\033[1;37m %04d\033[1;33m",sm1.staff_member_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                valid_prison_name_finder(sm1.staff_member_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n");

        }
        printf ( "\033[1;31m");
        printf ( "\n\tADD ANOTHER RECORD...(Y/N) \t" ) ;
        printf ( "\033[1;33m");
        fflush ( stdin );
        another = getch( );
    }

    fclose ( fp2 ) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
}


void staffmembersearchrecord( )
{
/*********************************************************
This function is used to search staff member records
*********************************************************/
	system("cls");
	sr sm1;
    FILE *fp2,*fp4;
	char id[10],choice;
	char name[50],string1[100],string2[100];
	int search_results=0;
    int ch,found=0;

         if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a13.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    do
	{

        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mSEARCH STAFF MEMBER RECORDS\033[1;31m\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");

		found=0;

        fp2 = fopen ( "DATA\\records\\staff member records", "rb" ) ;

        printf("\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\033[1;31m\n\t\t|\t\033[1;35mSearch by staff member ID\t[1]\t\t\t\033[1;31m|\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\033[1;31m\n\t\t|\t\033[1;35mSearch by staff member Name\t[2]\t\t\t\033[1;31m|\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\033[1;31m\033[1;31m\n\t\t|\t\033[1;37mBack\t\t\t\t[3]\t\t\t\033[1;31m|\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\n\t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\033[1;33m\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        printf("\033[1;37m");
        scanf("%d",&ch);
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
        switch(ch)
        {
         case 1:
            found=0;
            printf("\033[1;33m");
    		printf("\n\n\tENTER STAFF MEMBER ID : ");
    		printf("\033[1;37m");
            fflush(stdin);
            scanf("%s",&id);
            system("cls");

            while ( fread ( &sm1, sizeof ( sr ), 1, fp2 ))
          {
  if(strcmpi(sm1.id,id)==0)
               {
                found=1;
             printf("\n");
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\t\tRECORD OF THE STAFF MEMBER ID:\033[1;37m %s\033[1;33m",sm1.id);
                printf("\n\t\033[1;31m*****************************************************\033[1;33m\n");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NAME :\t\t\t\t\033[1;37m %s\033[1;33m",sm1.name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NAME WITH INITIALS :\t\t\033[1;37m %s\033[1;33m",sm1.name_with_initials);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NATIONAL ID :\t\t\t\033[1;37m %s\033[1;33m",sm1.national_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S OCCUPATION :\t\t\t\033[0;92m %s\033[1;33m",sm1.occupation);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S GENDER :\t\t\t\t\033[1;37m %s\033[1;33m",sm1.gender);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S DATE OF BIRTH :\t\t\t\033[1;37m %02d/%02d/%04d\033[1;33m",sm1.staff_member_birth_date,sm1.staff_member_birth_month,sm1.staff_member_birth_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S AGE :\t\t\t\t\033[1;37m %d\033[1;33m",sm1.age);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S CONTACT NUMBER :\t\t\t\033[1;37m %s\033[1;33m",sm1.staff_member_phone_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S PRISON ID NUMBER:\t\t\033[1;37m %04d\033[1;33m",sm1.staff_member_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                valid_prison_name_finder(sm1.staff_member_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n");

            }

          }
              if(!found){
                 printf("\033[1;31m");
                 printf("\nTHE RECORD DOES NOT EXIST.\n");
                 printf("\033[1;33m");
               }
                found=0;
                  break;

         case 2:
                        found=0;
                        printf("\033[1;33m");
                        printf("\n\n\tENTER STAFF MEMBER NAME : ");
                        printf("\033[1;37m");
                        fflush(stdin);
                        scanf("%s",&name);

                        for(int i = 0;i<50; i++)
            {
           string2[i] = tolower(name[i]);
            }


                  printf("\n\n\t\t HERE IS THE SEARCH RESULT");
          printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;32m");
                 printf("\n\t\tStaff member ID\t\tStaff member name");
          printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;37m");
            while ( fread ( &sm1, sizeof ( sr ), 1, fp2 ))
          {

          for(int i = 0;i<50; i++)
            {
           string1[i] = tolower(sm1.name[i]);
            }

          if(strstr(string1,string2)!=0)
               {


                 search_results++;
                 printf("\n\t\t %04d\t\t%s",sm1.id,sm1.name);
                printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;37m");
               }
            }
            printf("\n\tThere are %d search results",search_results);

           if(search_results>0){
            printf("\033[1;33m");
    		printf("\n\n\tSelect and enter staff member ID from above search results: ");
    		printf("\033[1;37m");
            fflush(stdin);
            scanf("%s",&id);
            system("cls");
            }
            search_results=0;
               rewind(fp2);
            while ( fread ( &sm1, sizeof ( sr ), 1, fp2 ))
          {
  if(strcmpi(sm1.id,id)==0)
               {
                found=1;
             printf("\n");
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\t\tRECORD OF THE STAFF MEMBER ID:\033[1;37m %s\033[1;33m",sm1.id);
                printf("\n\t\033[1;31m*****************************************************\033[1;33m\n");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NAME :\t\t\t\t\033[1;37m %s\033[1;33m",sm1.name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NAME WITH INITIALS :\t\t\033[1;37m %s\033[1;33m",sm1.name_with_initials);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NATIONAL ID :\t\t\t\033[1;37m %s\033[1;33m",sm1.national_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S OCCUPATION :\t\t\t\033[0;92m %s\033[1;33m",sm1.occupation);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S GENDER :\t\t\t\t\033[1;37m %s\033[1;33m",sm1.gender);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S DATE OF BIRTH :\t\t\t\033[1;37m %02d/%02d/%04d\033[1;33m",sm1.staff_member_birth_date,sm1.staff_member_birth_month,sm1.staff_member_birth_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S AGE :\t\t\t\t\033[1;37m %d\033[1;33m",sm1.age);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S CONTACT NUMBER :\t\t\t\033[1;37m %s\033[1;33m",sm1.staff_member_phone_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S PRISON ID NUMBER:\t\t\033[1;37m %04d\033[1;33m",sm1.staff_member_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                valid_prison_name_finder(sm1.staff_member_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n");
            }

          }
            if(!found){
                 printf("\033[1;31m");
                 printf("\nTHE RECORD DOES NOT EXIST.\n");
                 printf("\033[1;33m");

               }

               found=0;
               break;
        case 3:
            staff_records_menu();
        default:
            printf("\033[1;31m");
            printf("\n\t\t*You have entered an invalid choice. Please choose between 1 to 3");
            printf("\033[1;33m");
        }


        printf("\n\nWOULD YOU LIKE TO CONTINUE SEARCHING...(Y/N):");
        fflush(stdin);

        scanf(" %c",&choice);
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp2) ;

}

void staffmembereditrecord()
{
/*********************************************************
This function is used to edit staff member records
*********************************************************/
    system("cls");
    sr sm1;
    pr s1;
    prr p1;
    FILE *fp,*fp2,*fp3,*fp4;
    char id[10],choice;
    int num,count=0;

         if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a15.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    do
    {
        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mEDIT STAFF MEMBER RECORDS\033[1;31m\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");

        int k=0;
   if (strcmp(user_type,"\033[1;34mUSER MODE")==0)
    {

	printf("\033[1;31m\n\t\t");
	for (k = 0; k < 70; k++){
	printf("%c",205);}
	printf("  \n\t\t%c                                                                    %c",186,186);

	printf("  \n\t\t%c  ONLY SUPER ADMIN OR ANOTHER ADMIN CAN ADD,EDIT OR DELETE RECORDS. %c",186,186);
	printf("  \n\t\t%c                                                                    %c",186,186);
	printf("  \n\t\t");
	for (k = 0; k < 70; k++){
    printf("%c",205);}

     printf("\033[1;33m");
     printf("\n\n\tPRESS ANY KEY TO EXIT...");
     getch();

     return 0;
    }
        printf("\033[1;33m");
        printf("\n\tENTER STAFF MEMBER ID:");
        printf("\033[1;37m");
        fflush(stdin);
    	gets(id);
        fp2 = fopen ( "DATA\\records\\staff member records", "rb+" ) ;

        if ( fp2 == NULL )
        {

            printf("\033[1;31m");
            printf( "\nRECORD DOES NOT EXIST:" ) ;
            printf("\033[1;33m");
            printf("\nPRESS ANY KEY TO GO BACK");
            getch();
            return;

        }
        while ( fread ( &sm1, sizeof ( sr ), 1, fp2 ) == 1 )
        {
            if(strcmp(sm1.id,id)==0)
            {
                 printf("\n");
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\t\tRECORD OF THE STAFF MEMBER ID:\033[1;37m %s\033[1;33m",sm1.id);
                printf("\n\t\033[1;31m*****************************************************\033[1;33m\n");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NAME :\t\t\t\t\033[1;37m %s\033[1;33m",sm1.name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NAME WITH INITIALS :\t\t\033[1;37m %s\033[1;33m",sm1.name_with_initials);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NATIONAL ID :\t\t\t\033[1;37m %s\033[1;33m",sm1.national_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S OCCUPATION :\t\t\t\033[0;92m %s\033[1;33m",sm1.occupation);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S GENDER :\t\t\t\t\033[1;37m %s\033[1;33m",sm1.gender);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S DATE OF BIRTH :\t\t\t\033[1;37m %02d/%02d/%04d\033[1;33m",sm1.staff_member_birth_date,sm1.staff_member_birth_month,sm1.staff_member_birth_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S AGE :\t\t\t\t\033[1;37m %d\033[1;33m",sm1.age);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S CONTACT NUMBER :\t\t\t\033[1;37m %s\033[1;33m",sm1.staff_member_phone_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S PRISON ID NUMBER:\t\t\033[1;37m %04d\033[1;33m",sm1.staff_member_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                valid_prison_name_finder(sm1.staff_member_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n");

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..?");

                printf("\n\t\033[1;31m1.\033[1;37mID");
                printf("\n\t\033[1;31m2.\033[1;37mNAME");
                printf("\n\t\033[1;31m3.\033[1;37mNAME WITH INITIALS");
                printf("\n\t\033[1;31m4.\033[1;37mNATIONAL ID");
                printf("\n\t\033[1;31m5.\033[1;37mOCCUPATION");
                printf("\n\t\033[1;31m6.\033[1;37mGENDER");
                printf("\n\t\033[1;31m7.\033[1;37mDATE OF BIRTH");
                printf("\n\t\033[1;31m8.\033[1;37mAGE");
                printf("\n\t\033[1;31m9.\033[1;37mCONTACT NUMBER");
                printf("\n\t\033[1;31m10.\033[1;37mPRISON ID NUMBER");
                printf("\n\t\033[1;31m11.\033[1;34mWHOLE RECORD");
                printf("\n\t\033[1;31m12.\033[1;33mGO BACK TO STAFF MEMBER RECORDS MENU");

                do
                {
                   printf("\033[1;33m");
                    printf("\n\tENTER YOUR CHOICE:");
                    fflush(stdin);
                    printf("\033[1;37m");
                    fflush(stdin);
                    scanf("%d",&num);


                    switch(num)
                    {
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    case 1:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tSTAFF MEMBER ID:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.id);
            while(!valid_prisoner_id_or_staff_member_id(sm1.id))
        {
         printf("\033[1;33m");
         printf("\n\tSTAFF MEMBER ID:");
         printf("\033[1;37m");
         fflush(stdin);
         gets(sm1.id);

        }

                        break;
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    case 2:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tNAME:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.name);
                        while(!valid_name(sm1.name))
        {

         printf("\033[1;33m");
            printf("\n\tNAME:");
            printf("\033[1;37m");
            fflush(stdin);
            gets(sm1.name);
        }

                        break;
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    case 3:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tNAME WITH INITIALS:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.name_with_initials);
              while(!valid_name(sm1.name_with_initials))
        {
            printf("\033[1;33m");
            printf("\n\tNAME:");
            printf("\033[1;37m");
            fflush(stdin);
            gets(sm1.name);
        }
                        break;

printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    case 4:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tNATIONAL ID:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.national_id);
            while(!valid_national_id(sm1.national_id))
        {
         printf("\033[1;33m");
          printf("\n\tNATIONAL ID:");
          printf("\033[1;37m");
          fflush(stdin);
          gets(sm1.national_id);
        }

                        break;
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    case 5:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tOCCUPATION:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.occupation);
                        break;

printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    case 6:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tGENDER(male/female):");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.gender);

            while(!valid_gender(sm1.gender))
        {
          printf("\033[1;33m");
          printf("\n\tGENDER(male/female):");
          printf("\033[1;37m");
          fflush(stdin);
          gets(sm1.gender);
        }

                        break;

 printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    case 7:
            printf("\033[1;33m");
            printf("\n\tENTER THE NEW DATA:");
            printf("\n\tENTER STAFF MEMBER'S DATE OF BIRTH: ");
            printf("\n\t\tENTER DATE: ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%02d",&sm1.staff_member_birth_date);

            printf("\033[1;33m");
            printf("\n\t\tENTER MONTH: ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%02d",&sm1.staff_member_birth_month);

            printf("\033[1;33m");
            printf("\n\t\tENTER YEAR: ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%04d",&sm1.staff_member_birth_year);

            while(!valid_date(sm1.staff_member_birth_date,sm1.staff_member_birth_month,sm1.staff_member_birth_year))

    {
        printf("\n*Date is invalid.please enter valid date,month,year\n\n");

         printf("\n\tENTER STAFF MEMBER'S DATE OF BIRTH: ");
            printf("\n\t\tENTER DATE: ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%02d",&sm1.staff_member_birth_date);

            printf("\033[1;33m");
            printf("\n\t\tENTER MONTH: ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%02d",&sm1.staff_member_birth_month);

            printf("\033[1;33m");
            printf("\n\t\tENTER YEAR: ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%04d",&sm1.staff_member_birth_year);
    }
               break;
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                case 8:
      printf("\033[1;32m");
      printf("\n\t--------------------------------------------------------------------------------------");
            sm1.age = age_calculator(sm1.staff_member_birth_date,sm1.staff_member_birth_month,sm1.staff_member_birth_year);
            printf("\n\t ACCORDING TO THE DATE OF BIRTH,SYSTEM HAS DETECTED STAFF MEMBER'S AGE.\nAGE= %d",sm1.age);
       printf("\n\t--------------------------------------------------------------------------------------");
            printf("\033[1;33m");
                    break;
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    case 9:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tCONTACT NUMBER:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.staff_member_phone_number);
            while(!valid_mobile_number(sm1.staff_member_phone_number))
        {

            printf("\033[1;33m");
            printf("\n\tCONTACT NUMBER:");
            printf("\033[1;37m");
            fflush(stdin);
            gets(sm1.staff_member_phone_number);
        }

                        break;
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                     case 10:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");


fp3 =fopen("DATA\\records\\prison records", "rb");
             int staff_count=0;



               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\t\t***AVAILABLE PRISON LIST OF THE SYSTEM***");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\tPRISON ID\tPRISON NAME  ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3)==1)
                {

                   rewind(fp2);
                    while(fread(&sm1,sizeof(sr),1,fp2)==1)
                    {
                        if(p1.id==sm1.staff_member_prison_id)
                        {
                            staff_count++;
                        }
                    }
                 printf("\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;32m*Number of staff members : %d\033[1;33m",p1.id,p1.name,staff_count);

                staff_count=0;

               }
                printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");

                        printf("\033[1;33m");
                        printf("\n\n\tPRISON ID NUMBER:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        scanf("%d",&sm1.staff_member_prison_id);
                while(!valid_prison_ID_selecter(sm1.staff_member_prison_id))
        {
            printf("\033[1;33m");
            printf("\n\tPRISON ID NUMBER:");
            printf("\033[1;37m");
            fflush(stdin);
            scanf("%d",&sm1.staff_member_prison_id);
        }

                        break;
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    case 11:

                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tSTAFF MEMBER ID:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.id);
            while(!valid_prisoner_id_or_staff_member_id(sm1.id))
        {
         printf("\033[1;33m");
         printf("\n\tSTAFF MEMBER ID:");
         printf("\033[1;37m");
         fflush(stdin);
         gets(sm1.id);

        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\nNAME:");
                        gets(sm1.name);
            while(!valid_name(sm1.name))
        {
            printf("\n*name is invalid.please enter a valid name without numbers\n\n");
            printf("\nNAME:");
            gets(sm1.name);
        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tNAME:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.name);
                        while(!valid_name(sm1.name))
        {

         printf("\033[1;33m");
            printf("\n\tNAME:");
            printf("\033[1;37m");
            fflush(stdin);
            gets(sm1.name);
        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tNATIONAL ID:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.national_id);
            while(!valid_national_id(sm1.national_id))
        {
         printf("\033[1;33m");
          printf("\n\tNATIONAL ID:");
          printf("\033[1;37m");
          fflush(stdin);
          gets(sm1.national_id);
        }

printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                         printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tOCCUPATION:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.occupation);
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tGENDER(male/female):");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.gender);

            while(!valid_gender(sm1.gender))
        {
          printf("\033[1;33m");
          printf("\n\tGENDER(male/female):");
          printf("\033[1;37m");
          fflush(stdin);
          gets(sm1.gender);
        }
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\033[1;33m");
            printf("\n\tENTER THE NEW DATA:");
            printf("\n\tENTER STAFF MEMBER'S DATE OF BIRTH: ");
            printf("\n\t\tENTER DATE: ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%02d",&sm1.staff_member_birth_date);

            printf("\033[1;33m");
            printf("\n\t\tENTER MONTH: ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%02d",&sm1.staff_member_birth_month);

            printf("\033[1;33m");
            printf("\n\t\tENTER YEAR: ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%04d",&sm1.staff_member_birth_year);

            while(!valid_date(sm1.staff_member_birth_date,sm1.staff_member_birth_month,sm1.staff_member_birth_year))

    {
        printf("\n*Date is invalid.please enter valid date,month,year\n\n");

         printf("\n\tENTER STAFF MEMBER'S DATE OF BIRTH: ");
            printf("\n\t\tENTER DATE: ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%02d",&sm1.staff_member_birth_date);

            printf("\033[1;33m");
            printf("\n\t\tENTER MONTH: ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%02d",&sm1.staff_member_birth_month);

            printf("\033[1;33m");
            printf("\n\t\tENTER YEAR: ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%04d",&sm1.staff_member_birth_year);
    }

printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                       sm1.age = age_calculator(sm1.staff_member_birth_date,sm1.staff_member_birth_month,sm1.staff_member_birth_year);
                       printf("\n\t--------------------------------------------------------------------------------------");
            printf("\n\t ACCORDING TO THE DATE OF BIRTH,SYSTEM HAS DETECTED STAFF MEMBER'S AGE.\nAGE= %d\n",sm1.age);
            printf("\n\t--------------------------------------------------------------------------------------",s1.age);
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\n\tCONTACT NUMBER:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(sm1.staff_member_phone_number);
            while(!valid_mobile_number(sm1.staff_member_phone_number))
        {

            printf("\033[1;33m");
            printf("\n\tCONTACT NUMBER:");
            printf("\033[1;37m");
            fflush(stdin);
            gets(sm1.staff_member_phone_number);
        }

printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                         printf("\n\tENTER THE NEW DATA:");

fp =fopen("DATA\\records\\prisoner records", "rb");
fp3 =fopen("DATA\\records\\prison records", "rb");

                    staff_count=0;

               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\t\t***AVAILABLE PRISON LIST OF THE SYSTEM***");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\tPRISON ID\tPRISON NAME  ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3)==1)
                {

                   rewind(fp2);
                    while(fread(&sm1,sizeof(sr),1,fp2)==1)
                    {
                        if(p1.id==sm1.staff_member_prison_id)
                        {
                            staff_count++;
                        }
                    }
                 printf("\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;32m*Number of staff members : %d\033[1;33m",p1.id,p1.name,staff_count);

                staff_count=0;

               }
                printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\033[1;33m");
                        printf("\n\n\tPRISON ID NUMBER:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        scanf("%d",&sm1.staff_member_prison_id);
                while(!valid_prison_ID_selecter(sm1.staff_member_prison_id))
        {
            printf("\033[1;33m");
            printf("\n\tPRISON ID NUMBER:");
            printf("\033[1;37m");
            fflush(stdin);
            scanf("%d",&sm1.staff_member_prison_id);
        }


                        break;
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    case 12:
                        printf("\033[1;33m");
                        printf("\nPRESS ANY KEY TO GO BACK...\n");
                        getch();
                        return ;
                        break;

                    default:
                        printf("\033[1;31m");
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
                        printf("\033[1;33m");
                        break;

                    }

                }
                while(num<1||num>12);
                fseek(fp2,-sizeof(sr),SEEK_CUR);
                fwrite(&sm1,sizeof(sr),1,fp2);
                fseek(fp2,-sizeof(sr),SEEK_CUR);
                fread(&sm1,sizeof(sr),1,fp2);
                choice='k';

                break;
            }
        }

        if(choice=='k')

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");
            printf("--------------------\n");
            printf("THE NEW RECORD IS:\n");
            printf("\n");
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\t\tRECORD OF THE STAFF MEMBER ID:\033[1;37m %s\033[1;33m",sm1.id);
                printf("\n\t\033[1;31m*****************************************************\033[1;33m\n");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NAME :\t\t\t\t\033[1;37m %s\033[1;33m",sm1.name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NAME WITH INITIALS :\t\t\033[1;37m %s\033[1;33m",sm1.name_with_initials);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S NATIONAL ID :\t\t\t\033[1;37m %s\033[1;33m",sm1.national_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S OCCUPATION :\t\t\t\033[0;92m %s\033[1;33m",sm1.occupation);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S GENDER :\t\t\t\t\033[1;37m %s\033[1;33m",sm1.gender);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S DATE OF BIRTH :\t\t\t\033[1;37m %02d/%02d/%04d\033[1;33m",sm1.staff_member_birth_date,sm1.staff_member_birth_month,sm1.staff_member_birth_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S AGE :\t\t\t\t\033[1;37m %d\033[1;33m",sm1.age);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S CONTACT NUMBER :\t\t\t\033[1;37m %s\033[1;33m",sm1.staff_member_phone_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nSTAFF MEMBER'S PRISON ID NUMBER:\t\t\033[1;37m %04d\033[1;33m",sm1.staff_member_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                valid_prison_name_finder(sm1.staff_member_prison_id);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n");

            fclose(fp2);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
            scanf("%c",&choice);
            count++;

        }
        else
        {
            printf("\033[1;31m");
            printf("\nTHE RECORD DOES NOT EXIST::\n");
            printf("\033[1;33m");
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
        	scanf("%c",&choice);

        }
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp2 ) ;
    printf("\033[1;33m");
    printf("\tPRESS ANY KEY TO EXIT EDITING MENU.");
    getch();

}


void staffmemberviewrecord()
{
/*********************************************************
This function is used to view staff member details in each prison
*********************************************************/

    system("cls");
    sr sm1;
    prr p1;
    FILE *fp2,*fp3,*fp4;
    //struct record a;
    char another = 'Y';
    int count=0,found=0,prison_ID=0,found_p=0,staff_count=0;

   if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a17.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    fp2=fopen("DATA\\records\\staff member records","rb");
    rewind(fp2);
    fp3=fopen("DATA\\records\\prison records","rb");
    rewind(fp3);
 while ( another == 'Y' || another == 'y' )
{
  system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mLIST OF STAFF MEMBERS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");

   printf("\n*Please select a prison ID to get the list of staff members of selected prison.");
   staff_count=0;

               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\t\t***AVAILABLE PRISON LIST OF THE SYSTEM***");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\tPRISON ID\tPRISON NAME  ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3)==1)
                {

                   rewind(fp2);
                    while(fread(&sm1,sizeof(sr),1,fp2)==1)
                    {
                        if(p1.id==sm1.staff_member_prison_id)
                        {
                            staff_count++;
                        }
                    }
                 printf("\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;32m*Number of staff members : %d\033[1;33m",p1.id,p1.name,staff_count);

                staff_count=0;

               }
                printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
   printf("\n\n\tENTER PRISON ID:");
   scanf("%d",&prison_ID);
   fflush(stdin);
    rewind(fp3);
   while(fread(&p1,sizeof(prr),1,fp3)){

if(p1.id==prison_ID)
    {
       found_p=1;
       system("cls");
    printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
    printf("\n\t%04d         %s",p1.id,p1.name);
    printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");

    rewind(fp2);
    while(fread(&sm1,sizeof(sr),1,fp2))
    {

        if(sm1.staff_member_prison_id==prison_ID)
        {
            printf("\n(%d)",count+1);
            printf("\tID : %s",sm1.id);
            printf("\n\tNAME : %s",sm1.name);
            printf("\n\tAGE: %d",sm1.age);
            printf("\n\tOCCUPATION: %s",sm1.occupation);
            printf("\n");
            count++;
            found=1;
            printf("\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
        }

   }
   if(found){
    printf("\033[1;32m");
    printf("\n*There are \033[1;37m%d \033[1;32mstaff member record/records under prison ID:%04d.\n\n\n",count,p1.id);
    printf("\033[1;33m");
   }
   if(!found){
               printf("\033[1;31m");
               printf("\n*There are no staff member record/records under prison ID:%04d.\n\n\n",p1.id);
               printf("\033[1;33m");
             }
        }
   }
   if(!found_p){
          printf("\033[1;31m");
          printf("\n\t*This prison ID isn't available in the system.  ");
          printf("\033[1;33m");

         }

   count=0;
   prison_ID=0;
   printf("\nDO YOU WANT TO CHECK ANOTHER STAFF MEMBER LIST?(Y/N)");
   scanf(" %c",&another);

}

    fclose(fp2);
    fclose(fp3);
    printf("\n\n\nPRESS ANY KEY TO EXIT");
	getch();

}

void staffmemberdeleterecord()
{
/*********************************************************
This function is used to delete staff member records
*********************************************************/
    system("cls");
    sr sm1;
    ur u1;
    FILE *fp2,*ft2,*fp4,*fp6,*fp7;
    struct staff_member_record file;
    char another = 'Y',id[10];
    int choice,check;
    int j=0,found=0,k=0;

         if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a16.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mDELETE STAFF MEMBER RECORDS\033[1;31m\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");

        //filter admins
      k=0;
   if (strcmp(user_type,"\033[1;34mUSER MODE")==0)
    {

	printf("\033[1;31m\n\t\t");
	for (k = 0; k < 70; k++){
	printf("%c",205);}
	printf("  \n\t\t%c                                                                    %c",186,186);

	printf("  \n\t\t%c  ONLY SUPER ADMIN OR ANOTHER ADMIN CAN ADD,EDIT OR DELETE RECORDS. %c",186,186);
	printf("  \n\t\t%c                                                                    %c",186,186);
	printf("  \n\t\t");
	for (k = 0; k < 70; k++){
    printf("%c",205);}

    printf("\033[1;33m");
    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();
    return 0;

    }

    char input_pword[30],c;

fp6 = fopen( "DATA\\records\\password" , "r");
while (fscanf(fp6, "%s", pword)!=EOF)

 printf("\033[1;33m");
 printf("\nENTER PASSWORD : ");
 printf("\033[1;37m");
    int i=0;
    while(i<50)
	{
	    input_pword[i]=getch();
	    c=input_pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	input_pword[i]='\0';
	//char code=pword;
	i=0;
//Getting access for the super admin & other admins
int match=0;

fp7 = fopen( "DATA\\records\\userslist" , "r");

	while(fread(&u1,sizeof(ur),1,fp7)){
		if(strcmp(pword,input_pword)==0||strcmp(input_pword,u1.pword)==0)
        {
            if(strcmpi(u1.admin_status,"yes")==0)
            {
               match=1;
            }
        }
	}


if(match)
{
printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;32m");

     printf("\n\t\t*ACCESS GRANTED*");
printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;33m");
printf("\n\tPress any key to contnue...");
getch();

   while ( another == 'Y' || another == 'y' )

    {

    	system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mDELETE STAFF MEMBER RECORDS\033[1;31m\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");

        fp2 = fopen ("DATA\\records\\staff member records", "r" ) ;

        if ( fp2 == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXIST");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getch();
                    return ;
				}
				ft2=fopen("temp2","w");

				if(ft2==NULL)
                {
                	printf("\nSYSTEM ERROR");
                    printf("\nPRESS ANY KEY TO GO BACK");
                    getch();
                    return ;
                }
                printf("\033[1;33m");
                printf("\n\tENTER THE ID OF THE RECORD TO BE DELETED:");
                fflush(stdin);
                printf("\033[1;37m");
                scanf("%s",&id);
                rewind(fp2);

        		while(fread(&sm1,sizeof(sr),1,fp2)==1)
                {

                    if(strcmp(sm1.id,id)==0)
                        {
                            found=1;

                        }
                    else
                         fwrite(&sm1,sizeof(sr),1,ft2);
                }

        fclose(fp2);
        fclose(ft2);
        fclose(fp6);

        if(found)
            {
                ft2=fopen("temp2","r");
                fp2=fopen("DATA\\records\\staff member records","w");
                while(fread(&sm1,sizeof(sr),1,ft2))
                {
                    fwrite(&sm1,sizeof(sr),1,fp2);
                }
        fclose(fp2);
        fclose(ft2);

printf("\n\033[1;32m--------------------------------------------------------------------------------------------------");
        printf("\n\tDELETED SUCCESFULLY...");
printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;33m");
                   getch();

            }
       else{
             printf("\033[1;31m");
             printf("ID IS INCORRECT");
             printf("\033[1;33m");
             getch();

             }
        remove("temp2");
        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        fflush(stdin);
        scanf(" %c",&another);

               }

    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();

     }
	else
	{
		printf("\033[1;31m");
		printf("\nSorry!Invalid password\n");
		printf("\033[1;33m");
		printf("\n\n\tPRESS ANY KEY TO EXIT...");
        getch();
    }

}

void prisonaddrecord( )
{
/*********************************************************
This function is used to add prison records
*********************************************************/
    system("cls");
    prr p1;
    FILE *fp3 ;
    char another = 'Y',add_or_not='k';
    char id[10];
    int choice=0,k=0;

     if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a19.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    fp3 = fopen ("DATA\\records\\prison records", "ab+" ) ;

    if ( fp3 == NULL )
    {

        fp3=fopen("DATA\\records\\prison records","wb+");
        if(fp3==NULL)
        {

            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return ;

        }
    }

    while ( another == 'Y'|| another=='y' )

    {
        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mADD PRISON RECORDS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        //filter admins
  k=0;
   if (strcmp(user_type,"\033[1;34mUSER MODE")==0)
    {

	printf("\033[1;31m\n\t\t");
	for (k = 0; k < 70; k++){
	printf("%c",205);}
	printf("  \n\t\t%c                                                                    %c",186,186);

	printf("  \n\t\t%c  ONLY SUPER ADMIN OR ANOTHER ADMIN CAN ADD,EDIT OR DELETE RECORDS. %c",186,186);
	printf("  \n\t\t%c                                                                    %c",186,186);
	printf("  \n\t\t");
	for (k = 0; k < 70; k++){
    printf("%c",205);}

     printf("\033[1;33m");

     printf("\n\n\tPRESS ANY KEY TO EXIT...");

     getch();
     return 0;

    }
if (strcmp(user_type,"\033[1;34mUSER MODE")!=0)
   {
       while(add_or_not!='y'&&add_or_not!='Y'&&add_or_not!='n'&&add_or_not!='N')
       {
       printf ( "\033[1;33m");
       printf("\n\n\tDO YOU WANT TO ADD NEW PRISON?(Y/N)");
       fflush(stdin);
       printf ( "\033[1;37m");
       scanf("%c",&add_or_not);
       }
       if(add_or_not=='n'||add_or_not=='N')
       {
           return 0;
       }
        printf("\n\n\t\ ENTER NEW DETAILS");
        printf("\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
   }

        choice=0;

        printf ( "\033[1;33m");
		printf ( "\n\n\tENTER PRISON ID NUMBER : ");
		printf ( "\033[1;37m");
		fflush(stdin);
        scanf("%s",&id);
        rewind(fp3);

        while(!valid_prison_ID(id))
        {
            printf ( "\033[1;33m");
            printf ( "\n\tENTER PRISON ID NUMBER : ");
            printf ( "\033[1;37m");
            fflush(stdin);
            scanf("%s",&id);
            rewind(fp3);
        }

        while(fread(&p1,sizeof(prr),1,fp3)==1)
        {
            if(p1.id==valid_prison_ID(id))
            {
                printf ( "\033[1;31m");
                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                printf ( "\033[1;33m");
                choice=1;
            }
        }

        if(choice==0)
        {

            p1.id=valid_prison_ID(id);
            fflush(stdin);
printf("\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf ( "\033[1;33m");
            printf("\n\tENTER PRISON NAME : ");
            printf ( "\033[1;37m");
            fflush(stdin);
            gets(p1.name);
            while(!valid_name(p1.name))
        {
            printf ( "\033[1;33m");
            printf("\n\tENTER PRISON NAME: ");
            printf ( "\033[1;37m");
            fflush(stdin);
            gets(p1.name);
        }
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
			char capacity[10];
			printf ( "\033[1;33m");
			printf("\n\tENTER PRISON CAPACITY: ");
			printf ( "\033[1;37m");
			fflush(stdin);
            scanf("%s",&capacity);

            while(!valid_prison_capacity(capacity))
        {
            printf ( "\033[1;33m");
            printf("\n\tENTER PRISON CAPACITY: ");
            printf ( "\033[1;37m");
            fflush(stdin);
            scanf("%s",&capacity);

        }
         p1.capacity=valid_prison_capacity(capacity);
         fflush(stdin);
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            char cells[10];
            printf ( "\033[1;33m");
            printf("\n\tENTER NUMBER OF CELLS: ");
            printf ( "\033[1;37m");
            fflush(stdin);
            scanf("%s",&cells);

            while(!valid_number_of_cells(cells))
        {
            printf ( "\033[1;33m");
            printf("\n\tENTER NUMBER OF CELLS: ");
            printf ( "\033[1;37m");
            fflush(stdin);
            scanf("%s",&cells);

        }
     p1.cells= valid_number_of_cells(cells);
     fflush(stdin);
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
            printf ( "\033[1;33m");
            printf("\n\tCONTACT NUMBER OF THE PRISON: ");
            printf ( "\033[1;37m");
            fflush(stdin);
            gets(p1.prison_phone_number);

            while(!valid_mobile_number(p1.prison_phone_number))
        {
            printf ( "\033[1;33m");
            printf("\n\tCONTACT NUMBER:");
            printf ( "\033[1;37m");
            fflush(stdin);
            gets(p1.prison_phone_number);

        }

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");

            fwrite ( &p1, sizeof ( prr ), 1, fp3 ) ;
            printf("\033[1;32m");
            printf("\nYOUR RECORD IS ADDED...\n");
            printf("\033[1;33m");

        }

        printf ( "\n\tADD ANOTHER RECORD...(Y/N) \t" ) ;
        fflush ( stdin );
        another = getch( );

    }

    fclose ( fp3 ) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();

}



void prisonsearchrecord( )
{
/*********************************************************
This function is used to search prison records
*********************************************************/
	system("cls");
	prr p1;
	sr sm1;
	pr s1;
    FILE *fp,*fp2,*fp3,*fp4;
	char choice,name[50],string1[50],string2[50];
    int ch=0,found=0,id=0,staff_count=0,prisoners_count=0,search_results=0;

         if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a18.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    do
	{
system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mSEARCH PRISON RECORDS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");

        fp3 = fopen ( "DATA\\records\\prison records", "r" ) ;
        fp2 = fopen ( "DATA\\records\\staff member records", "r" ) ;
        fp  = fopen ( "DATA\\records\\prisoner records", "r" ) ;

        //system("cls");
        printf("\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\033[1;31m\n\t\t|\t\033[1;35mSearch by Prison ID\t\t[1]\t\t\t\033[1;31m|\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\033[1;31m\n\t\t|\t\033[1;35mSearch by Name\t\t\t[2]\t\t\t\033[1;31m|\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\033[1;31m\033[1;31m\n\t\t|\t\033[1;37mBack\t\t\t\t[3]\t\t\t\033[1;31m|\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\n\t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\033[1;33m\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        printf("\033[1;37m");
        scanf("%d",&ch);
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
        switch(ch)
        {
         case 1:

            printf("\033[1;33m");
    		printf("\n\n\tENTER PRISON ID : ");
    		printf("\033[1;37m");
            fflush(stdin);
            scanf("%d",&id);
            system("cls");

            while ( fread ( &p1, sizeof ( prr ), 1, fp3 ))
          {
          if(p1.id==id)
               {
                 found=1;

                 rewind(fp2);
                    while(fread(&sm1,sizeof(sr),1,fp2)==1)
                    {
                        if(p1.id==sm1.staff_member_prison_id)
                        {
                            staff_count++;
                        }
                    }
                     rewind(fp);
                    while(fread(&s1,sizeof(sr),1,fp)==1)
                    {
                        if(p1.id==s1.prisoner_prison_id)
                        {
                            prisoners_count++;

                        }
                    }

                printf("\n");
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\t\tRECORD OF THE PRISON ID: \033[1;37m%04d\033[1;33m",p1.id);
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISON NAME IS:\t\t\t\t\033[1;37m%s\033[1;33m",p1.name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISON CAPACITY:\t\t\t\033[1;32m%d/%d\033[1;33m",prisoners_count,p1.capacity);
                if(p1.capacity<prisoners_count)
                    {
                        printf("\n\t\033[1;31m*Capacity limit has reached in this prison.\033[1;33m");
                    }
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nNUMBER OF STAFF MEMBERS:\t\t\033[1;32m%d\033[1;33m",staff_count);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nNUMBER OF CELLS  :\t\t\t\033[1;37m%d\033[1;33m",p1.cells);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nCONTACT NUMBER OF THE PRISON IS:\t\033[1;37m%s\033[1;33m",p1.prison_phone_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n");
            }
            staff_count=0;
            prisoners_count=0;

          }
              if(!found){
                 printf("\033[1;31m");
                 printf("\nTHE RECORD DOES NOT EXIST.\n");
                 printf("\033[1;33m");
               }
                found=0;
                  break;

         case 2:
                        printf("\033[1;33m");
                        printf("\n\n\tENTER PRISON NAME : ");
                        printf("\033[1;37m");
                        fflush(stdin);
                        scanf("%s",&name);

                        for(int i = 0;i<50; i++)
            {
           string2[i] = tolower(name[i]);
            }


                  printf("\n\n\t\t HERE IS THE SEARCH RESULT");
          printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;32m");
                 printf("\n\t\tPrison ID\t\tPrison name");
          printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;37m");
            while ( fread ( &p1, sizeof ( prr ), 1, fp3 ))
          {

          for(int i = 0;i<50; i++)
            {
           string1[i] = tolower(p1.name[i]);
            }

          if(strstr(string1,string2)!=0)
               {


                 search_results++;
                 printf("\n\t\t %04d\t\t%s",p1.id,p1.name);
                printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;37m");
               }
            }
            printf("\n\tThere are %d search results",search_results);

            if(search_results>0){
            printf("\033[1;33m");
    		printf("\n\n\tSelect and enter prison ID from above search results: ");
    		printf("\033[1;37m");
            fflush(stdin);
            scanf("%d",&id);
            system("cls");
            }
              search_results=0;
               rewind(fp3);
        while ( fread ( &p1, sizeof ( prr ), 1, fp3 ))
          {
          if(p1.id==id)
               {
                 found=1;

                rewind(fp2);
                    while(fread(&sm1,sizeof(sr),1,fp2)==1)
                    {
                        if(p1.id==sm1.staff_member_prison_id)
                        {
                            staff_count++;
                        }
                    }

                rewind(fp);
                    while(fread(&s1,sizeof(sr),1,fp)==1)
                    {
                        if(p1.id==s1.prisoner_prison_id)
                        {
                            prisoners_count++;
                        }
                    }

         printf("\n");
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\t\tRECORD OF THE PRISON ID: \033[1;37m%04d\033[1;33m",p1.id);
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISON NAME IS:\t\t\t\t\033[1;37m%s\033[1;33m",p1.name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISON CAPACITY:\t\t\t\033[1;32m%d/%d\033[1;33m",prisoners_count,p1.capacity);
                if(p1.capacity<prisoners_count)
                    {
                        printf("\n\t\033[1;31m*Capacity limit has reached in this prison.\033[1;33m");
                    }
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nNUMBER OF STAFF MEMBERS:\t\t\033[1;32m%d\033[1;33m",staff_count);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nNUMBER OF CELLS  :\t\t\t\033[1;37m%d\033[1;33m",p1.cells);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nCONTACT NUMBER OF THE PRISON IS:\t\033[1;37m%s\033[1;33m",p1.prison_phone_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n");

            staff_count=0;
            prisoners_count=0;
               }
          }
            if(!found){
                 printf("\033[1;31m");
                 printf("\nTHE RECORD DOES NOT EXIST.\n");
                 printf("\033[1;33m");

               }

               found=0;
               break;
        case 3:
            prison_records_menu();
        default:
            printf("\033[1;31m");
            printf("\n\t\t*You have entered an invalid choice. Please choose between 1 to 3");
            printf("\033[1;33m");
        }


        printf("\n\nWOULD YOU LIKE TO CONTINUE SEARCHING...(Y/N):");
        fflush(stdin);

        scanf(" %c",&choice);
    }
    while(choice=='Y'||choice=='y');

    fclose(fp3) ;
	getch();
    return ;
}

void prisoneditrecord()
{
/*********************************************************
This function is used to search prison records
*********************************************************/
    system("cls");
    prr p1;
	sr sm1;
	pr s1;
    FILE *fp3,*fp2,*fp;
    char choice;
    char capacity[10],charid[10];
    int num,count=0,id,staff_count=0,prisoners_count=0;

    if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a20.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }


    do
    {
        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mEDIT PRISON RECORDS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");

        int k=0;
   if (strcmp(user_type,"\033[1;34mUSER MODE")==0)
    {

	printf("\033[1;31m\n\t\t");
	for (k = 0; k < 70; k++){
	printf("%c",205);}
	printf("  \n\t\t%c                                                                    %c",186,186);

	printf("  \n\t\t%c  ONLY SUPER ADMIN OR ANOTHER ADMIN CAN ADD,EDIT OR DELETE RECORDS. %c",186,186);
	printf("  \n\t\t%c                                                                    %c",186,186);
	printf("  \n\t\t");
	for (k = 0; k < 70; k++){
    printf("%c",205);}

     printf("\033[1;33m");

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();


     return 0;

    }



        fp3 = fopen ( "DATA\\records\\prison records", "rb+" );
        fp2 = fopen ( "DATA\\records\\staff member records", "r" );
        fp  = fopen ( "DATA\\records\\prisoner records", "r" );
        printf("\033[1;33m");
        printf("\n\tENTER PRISON ID:");
        printf("\033[1;37m");
    	scanf("%d",&id);


        while ( fread ( &p1, sizeof ( prr ), 1, fp3 ) == 1 )
        {

            if(p1.id==id)
            {

                rewind(fp2);
                    while(fread(&sm1,sizeof(sr),1,fp2)==1)
                    {
                        if(p1.id==sm1.staff_member_prison_id)
                        {
                            staff_count++;
                        }
                    }
                     rewind(fp);
                    while(fread(&s1,sizeof(sr),1,fp2)==1)
                    {
                        if(p1.id==s1.prisoner_prison_id)
                        {
                            prisoners_count++;


                        }
                    }

               printf("\n");
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\t\tRECORD OF THE PRISON ID: \033[1;37m%04d\033[1;33m",p1.id);
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISON NAME IS:\t\t\t\t\033[1;37m%s\033[1;33m",p1.name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISON CAPACITY:\t\t\t\033[1;32m%d/%d\033[1;33m",prisoners_count,p1.capacity);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nNUMBER OF STAFF MEMBERS:\t\t\033[1;32m%d\033[1;33m",staff_count);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nNUMBER OF CELLS  :\t\t\t\033[1;37m%d\033[1;33m",p1.cells);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nCONTACT NUMBER OF THE PRISON IS:\t\033[1;37m%s\033[1;33m",p1.prison_phone_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");


                printf("\n\033[1;31m1.\033[1;37mID.");
                printf("\n\033[1;31m2.\033[1;37mNAME.");
                printf("\n\033[1;31m3.\033[1;37mCAPACITY.");
                printf("\n\033[1;31m4.\033[1;37mNUMBER OF CELLS.");
                printf("\n\033[1;31m5.\033[1;37mCONTACT NUMBER.");
                printf("\n\033[1;31m6.\033[1;34mWHOLE RECORD.");
                printf("\n\033[1;31m7.\033[1;32mGO BACK TO PRISON RECORDS MENU.");

                do
                {
                    printf("\033[1;33m");
                    printf("\n\tENTER YOUR CHOICE:");
                    fflush(stdin);
                     printf("\033[1;37m");
                    scanf("%d",&num);
                    fflush(stdin);

                    switch(num)
                    {

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                    case 1:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tID:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        scanf("%s",&charid);

            while(!valid_prison_ID(charid))
        {
            printf("\033[1;33m");
            printf("\n\tID:");
            printf("\033[1;37m");
            fflush(stdin);
            scanf("%s",&charid);
        }
p1.id=valid_prison_ID(charid);
                        break;
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                    case 2:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tNAME:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(p1.name);
            while(!valid_name(p1.name))
        {
            printf("\033[1;33m");
            printf("\n\tNAME:");
            printf("\033[1;37m");
            fflush(stdin);
            gets(p1.name);
        }

                        break;
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                    case 3:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tCAPACITY:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        fflush(stdin);
                        scanf("%s",&capacity);

            while(!valid_prison_capacity(capacity))
        {
            printf("\033[1;33m");
            printf("\n\tCAPACITY:");
            printf("\033[1;37m");
            fflush(stdin);
            scanf("%s",&capacity);
        }


 p1.capacity= valid_prison_capacity(capacity);
                        break;
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                    case 4:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tNUMBER OF CELLS:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        scanf("%s",&p1.cells);
                        while(!valid_number_of_cells(p1.cells))
        {
            printf("\033[1;33m");
            printf("\n\tNUMBER OF CELLS:");
            printf("\033[1;37m");
            fflush(stdin);
            scanf("%s",&p1.cells);
        }

                        break;
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                    case 5:
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tCONTACT NUMBER:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(p1.prison_phone_number);
                        while(!valid_mobile_number(p1.prison_phone_number))
        {
            printf("\033[1;33m");
            printf("\n\tCONTACT NUMBER:");
            printf("\033[1;37m");
            fflush(stdin);
            gets(p1.prison_phone_number);
        }

                        break;

printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                    printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tID:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        scanf("%s",&charid);

            while(!valid_prison_ID(charid))
        {
            printf("\033[1;33m");
            printf("\n\tID:");
            printf("\033[1;37m");
            fflush(stdin);
            scanf("%s",&charid);
        }
p1.id=valid_prison_ID(charid);
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");

                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tNAME:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(p1.name);
            while(!valid_name(p1.name))
        {
            printf("\033[1;33m");
            printf("\n\tNAME:");
            printf("\033[1;37m");
            fflush(stdin);
            gets(p1.name);
        }
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tCAPACITY:");
                        fflush(stdin);
                        printf("\033[1;37m");
                        fflush(stdin);
                        scanf("%s",&capacity);

            while(!valid_prison_capacity(capacity))
        {
            printf("\033[1;33m");
            printf("\n\tCAPACITY:");
            printf("\033[1;37m");
            fflush(stdin);
            scanf("%s",&capacity);
        }
p1.capacity= valid_prison_capacity(capacity);
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                       printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tNUMBER OF CELLS:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        scanf("%s",&p1.cells);
                        while(!valid_number_of_cells(p1.cells))
        {
            printf("\033[1;33m");
            printf("\n\tNUMBER OF CELLS:");
            printf("\033[1;37m");
            fflush(stdin);
            scanf("%s",&p1.cells);
        }
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                       printf("\033[1;33m");
                        printf("\n\tENTER THE NEW DATA:");
                        printf("\n\tCONTACT NUMBER:");
                        printf("\033[1;37m");
                        fflush(stdin);
                        gets(p1.prison_phone_number);
                        while(!valid_mobile_number(p1.prison_phone_number))
        {
            printf("\033[1;33m");
            printf("\n\tCONTACT NUMBER:");
            printf("\033[1;37m");
            fflush(stdin);
            gets(p1.prison_phone_number);
        }
                        break;
printf("\n\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
                    case 7:
                        printf("\033[1;33m");
                        printf("\n\tPRESS ANY KEY TO GO BACK...\n");
                        getch();
                        return ;
                        break;

                    default:
                        printf("\033[1;31m");
                        printf("\n\tYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
                        printf("\033[1;33m");
                        break;

                    }

                }
                while(num<1||num>7);
                fseek(fp3,-sizeof(prr),SEEK_CUR);
                fwrite(&p1,sizeof(prr),1,fp3);
                fseek(fp3,-sizeof(prr),SEEK_CUR);
                fread(&p1,sizeof(prr),1,fp3);
                choice=='k';
                break;

            }
        }

        if(choice=='k')

        {

            system("cls");

            printf("\033[1;32m");
            printf("\n-----------------------------------------------");
            printf("\n\t\tEDITING HAS COMPLETED...");
            printf("\n-----------------------------------------------");
            printf("\033[1;33m");
            printf("\nTHE NEW RECORD IS:");
            rewind(fp2);
                    while(fread(&sm1,sizeof(sr),1,fp2)==1)
                    {
                        if(p1.id==sm1.staff_member_prison_id)
                        {
                            staff_count++;
                        }
                    }
                     rewind(fp);
                    while(fread(&s1,sizeof(sr),1,fp2)==1)
                    {
                        if(p1.id==s1.prisoner_prison_id)
                        {
                            prisoners_count++;

                        }
                    }

                printf("\n");
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\t\tRECORD OF THE PRISON ID: \033[1;37m%04d\033[1;33m",p1.id);
                printf("\n\t\033[1;31m*****************************************************\033[1;33m");
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISON NAME IS:\t\t\t\t\033[1;37m%s\033[1;33m",p1.name);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nPRISON CAPACITY:\t\t\t\033[1;32m%d/%d\033[1;33m",prisoners_count,p1.capacity);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nNUMBER OF STAFF MEMBERS:\t\t\033[1;32m%d\033[1;33m",staff_count);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nNUMBER OF CELLS  :\t\t\t\033[1;37m%d\033[1;33m",p1.cells);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\nCONTACT NUMBER OF THE PRISON IS:\t\033[1;37m%s\033[1;33m",p1.prison_phone_number);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");

            fclose(fp3);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);
            count++;

        }
        else
        {

            printf("\033[1;31m");
            printf("\nTHE RECORD DOES NOT EXIST::\n");
            printf("\033[1;33m");
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
            fflush(stdin);
        	scanf(" %c",&choice);

        }
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp3 ) ;
    printf("\033[1;33m");
    printf("\n\tPRESS ENTER TO EXIT EDITING MENU.");
    getch();

}

void prisonviewrecord()
{
/*********************************************************
This function is used to search prison records
*********************************************************/
    system("cls");
    prr p1;
    pr s1;
    FILE *fp3,*fp;

    system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mLIST OF PRISONS\033[1;31m\t\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");

        if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a22.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    fp3=fopen("DATA\\records\\prison records","rb");
    rewind(fp3);


  fp =fopen("DATA\\records\\prisoner records", "rb");



              int prisoner_count=0;



               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\t\t***AVAILABLE PRISON LIST OF THE SYSTEM***");
               printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
               printf("\n\tPRISON ID\tPRISON NAME\t\t\t\tNUMBER OF CELLS  ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3)==1)
                {

                   rewind(fp);
                    while(fread(&s1,sizeof(pr),1,fp)==1)
                    {
                        if(p1.id==s1.prisoner_prison_id)
                        {
                            prisoner_count++;
                        }
                    }
                 printf("\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
                 if(prisoner_count>=p1.capacity)
                    {
                     printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;31mCAPACITY : %d/%d\033[1;33m\t\t\t  %d\033[1;33m",p1.id,p1.name,prisoner_count,p1.capacity,p1.cells);
                    }
                printf("\033[1;33m\n\t%04d\t\t\033[1;37m%s\n\t\t\t\033[1;32mCAPACITY : %d/%d\033[1;33m\t\t\t  %d\033[1;33m",p1.id,p1.name,prisoner_count,p1.capacity,p1.cells);

                prisoner_count=0;

               }
                printf("\n\n\033[1;37m--------------------------------------------------------------------------------------------------\033[1;33m");
   printf("\n\n\tPRESS ANY KEY TO EXIT...");

    fclose(fp3);
	getch();

}

void prisondeleterecord( )
{
/*********************************************************
This function is used to delete prison records
*********************************************************/
    system("cls");
    prr p1;
    pr s1;
    sr sm1;
    ur u1;
    FILE *fp3,*ft3,*fp,*ft,*fp2,*ft2,*fp6,*fp7;
    struct prison_record file ;
    struct staff_member_record_file  ;
    struct prisoner_record_file ;
    char another = 'Y',input_pword[50],c;
    int choice,check,count_prisoners=0,count_staff_members=0,found_prisoner=0,found_staff_member=0,found_p = 0,found_s = 0;
    int j=0,found=0,id=0,i=0,match=0,k=0;

    if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a21.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mDELETE PRISON RECORDS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");

     k=0;
   if (strcmp(user_type,"\033[1;34mUSER MODE")==0)
    {

	printf("\033[1;31m\n\t\t");
	for (k = 0; k < 70; k++){
	printf("%c",205);}
	printf("  \n\t\t%c                                                                    %c",186,186);
    printf("  \n\t\t%c  ONLY SUPER ADMIN OR ANOTHER ADMIN CAN ADD,EDIT OR DELETE RECORDS. %c",186,186);
	printf("  \n\t\t%c                                                                    %c",186,186);
	printf("  \n\t\t");
	for (k = 0; k < 70; k++){
    printf("%c",205);}

     printf("\033[1;33m");

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

     getch();
     return 0;
    }

fp6 = fopen( "DATA\\records\\password" , "r");
while (fscanf(fp6, "%s", pword)!=EOF)
printf("\033[1;33m");
 printf("\n\n\tENTER PASSWORD : ");
 printf("\033[1;37m");
    i=0;
    while(i<50)
	{
	    input_pword[i]=getch();
	    c=input_pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	input_pword[i]='\0';
	//char code=pword;
	i=0;
	//Getting access for the super admin & other admins
match=0;

fp7 = fopen( "DATA\\records\\userslist" , "r");

	while(fread(&u1,sizeof(ur),1,fp7)){

		if(strcmp(pword,input_pword)==0||strcmp(input_pword,u1.pword)==0)
        {
           if(strcmpi(u1.admin_status,"yes")==0)
            {
               match=1;
            }
        }
	}

if(match)
{

printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;32m");
     printf("\n\t\t*ACCESS GRANTED*\n\n");
printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;33m");
printf("\n\tPress any key to contnue...");
getch();

   while ( another == 'Y' || another == 'y' )

    {
system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mDELETE PRISON RECORDS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");

        fp3 = fopen ("DATA\\records\\prison records", "r" ) ;
        if ( fp3 == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXIST");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getch();
                    return ;
				}
				ft3=fopen("DATA\\records\\temp","w");

				if(ft3==NULL)
                {
                	printf("\nSYSTEM ERROR");
                    printf("\nPRESS ANY KEY TO GO BACK");
                    getch();
                    return ;
                }
                printf("\033[1;33m");
                printf("\n\n\tENTER THE ID OF PRISON TO BE DELETED:");
                printf("\033[1;37m");
                fflush(stdin);
                scanf("%d",&id);

        		while(fread(&p1,sizeof(prr),1,fp3)==1)
                {

                    if(p1.id==id)
                        {
                            found=1;
                        }
                    else
                        fwrite(&p1,sizeof(prr),1,ft3);
                }

        fclose(fp3);
        fclose(ft3);
        fclose(fp6);

        if(found)
            {
                        fp=fopen("DATA\\records\\prisoner records","r");

                          while(fread(&s1,sizeof(pr),1,fp)==1)
                          {
                            if(s1.prisoner_prison_id==id)
                                {
                                count_prisoners++;
                                found_prisoner=1;
                                }
                          }

                      fclose(fp);

                              fp2=fopen("DATA\\records\\staff member records","r");

                            while(fread(&sm1,sizeof(sr),1,fp2)==1)
                          {
                            if(sm1.staff_member_prison_id==id)
                                {
                                count_staff_members++;
                                found_staff_member=1;
                                }
                          }
                      fclose(fp2);

                            if(found_prisoner){
                                    printf("\033[1;31m");
                                printf("\n\t*There is/are %d prisoner/prisoners under this prison ID.",count_prisoners);
                            printf("\033[1;33m");
                            }

                            if(found_staff_member){
                                    printf("\033[1;31m");
                                printf("\n\t*There is/are %d staff member/members under this prison ID.",count_staff_members);
                            printf("\033[1;33m");
                            }

                            if(found_prisoner==1||found_staff_member==1)
                            {
                            printf("\033[1;31m");
                            printf("\n\n\tWARNING!!!\n\t*Therefore, if you delete the record of this prison, all the prisoner records & staff member records under this prison will be also deleted from the system ");
                            printf("\033[1;33m");

                            }
                printf("\033[1;33m");
                printf("\n\tDO YOU WANT TO DELETE THE RECORD OF THIS PRISON?(Y/N) ");
                           fflush(stdin);
                            scanf(" %c",&choice);
                                        if(choice=='Y'||choice=='y')
                                                {
                                                            ft3=fopen("DATA\\records\\temp","r");
                                                            fp3=fopen("DATA\\records\\prison records","w");
                                                            while(fread(&p1,sizeof(prr),1,ft3))
                                                            {
                                                                fwrite(&p1,sizeof(prr),1,fp3);
                                                            }
                                                    fclose(fp3);
                                                    fclose(ft3);
                                                    remove("DATA\\records\\temp");
printf("\n\033[1;32m--------------------------------------------------------------------------------------------------");
                                                    printf("\n\t*PRISON RECORD HAS DELETED SUCCESFULLY...");
                                                                if(found_prisoner)
                                                                    {
                                                                                fp=fopen("DATA\\records\\prisoner records","r");
                                                                                ft=fopen("DATA\\records\\temp2","w");
                                                                      while(fread(&s1,sizeof(pr),1,fp)==1)
                                                                      {
                                                                        if(s1.prisoner_prison_id!=id)
                                                                            {

                                                                             fwrite(&s1,sizeof(pr),1,ft);
                                                                            }
                                                                      }

                                                                  fclose(fp);
                                                                  fclose(ft);

                                                                        ft=fopen("DATA\\records\\temp2","r");
                                                                        fp=fopen("DATA\\records\\prisoner records","w");
                                                                        while(fread(&s1,sizeof(pr),1,ft))
                                                                        {
                                                                            fwrite(&s1,sizeof(pr),1,fp);
                                                                        }
                                                                fclose(fp);
                                                                fclose(ft);
                                                                remove("DATA\\records\\temp2");

                                                                printf("\n\t*ALL THE PRISONER RECORDS UNDER THAT PRISON, HAVE DELETED SUCCESFULLY...");

                                                                    }
                                                                if(found_staff_member)
                                                                    {
                                                                        fp2=fopen("DATA\\records\\staff member records","r");
                                                                        ft2=fopen("DATA\\records\\temp3","w");
                                                                    while(fread(&sm1,sizeof(sr),1,fp2)==1)
                                                                  {
                                                                    if(sm1.staff_member_prison_id!=id)
                                                                        {
                                                                        fwrite(&sm1,sizeof(sr),1,ft2);
                                                                        }

                                                                  }
                                                              fclose(fp2);
                                                              fclose(ft2);

                                                                        ft2=fopen("DATA\\records\\temp3","r");
                                                                        fp2=fopen("DATA\\records\\staff member records","w");
                                                                        while(fread(&sm1,sizeof(sr),1,ft2))
                                                                        {
                                                                            fwrite(&sm1,sizeof(sr),1,fp2);
                                                                        }
                                                                fclose(fp2);
                                                                fclose(ft2);
                                                                remove("DATA\\records\\temp3");

                                                                printf("\n\t*ALL THE STAFF MEMBER RECORDS UNDER THAT PRISON, HAVE DELETED SUCCESFULLY...");

                                                         printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;33m");
                                                                    }

                                                }

                                  count_prisoners=0;
                                  found_prisoner=0;
                                  count_staff_members=0;
                                  found_staff_member=0;

                }
       else{
             printf("\033[1;31m");
             printf("ID IS INCORRECT");
             printf("\033[1;33m");
             getch();

             }

        printf("\033[1;33m");
        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        fflush(stdin);
        scanf("%c",&another);


               }

    printf("\033[1;33m");
    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();

     }
	else
	{
		printf("\033[1;31m");
		printf("\nSorry!Invalid password\n");
		printf("\033[1;33m");
    }
		getch();

}

void outdated_prisoner_records()
{
/*********************************************************
This function is used to find outdated prisoner records
*********************************************************/

   FILE *fp,*ft;
   pr s1;
char choice='Y';
do{
   int count=0,ch=0,i=0,found=0,number=0;
   char record[9000][20];
   char id[20]="";
   system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mOUTDATED PRISONER RECORDS\033[1;31m\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");

    printf("\n\n\033[1;36m\tHERE IS THE LIST OF OUTDATED PRISONER RECORDS\033[1;37m");
   fp=fopen("DATA\\records\\prisoner records","r");
      while(fread(&s1,sizeof(pr),1,fp))
      {
          if(old_date_finder(s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year))
          {

              printf("\n\n\t\033[1;37m(%d)\033[1;36m %s\033[1;37m",count+1,s1.id);
              strcpy(record[count],s1.id);
              count++;
          }
      }
    if(count)
      {
printf("\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
          printf("\n\n\033[1;33m\t\tDELETE ALL\t\t\033[1;37m[1]");
          printf("\n\n\033[1;33m\t\tDELETE SELECTED RECORD\t\033[1;37m[2]");
          printf("\n\n\033[1;33m\t\tBACK TO MAIN MENU\t\033[1;37m[3]");
printf("\n\033[1;31m--------------------------------------------------------------------------------------------------\033[1;33m");
           printf("\n\tENTER YOUR CHOICE :");
           scanf("%d",&ch);

        switch(ch)
        {

                       case 1:
                                     printf("\n\033[1;32m--------------------------------------------------------------------------------------------------");
                                     for(i=0;i<count;i++){

                                             fp = fopen ("DATA\\records\\prisoner records", "r" ) ;
                                        if ( fp == NULL )
                                                {
                                                    printf("\nTHE FILE DOES NOT EXIST");
                                                    printf("\nPRESS ANY KEY TO GO BACK.");
                                                    getch();
                                                    return ;
                                                }
                                                ft=fopen("DATA\\records\\temp","w");

                                                if(ft==NULL)
                                                {
                                                    printf("\nSYSTEM ERROR");
                                                    printf("\nPRESS ANY KEY TO GO BACK");
                                                    getch();
                                                    return ;
                                                }
                                               strcpy(id,record[i]);

                                                while(fread(&s1,sizeof(pr),1,fp)==1)
                                                {

                                                    if(strcmp(s1.id,id)==0)
                                                        {
                                                            found=1;
                                                        }
                                                    else

                                                     fwrite(&s1,sizeof(pr),1,ft);
                                                }

                                        fclose(fp);
                                        fclose(ft);


                                        if(found)
                                            {
                                                ft=fopen("DATA\\records\\temp","r");
                                                fp=fopen("DATA\\records\\prisoner records","w");
                                                while(fread(&s1,sizeof(pr),1,ft))
                                                {
                                                    fwrite(&s1,sizeof(pr),1,fp);
                                                }
                                        fclose(fp);
                                        fclose(ft);
                                         remove("DATA\\records\\temp");
                                         printf("\033[1;32m");



                                        printf("\n\t%s WAS DELETED SUCCESFULLY...",id);
                                printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;33m");


                                            }
                                     }

                                    break;

                    case 2:



                                             fp = fopen ("DATA\\records\\prisoner records", "r" ) ;
                                        if ( fp == NULL )
                                                {
                                                    printf("\nTHE FILE DOES NOT EXIST");
                                                    printf("\nPRESS ANY KEY TO GO BACK.");
                                                    getch();
                                                    return ;
                                                }
                                                ft=fopen("DATA\\records\\temp","w");

                                                if(ft==NULL)
                                                {
                                                    printf("\nSYSTEM ERROR");
                                                    printf("\nPRESS ANY KEY TO GO BACK");
                                                    getch();
                                                    return ;
                                                }
                                               printf("SELECT THE NUMBER OF THE PRISONER ID FROM ABOVE LIST:");
                                               fflush(stdin);
                                               scanf("%d",&number);
                                                 while(number>count||number<1)
                                                    {
                                                      printf("SELECT THE NUMBER OF THE PRISONER ID FROM ABOVE LIST:");
                                                      fflush(stdin);
                                                      scanf("%d",&number);
                                                    }

                                                    strcpy(id,record[number-1]);
                                                while(fread(&s1,sizeof(pr),1,fp)==1)
                                                {

                                                    if(strcmp(s1.id,id)==0)
                                                        {
                                                            found=1;
                                                        }
                                                    else

                                                     fwrite(&s1,sizeof(pr),1,ft);
                                                }

                                        fclose(fp);
                                        fclose(ft);


                                        if(found)
                                            {
                                                ft=fopen("DATA\\records\\temp","r");
                                                fp=fopen("DATA\\records\\prisoner records","w");
                                                while(fread(&s1,sizeof(pr),1,ft))
                                                {
                                                    fwrite(&s1,sizeof(pr),1,fp);
                                                }
                                        fclose(fp);
                                        fclose(ft);

                                         remove("DATA\\records\\temp");
                                         printf("\033[1;32m");


                                printf("\n\033[1;32m--------------------------------------------------------------------------------------------------");
                                        printf("\n\t%s WAS DELETED SUCCESFULLY...",id);
                                printf("\n\033[1;32m--------------------------------------------------------------------------------------------------\033[1;33m");


                                            }

                                    break;



        case 3:
            main_menu();
            break;

        default:
            printf("\n\tINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 3.");
            printf("\n\tDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);

        }

      }
      else
      {
        printf("\n\n\t\033[1;32m*THERE ARE NO OUTDATED PRISONER RECORDS\033[1;33m");
        printf("\n\tPRESS ANY KEY TO EXIT");
        getch();
        main_menu();
      }
}while(choice=='y'||choice=='Y');
}

int remaining_punishment_time(int end_date,int end_month,int end_year)
{
/*********************************************************
This function is used to find remaining punishment time of prisoners
*********************************************************/
  int day_diff, mon_diff, year_diff;
  /*systemtime audio_switch_t;*/
  time_t currentTime;
  time(&currentTime);
  struct tm*myTime = localtime(&currentTime);
  pr s1;
  FILE *fp;
  char ch;

   fp=fopen("DATA\\records\\prisoner records","r");
      while(fread(&s1,sizeof(pr),1,fp))


    if(!valid_date(myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year+1900))
    {
        printf("date is invalid.\n");

    }

    if(!valid_date(end_date,end_month,end_year))
    {
        printf("\nDate is invalid.Please enter valid date,month,year\n");
        return 0;
    }

    if(end_date < myTime->tm_mday)
    {
        // borrow days from february
        if (end_month == 3)
        {
            //  check whether year is a leap year
            if ((end_year % 4 == 0 && end_year % 100 != 0) || (end_year % 400 == 0))
            {
                end_date += 29;
            }

            else
            {
                end_date += 28;
            }
        }

        // borrow days from April or June or September or November
        else if (end_month == 5 || end_month == 7 || end_month == 10 || end_month == 12)
        {
           end_date += 30;
        }

        // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
        else
        {
           end_date += 31;
        }

        end_month = end_month - 1;
    }

    if (end_month < (myTime->tm_mon+1))
    {
        end_month = end_month+12;
        end_year = end_year-1;
    }

    day_diff = end_date - myTime->tm_mday;
    mon_diff = end_month - (myTime->tm_mon+1);
    year_diff = end_year - (myTime->tm_year+1900);

   /* if(year_diff<0||mon_diff<0||day_diff<0){

           printf("\n*Punishment end date is over.please enter a valid date");
            return 0;
            fclose(fp);
    }*/

printf("\033[1;32m");
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
printf("\nPRISONER'S REMAINING PUNISHMENT TIME:\t\t\033[1;32m %d years %02d months and %02d days.\033[1;33m",year_diff,mon_diff,day_diff);
printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
printf("\033[1;33m");
    return 1;
    fclose(fp);

}


int old_date_finder(int end_date,int end_month,int end_year)
{
/*********************************************************
This function is used to find old dates and discard them from the system
*********************************************************/

  int day_diff, mon_diff, year_diff;
  /*systemtime audio_switch_t;*/
  time_t currentTime;
  time(&currentTime);
  struct tm*myTime = localtime(&currentTime);
  pr s1;
  FILE *fp;
  char ch;

   fp=fopen("DATA\\records\\prisoner records","r");
      while(fread(&s1,sizeof(pr),1,fp))

    if(!valid_date(myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year+1900))
    {
        printf("date is invalid.\n");
    }

    if(!valid_date(end_date,end_month,end_year))
    {
        printf("\nDate is invalid.Please enter valid date,month,year\n");
        return 0;
    }

    if(end_date < myTime->tm_mday)
    {
        // borrow days from february
        if (end_month == 3)
        {
            //  check whether year is a leap year
            if ((end_year % 4 == 0 && end_year % 100 != 0) || (end_year % 400 == 0))
            {
                end_date += 29;
            }

            else
            {
                end_date += 28;
            }
        }

        // borrow days from April or June or September or November
        else if (end_month == 5 || end_month == 7 || end_month == 10 || end_month == 12)
        {
           end_date += 30;
        }

        // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
        else
        {
           end_date += 31;
        }

        end_month = end_month - 1;
    }

    if (end_month < (myTime->tm_mon+1))
    {
        end_month = end_month+12;
        end_year = end_year-1;
    }

    day_diff = end_date - myTime->tm_mday;
    mon_diff = end_month - (myTime->tm_mon+1);
    year_diff = end_year - (myTime->tm_year+1900);

    if(year_diff<0||mon_diff<0||day_diff<0){

           //printf("\n*Punishment end date is over.please enter a valid date");
           fclose(fp);
            return 1;

    }
    fclose(fp);
    return 0;
}


int age_calculator(int date,int month,int year)
{
/*********************************************************
This function is used to find age of persons from their given birthdays
*********************************************************/
  /*systemtime audio_switch_t;*/
  int year_diff,mon_diff,day_diff;
  time_t currentTime;
  time(&currentTime);
  struct tm*myTime = localtime(&currentTime);
  pr s1;
  FILE *fp;
  char ch;

   fp=fopen("DATA\\records\\prisoner records","r");
      while(fread(&s1,sizeof(pr),1,fp))


    if(!valid_date(date,month,year))
    {
        printf("First date is invalid.\n");
    }

    if(!valid_date(myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year+1900))
    {
        printf("Second date is invalid.\n");
        exit(0);
    }

    if(myTime->tm_mday < date)
    {
        // borrow days from february
        if (myTime->tm_mon+1 == 3)
        {
            //  check whether year is a leap year
            if ((myTime->tm_year+1900 % 4 == 0 && myTime->tm_year+1900 % 100 != 0) || (myTime->tm_year+1900 % 400 == 0))
            {
                myTime->tm_mday += 29;
            }

            else
            {
                myTime->tm_mday += 28;
            }
        }

        // borrow days from April or June or September or November
        else if (myTime->tm_mon+1 == 5 || myTime->tm_mon+1 == 7 || myTime->tm_mon+1 == 10 || myTime->tm_mon+1 == 12)
        {
           myTime->tm_mday += 30;
        }

        // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
        else
        {
           myTime->tm_mday += 31;
        }

        (myTime->tm_mon+1) == (myTime->tm_mon+1) - 1;
    }

    if (myTime->tm_mon+1 < month)
    {
        /*myTime->tm_mon+1 += 12;*/

        myTime->tm_mon+1 == myTime->tm_mon+1 + 12;
        myTime->tm_year+1900 ==  myTime->tm_year+1900 - 1;
    }

    day_diff = myTime->tm_mday - date;
    mon_diff = myTime->tm_mon+1 - month;
    year_diff = myTime->tm_year+1900 - year;

    /*printf("\nPRISONER AGE IS: %d years %02d months and %02d days.",year_diff,mon_diff,day_diff);*/
    /*strcpy(s1.age,year_diff);
    fflush(stdin);*/
    fclose(fp);
    return year_diff;

}


float BMI_calculator(int height,int weight)
{
/**************************************************************************************
This function is used to find the BMI of prisoners from their given heights and weights
***************************************************************************************/
     float height_in_meter;
     float height_squared;
     float BMI= 0.00;
     char BMI_category[30];

  height_in_meter = height/100.00;
  height_squared = height_in_meter*height_in_meter;

          BMI= weight/height_squared;

    return BMI;

}

void BMI_category(char *BMI_category,int height,int weight)

{
/**************************************************************************************
This function is used to find the BMI category of prisoners from their given heights and weights
***************************************************************************************/
     float height_in_meter;
     float height_squared;
     float BMI= 0.00;

  height_in_meter = height/100.00;
  height_squared = height_in_meter*height_in_meter;

          BMI= weight/height_squared;


    if(BMI < 18.5)
    {
      strcpy(BMI_category,"\033[1;37mUNDERWEIGHT");
    }
    if(BMI >= 18.5 && BMI < 25.0 )
    {
      strcpy(BMI_category,"\033[1;32mNORMAL");
    }
    if(BMI >= 25.0 && BMI < 30.0)
    {
      strcpy(BMI_category,"\033[1;34mOVERWEIGHT");
    }
    if(BMI >= 30.0)
    {
      strcpy(BMI_category,"\033[1;31mOBESITY");
    }

}


int valid_name(char *s)
{
/*************************************************************************************************************************
This function is used to validate names as a user inputs and it will discard digits and punctuaion characters inside names
**************************************************************************************************************************/

  int i=0, error1=0,error2=0,error3=0,no_of_punctuaion_characters=0,no_of_digits=0;

 printf("\033[1;31m");

  if(!s)
          {
           error2=1;
           }

    while(s[i]){
        if(isdigit(s[i])){

                 error1=1;
                 no_of_digits++;

              }
        if(ispunct(s[i])){
            if(s[i]!='.')
            {
            error3=1;
            no_of_punctuaion_characters++;

        }}

      i++;
    }

        if(error1==1){
                printf("\n*You have entered %d digit/digits inside the name. Digits can't be included inside a name.",no_of_digits);

               }
         if(error2==1)
               {
                printf("\n*You haven't entered a name");
               }

        if(error3==1){
                printf("\n*You have entered %d invalid punctuation character/characters inside the name. Invalid punctuation characters can't be included inside a name.",no_of_punctuaion_characters);
               }

          if(error1==1||error2==1||error3==1)
          {
             printf("\n*Name is invalid.please enter a valid name\n\n");
             printf("\033[1;33m");
             return 0;
          }

  printf("\033[1;33m");
  return 1;
}


int valid_colour(char *s)
{
/***************************************************************************************************************************************
This function is used to validate colour names as a user inputs and it will discard digits and punctuaion characters inside colour names
****************************************************************************************************************************************/

  int i=0, error1=0,error2=0,error3=0,no_of_punctuaion_characters=0,no_of_digits=0;

 printf("\033[1;31m");

  if(!s)
          {
           error2=1;
           }

    while(s[i]){
        if(isdigit(s[i])){

                 error1=1;
                 no_of_digits++;

              }
        if(ispunct(s[i])){
            if(s[i]!='.')
            {
            error3=1;
            no_of_punctuaion_characters++;

        }}
      i++;
    }

        if(error1==1){
                printf("\n*You have entered %d digit/digits inside the colour name. Digits can't be included inside a colour name.",no_of_digits);

               }
         if(error2==1)
               {
                printf("\n*You haven't entered a colour");
               }

        if(error3==1){
                printf("\n*You have entered %d invalid punctuation character/characters inside the colour name. Invalid punctuation characters can't be included inside a colour name.",no_of_punctuaion_characters);

               }

          if(error1==1||error2==1||error3==1)
          {

             printf("\n*Colour is invalid.please enter a valid colour\n\n");
             printf("\033[1;33m");
             return 0;
          }

  printf("\033[1;33m");
  return 1;
}


int valid_height(char *s)
{
/***************************************************************************************************************************************
This function is used to validate prisoner heights entered by the user
****************************************************************************************************************************************/
int i=0, error1=0,error2=0,error3=0,error4=0,error5=0,error6=0,no_of_punctuaion_characters=0,no_of_non_digits=0,no_of_spaces=0;
int height=0, valid_height=0;

 printf("\033[1;31m");

   if(!s){
            error2=1;
         }

    while(s[i]){

        if(isdigit(s[i])==0){

                 error1=1;
                 no_of_non_digits++;

              }
        if(ispunct(s[i])){


            error3=1;
            no_of_punctuaion_characters++;

        }
        if(s[i]==' ')
             {
              error6=1;
              no_of_spaces++;
            }

      i++;
    }

    height= atoi(s);


if(error1==0&&error3==0&&error6==0)

{
    if (height < 50 )
            {
             error4=1;
            }


    if(height > 300)
            {
                error5=1;
            }
}

        if(error1==1){
                printf("\n*You have entered %d non-digit character/characters inside height.Non-digit characters can't be included inside the value of height.",no_of_non_digits);

               }
         if(error2==1)
               {
                printf("\n*You haven't entered a height");
               }

        if(error3==1){
                printf("\n*You have entered %d invalid punctuation character/characters inside height. Invalid punctuation characters can't be included inside the value of height.",no_of_punctuaion_characters);

               }
        if(error4==1){
                printf("\n*Value of the height is too low. Please enter a valid value");
                 }

         if(error5==1){
                printf("\n*Value of the height is too high. Please enter a valid value");
                 }
          if(error6==1){
                printf("\n*You have entered %d space/spaces inside height. spaces can't be included inside the value of height.",no_of_spaces);
               }
          if(error1==1||error2==1||error3==1||error4==1||error5==1||error6==1)
          {

             printf("\n*Height is invalid.please enter a valid height\n\n");
             printf("\033[1;33m");
             return 0;
          }

  valid_height=height;

  printf("\033[1;33m");
  return valid_height;

}

int valid_weight(char *s)
{
/***************************************************************************************************************************************
This function is used to validate prisoner weights entered by the user
****************************************************************************************************************************************/
int i=0, error1=0,error2=0,error3=0,error4=0,error5=0,error6=0,no_of_punctuaion_characters=0,no_of_non_digits=0,no_of_spaces=0;
int weight=0, valid_weight=0;

 printf("\033[1;31m");

   if(!s){
            error2=1;
   }

    while(s[i]){

        if(isdigit(s[i])==0){

                 error1=1;
                 no_of_non_digits++;

              }
        if(ispunct(s[i])){

            error3=1;
            no_of_punctuaion_characters++;

        }
        if(s[i]==' ')
             {
              error6=1;
              no_of_spaces++;
            }

      i++;
    }

    weight= atoi(s);


if(error1==0&&error3==0&&error6==0)

{
    if (weight < 10 )
            {
             error4=1;
            }


    if(weight > 1000)
            {
                error5=1;
            }
}

        if(error1==1){
                printf("\n*You have entered %d non-digit character/characters inside weight.Non-digit characters can't be included inside the value of weight.",no_of_non_digits);

               }
         if(error2==1)
               {
                printf("\n*You haven't entered a weight");
               }

        if(error3==1){
                printf("\n*You have entered %d invalid punctuation character/characters inside weight. Invalid punctuation characters can't be included inside the value of weight.",no_of_punctuaion_characters);

               }
        if(error4==1){
                printf("\n*Value of the weight is too low. Please enter a valid value");
                 }

         if(error5==1){
                printf("\n*Value of the weight is too high. Please enter a valid value");
                 }
          if(error6==1){
                printf("\n*You have entered %d space/spaces inside weight. spaces can't be included inside the value of weight.",no_of_spaces);

               }
          if(error1==1||error2==1||error3==1||error4==1||error5==1||error6==1)
          {

             printf("\n*Weight is invalid.please enter a valid weight\n\n");
             printf("\033[1;33m");
             return 0;
          }

  valid_weight=weight;

  printf("\033[1;33m");
  return valid_weight;

}

int valid_mobile_number(char *s)
{
/***************************************************************************************************************************************
This function is used to validate mobile numbers entered by the user
****************************************************************************************************************************************/
     int len;
    len=strlen(s);
    int error1=0,error2=0,error3=0,error4=0;
    int i=0,no_of_punctuaion_characters=0,no_of_non_digits=0,no_of_spaces=0;

printf("\033[1;31m");

   if(!s)
          {
            error2=1;
            printf("\n*You haven't entered the the contact number");
           }
     if(len != 10)
           {
            error2=1;
           }

    while(s[i]){

            if(ispunct(s[i]))
         {
             no_of_punctuaion_characters++;
             error1=1;
          }

            if(!isdigit(s[i]))
          {
            no_of_non_digits++;
            error3=1;
         }

         if(s[i]==' ')
             {
              error4=1;
              no_of_spaces++;
            }

        i++;
    }

        if(error1==1){
                printf("\n*This contact number has %d Punctuation characters.Punctuation characters can't be included in the contact number",no_of_punctuaion_characters);

               }
        if(error2==1){

                     printf("\n*Contact number length should be 10");

                      }

        if(error3==1)
            {
                printf("\n*You have entered %d non-digit character/characters.non-digit characters can't be included in the contact number",no_of_non_digits);
            }
        if(error4==1){
                printf("\n*You have entered %d space/spaces. spaces can't be included inside the contact number.",no_of_spaces);

               }
        if(error1==1||error2==1||error3==1||error4==1){

                printf("\n*Contact number is invalid.please enter a valid contact number\n\n");
                printf("\033[1;33m");
                return 0;
              }

printf("\033[1;33m");

 return 1;

}

int valid_prison_ID(char *s)
{
/***************************************************************************************************************************************
This function is used to validate prison IDs entered by the user
****************************************************************************************************************************************/
    int len;
    len=strlen(s);
    int error1=0,error2=0,error3=0,error4=0,valid_prison_ID;
    int i=0,no_of_punctuaion_characters=0,no_of_non_digits=0,no_of_spaces=0;

printf("\033[1;31m");

   if(!s)
          {
            error2=1;
            printf("\n*You haven't entered the prison ID");
           }
     if(len > 4)
           {
            error2=1;
           }

    while(s[i]){

            if(ispunct(s[i]))
         {
             no_of_punctuaion_characters++;
             error1=1;
          }

            if(!isdigit(s[i]))
          {
            no_of_non_digits++;
            error3=1;

         }

         if(s[i]==' ')
             {
              error4=1;
              no_of_spaces++;
            }

        i++;
    }

        if(error1==1){
                printf("\n*This prison id number has %d Punctuation characters.Punctuation characters can't be included in the prison id",no_of_punctuaion_characters);

               }
        if(error2==1){

                     printf("\n*Maximum length of prison ID should be 4");

                      }

        if(error3==1)
            {
                printf("\n*You have entered %d non-digit character/characters.non-digit characters can't be included in the prison ID",no_of_non_digits);
            }
        if(error4==1){
                printf("\n*You have entered %d space/spaces. spaces can't be included inside the prison ID.",no_of_spaces);

               }
        if(error1==1||error2==1||error3==1||error4==1){

                printf("\n*Prison ID is invalid.please enter a valid prison ID\n\n");
                printf("\033[1;33m");
                return 0;
              }
valid_prison_ID=atoi(s);
printf("\033[1;33m");
return valid_prison_ID;

}

int valid_user_ID(char *s)
{
/***************************************************************************************************************************************
This function is used to validate user IDs entered by the user
****************************************************************************************************************************************/
    int len;
    len=strlen(s);
    int error1=0,error2=0,error3=0,error4=0,valid_user_ID;
    int i=0,no_of_punctuaion_characters=0,no_of_non_digits=0,no_of_spaces=0;

printf("\033[1;31m");

   if(!s)
          {
            error2=1;
            printf("\n*You haven't entered the user ID");
           }
     if(len > 4)
           {
            error2=1;
           }

    while(s[i]){
            if(ispunct(s[i]))
         {
             no_of_punctuaion_characters++;
             error1=1;
          }

            if(!isdigit(s[i]))
          {
            no_of_non_digits++;
            error3=1;

         }

         if(s[i]==' ')
             {
              error4=1;
              no_of_spaces++;
            }

        i++;
    }

        if(error1==1){
                printf("\n*This user id number has %d Punctuation characters.Punctuation characters can't be included in the user id",no_of_punctuaion_characters);

               }
        if(error2==1){
                     printf("\n*Maximum length of user ID should be 4");
                      }
        if(error3==1)
            {
                printf("\n*You have entered %d non-digit character/characters.non-digit characters can't be included in the user ID",no_of_non_digits);
            }
        if(error4==1){
                printf("\n*You have entered %d space/spaces. spaces can't be included inside the user ID.",no_of_spaces);

               }
        if(error1==1||error2==1||error3==1||error4==1){

                printf("\n*User ID is invalid.please enter a valid user ID\n\n");
                printf("\033[1;33m");
                return 0;
              }
valid_user_ID=atoi(s);
printf("\033[1;33m");
return valid_user_ID;

}

int valid_prison_ID_selecter(int s)
{
/***************************************************************************************************************************************
This function is used to select prison IDs which are already exist in the system
****************************************************************************************************************************************/
prr p1;
FILE *fp3;
int found=0;
fp3 = fopen ("DATA\\records\\prison records", "rb" );

while(fread(&p1,sizeof(prr),1,fp3))
    {
    if(s==p1.id)
      {
       found=1;
       printf("\033[1;32m");
       printf("\n\t\t*Selected prison ID: %04d",p1.id);
       printf("\n\t\t*Selected prison Name: %s",p1.name);
       printf("\033[1;33m");
       return 1;
      }
    }
if(!found){
    printf("\033[1;31m");
    printf("\n\t*Wrong prison ID. Please select a correct prison ID from the above prison list");
    printf("\033[1;33m");
    return 0;
}

}

void valid_prison_name_finder(int s)
{
/*********************************************************************************
This function is used to find prison name from a given prison ID
**********************************************************************************/
prr p1;
FILE *fp3;
int found=0;
    fp3 = fopen ("DATA\\records\\prison records", "rb" ) ;

    while(fread(&p1,sizeof(prr),1,fp3)){

    if(s==p1.id)
      {
       found=1;
       printf("\n\033[1;33mPRISON NAME:\t\t\t\t\t\033[1;36m %s\033[1;33m",p1.name);
       return 1;
      }
    }
if(!found){
    printf("\033[1;31m");
    printf("\n\t*Wrong prison ID. There is no prison with this prison ID");
    printf("\033[1;33m");
    return 0;
}

}

int valid_cell_number(char *s)
{
/*************************************************************
This function is used to validate cell numbers of the prison
**************************************************************/
int len;
    len=strlen(s);
    int error1=0,error2=0,error3=0,error4=0;
    int i=0,no_of_punctuaion_characters=0,no_of_non_digits=0,no_of_spaces=0,valid_cell_number;

printf("\033[1;31m");

   if(!s)
          {
            error2=1;
            printf("\n*You haven't entered the cell number");
           }
     if(len > 4)
           {
            error2=1;
           }

    while(s[i]){

            if(ispunct(s[i]))
          {
             no_of_punctuaion_characters++;
             error1=1;
          }

            if(!isdigit(s[i]))
          {
            no_of_non_digits++;
            error3=1;
          }

         if(s[i]==' ')
             {
              error4=1;
              no_of_spaces++;
            }

        i++;
    }

        if(error1==1){
                printf("\n*This cell number has %d Punctuation characters.Punctuation characters can't be included in the cell number",no_of_punctuaion_characters);
                     }
        if(error2==1){
                     printf("\n*Maximum length of the cell number should be 4");
                     }

        if(error3==1)
            {
                printf("\n*You have entered %d non-digit character/characters.non-digit characters can't be included in the cell number",no_of_non_digits);
            }
        if(error4==1){
                printf("\n*You have entered %d space/spaces. spaces can't be included inside the cell number.",no_of_spaces);

               }
        if(error1==1||error2==1||error3==1||error4==1){

                printf("\n*Cell number is invalid.please enter a valid cell number\n\n");
                printf("\033[1;33m");
                return 0;
              }
valid_cell_number=atoi(s);


printf("\033[1;33m");

return valid_cell_number;

}

int valid_cell_number_selecter(int prison_id,char *s)
{
/*************************************************************
This function is used to validate cell numbers of the prisons
**************************************************************/
    prr p1;
    FILE *fp3;
    int len;
    len=strlen(s);
    int error1=0,error2=0,error3=0,error4=0;
    int i=0,no_of_punctuaion_characters=0,no_of_non_digits=0,no_of_spaces=0,valid_cell_number;

printf("\033[1;31m");

   if(!s)
          {
            error2=1;
            printf("\n*You haven't entered the cell number");
           }
     if(len > 4)
           {
            error2=1;
           }

    while(s[i]){

            if(ispunct(s[i]))
         {
             no_of_punctuaion_characters++;
             error1=1;
          }

            if(!isdigit(s[i]))
          {
            no_of_non_digits++;
            error3=1;
          }

         if(s[i]==' ')
             {
              error4=1;
              no_of_spaces++;
             }
        i++;
    }

        if(error1==1){
                printf("\n*This cell number has %d Punctuation characters.Punctuation characters can't be included in the cell number",no_of_punctuaion_characters);

               }
        if(error2==1){
                     printf("\n*Maximum length of the cell number should be 4");
                     }

        if(error3==1)
            {
                printf("\n*You have entered %d non-digit character/characters.non-digit characters can't be included in the cell number",no_of_non_digits);
            }
        if(error4==1){
                printf("\n*You have entered %d space/spaces. spaces can't be included inside the cell number.",no_of_spaces);

               }
        if(error1==1||error2==1||error3==1||error4==1){

                printf("\n*Cell number is invalid.please enter a valid cell number\n\n");
                printf("\033[1;33m");
                return 0;
              }
valid_cell_number=atoi(s);

printf("\033[1;33m");

       fp3=fopen("DATA\\records\\prison records","r");
        while(fread(&p1,sizeof(prr),1,fp3))
        {
          if(prison_id==p1.id)
            {
              //printf("\n\tTHIS PRISON HAS %d CELLS.THEREFORE PLEASE ENTER A CELL NUMBER WITHIN 1 TO %d",p1.cells,p1.cells);
               if(valid_cell_number>p1.cells||valid_cell_number<1){
               printf("\033[1;31m");
               printf("\n\t*THIS PRISON HAS %d CELLS.THEREFORE PLEASE ENTER A CELL NUMBER WITHIN 1 TO %d",p1.cells,p1.cells);

               printf("\033[1;33m");
               return 0;
               }
             }
        }
  return valid_cell_number;
  fclose(fp3);

}


int valid_prison_capacity(char *s)
{
/***********************************************************************************
This function is used to validate prison capacities which are entered as user inputs
************************************************************************************/
int i=0, error1=0,error2=0,error3=0,error4=0,error5=0,error6=0,no_of_punctuaion_characters=0,no_of_non_digits=0,no_of_spaces=0;
int capacity=0, valid_capacity=0;

 printf("\033[1;31m");

   if(!s){
            error2=1;
   }

    while(s[i]){
        if(isdigit(s[i])==0){

                 error1=1;
                 no_of_non_digits++;

              }
        if(ispunct(s[i])){

            error3=1;
            no_of_punctuaion_characters++;

        }
        if(s[i]==' ')
             {
              error6=1;
              no_of_spaces++;
            }
      i++;
    }

    capacity= atoi(s);
if(error1==0&&error3==0&&error6==0)

{
    if (capacity < 100 )
            {
             error4=1;
            }

    if(capacity > 10000)
            {
                error5=1;
            }

}

        if(error1==1){
                printf("\n*You have entered %d non-digit character/characters inside capacity.Non-digit characters can't be included inside the value of capacity.",no_of_non_digits);

               }
         if(error2==1)
               {
                printf("\n*You haven't entered a capacity");
               }

        if(error3==1){
                printf("\n*You have entered %d invalid punctuation character/characters inside capacity. Invalid punctuation characters can't be included inside the value of capacity.",no_of_punctuaion_characters);

               }
        if(error4==1){
                printf("\n*Value of the capacity is too low to consider as a prison capacity. Please enter a valid capacity");
                 }

         if(error5==1){
                printf("\n*Value of the capacity is too high to consider as a prison capacity. Please enter a valid capacity");
                 }
          if(error6==1){
                printf("\n*You have entered %d space/spaces inside capacity. spaces can't be included inside the value of the capacity.",no_of_spaces);

               }

          if(error1==1||error2==1||error3==1||error4==1||error5==1||error6==1)
          {

             printf("\n*Capacity is invalid.please enter a valid capacity\n\n");
             printf("\033[1;33m");
             return 0;
          }

  valid_capacity=capacity;

  printf("\033[1;33m");
  return valid_capacity;

}




int valid_number_of_cells(char *s)
{
/***********************************************************************************
This function is used to validate number of cells of prisons
************************************************************************************/
int i=0, error1=0,error2=0,error3=0,error4=0,error5=0,error6=0,no_of_punctuaion_characters=0,no_of_non_digits=0,no_of_spaces=0;
int number_of_cells=0, valid_number_of_cells=0;

 printf("\033[1;31m");

   if(!s){
            error2=1;
   }

    while(s[i]){

        if(isdigit(s[i])==0){

                 error1=1;
                 no_of_non_digits++;

              }
        if(ispunct(s[i])){

            error3=1;
            no_of_punctuaion_characters++;

        }
        if(s[i]==' ')
             {
              error6=1;
              no_of_spaces++;
            }
      i++;
    }

    number_of_cells= atoi(s);


if(error1==0&&error3==0&&error6==0)
{
    if (number_of_cells < 100 )
            {
             error4=1;
            }


    if(number_of_cells > 10000)
            {
                error5=1;
            }
}

        if(error1==1){
                printf("\n*You have entered %d non-digit character/characters inside the number of cells.Non-digit characters can't be included inside the number of cells.",no_of_non_digits);

               }
         if(error2==1)
               {
                printf("\n*You haven't entered a number of cells");
               }

        if(error3==1){
                printf("\n*You have entered %d invalid punctuation character/characters inside the number of cells. Invalid punctuation characters can't be included inside the number of cells.",no_of_punctuaion_characters);

               }
        if(error4==1){
                printf("\n*The number of cells is too low to consider as a prison. Please enter a valid number of cells");
                 }

         if(error5==1){
                printf("\n*The number of cells is too high to consider as a prison. Please enter a valid number of cells");
                 }
          if(error6==1){
                printf("\n*You have entered %d space/spaces inside the number of cells. spaces can't be included inside the number of cells.",no_of_spaces);

               }

          if(error1==1||error2==1||error3==1||error4==1||error5==1||error6==1)
          {
             printf("\n*Number of cells is invalid.please enter a valid number of cells\n\n");
             printf("\033[1;33m");
             return 0;
          }

  valid_number_of_cells=number_of_cells;

  printf("\033[1;33m");
  return valid_number_of_cells;

}


int valid_national_id(char *s)
{
/***********************************************************************************
This function is used to validate national IDs of prisoners
************************************************************************************/
    int len;
    len=strlen(s);
    int error1=0,error2=0,error3=0,error4=0;
    int i=0,no_of_punctuaion_characters=0,lowercase=0,no_of_spaces=0;

printf("\033[1;31m");

   if(!s)
          {
            error2=1;
            printf("\n*You haven't entered the national ID");
           }
     if(len != 12)
           {
            error2=1;
           }

    while(s[i]){

            if(ispunct(s[i]))
         {
             no_of_punctuaion_characters++;
             error1=1;
          }

            if(islower(s[i]))
          {
            lowercase++;
            error3=1;

         }

         if(s[i]==' ')
             {
              error4=1;
              no_of_spaces++;
            }
        i++;
    }

        if(error1==1){
                printf("\n*Your ID has %d Punctuation characters.Punctuation characters can't be included in the ID",no_of_punctuaion_characters);

               }
        if(error2==1){

                     printf("\n*ID length should be 12");

                      }

        if(error3==1)
            {
                printf("\n*You have entered %d lowercase characters. Lowercase characters can't be included in the ID",lowercase);
            }
        if(error4==1){
                printf("\n*You have entered %d space/spaces. spaces can't be included inside the national ID number.",no_of_spaces);

               }
        if(error1==1||error2==1||error3==1||error4==1){

                printf("\n*ID is invalid.please enter a valid ID\n\n");
                printf("\033[1;33m");
                return 0;
              }

printf("\033[1;33m");

 return 1;

}

int valid_prisoner_id_or_staff_member_id(char *s)
{
/***************************************************************************************************************
This function is used to validate Prisoner IDs and staff member IDs.These two ID numbers are unique for this system
****************************************************************************************************************/
    int len;
    len=strlen(s);
    int error1=0,error2=0,error4=0,error3=0;
    int i=0,no_of_punctuation_characters=0,lowercase=0,no_of_spaces=0;
    FILE *fp,*fp2;
    pr s1;
    sr sm1;

printf("\033[1;31m");

   fp=fopen("DATA\\records\\prisoner records","r");
   while(fread( &s1,sizeof(pr),1,fp)==1)
        {

            if(strcmp(s1.id,s)==0)
            {
                printf ( "\033[1;31m");
                printf("\n\t*THIS ID ALREADY EXISTS AS A PRISONER ID.PLEASE ENTER A DIFFERENT ID\n");
                printf ( "\033[1;33m");
                return 0;
            }
        }

    fp2=fopen("DATA\\records\\staff member records","r");
   while(fread( &sm1,sizeof(sr),1,fp2)==1)
        {
            if(strcmp(sm1.id,s)==0)
            {
                printf ( "\033[1;31m");
                printf("\n\t*THIS ID ALREADY EXISTS AS A STAFF MEMBER ID.PLEASE ENTER A DIFFERENT ID\n");
                printf ( "\033[1;33m");
                return 0;
            }
        }
   if(!s)
          {
            error2=1;
            printf("\n*You haven't entered the ID");
           }

   if(len != 9)
           {
            error2=1;
           }

    while(s[i]){

            if(ispunct(s[i]))
         {

             no_of_punctuation_characters++;
             error1=1;
          }

            if(islower(s[i]))
          {
            lowercase++;
            error3=1;
         }

         if(s[i]==' ')
             {
              error4=1;
              no_of_spaces++;
            }
      i++;
    }

        if(error1==1){
                printf("\n*Your ID has %d Punctuation characters.Punctuation characters can't be included in the ID",no_of_punctuation_characters);

               }
        if(error2==1){
                       printf("\n*ID length should be 9");
              }

        if(error3==1)
            {
                printf("\n*You have entered %d lowercase characters. Lowercase characters can't be included in the ID",lowercase);
            }

        if(error4==1){
                printf("\n*You have entered %d space/spaces. spaces can't be included in the ID.",no_of_spaces);

               }
        if(error1==1||error2==1||error3==1||error4==1){

                 printf("\n*ID is invalid.please enter a valid id\n\n");
                 printf("\033[1;33m");
                return 0;
              }
printf("\033[1;33m");
 return 1;
}


int valid_gender(char*s)
{
/*********************************************************************************************************************************
This function is used to validate the gender of a person.This function helps to discard all invalid inputs except a correct gender
**********************************************************************************************************************************/
printf("\033[1;31m");
   if(strcmpi(s,"male")==0||strcmpi(s,"female")==0)
   {
       printf("\033[1;33m");
       return 1;
   }
    else{
        printf("\n*Gender is invalid.Please enter \"male\" or \"female\"");
        printf("\033[1;33m");
        return 0;
    }
}


int valid_condition(char*s)
{
/*********************************************************************************************************************************
This function is used to validate the gender of a person.This function helps to discard all invalid inputs except a correct gender
**********************************************************************************************************************************/
printf("\033[1;31m");
   if(strcmpi(s,"good")==0||strcmpi(s,"bad")==0)
   {
       printf("\033[1;33m");
       return 1;
   }
    else{
        printf("\nPlease enter \"good\" or \"bad\"");
        printf("\033[1;33m");
        return 0;
    }
}

// function to check whether a date is valid or not

int valid_date(int day, int mon, int year)
{
/***********************************************************
This function is used to get a valid date as a user input
************************************************************/
    int is_valid = 1, is_leap = 0;

    if (year >= 1800 && year <= 9999)
    {
        //  check whether year is a leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            is_leap = 1;
        }

        // check whether mon is between 1 and 12
        if(mon >= 1 && mon <= 12)
        {
            // check for days in feb
            if (mon == 2)
            {
                if (is_leap && day == 29)
                {
                    is_valid = 1;
                }
                else if(day > 28)
                {
                    is_valid = 0;
                }
            }

            // check for days in April, June, September and November
            else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
            {
                if (day > 30)
                {
                    is_valid = 0;
                }
            }

            // check for days in rest of the months
            // i.e Jan, Mar, May, July, Aug, Oct, Dec
            else if(day > 31)
            {
                is_valid = 0;
            }
        }
        else
        {
            is_valid = 0;
        }
    }
    else
    {
        is_valid = 0;
    }

    return is_valid;
    getch();
    return 0;
}

int valid_password(char *s)
{
/********************************************************
 This function is used to validate user passwords
*********************************************************/
    int len,error1=0,error2=0;
    len=strlen(s);

 printf("\033[1;31m");

        if(len > 30){
            error2=1;
       }
         if(len <3){
        error1=1;
          }

     if(error1==1) {
        printf("\n*Please enter minimum of 3 characters for the password");
     }

     if(error2==1) {
        printf("\n*Password length is too long. Maximum length should be 30");

     }
    if(error1==1||error2==1){
        printf("\n*Invalid password.Please enter a valid password");
         printf("\033[1;33m");
        return 0;
    }

  printf("\033[1;33m");
  return 1;
}


int valid_username(char *s)
{
/********************************************************
 This function is used to validate usernames
********************************************************/
    FILE *fp7;
    ur u1;
    int len,error1=0,error2=0,error3=0;
    len=strlen(s);

 printf("\033[1;31m");

    if(len < 3){
        error1=1;
    }

if(len > 30){
            error2=1;
           }
fp7=fopen("DATA\\records\\userslist","r");
 while(fread(&u1,sizeof(ur),1,fp7))
        {
                    if(strcmp(u1.uname,s)==0)
                    {
                        error3=1;
                    }
        }
     if(error3==1)
     {
        printf("\n--------------------------------------------------------------------------------------------------");
        printf("\n*This username is already taken by someone. Please enter a different username.");
        printf("\n--------------------------------------------------------------------------------------------------\n");
        printf("\033[1;33m");
         fclose(fp7);
        return 0;
     }

     if(error1==1) {
        printf("\n*Please enter minimum of 3 characters for the username");
     }

     if(error2==1) {
        printf("\n*Username length is too long. Maximum length should be 30");

     }
    if(error1==1||error2==1){
        printf("\n*Invalid username.Please enter a valid username");
         printf("\033[1;33m");
        fclose(fp7);
        return 0;
    }

  printf("\033[1;33m");
  return 1;
  fclose(fp7);
}



void report_one()
{
/**************************************************************************************************
 This function is used to get the list of prisoners who are currently on death penalty.
***************************************************************************************************/

  system("cls");
   pr s1;
   prr p1;
   FILE *fp,*fp3;
   char condition[10];
   int found=0,count=0,count_of_single_prison=0,k=0;

   if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a23.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

 system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\033[1;37mLIST OF PRISONERS WHO ARE CURRENTLY ON DEATH PENALTY\033[1;31m\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");

    fp=fopen("DATA\\records\\prisoner records","rb");
    rewind(fp);
    fp3=fopen("DATA\\records\\prison records","rb");
    rewind(fp3);

if(strcmpi(death_penalty,"AVAILABLE")==0)
        {
                    while(fread(&p1,sizeof(prr),1,fp3))
               {
                   printf("\n\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");
                   printf("\n\t\t\033[1;37m%04d\t\t\033[1;36m%s\033[1;33m",p1.id,p1.name);
                   printf("\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");

      while(fread(&s1,sizeof(pr),1,fp))
               {
                 if(s1.prisoner_prison_id==p1.id)
                 {


                 if(s1.penalty_type==2)
                    {
                         found=1;

                printf("\n\tPRISONER ID    : %s",s1.id);
                printf("\n\tNAME           : %s",s1.full_name);
                printf("\n\tAGE            : %d",s1.age);
                printf("\n\tEXECUTION DATE : %02d/%02d/%04d",s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);

                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        count++;
                        count_of_single_prison++;
                    }
                 }
                }

                if(!count_of_single_prison)
                {
                  printf("\n\t\033[1;31m*THERE ARE NO PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                }
                else
                {
                  printf("\n\t\033[1;32m*THERE ARE %d PRISONER/PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                }

                count_of_single_prison=0;
               }
printf("\n\n\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");
    if(found)
        {
         printf("\n\t\033[1;32m*THERE ARE %d PRISONER/PRISONERS IN THIS LIST.\033[1;33m ",count);
        }
    if(!found){
            printf("\n\t\033[1;31m*\033[1;32mTHERE ARE NO PRISONERS IN THE LIST\033[1;33m ");
    }
printf("\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");
}
  else
    {
            k=0;
            printf("\033[1;31m\n\t\t");
            for (k = 0; k < 70; k++){
            printf("%c",205);}
            printf("  \n\t\t%c                                                                    %c",186,186);
            printf("  \n\t\t%c  DEATH PENALTY IS CURRENTLY NOT AVAILABLE IN YOUR COUNTRY/STATE.   %c",186,186);
            printf("  \n\t\t%c                                                                    %c",186,186);
            printf("  \n\t\t");
            for (k = 0; k < 70; k++){
            printf("%c",205);}
            printf("\033[1;33m");

    }

    fclose(fp);
    fclose(fp3);
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();

}



void report_two()

{
/*******************************************************************************************************
 This function is used to get the list of prisoners who will be released soon.(This month or next month)
********************************************************************************************************/
    system("cls");
  /*systemtime audio_switch_t;*/
  time_t currentTime;
  time(&currentTime);
  struct tm*myTime = localtime(&currentTime);
  pr s1;
  prr p1;
  FILE *fp,*fp3;
  char ch,choice='Y';
  int found=0,count=0,count_of_single_prison=0;

  if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a24.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

do{
        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\033[1;37mLIST OF PRISONERS WHO WILL BE RELEASED SOON\033[1;31m\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;36m\tTODAY'S DATE : %d/%d/%d \033[1;31m\t\t\t|",myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year+1900);
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mPRISONERS WHO SHOULD BE RELEASED IN THIS MONTH\t\033[1;37m[1]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mPRISONERS WHO WILL BE RELEASED IN NEXT MONTH\t\033[1;37m[2]\033[1;31m\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\t\t\t\033[1;37m[3]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEXIT\t\t\t\t\t\t\033[1;37m[4]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch);

       switch(ch)

    {case 1:
     system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\033[1;37mPRISONERS WHO SHOULD BE RELEASED IN THIS MONTH\033[1;31m\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");


     fp=fopen("DATA\\records\\prisoner records","r");
     rewind(fp);
     fp3=fopen("DATA\\records\\prison records","r");
     rewind(fp3);

     while(fread(&p1,sizeof(prr),1,fp3))
               {
                   printf("\n\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");
                   printf("\n\t\t\033[1;37m%04d\t\t\033[1;36m%s\033[1;33m",p1.id,p1.name);
                   printf("\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");

      while(fread(&s1,sizeof(pr),1,fp))
    {
       if(s1.prisoner_prison_id==p1.id)
                 {
          if((s1.punishment_end_month == myTime->tm_mon+1) && (s1.punishment_end_year == myTime->tm_year+1900))
             {
        found=1;

                printf("\n\tPRISONER ID    : %s",s1.id);
                printf("\n\tNAME           : %s",s1.full_name);
                printf("\n\tRELEASE DATE   : %d/%d/%d",s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        count++;
                        count_of_single_prison++;

             }
           }
         }
        if(!count_of_single_prison)
                {
                  printf("\n\t\033[1;31m*THERE ARE NO PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                }
                else
                {
                  printf("\n\t\033[1;32m*THERE ARE %d PRISONER/PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                }

                count_of_single_prison=0;
       }
printf("\n\n\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");
       if(found)
        {
         printf("\n\033[1;32m*THERE ARE %d PRISONER/PRISONERS TO BE RELEASED IN THIS MONTH.\033[1;33m ",count);
        }

        if(!found){
            printf("\n\033[1;31m*CURRENTLY THERE ARE NO PRISONERS TO BE RELEASED IN THIS MONTH.\033[1;33m");
              }
printf("\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");
    count=0;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
	getch();
     break;


     case 2:

        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\033[1;37mPRISONERS WHO WILL BE RELEASED IN NEXT MONTH\033[1;31m\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");



     fp=fopen("DATA\\records\\prisoner records","r");
     rewind(fp);
     fp3=fopen("DATA\\records\\prison records","r");
     rewind(fp3);

     while(fread(&p1,sizeof(prr),1,fp3))
               {
                   printf("\n\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");
                   printf("\n\t\t\033[1;37m%04d\t\t\033[1;36m%s\033[1;33m",p1.id,p1.name);
                   printf("\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");

      while(fread(&s1,sizeof(pr),1,fp))
    {
       if(s1.prisoner_prison_id==p1.id)
                 {
          if(((s1.punishment_end_year == myTime->tm_year+1900) && ((s1.punishment_end_month) - (myTime->tm_mon+1) == 1))||(((s1.punishment_end_year)-(myTime->tm_year+1900) == 1) && (s1.punishment_end_month == 1 )&& (myTime->tm_mon+1 == 12)) )
             {
        found=1;
                printf("\n\tPRISONER ID    : %s",s1.id);
                printf("\n\tNAME           : %s",s1.full_name);
                printf("\n\tRELEASE DATE   : %d/%d/%d",s1.punishment_end_date,s1.punishment_end_month,s1.punishment_end_year);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        count++;
                        count_of_single_prison++;

             }
           }
         }
        if(!count_of_single_prison)
                {
                  printf("\n\t\033[1;31m*THERE ARE NO PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                }
                else
                {
                  printf("\n\t\033[1;32m*THERE ARE %d PRISONER/PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                }

                count_of_single_prison=0;
       }
printf("\n\n\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");
       if(found)
        {
         printf("\n\t\033[1;32m*THERE ARE %d PRISONER/PRISONERS TO BE RELEASED IN NEXT MONTH.\033[1;33m ",count);
        }

        if(!found){
            printf("\n\t\033[1;31m*CURRENTLY THERE ARE NO PRISONERS TO BE RELEASED IN NEXT MONTH\033[1;33m");
              }
  printf("\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");
                    count=0;
                    printf("\n\n\tPRESS ANY KEY TO EXIT...");
                    getch();
                    break;

                      case 3: reports_menu();
                            break;
                      case 4:main_menu();
                            break;

        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 4.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf("%c",&choice);

        }

}while(choice=='y'||choice=='Y');

}

void report_three()
{
/***************************************************************************
 This function is used to get the list of prisoners according to an age gap
****************************************************************************/
  system("cls");
  int  starting_age,ending_age;
  pr s1;
  prr p1;
  FILE *fp,*fp3;
  char another='Y';
  int found=0,ch,count=0,count_of_single_prison=0;

    if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a25.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\033[1;37mLIST OF PRISONERS ACCORDING TO AN AGE GAP\033[1;31m\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");


     while ( another == 'Y' || another == 'y' )

    {
     printf("\n\n\t\t\033[1;33mPLEASE ENTER THE STARTING AGE OF THE AGE GAP:\033[1;37m ");
     scanf("%d",&starting_age);
     printf("\n\t\t\033[1;33mPLEASE ENTER THE ENDING AGE OF THE AGE GAP:\033[1;37m ");
     scanf("%d",&ending_age);
     printf("\n\t\033[1;31m***************************************************************************");
     printf("\n\t\t\033[1;33mHERE IS THE LIST OF PRISONERS BETWEEN THE AGES OF %d TO %d ",starting_age,ending_age);
     printf("\n\t\033[1;31m***************************************************************************\033[1;33m");
      fp=fopen("DATA\\records\\prisoner records","rb");
      rewind(fp);
      fp3=fopen("DATA\\records\\prison records","rb");
      rewind(fp3);

    while(fread(&p1,sizeof(prr),1,fp3))
               {
                   printf("\n\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");
                   printf("\n\t\t\033[1;37m%04d\t\t\033[1;36m%s\033[1;33m",p1.id,p1.name);
                   printf("\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");

      while(fread(&s1,sizeof(pr),1,fp))
    {
       if(s1.prisoner_prison_id==p1.id)
                 {
          if(s1.age >= starting_age && s1.age <= ending_age)
             {
        found=1;
                printf("\n\tPRISONER ID    : %s",s1.id);
                printf("\n\tNAME           : %s",s1.full_name);
                printf("\n\tAGE            : %d",s1.age);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        count++;
                        count_of_single_prison++;

             }
           }
         }
        if(!count_of_single_prison)
                {
                  printf("\n\t\033[1;31m*THERE ARE NO PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                }
                else
                {
                  printf("\n\t\033[1;32m*THERE ARE %d PRISONER/PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                }

                count_of_single_prison=0;
       }

printf("\n\n\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");
if(found){
        printf("\n\n\033[1;32m*THERE ARE %d PRISONER/PRISONERS INSIDE THIS AGE GAP\033[1;33m",count);
           }

 if(!found){
        printf("\n\n\033[1;31m*THERE ARE NO PRISONERS INSIDE THIS AGE GAP\033[1;33m");
           }
printf("\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");

    fclose(fp3);
    fclose(fp);
	getch();

	printf("\n\tDO YOU LIKE TO CHECK ANOTHER AGE GAP?.(Y/N):");
    fflush(stdin);
    scanf("%c",&another);


}
 printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();

}

void report_four()
{
/***************************************************************************
 This function is used to get the health reports of prisoners
****************************************************************************/
  system("cls");
    pr s1;
    prr p1;
    FILE *fp,*fp3;
    char condition[10];
    char id[10],another='Y',choice='Y',choice2='Y';
    char selected_category[30];
    char calculated_BMI_category[30];
    int found=0,ch,ch2=0,count=0,count_of_single_prison=0,found_record=0;
    int selected_category_no=0,count_category=0;


   if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a26.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    do{

        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mHEALTH REPORTS OF PRISONERS\033[1;31m\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mCHECK PHYSICAL HEALTH CONDITIONS\t\033[1;37m[1]\033[1;31m\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mCHECK MENTAL HEALTH CONDITIONS\t\t\033[1;37m[2]\033[1;31m\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mCHECK BMI REPORTS OF PRISONERS\t\t\033[1;37m[3]\033[1;31m\t\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO REPORTS MENU\t\t\t\033[1;37m[4]\033[1;31m\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\t\t\033[1;37m[5]\033[1;31m\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch);

        switch(ch)
        {
           case 1:
     system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mCHECK PHYSICAL HEALTH CONDITIONS\033[1;31m\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");

    fp=fopen("DATA\\records\\prisoner records","rb");
    rewind(fp);
    printf("\n\n\tENTER PHYSICAL HEALTH CONDITION(good/bad):\033[1;37m");
    scanf("%s",&condition);
    printf("\033[1;33m");
    while(!valid_condition(condition))
        {
            printf("\033[1;31m\n*Condition is invalid.Please enter a valid condition(good/bad)\n\n\033[1;33m");
            printf("\033[1;33m\tENTER PHYSICAL HEALTH CONDITION(good/bad) : \033[1;37m");
            gets(condition);
            printf("\033[1;33m");
        }


    fp=fopen("DATA\\records\\prisoner records","rb");
    rewind(fp);
    fp3=fopen("DATA\\records\\prison records","rb");
    rewind(fp3);

    while(fread(&p1,sizeof(prr),1,fp3))
               {
                   printf("\n\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");
                   printf("\n\t\t\033[1;37m%04d\t\t\033[1;36m%s\033[1;33m",p1.id,p1.name);
                   printf("\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");

      while(fread(&s1,sizeof(pr),1,fp))
    {
       if(s1.prisoner_prison_id==p1.id)
                 {
          if(strcmpi(s1.physical_health,condition)==0)
             {
        found=1;
                printf("\n\tPRISONER ID               : %s",s1.id);
                printf("\n\tNAME                      : %s",s1.full_name);
                printf("\n\tAGE                       : %d",s1.age);
				printf("\n\tPHYSICAL HEALTH CONDITION : %s",s1.physical_health);
				printf("\n\tMENTAL HEALTH CONDITION   : %s",s1.mental_health);
				printf("\n\tSPECIFIC ILLNESSES        : %s",s1.specific_illnesses);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        count++;
                        count_of_single_prison++;

             }
           }
         }
        if(!count_of_single_prison)
                {
                  printf("\n\t\033[1;31m*THERE ARE NO PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                }
                else
                {
                  printf("\n\t\033[1;32m*THERE ARE %d PRISONER/PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                }

                count_of_single_prison=0;
       }

printf("\n\n\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");
if(found){
        printf("\n\n\033[1;32m*THERE ARE %d PRISONER/PRISONERS WITH %s PHYSICAL HEALTH CONDITIONS\033[1;33m",count,condition);
           }

 if(!found){
        printf("\n\n\033[1;31m*THERE ARE NO PRISONERS WITH %s PHYSICAL HEALTH CONDITIONS\033[1;33m",condition);
           }
printf("\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");

    fclose(fp3);
    fclose(fp);
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
	getch();
    break;

case 2:
   system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mCHECK MENTAL HEALTH CONDITIONS\033[1;31m\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
    fp=fopen("DATA\\records\\prisoner records","r");
    rewind(fp);
    printf("\n\n\tENTER MENTAL HEALTH CONDITION(good/bad):\033[1;37m");
    scanf("%s",&condition);
    printf("\033[1;33m");
    while(!valid_condition(condition))
        {
            printf("\033[1;31m\n*Condition is invalid.Please enter a valid condition(good/bad)\n\n\033[1;33m");
            printf("\033[1;33m\tENTER MENTAL HEALTH CONDITION(good/bad) : \033[1;37m");
            gets(condition);
            printf("\033[1;33m");
        }

    fp=fopen("DATA\\records\\prisoner records","rb");
    rewind(fp);
      fp3=fopen("DATA\\records\\prison records","rb");
      rewind(fp3);

    while(fread(&p1,sizeof(prr),1,fp3))
               {
                   printf("\n\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");
                   printf("\n\t\t\033[1;37m%04d\t\t\033[1;36m%s\033[1;33m",p1.id,p1.name);
                   printf("\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");

      while(fread(&s1,sizeof(pr),1,fp))
    {
       if(s1.prisoner_prison_id==p1.id)
                 {
          if(strcmpi(s1.mental_health,condition)==0)
             {
        found=1;
                printf("\n\tPRISONER ID               : %s",s1.id);
                printf("\n\tNAME                      : %s",s1.full_name);
                printf("\n\tAGE                       : %d",s1.age);
				printf("\n\tPHYSICAL HEALTH CONDITION : %s",s1.physical_health);
				printf("\n\tMENTAL HEALTH CONDITION   : %s",s1.mental_health);
				printf("\n\tSPECIFIC ILLNESSES        : %s",s1.specific_illnesses);
                printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        count++;
                        count_of_single_prison++;

             }
           }
         }
        if(!count_of_single_prison)
                {
                  printf("\n\t\033[1;31m*THERE ARE NO PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                }
                else
                {
                  printf("\n\t\033[1;32m*THERE ARE %d PRISONER/PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                }

                count_of_single_prison=0;
       }

printf("\n\n\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");
if(found){
        printf("\n\n\033[1;32m*THERE ARE %d PRISONER/PRISONERS WITH %s MENTAL HEALTH CONDITIONS\033[1;33m",count,condition);
           }

 if(!found){
        printf("\n\n\033[1;31m*THERE ARE NO PRISONERS WITH %s MENTAL HEALTH CONDITIONS\033[1;33m",condition);
           }
printf("\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");

    fclose(fp3);
    fclose(fp);
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
	getch();
    break;

    case 3:


 do{
        ch2=0;

        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mBMI REPORTS OF THE PRISONERS\033[1;31m\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mCHECK BMI FOR A PARTICULAR PRISONER\t\t\033[1;37m[1]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mLIST OF PRISONERS ACCORDING TO THE BMI CATEGORY\t\033[1;37m[2]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mGO BACK\t\t\t\t\t\t\033[1;37m[3]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\t\t\t\033[1;37m[4]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch2);

        switch(ch2)
              {case 1:

                              do{
                             system("cls");

        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\033[1;37mCHECK BMI FOR A PARTICULAR PRISONER\033[1;31m\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");


                             fp=fopen("DATA\\records\\prisoner records","rb");
                             rewind(fp);
                             printf("\n\n\tENTER PRISONER ID:");
                             scanf(" %s",&id);

                             found_record=0;

                                while(fread( &s1,sizeof(pr),1,fp)==1)
                                {

                                    if(strcmp(s1.id,id)==0)
                                    {
                                        found_record=1;
                                        printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;37m");
                                        printf("\n\tPRISONER HEIGHT :\033[1;32m %d centimeters\033[1;37m", s1.height);
                                        printf("\n\tPRISONER WEIGHT :\033[1;32m %d kilograms\033[1;37m", s1.weight);
                                        printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");


                                           BMI_category(calculated_BMI_category,s1.height,s1.weight);

                                        printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;37m");
                                        printf ("\n\t BMI         :-\033[1;36m %.2f\033[1;37m",BMI_calculator(s1.height,s1.weight));
                                        printf ("\n\t BMI CATEGORY:- %s ",calculated_BMI_category);
                                        printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                                        printf("\n\n\tPRESS ANY KEY TO EXIT...");
                                        getch();
                                    }
                                }

                            if(!found_record) {
                                        printf("\n\t\033[1;31mTHIS PRISONER ID DOES NOT EXIST...\n\033[1;33m");
                                    }

                                 printf("\n\n\tDO YOU WANT TO TRY AGAIN?(Y/N).\n");
                                 scanf(" %c",&choice2);


                             } while(choice2 == 'Y'|| choice2 == 'y');


                             fclose(fp);
                             break;

               case 2:

                   while(another=='Y'||another=='y')
                   {
                        system("cls");

        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\033[1;37mLIST OF PRISONERS ACCORDING TO THE BMI CATEGORY\033[1;31m\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");

                        selected_category_no=0;
                        count_category=0;


                        printf("\033[1;33m\n\tTHERE ARE 4 BMI CATEGORIES,\033[1;33m\n");
                        printf("\033[1;37m\n\t\t(1)UNDERWEIGHT");
                        printf("\033[1;32m\n\t\t(2)NORMAL");
                        printf("\033[1;34m\n\t\t(3)OVERWEIGHT");
                        printf("\033[1;31m\n\t\t(4)OBESITY");
                        printf("\033[1;33m\n\n\t*PLEASE ENTER THE BMI CATEGORY NUMBER TO GET THE LIST OF PRISONERS UNDER THAT PARTICULAR CATEGORY. \n");
                        scanf("%d",&selected_category_no);

                        fp=fopen("DATA\\records\\prisoner records","rb");
                        rewind(fp);


                        if(selected_category_no==1||selected_category_no==2||selected_category_no==3||selected_category_no==4)
                            {

                                    if(selected_category_no==1 )
                                        {
                                             strcpy(selected_category,"\033[1;37mUNDERWEIGHT");
                                        }
                                    if(selected_category_no==2 )
                                        {
                                             strcpy(selected_category,"\033[1;32mNORMAL");
                                        }

                                    if(selected_category_no==3 )
                                        {
                                             strcpy(selected_category,"\033[1;34mOVERWEIGHT");
                                        }
                                    if(selected_category_no==4 )
                                        {
                                             strcpy(selected_category,"\033[1;31mOBESITY");
                                        }
                                   printf("\033[1;31m\n\n\t*********************************************************");
                                   printf("\033[1;37m\n\t\tLIST OF PRISONERS UNDER %s \033[1;37mCATEGORY",selected_category);
                                   printf("\033[1;31m\n\t*********************************************************");


                            fp=fopen("DATA\\records\\prisoner records","r");
                            rewind(fp);
                            fp3=fopen("DATA\\records\\prison records","r");
                            rewind(fp3);

                                            while(fread(&p1,sizeof(prr),1,fp3))
                                       {
                                           printf("\n\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");
                                           printf("\n\t\t\033[1;37m%04d\t\t\033[1;36m%s\033[1;33m",p1.id,p1.name);
                                           printf("\n\033[1;37m-----------------------------------------------------------------------------------------------------\033[1;33m");

                              while(fread(&s1,sizeof(pr),1,fp))
                                       {

                                         if(s1.prisoner_prison_id==p1.id)
                                         {

                                              char calculated_BMI_category[30];
                                              float BMI=BMI_calculator(s1.height,s1.weight);
                                              BMI_category(calculated_BMI_category,s1.height,s1.weight);

                                         if(strcmpi(selected_category,calculated_BMI_category)==0)
                                            {
                                                 found=1;

                                        printf("\n\tPRISONER ID    : %s",s1.id);
                                        printf("\n\tNAME           : %s",s1.full_name);
                                        printf("\n\tAGE            : %d",s1.age);
                                        printf("\n\tBMI            : %.2f",BMI);

                                        printf("\n\033[1;31m-----------------------------------------------------------------------------------------------------\033[1;33m");
                                                count++;
                                                count_of_single_prison++;
                                            }
                                         }
                                        }

                                        if(!count_of_single_prison)
                                        {
                                          printf("\n\t\033[1;31m*THERE ARE NO PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                                        }
                                        else
                                        {
                                          printf("\n\t\033[1;32m*THERE ARE %d PRISONER/PRISONERS FROM THIS PRISON.\033[1;33m ",count_of_single_prison);
                                        }

                                        count_of_single_prison=0;
                                       }
                        printf("\n\n\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");
                            if(found)
                                {
                                 printf("\n\t\033[1;32m*THERE ARE %d PRISONER/PRISONERS UNDER %s \033[1;32mCATEGORY.\033[1;33m ",count,selected_category);
                                }
                            if(!found){
                                    printf("\n\t\033[1;31m*THERE ARE NO PRISONERS UNDER %s \033[1;31mCATEGORY.\033[1;33m ",selected_category);
                            }
                        printf("\n\033[1;32m-----------------------------------------------------------------------------------------------------\033[1;33m");


                        }

                      else{
                           printf("\n\t\033[1;31m*INVALID CATEGORY NUMBER \033[1;33m");
                          }

                        printf("\033[1;33m\n\n\tDO YOU WANT TO TRY AGAIN?(Y/N)");
                        scanf(" %c",&another);

                        }

                          fclose(fp);
                          fclose(fp3);

               case 3:
                   system("cls");
                   report_four();
                   break;
               case 4:
                   system("cls");
                   main_menu();

               default:
                        printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 5.");
                        printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
                        fflush(stdin);
                        scanf("%c",&choice2);

              }
              }while(choice2=='y'||choice2=='Y');


  case 4:reports_menu();
            break;
  case 5:main_menu();
                    break;


        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 5.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");

            fflush(stdin);
            scanf("%c",&choice);

        }

}while(choice=='y'||choice=='Y');


}


void report_five()
{

 int ch;
 char choice='Y';
 FILE *fp4;

     if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a27.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

do{

        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch);printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mCOMPARISON REPORTS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mDISTRIBUTIONS OF PRISONER POPULATION\t\t\033[1;37m[1]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mDISTRIBUTIONS OF STAFF MEMBER POPULATION\t\033[1;37m[2]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mDISTRIBUTIONS OF PRISON ATTRIBUTES\t\t\033[1;37m[3]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO REPORTS MENU\t\t\t\t\033[1;37m[4]\033[1;31m\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\t\t\t\033[1;37m[5]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEXIT\t\t\t\t\t\t\033[1;37m[6]\033[1;31m\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");

        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            distributions_of_prisoner_population();
            break;

        case 2:
            distributions_of_staff_member_population();
            break;

        case 3:
            distributions_of_prison_attributes();
            break;

        case 4:
            reports_menu();
            break;

        case 5:
            main_menu();
            break;

        case 6:
        	system("cls");
            exit_screen();

        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 6.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);
        }
}while(choice=='y'||choice=='Y');
getch();

}

void distributions_of_prisoner_population()
{
/***************************************************************************
 This function is used to get distributions of prisoner population
****************************************************************************/
  system("cls");
  printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\033[1;37mDISTRIBUTIONS OF PRISONER POPULATION\033[1;31m\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m\n\n");
  comparison_02_for_prisoners();
  printf("\n\n");
  comparison_01_for_prisoners();
  printf("\n\n");
  comparison_03();
  printf("\n\n");
  comparison_03_with_gender();
printf("\n\n\n\tPRESS ANY KEY TO EXIT...");
	getch();

}

void distributions_of_prison_attributes()
{
/***************************************************************************
 This function is used to get distributions of prison attributes
****************************************************************************/
    system("cls");
    printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mDISTRIBUTIONS OF PRISON ATTRIBUTES\033[1;31m\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m\n\n");

    comparison_04();
    printf("\n\n");
    comparison_05();
    printf("\n\n");
    printf("\n\n\n\tPRESS ANY KEY TO EXIT...");
	getch();

}


void distributions_of_staff_member_population()
{
/***************************************************************************
 This function is used to get distributions of staff member population
****************************************************************************/
    system("cls");
    printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\033[1;37mDISTRIBUTIONS OF STAFF MEMBER POPULATION\033[1;31m\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m\n\n");

    comparison_02_for_staff_members();
    printf("\n\n");
    comparison_01_for_staff_members();
    printf("\n\n");
    printf("\n\n\n\tPRESS ANY KEY TO EXIT...");
	getch();
}

void comparison_01_for_prisoners()
{
/**********************************************************************************************************************
 This function is used to generate a bar chart according to distribution of gender of prisoners in all the prisons
***********************************************************************************************************************/
    pr s1;
    FILE *fp;

    int total_prisoners=0,no_male=0,no_female=0,found=0,bar_male=0,bar_female=0;
    float presentage_male=0,presentage_female=0;

    fp=fopen("DATA\\records\\prisoner records","rb");
    rewind(fp);
      while(fread(&s1,sizeof(pr),1,fp))
    {
     if(s1.age> 0){
            found=1;
              total_prisoners++;

              if (strcmpi(s1.gender,"male")==0)
                {
                   no_male++;
                }
               else if (strcmpi(s1.gender,"female")==0)
                {
                   no_female++;
                }

        }
    }
    if(!found)
        {
          printf("There are no records of prisoners");

        }

    printf("\033[1;34m\n\t**********************************************************************\n");
    printf(  "\t*** \033[1;37mDISTRIBUTION OF PRISONER'S GENDER ACCORDING TO ALL THE PRISONS\033[1;34m ***");
    printf("\n\t**********************************************************************\n\033[1;33m");
    printf("\n\nTOTAL NUMBER OF PRISONERS = %d\n",total_prisoners);
    printf("\n[1]:-NUMBER OF MALE PRISONERS = %d\n",no_male);
    printf("\n[2]:-NUMBER OF FEMALE PRISONERS = %d\n\n",no_female);

    presentage_male=(float)no_male/total_prisoners*100.0;
    presentage_female=(float)no_female/total_prisoners*100.0;

    bar_male=(presentage_male/2);
    bar_female=(presentage_female/2);

fflush(stdin);
 int hist1[] = {bar_male,bar_female};
 int result1[]= {no_male,no_female};
 char* category[2]={"Male","Female"};
  hist1[2]=0;

   int i;
   fflush(stdin);
   for(i=0;i<2;i++){

   }
    printHistogram(hist1,result1,category,2,"count","prisons");
    fclose(fp);

}

 void comparison_01_for_staff_members()
{
/**********************************************************************************************************************
 This function is used to generate a bar chart according to distribution of gender of staff members in all the prisons
***********************************************************************************************************************/

    sr sm1;
    FILE *fp2;

      int total_staff_members=0;
      int no_male=0,no_female=0,found=0,bar_male=0,bar_female=0;
      int presentage_male=0,presentage_female=0;

    fp2=fopen("DATA\\records\\staff member records","rb");
    rewind(fp2);
      while(fread(&sm1,sizeof(sr),1,fp2))
    {
     if(sm1.age> 0)
        {
           found=1;
              total_staff_members++;

              if (strcmpi(sm1.gender,"male")==0)
                {
                   no_male++;
                }
               else if (strcmpi(sm1.gender,"female")==0)
                {
                   no_female++;
                }

               }
    }
    if(!found)
        {
          printf("There are no records of staff members");

        }

    printf("\033[1;34m\n\t**************************************************************************\n");
    printf(  "\t*** \033[1;37mDISTRIBUTION OF STAFF MEMBER'S GENDER ACCORDING TO ALL THE PRISONS\033[1;34m ***");
    printf("\n\t**************************************************************************\n\033[1;33m");
    printf("\n\nTOTAL NUMBER OF STAFF MEMBERS = %d\n",total_staff_members);
    printf("\n[1]:-NUMBER OF MALE STAFF MEMBERS = %d\n",no_male);
    printf("\n[2]:-NUMBER OF FEMALE STAFF MEMBERS = %d\n\n",no_female);




    presentage_male=(float)no_male/total_staff_members*100.0;
    presentage_female=(float)no_female/total_staff_members*100.0;

    bar_male=(presentage_male/2);
    bar_female=(presentage_female/2);


     int max_bar_value=0;
     if(bar_male>bar_female)
     {
         max_bar_value=bar_male;
     }
     else{
         max_bar_value=bar_female;
     }

      int value_to_multiply=0;

      value_to_multiply=(float)50/max_bar_value;

        bar_male *= (value_to_multiply);
        bar_female *= (value_to_multiply);


 int hist2[] = {bar_male,bar_female};
 int result2[]= {no_male,no_female};
 char* category2[2]={"Male","Female"};
  hist2[2]=0;

    printHistogram(hist2,result2,category2,2,"Number of prisoners","Gender");

    fclose(fp2);

}

void printHistogram(int *hist,int *result,char* category[],int n,char* x,char* y) {
/************************************************
 This function is used to generate a bar chart
*************************************************/
      int i, j,k;
      printf("\n\t %c",179);
      for (k = 0; k < 60; k++){
      printf("%c",196);
      }
      printf(">%s",x);
      printf("\n");
      for (i = 0; i < n; i++) {
      printf("[%s\t]%c ",category[i],179);
      printf("\033[1;3%dm",i+1);
      for ( j = 0; j < hist[i]; ++j) {
      printf("%c",219);
      }
      printf("\033[1;33m");
      printf("(%d)",result[i]);
      printf("\n");
      printf("\t %c\n",179);
   }
  printf("\t V\n\t%s",y);
}

void comparison_02_for_prisoners()
{
/**********************************************************************************************************************
 This function is used to generate a bar chart according to distribution of gender of prisoners in each prison separately
***********************************************************************************************************************/
 prr p1;
 pr s1;
 FILE *fp,*fp3;
 struct prisons{

                int count_of_male_prisoners;
                int count_of_female_prisoners;
                int count_of_total_prisoners;

             };

 int no_of_prisons=0,prison_ID=0,i=0,count_of_total_prisoners=0,count_of_male_prisoners=0,count_of_female_prisoners=0;


    printf("\033[1;34m\n\t******************************************************************\n");
    printf(  "\t*** \033[1;37mDISTRIBUTION OF PRISONER'S GENDER ACCORDING TO EACH PRISON\033[1;34m ***");
    printf("\n\t******************************************************************\n\033[1;33m");

 fp=fopen("DATA\\records\\prisoner records","rb");
 rewind(fp);
 fp3=fopen("DATA\\records\\prison records","rb");
 rewind(fp3);


 while(fread(&p1,sizeof(prr),1,fp3))
 {
     if(p1.id>0)
        {

        no_of_prisons++;
     }
 }
 struct prisons pn[no_of_prisons];
 int prison_id[no_of_prisons];

rewind(fp3);
 while(fread(&p1,sizeof(prr),1,fp3)==1)
    {

                rewind(fp);
                while(fread(&s1,sizeof(pr),1,fp))
                {
                  prison_ID=p1.id;
                  if(p1.id==s1.prisoner_prison_id)
                  {
                      count_of_total_prisoners++;
                      if(strcmpi(s1.gender,"male")==0)
                        {
                          count_of_male_prisoners++;
                        }
                      if(strcmpi(s1.gender,"female")==0)
                        {
                          count_of_female_prisoners++;
                        }

                  }
                }
         fflush(stdin);
        prison_id[i]=prison_ID;
        pn[i].count_of_total_prisoners=count_of_total_prisoners;
        pn[i].count_of_male_prisoners=count_of_male_prisoners;
        pn[i].count_of_female_prisoners=count_of_female_prisoners;

        i++;
        count_of_total_prisoners=0;
        count_of_male_prisoners=0;
        count_of_female_prisoners=0;
     }

//Finding the maximum values of arrays
     int a=1,max_location_1=0;
     fflush(stdin);
     for (a = 1; a < no_of_prisons; a++){
     if (pn[a].count_of_total_prisoners > pn[max_location_1].count_of_total_prisoners)
      {max_location_1 = a;}}

     int b=1,max_location_2=0;
     fflush(stdin);
     for (b = 1; b < no_of_prisons; b++){
     if (pn[b].count_of_male_prisoners > pn[max_location_2].count_of_male_prisoners)
      {max_location_2 = b;}}

     int c=1,max_location_3=0;

     fflush(stdin);
     for (c = 1; c < no_of_prisons; c++){
     if (pn[c].count_of_female_prisoners > pn[max_location_3].count_of_female_prisoners)
      {max_location_3 = c;}}


     int max_gender_value=0;
     if(pn[max_location_2].count_of_male_prisoners>pn[max_location_3].count_of_female_prisoners)
     {
         max_gender_value=pn[max_location_2].count_of_male_prisoners;
     }
     else{

            max_gender_value=pn[max_location_3].count_of_female_prisoners;
         }

    int presentage_male[no_of_prisons],presentage_female[no_of_prisons], bar_male[no_of_prisons], bar_female[no_of_prisons];

  for(i=0;i< no_of_prisons;i++){

    fflush(stdin);
    presentage_male[i]=(float)pn[i].count_of_male_prisoners/max_gender_value*100.0;
    presentage_female[i]=(float)pn[i].count_of_female_prisoners/max_gender_value*100.0;

    bar_male[i]=(presentage_male[i]/2);
    bar_female[i]=(presentage_female[i]/2);
  }

    int d=1,max_location_4=0;
     fflush(stdin);
     for (d= 1; d < no_of_prisons; d++){
     if (bar_male[d] > bar_male[max_location_4])
      {max_location_4 = d;}}

     int e=1,max_location_5=0;
     fflush(stdin);
     for (e= 1; e < no_of_prisons; e++){
     if (bar_female[e] > bar_female[max_location_5])
      {max_location_5 = e;}}

    // printf("\nmax_location_4=%d",max_location_4);
    // printf("\nmax_location_5=%d",max_location_5);


     int max_bar_value=0;

     if(bar_male[max_location_4]>bar_female[max_location_5])
     {

         max_bar_value=bar_male[max_location_4];
     }
     else{

         max_bar_value=bar_female[max_location_5];
     }

     // printf("\nmax_bar_value=%d\n",max_bar_value);
      int value_to_multiply=0;

      value_to_multiply=(float)50/max_bar_value;
     // printf("\nvalue_to_multiply=%d\n",value_to_multiply);

      for(i = 0; i < no_of_prisons; i++)
        {bar_male[i] *= value_to_multiply;
         bar_female[i] *= value_to_multiply;

        }

     int result_male[no_of_prisons],result_female[no_of_prisons],result_total[no_of_prisons];

     for(i=0;i<no_of_prisons;i++)
    {

      result_male[i]=pn[i].count_of_male_prisoners;
      result_female[i]=pn[i].count_of_female_prisoners;
      result_total[i]=pn[i].count_of_total_prisoners;


     }
      fp3 = fopen ("DATA\\records\\prison records", "rb" ) ;
      rewind(fp3);

               printf("\n\n---------------------------------------------------------------------");
               printf("\n\t\t***PRISON LIST OF THE SYSTEM***");
               printf("\n---------------------------------------------------------------------");
               printf("\n\tPRISON ID         PRISON NAME             ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3))
                {

                printf("\n--------------------------------------------------------------------");
                printf("\n\t%04d               %s",p1.id,p1.name);

               }
               printf("\n---------------------------------------------------------------------\n");


     printHistogram2(bar_male,bar_female,result_male,result_female,result_total,prison_id,no_of_prisons,"Number of prisoners","Prisons");

fclose(fp);
fclose(fp3);

}


void comparison_02_for_staff_members()
{
/****************************************************************************************************************************
 This function is used to generate a bar chart according to distribution of gender of staff members in each prison separately
*****************************************************************************************************************************/
prr p1;
sr sm1;
FILE *fp2,*fp3;
struct prisons{
                int count_of_male_staff_members;
                int count_of_female_staff_members;
                int count_of_total_staff_members;

             };

 int no_of_prisons=0,prison_ID=0,i=0,count_of_total_staff_members=0,count_of_male_staff_members=0,count_of_female_staff_members=0;

 fp2=fopen("DATA\\records\\staff member records","rb");
 rewind(fp2);
 fp3=fopen("DATA\\records\\prison records","rb");
 rewind(fp3);

    printf("\033[1;34m\n\t***********************************************************************\n");
    printf(  "\t*** \033[1;37mDISTRIBUTION OF STAFF MEMBERS'S GENDER ACCORDING TO EACH PRISON \033[1;34m***");
    printf("\n\t***********************************************************************\n\033[1;33m");


 while(fread(&p1,sizeof(prr),1,fp3))
 {
     if(p1.id>0)
        {

        no_of_prisons++;
     }
 }
 struct prisons pn[no_of_prisons];
 int prison_id[no_of_prisons];

rewind(fp3);
 while(fread(&p1,sizeof(prr),1,fp3)==1)
    {

                rewind(fp2);
                while(fread(&sm1,sizeof(sr),1,fp2))
                {
                  prison_ID=p1.id;
                  if(p1.id==sm1.staff_member_prison_id)
                  {
                      count_of_total_staff_members++;
                      if(strcmpi(sm1.gender,"male")==0)
                        {
                          count_of_male_staff_members++;
                        }
                      if(strcmpi(sm1.gender,"female")==0)
                        {
                          count_of_female_staff_members++;
                        }
                  }
                }

         fflush(stdin);
        prison_id[i]=prison_ID;
        pn[i].count_of_total_staff_members=count_of_total_staff_members;
        pn[i].count_of_male_staff_members=count_of_male_staff_members;
        pn[i].count_of_female_staff_members=count_of_female_staff_members;

        i++;
        count_of_total_staff_members=0;
        count_of_male_staff_members=0;
        count_of_female_staff_members=0;
     }

//Finding the maximum values of arrays
     int a=1,max_location_1=0;
     fflush(stdin);
     for (a = 1; a < no_of_prisons; a++){
     if (pn[a].count_of_total_staff_members > pn[max_location_1].count_of_total_staff_members)
      {max_location_1 = a;}}

     int b=1,max_location_2=0;
     fflush(stdin);
     for (b = 1; b < no_of_prisons; b++){
     if (pn[b].count_of_male_staff_members > pn[max_location_2].count_of_male_staff_members)
      {max_location_2 = b;}}

     int c=1,max_location_3=0;

     fflush(stdin);
     for (c = 1; c < no_of_prisons; c++){
     if (pn[c].count_of_female_staff_members > pn[max_location_3].count_of_female_staff_members)
      {max_location_3 = c;}}


     int max_gender_value=0;
     if(pn[max_location_2].count_of_male_staff_members>pn[max_location_3].count_of_female_staff_members)
     {


         max_gender_value=pn[max_location_2].count_of_male_staff_members;
     }
     else{

            max_gender_value=pn[max_location_3].count_of_female_staff_members;
         }

    int presentage_male[no_of_prisons],presentage_female[no_of_prisons], bar_male[no_of_prisons], bar_female[no_of_prisons];

  for(i=0;i< no_of_prisons;i++){


    fflush(stdin);
    presentage_male[i]=(float)pn[i].count_of_male_staff_members/max_gender_value*100.0;
    presentage_female[i]=(float)pn[i].count_of_female_staff_members/max_gender_value*100.0;

    bar_male[i]=(presentage_male[i]/2);
    bar_female[i]=(presentage_female[i]/2);

  }


    int d=1,max_location_4=0;
     fflush(stdin);
     for (d= 1; d < no_of_prisons; d++){
     if (bar_male[d] > bar_male[max_location_4])
      {max_location_4 = d;}}

     int e=1,max_location_5=0;
     fflush(stdin);
     for (e= 1; e < no_of_prisons; e++){
     if (bar_female[e] > bar_female[max_location_5])
      {max_location_5 = e;}}

    // printf("\nmax_location_4=%d",max_location_4);
    // printf("\nmax_location_5=%d",max_location_5);


     int max_bar_value=0;

     if(bar_male[max_location_4]>bar_female[max_location_5])
     {

         max_bar_value=bar_male[max_location_4];
     }
     else{

         max_bar_value=bar_female[max_location_5];
     }

     // printf("\nmax_bar_value=%d\n",max_bar_value);
      int value_to_multiply=0;

      value_to_multiply=(float)50/max_bar_value;
     // printf("\nvalue_to_multiply=%d\n",value_to_multiply);

      for(i = 0; i < no_of_prisons; i++)
        {bar_male[i] *= value_to_multiply;
         bar_female[i] *= value_to_multiply;

        }



     int result_male[no_of_prisons],result_female[no_of_prisons],result_total[no_of_prisons];

     for(i=0;i<no_of_prisons;i++)
    {

      result_male[i]=pn[i].count_of_male_staff_members;
      result_female[i]=pn[i].count_of_female_staff_members;
      result_total[i]=pn[i].count_of_total_staff_members;


     }
      fp3 = fopen ("DATA\\records\\prison records", "rb" ) ;
      rewind(fp3);


               printf("\n\n---------------------------------------------------------------------");
               printf("\n\t\t***PRISON LIST OF THE SYSTEM***");
               printf("\n---------------------------------------------------------------------");
               printf("\n\tPRISON ID         PRISON NAME             ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3))
                {

                printf("\n--------------------------------------------------------------------");
                printf("\n\t%04d               %s",p1.id,p1.name);

               }
               printf("\n---------------------------------------------------------------------\n");


     printHistogram2(bar_male,bar_female,result_male,result_female,result_total,prison_id,no_of_prisons,"Number of staff members","Prisons");

fclose(fp2);
fclose(fp3);

}

void printHistogram2(int *bar_male,int *bar_female,int *result_male,int *result_female,int *result_total,int *prison_id[],int no_of_prisons,char* x,char* y)
{
 /************************************************
 This function is used to generate a bar chart
*************************************************/
      int i, j,k,l;
      printf("\n      %c",179);
      for (k = 0; k < 60; k++){
      printf("%c",196);
      }
      printf(">%s",x);
      for (i = 0; i < no_of_prisons; i++)
      {
              printf("\n");
              printf("[%04d]%c",prison_id[i],179);
              for ( j = 0; j < bar_male[i]; ++j)
              {
              printf("\033[1;31m");
              printf("%c",219);
              printf("\033[1;33m");
              }
              printf("Male(%d)| Total (%d)",result_male[i],result_total[i]);
              printf("\n");
              printf("      %c",179);
              for ( l = 0; l < bar_female[i]; ++l)
              {
              printf("\033[1;32m");
              printf("%c",219);
              printf("\033[1;33m");

              }
             printf("Female(%d)|",result_female[i]);
             printf("\n");
             printf("      %c",179);
             printf("\n");
             printf("      %c",179);


   }
printf("\n      V\n     %s",y);

}

void comparison_03()
{
/****************************************************************************************************************************
 This function is used to generate a bar chart according to distribution of age gaps of prisoners in all prisons
*****************************************************************************************************************************/

    printf("\033[1;34m\n\n\n\t*******************************************************");
    printf("    \n\t**\033[1;37mDISTRIBUTION OF PRISONERS ACCORDING TO THE AGE GAPS\033[1;34m**");
    printf("    \n\t*******************************************************\n\033[1;33m");

    pr s1;
    FILE *fp;
    int count_18to30=0,count_31to40=0,count_41to50=0,count_51to60=0,count_61to70=0,count_70plus=0,found=0,total_prisoners=0;

    char *category[6]={"18-30","31-40","41-50","51-60","61-70",">70"};
    fp=fopen("DATA\\records\\prisoner records","rb");
    rewind(fp);
    fflush(stdin);
      while(fread(&s1,sizeof(pr),1,fp))
    {
        total_prisoners++;

        if(s1.age>=18&&s1.age<=30)
          {
              found=1;
              count_18to30++;
          }
        if(s1.age>=31&&s1.age<=40)
          {
              found=1;
              count_31to40++;
          }
        if(s1.age>=41&&s1.age<=50)
          {
              found=1;
              count_41to50++;
          }
        if(s1.age>=51&&s1.age<=60)
          {
              found=1;
              count_51to60++;
          }
        if(s1.age>=61&&s1.age<=70)
          {
              found=1;
              count_61to70++;
          }
        if(s1.age>=71)
          {
              found=1;
              count_70plus++;
          }
    }

    if(!found)
        {
          printf("There are no records of prisoners\n");

        }

int counts[6]={count_18to30,count_31to40,count_41to50,count_51to60,count_61to70,count_70plus};


    int presentages[6],bar_sizes[6],i=0;

  for(i=0;i<6;i++){
    presentages[i]=(float)counts[i]/total_prisoners*100;
    bar_sizes[i]=(presentages[i]/2);
  }
     int e=1,max_location=0;
     fflush(stdin);
     for (e= 1; e < 6; e++){
     if (bar_sizes[e] > bar_sizes[max_location])
      {max_location = e;}}

    int max_bar_value;
      max_bar_value=bar_sizes[max_location];


     // printf("\nmax_bar_value=%d\n",max_bar_value);
      int value_to_multiply=0;

      value_to_multiply=(float)50/max_bar_value;


      for(i = 0; i < 6; i++)
        {bar_sizes[i] *= value_to_multiply;

        }

    printHistogram(bar_sizes,counts,category,6,"Number of prisoners","Age gaps");
    fclose(fp);
}

void comparison_03_with_gender()
{
/****************************************************************************************************************************
 This function is used to generate a bar chart according to distribution of age gaps of prisoners with their gender
*****************************************************************************************************************************/
    printf("\033[1;34m\n\n\n\t****************************************************************");
    printf("    \n\t**\033[1;37mDISTRIBUTION OF PRISONER'S GENDER ACCORDING TO THE AGE GAPS \033[1;34m**");
    printf("    \n\t****************************************************************\n\033[1;33m");

    pr s1;
    FILE *fp;
    int count_18to30=0,count_31to40=0,count_41to50=0,count_51to60=0,count_61to70=0,count_70plus=0,found=0,total_prisoners=0;
    int count_18to30M=0,count_31to40M=0,count_41to50M=0,count_51to60M=0,count_61to70M=0,count_70plusM=0;
    int count_18to30F=0,count_31to40F=0,count_41to50F=0,count_51to60F=0,count_61to70F=0,count_70plusF=0;

    char *age_gaps[6]={"18-30","31-40","41-50","51-60","61-70",">70"};
    fp=fopen("DATA\\records\\prisoner records","rb");
    rewind(fp);
    fflush(stdin);
      while(fread(&s1,sizeof(pr),1,fp))
    {
        total_prisoners++;

        if(s1.age>=18&&s1.age<=30)
          {
              found=1;
              count_18to30++;
              if(strcmpi(s1.gender,"male")==0)
                {
                  count_18to30M++;
                }
               if(strcmpi(s1.gender,"female")==0)
                {
                  count_18to30F++;
                }

          }
        if(s1.age>=31&&s1.age<=40)
          {
              found=1;
              count_31to40++;
              if(strcmpi(s1.gender,"male")==0)
                {
                  count_31to40M++;
                }
               if(strcmpi(s1.gender,"female")==0)
                {
                  count_31to40F++;
                }

          }
        if(s1.age>=41&&s1.age<=50)
          {
              found=1;
              count_41to50++;
              if(strcmpi(s1.gender,"male")==0)
                {
                  count_41to50M++;
                }
               if(strcmpi(s1.gender,"female")==0)
                {
                  count_41to50F++;
                }
          }
        if(s1.age>=51&&s1.age<=60)
          {
              found=1;
              count_51to60++;
              if(strcmpi(s1.gender,"male")==0)
                {
                  count_51to60M++;
                }
               if(strcmpi(s1.gender,"female")==0)
                {
                  count_51to60F++;
                }
          }
        if(s1.age>=61&&s1.age<=70)
          {
              found=1;
              count_61to70++;
              if(strcmpi(s1.gender,"male")==0)
                {
                  count_61to70M++;
                }
               if(strcmpi(s1.gender,"female")==0)
                {
                  count_61to70F++;
                }
          }
        if(s1.age>=71)
          {
              found=1;
              count_70plus++;
              if(strcmpi(s1.gender,"male")==0)
                {
                  count_70plusM++;
                }
               if(strcmpi(s1.gender,"female")==0)
                {
                  count_70plusF++;
                }
          }
    }

    if(!found)
        {
          printf("There are no records of prisoners\n");

        }

int counts[6]={count_18to30,count_31to40,count_41to50,count_51to60,count_61to70,count_70plus};
int countsM[6]={count_18to30M,count_31to40M,count_41to50M,count_51to60M,count_61to70M,count_70plusM};
int countsF[6]={count_18to30F,count_31to40F,count_41to50F,count_51to60F,count_61to70F,count_70plusF};



    int presentagesM[6],presentagesF[6],bar_sizesM[6],bar_sizesF[6],i=0;

  for(i=0;i<6;i++){
    presentagesM[i]=(float)countsM[i]/total_prisoners*100;
    bar_sizesM[i]=(presentagesM[i]/2);

    presentagesF[i]=(float)countsF[i]/total_prisoners*100;
    bar_sizesF[i]=(presentagesF[i]/2);

  }
     int a=1,max_location_1=0;
     fflush(stdin);
     for (a= 1; a < 6; a++){
     if (bar_sizesM[a] > bar_sizesM[max_location_1])
      {max_location_1 = a;}}

    int b=1,max_location_2=0;
     fflush(stdin);
     for (b= 1; b < 6; b++){
     if (bar_sizesF[b] > bar_sizesF[max_location_2])
      {max_location_2 = b;}}

   int max_bar_value=0;

    if(bar_sizesM[max_location_1] > bar_sizesF[max_location_2])
    {
       max_bar_value=bar_sizesM[max_location_1];
    }
     else
     {
       max_bar_value=bar_sizesF[max_location_2];
     }

     // printf("\nmax_bar_value=%d\n",max_bar_value);
      int value_to_multiply=0;

      value_to_multiply=(float)50/max_bar_value;


      for(i = 0; i < 6; i++)
        {bar_sizesM[i] *= value_to_multiply;
         bar_sizesF[i] *= value_to_multiply;

        }

    printHistogram3(bar_sizesM,bar_sizesF,countsM,countsF,counts,age_gaps,6,"Number of prisoners","Age_gaps");
    fclose(fp);

}

void printHistogram3(int *bar_male,int *bar_female,int *result_male,int *result_female,int *result_total,char *category[],int no_of_categories,char* x,char* y)
{
/************************************************
 This function is used to generate a bar chart
*************************************************/
      int i, j,k,l;
      printf("\n\t %c",179);
      for (k = 0; k < 60; k++){
      printf("%c",196);
      }
      printf(">%s",x);
      for (i = 0; i < no_of_categories; i++)
      {
              printf("\n");
              printf("[%s\t]%c",category[i],179);
              for ( j = 0; j < bar_male[i]; ++j)
              {
              printf("\033[1;31m");
              printf("%c",219);
              printf("\033[1;33m");
              }
              printf("Male(%d)| Total (%d)",result_male[i],result_total[i]);
              printf("\n");
              printf("\t %c",179);
              for ( l = 0; l < bar_female[i]; ++l)
              {
              printf("\033[1;32m");
              printf("%c",219);
              printf("\033[1;33m");

              }
             printf("Female(%d)|",result_female[i]);
             printf("\n");
             printf("\t %c",179);
             printf("\n");
             printf("\t %c",179);


   }
printf("\n\t V\n\t%s",y);

}

void comparison_04()
{
/*******************************************************************************************************
 This function is used to generate a bar chart according to distribution of capacities of prisons
********************************************************************************************************/
 prr p1;
 FILE *fp3;
 int  no_of_prisons=0;
 int max_bar_value=0;
 int a=1,max_location=0;


    printf("\033[1;34m\n\n\n\t********************************************************");
    printf("    \n\t**\033[1;37mDISTRIBUTION ACCORDING TO THE CAPACITIES OF PRISONS\033[1;34m **");
    printf("    \n\t********************************************************\n\033[1;33m");


 fp3=fopen("DATA\\records\\prison records","rb");
 rewind(fp3);

 while(fread(&p1,sizeof(prr),1,fp3))
 {
    no_of_prisons++;
 }
int capacity[no_of_prisons],prison_id[no_of_prisons],i=0;

            rewind(fp3);
            while(fread(&p1,sizeof(prr),1,fp3))
             {
                 capacity[i]=p1.capacity;
                 prison_id[i]=p1.id;
                 i++;
             }


      int total_capacity=0;
      for(i=0; i<no_of_prisons; i++)
    {
        total_capacity+=capacity[i];
    }

    int presentages[no_of_prisons], bar_values[no_of_prisons];

  for(i=0;i< no_of_prisons;i++){

    fflush(stdin);
    presentages[i]=(float)capacity[i]/total_capacity*100.0;

    bar_values[i]=(presentages[i]/2);

  }
 //Finding the maximum values of arrays

     fflush(stdin);
     for (a = 1; a < no_of_prisons; a++){
     if (bar_values[a] > bar_values[max_location])
      {max_location = a;}}

    max_bar_value=bar_values[max_location];

      int value_to_multiply=0;

      value_to_multiply=(float)50/max_bar_value;

      for(i = 0; i < no_of_prisons; i++)
        {bar_values[i] *= value_to_multiply;

        }

      fp3 = fopen ("DATA\\records\\prison records", "rb" ) ;
      rewind(fp3);

               printf("\n\n---------------------------------------------------------------------");
               printf("\n\t\t***PRISON LIST OF THE SYSTEM***");
               printf("\n---------------------------------------------------------------------");
               printf("\n\tPRISON ID         PRISON NAME             ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3))
                {

                printf("\n--------------------------------------------------------------------");
                printf("\n\t%04d               %s",p1.id,p1.name);

               }
               printf("\n---------------------------------------------------------------------\n");

    printHistogram4(bar_values,capacity,prison_id,no_of_prisons,"Prison capacity","Prison ID");
fclose(fp3);

}

void printHistogram4(int *hist,int *result,int* category,int n,char* x,char* y)
{
/************************************************
 This function is used to generate a bar chart
*************************************************/
      int i, j,k,l=0;
      printf("\n\t %c",179);
      for (k = 0; k < 60; k++){
      printf("%c",196);
      }
      printf(">%s",x);
      printf("\n");
      for (i = 0; i < n; i++) {
      printf("[%04d\t]%c ",category[i],179);
      if(l==8){
        l=0;
      }

      printf("\033[1;%dm",l+30);
      for ( j = 0; j < hist[i]; ++j) {
      printf("%c",219);

      }

      printf("\033[1;33m");
      printf("(%d)",result[i]);
      printf("\n");
      printf("\t %c\n",179);
       l++;
   }

  printf("\t V\n\t%s",y);
}

void comparison_05()
{
/*******************************************************************************************************
 This function is used to generate a bar chart according to distribution of number of cells in prisons
********************************************************************************************************/
 prr p1;
 FILE *fp3;
 int  no_of_prisons=0;

    printf("\033[1;34m\n\n\n\t**********************************************");
    printf("\n\t**\033[1;37mDISTRIBUTION OF NUMBER OF CELLS IN PRISONS\033[1;34m**");
    printf("\n\t**********************************************\n\033[1;33m");

 fp3=fopen("DATA\\records\\prison records","rb");
 rewind(fp3);

 while(fread(&p1,sizeof(prr),1,fp3))
 {
     no_of_prisons++;
 }
int cells[no_of_prisons],prison_id[no_of_prisons],i=0;

            rewind(fp3);
            while(fread(&p1,sizeof(prr),1,fp3))
             {
                 cells[i]=p1.cells;
                 prison_id[i]=p1.id;
                 i++;
             }

      int total_cells=0;
      for(i=0; i<no_of_prisons; i++)
    {
        total_cells+=cells[i];
    }
    int presentages[no_of_prisons], bar_values[no_of_prisons];

  for(i=0;i< no_of_prisons;i++){
    fflush(stdin);
    presentages[i]=(float)cells[i]/total_cells*100.0;
    bar_values[i]=(presentages[i]/2);
  }

 //Finding the maximum values of arrays

 int max_bar_value=0;
 int a=1,max_location=0;
     fflush(stdin);
     for (a = 1; a < no_of_prisons; a++){
     if (bar_values[a] > bar_values[max_location])
      {max_location = a;}}

    max_bar_value=bar_values[max_location];

      int value_to_multiply=0;

      value_to_multiply=(float)50/max_bar_value;

      for(i = 0; i < no_of_prisons; i++)
        {bar_values[i] *= value_to_multiply;

        }

      fp3 = fopen ("DATA\\records\\prison records", "rb" ) ;
      rewind(fp3);

               printf("\n\n---------------------------------------------------------------------");
               printf("\n\t\t***PRISON LIST OF THE SYSTEM***");
               printf("\n---------------------------------------------------------------------");
               printf("\n\tPRISON ID         PRISON NAME             ");
               rewind(fp3);
               while(fread(&p1,sizeof(prr),1,fp3))
                {

                printf("\n--------------------------------------------------------------------");
                printf("\n\t%04d               %s",p1.id,p1.name);

               }
               printf("\n---------------------------------------------------------------------\n");

    printHistogram4(bar_values,cells,prison_id,no_of_prisons,"Number of cells","Prison ID");

fclose(fp3);

}

void settings_menu()
{

  system("cls");
  int ch;
  char choice='Y';
  FILE *fp4;

        if(strcmp(audio_switch,"on")==0)
                {
                mciSendString("close mp3", NULL, 0, NULL);
                mciSendString("open \"DATA\\audio\\a5-settings.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
                mciSendString("play mp3", NULL, 0, NULL);
                }

do{
        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mSETTINGS\033[1;31m\t\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;34mSECURITY SETTINGS\t\033[1;37m[1]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mPENALTY SETTINGS\t\033[1;37m[2]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mAUDIO SETTINGS\t\t\033[1;37m[3]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mCREDIT\t\t\t\033[1;37m[4]\033[1;31m\t\t\t\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\033[1;37m[5]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEXIT\t\t\t\033[1;37m[6]\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch);

       switch(ch)

        {case 1:security_settings(1);
        system("cls");


        break;

         case 2:penalty_settings();
        system("cls");

        break;

         case 3:audio_settings();
        system("cls");

        break;

        case 4:credit();
        system("cls");

        break;

        case 5:main_menu();
        system("cls");

        break;

        case 6:
            exit_screen();
            break;

        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 5.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);

        }

}while(choice=='y'||choice=='Y');

}


void security_settings(int x)
{
system("cls");
ur u1;
char input_pword[100],c,choice;
FILE *fp6,*fp7;
int match=0,k=0;
int ch;

if(x){
       if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a28.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }
  fp6 = fopen( "DATA\\records\\password" , "r");
  rewind(fp6);
  while (fscanf(fp6, "%s", pword)!=EOF)

printf("\n\n\n\n");
printf("\n\t\tACCESSING TO SECURITY SETTINGS");
printf("\n \t\t\033[1;31m---------------------------------------------------------------\033[1;31m");
 k=0;
               if (strcmp(user_type,"\033[1;34mUSER MODE")==0)
                {

                printf("\033[1;31m\n\t\t");
                for (k = 0; k < 74; k++){
                printf("%c",205);}
                printf("  \n\t\t%c                                                                        %c",186,186);
                printf("  \n\t\t%c ONLY SUPER ADMIN OR ANOTHER ADMIN CAN ACCESS TO THE SECURITY SETTINGS. %c",186,186);
                printf("  \n\t\t%c                                                                        %c",186,186);
                printf("  \n\t\t");
                for (k = 0; k < 74; k++){
                printf("%c",205);}
                printf("\033[1;33m");
                printf("\n\n\tPRESS ANY KEY TO EXIT...");

                getch();
                return 0;
                }

 printf("\n\t\t\t\tENTER PASSWORD : ");
printf("\033[1;37m");
    int i=0;
    while(i<100)
	{
	    input_pword[i]=getch();
	    c=input_pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	input_pword[i]='\0';

	i=0;

printf("\n  \t\t\033[1;31m---------------------------------------------------------------\n\033[1;31m");
		//Getting access for the super admin & other admins
match=0;

fp7 = fopen( "DATA\\records\\userslist" , "r");
rewind(fp7);

	while(fread(&u1,sizeof(ur),1,fp7)){

		if(strcmp(pword,input_pword)==0||strcmp(input_pword,u1.pword)==0)
        {
           if(strcmpi(u1.admin_status,"yes")==0)
            {
               match=1;
            }
        }
	}

if(match)
{

    printf("\n \t\t\033[1;32m---------------------------------------------------------------\033[1;31m");
     printf("\n\t\t\t\t\033[1;32m*ACCESS GRANTED*\033[1;33m");
printf("\n \t\t\033[1;32m---------------------------------------------------------------\033[1;33m");

printf("\n\t\t\t\tPRESS ANY KEY TO CONTINUE...\n");
getch();
}
else{
    printf("\033[1;31m");
    printf("\nInvalid password");
    printf("\033[1;33m");
    getch();
    settings_menu();
}

system("cls");
}

choice='Y';

do{
        system("cls");
           if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a31.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }
        printf("\n\n\n\t\033[1;34mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mSECURITY SETTINGS\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mSUPER ADMIN SETTINGS\t\033[1;37m[1]\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mUSER MANAGEMENT\t\t\033[1;37m[2]\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mRESET SYSTEM\t\t\033[1;37m[3]\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO SETTINGS\t\033[1;37m[4]\033[1;34m\t\t\t\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\033[1;37m[5]\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEXIT\t\t\t\033[1;37m[6]\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:super_admin_settings();
        system("cls");

        break;

         case 2:user_management();
        system("cls");

        break;

        case 3:system_reset_menu();
        system("cls");

        break;

        case 4:

        settings_menu();
        system("cls");

        break;

        case 5:
            main_menu();
            break;

        case 6:
            exit_screen();
            break;

        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 6.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);

        }
}while(choice=='y'||choice=='Y');

fclose(fp6);
}

int penalty_settings()
{
system("cls");
    char choice='Y';
    int ch,k=0;
   FILE *fp4,*fp9;
         if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a29.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

 do{
        fp9 = fopen ("DATA\\records\\Death penalty", "r");
        rewind(fp9);
        fscanf(fp9, "%s", death_penalty)!=EOF;
        system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mPENALTY SETTINGS\033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");

            k=0;
               if (strcmp(user_type,"\033[1;34mUSER MODE")==0)
                {

                printf("\033[1;31m\n\t\t");
                for (k = 0; k < 70; k++){
                printf("%c",205);}
                printf("  \n\t\t%c                                                                    %c",186,186);
                printf("  \n\t\t%c  ONLY SUPER ADMIN OR ANOTHER ADMIN CAN CHANGE PENALTY SETTINGS.    %c",186,186);
                printf("  \n\t\t%c                                                                    %c",186,186);
                printf("  \n\t\t");
                for (k = 0; k < 70; k++){
                printf("%c",205);}

                 printf("\033[1;33m");

                printf("\n\n\tPRESS ANY KEY TO EXIT...");
                getch();
                return 0;
                }

        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;31mDEATH PENALTY IS \033[1;33m%s\033[1;37m\t\033[1;37m[1]\033[1;31m\t\t\t|",death_penalty);
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mGO BACK\t\t\t\t\033[1;37m[2]\033[1;31m\t\t\t|\033[1;31m");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");

        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:
                printf("\n\n\t*IS THE DEATH PENALTY AVAILABLE IN YOUR COUNTRY?(Y/N)");
                fflush(stdin);
                scanf(" %c",&choice);
                        if(choice=='y'||choice=='Y')
                        {
                            strcpy(death_penalty,"AVAILABLE");

                            fp9 = fopen ("DATA\\records\\Death penalty", "w");
                            fprintf(fp9, "%s", "AVAILABLE");
                            fclose(fp9);
                            system("cls");
                            penalty_settings();
                            break;
                        }
                         if(choice=='n'||choice=='N')
                        {
                            strcpy(death_penalty,"NOT_AVAILABLE");

                            fp9 = fopen ("DATA\\records\\Death penalty", "w");
                            fprintf(fp9, "%s", "NOT_AVAILABLE");
                            fclose(fp9);
                            system("cls");
                            penalty_settings();
                            break;
                        }
                        choice='y';

                        break;

         case 2:settings_menu();
                system("cls");

        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 5.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);

        }
}while(choice=='y'||choice=='Y');
  fclose(fp4);

}

void super_admin_settings()
{

 char choice='Y';
 int ch,k=0;
 FILE *fp4;
    if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a32.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

do{
        system("cls");
        printf("\n\n\n\t\033[1;34mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mSUPER ADMIN SETTINGS\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");

        k=0;
               if (strcmp(user_type,"\033[1;34mUSER MODE")==0||strcmp(user_type,"\033[1;31mADMIN MODE")==0)
                {
                printf("\033[1;31m\n\t\t");
                for (k = 0; k < 63; k++){
                printf("%c",205);}
                printf("  \n\t\t%c                                                             %c",186,186);
                printf("  \n\t\t%c   ONLY SUPER ADMIN CAN ACCESS TO THE SUPER ADMIN SETTINGS   %c",186,186);
                printf("  \n\t\t%c                                                             %c",186,186);
                printf("  \n\t\t");
                for (k = 0; k < 63; k++){
                printf("%c",205);}
                printf("\033[1;33m");
                printf("\n\n\tPRESS ANY KEY TO EXIT...");
                getch();
                return 0;
                }

        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mCHANGE SUPER ADMIN USERNAME\t\033[1;37m[1]\033[1;34m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mCHANGE SUPER ADMIN PASSWORD\t\033[1;37m[2]\033[1;34m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mGO BACK\t\t\t\t\033[1;37m[3]\033[1;34m\t\t\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\t\033[1;37m[4]\033[1;34m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEXIT\t\t\t\t\033[1;37m[5]\033[1;34m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:change_username();
        system("cls");

        break;

         case 2:change_password();
        system("cls");

        break;

        case 3:security_settings(0);
        system("cls");

        break;

        case 4:
            main_menu();
            break;

        case 5:
            exit_screen();
            break;

        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 5.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);

        }
}while(choice=='y'||choice=='Y');
fclose(fp4);

}


void user_management()
{

char choice='Y';
int ch;
FILE *fp4;
   if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a33.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

do{
        system("cls");
        printf("\n\n\n\t\033[1;34mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mUSER MANAGEMENT MENU\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mADD NEW USERS\t\t\033[1;37m[1]\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mSEARCH USERS \t\t\033[1;37m[2]\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEDIT USER DETAILS\t\033[1;37m[3]\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mREMOVE USERS \t\t\033[1;37m[4]\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mVIEW USERS LIST \t\033[1;37m[5]\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mGO BACK\t\t\t\033[1;37m[6]\033[1;34m\t\t\t\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\033[1;37m[7]\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEXIT\t\t\t\033[1;37m[8]\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:add_users();

        break;

        case 2:search_users();

        break;

         case 3:edit_users();

        break;

        case 4:delete_users();

        break;

        case 5:view_users();

        break;

        case 6:security_settings(0);

        break;

        case 7:
            main_menu();
            break;

        case 8:
            exit_screen();
            break;

        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 5.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);

        }
}while(choice=='y'||choice=='Y');


fclose(fp4);

}


void add_users()
{
/*********************************************************
**This function is used to add new user details
*********************************************************/
    system("cls");
    ur u1;
    FILE *fp7,*fp4;
    char another = 'Y';
    char id[10];
    int choice,k=0;
    char username[50],password[50];

       if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a34.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    system("cls");
        printf("\n\n\n\t\033[1;37mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mADD USERS\033[1;34m\t\t\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;33m");

        k=0;
               if (strcmp(user_type,"\033[1;34mUSER MODE")==0||strcmp(user_type,"\033[1;31mADMIN MODE")==0)
                {

                printf("\033[1;31m\n\t\t");
                for (k = 0; k < 63; k++){
                printf("%c",205);}
                printf("  \n\t\t%c                                                             %c",186,186);
                printf("  \n\t\t%c     ONLY SUPER ADMIN CAN ADD,EDIT OR DELETE USER RECORDS.   %c",186,186);
                printf("  \n\t\t%c                                                             %c",186,186);
                printf("  \n\t\t");
                for (k = 0; k < 63; k++){
                printf("%c",205);}
                printf("\033[1;33m");
                printf("\n\n\tPRESS ANY KEY TO EXIT...");
                getch();
                return 0;
                }

    fp7 = fopen ("DATA\\records\\userslist", "ab+" ) ;
     if ( fp7 == NULL )
    {
        fp7=fopen("DATA\\records\\userslist","wb+");
        if(fp7==NULL)
        {
            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return ;
        }
    }
    while ( another == 'Y'|| another=='y' )
    {
        choice=0;
        fflush(stdin);
printf("\n\033[1;34m-------------------------------------------------------------------------------------------\033[1;33m");
		printf ( "\n\tENTER USER ID:\t");
		printf("\033[1;37m");
        scanf("%s",&id);
        rewind(fp7);

        while(!valid_user_ID(id))
        {
            fflush(stdin);
            printf("\033[1;33m");
            printf ( "\n\tENTER USER ID:\t");
            printf("\033[1;37m");
            scanf("%s",&id);
            rewind(fp7);
        }

        while(fread(&u1,sizeof(ur),1,fp7)==1)
        {
            if(u1.user_id==valid_user_ID(id))
            {
                printf("\033[1;31m");
                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                choice=1;
                printf("\033[1;33m");
            }
        }

        if(choice==0)
        {

            u1.user_id=valid_user_ID(id);
            fflush(stdin);
printf("\n\033[1;34m-------------------------------------------------------------------------------------------\033[1;33m");
            printf("\n\tENTER USERNAME: ");
           printf("\033[1;37m");
           fflush(stdin);
            gets(u1.uname);

            while(!valid_username(u1.uname))
        {
            printf("\033[1;33m");
            printf("\n\tENTER USERNAME: ");
            printf("\033[1;37m");
            fflush(stdin);
            gets(u1.uname);
        }
 printf("\n\033[1;34m-------------------------------------------------------------------------------------------\033[1;33m");
            printf("\n\tENTER PASSWORD: ");
            printf("\033[1;37m");
            fflush(stdin);
            gets(u1.pword);

            while(!valid_password(u1.pword))
        {
           printf("\033[1;33m");
            printf("\n\tENTER PASSWORD: ");
            printf("\033[1;37m");
            gets(u1.pword);
            fflush(stdin);
        }

printf("\n\033[1;34m-------------------------------------------------------------------------------------------\033[1;33m");

			printf("\n\tENTER ADMIN STATUS(YES/NO): ");
			fflush(stdin);
			printf("\033[1;37m");
            scanf("%s",&u1.admin_status);

            while(!strcmpi(u1.admin_status,"yes")==0&&!strcmpi(u1.admin_status,"no")==0)
        {
            printf("\033[1;31m");
            printf("\n\t*Please enter \"YES\"or\"NO\"...");
            printf("\033[1;33m");
            printf("\n\tENTER ADMIN STATUS(Y/N): ");
            printf("\033[1;37m");
            fflush(stdin);
            scanf("%s",&u1.admin_status);
        }

 printf("\n\033[1;34m-------------------------------------------------------------------------------------------\033[1;33m");

            printf("\033[1;32m");
            printf("\n\033[1;32mNEW USER HAS ADDED SUCCESFULLY...\033[1;33m\n");

            printf("\033[1;33m");
            printf("\n\n\tHERE IS THE USER DETAILS, YOU HAVE ADDED ...\n");
                printf("\n");
                printf("\n");
                printf("\n\t\033[1;34m********************************************************");
                printf("\n\t*********** \033[1;33mUSER ID:\033[1;37m %04d\033[1;31m ***********",u1.user_id);
                printf("\n\t\033[1;34m********************************************************\033[1;33m");
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n\t\tUSERNAME : \t\033[1;37m %s  \033[1;33m   ",u1.uname);
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n\t\tPASSWORD :\t \033[1;37m%s \033[1;33m",u1.pword);
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                 if(strcmpi(u1.admin_status,"yes")==0)

                {
                printf("\n\t\tUSER ROLE :\t\033[1;31m ADMIN \033[1;33m");
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");
                }
                else
                {
                printf("\n\t\tUSER ROLE :\t\033[1;32m NORMAL USER \033[1;33m");
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");
                }

                printf("\n");

            fwrite ( &u1, sizeof ( ur ), 1, fp7 ) ;
        }

        printf ( "\n\tADD ANOTHER USER...?(Y/N) \t" ) ;
        fflush ( stdin );
        another = getch( );
    }

    fclose ( fp7 ) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();

}

void search_users()
{
 system("cls");
/*********************************************************
**This function is used to search user details
*********************************************************/
	ur u1;
    FILE *fp7,*fp4;
	char choice,userslist[3000];
    int ch,found=0,id=0;

      if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a35.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

    do
	{
        system("cls");
        printf("\n\n\n\t\033[1;37mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mSEARCH USERS\033[1;34m\t\t\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;33m");


        fp7 = fopen ( "DATA\\records\\userslist", "r" );

            printf("\033[1;33m");
    		printf("\n\n\t\tENTER USER ID:");
    		printf("\033[1;37m");
            fflush(stdin);
            scanf("%d",&id);
            system("cls");
            printf("\nTHE WHOLE RECORD IS:");

            while ( fread ( &u1, sizeof ( ur ), 1, fp7 ))

          {
          if(u1.user_id==id)
               {
                found=1;
                printf("\n");
                printf("\n");

                printf("\n\t\033[1;34m********************************************************");
                          printf("\n\t*********** \033[1;33mUSER ID:\033[1;37m %04d\033[1;31m ***********",u1.user_id);
                printf("\n\t\033[1;34m********************************************************\033[1;33m");
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n\t\tUSERNAME : \t\033[1;37m %s  \033[1;33m   ",u1.uname);
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                if(strcmp(user_type,"\033[1;33mSUPER ADMIN MODE")==0){
                printf("\n\t\tPASSWORD :\t \033[1;37m%s \033[1;33m",u1.pword);
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                }

                 if(strcmpi(u1.admin_status,"yes")==0)

                {
                printf("\n\t\tUSER ROLE :\t\033[1;31m ADMIN \033[1;33m");
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");
                }
                else
                {
                printf("\n\t\tUSER ROLE :\t\033[1;32m NORMAL USER \033[1;33m");
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");
                }
            }
          }
            if(!found){
                 printf("\033[1;31m");
                 printf("\nTHE RECORD DOES NOT EXIST.\n");
                 printf("\033[1;33m");
           }
        printf("\n\nWOULD YOU LIKE TO SEARCH ANOTHER USER..?(Y/N):");
        fflush(stdin);

        scanf(" %c",&choice);
    }
    while(choice=='Y'||choice=='y');

    fclose(fp7) ;
	getch();
    return ;
}

void edit_users()
{
/*********************************************************
**This function is used to edit new user details
*********************************************************/
  system("cls");
    ur u1;
    FILE *fp7,*fp4;
    char search_uname[100];
    int id,num,choice,k=0;

     if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a36.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }
   system("cls");
        printf("\n\n\n\t\033[1;37mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mEDIT USER DETAILS\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");

    do
    {
         k=0;
               if (strcmp(user_type,"\033[1;34mUSER MODE")==0||strcmp(user_type,"\033[1;31mADMIN MODE")==0)
                {

                printf("\033[1;31m\n\t\t");
                for (k = 0; k < 63; k++){
                printf("%c",205);}
                printf("  \n\t\t%c                                                             %c",186,186);
                printf("  \n\t\t%c     ONLY SUPER ADMIN CAN ADD,EDIT OR DELETE USER RECORDS.   %c",186,186);
                printf("  \n\t\t%c                                                             %c",186,186);
                printf("  \n\t\t");
                for (k = 0; k < 63; k++){
                printf("%c",205);}

                 printf("\033[1;33m");
                printf("\n\n\tPRESS ANY KEY TO EXIT...");
                getch();
                return 0;

                }

        fp7 = fopen ( "DATA\\records\\userslist", "rb+" ) ;

        printf("\033[1;33m");
        fflush(stdin);
        printf("\n\tENTER USER ID:");
        printf("\033[1;37m");
    	scanf("%d",&id);


        while ( fread ( &u1, sizeof ( ur ), 1, fp7 ) == 1 )
        {

            if(u1.user_id==id)
        {

                printf("\n");
                printf("\n");

                printf("\n\t\033[1;34m********************************************************");
                          printf("\n\t*********** \033[1;33mUSER ID:\033[1;37m %04d\033[1;31m ***********",u1.user_id);
                printf("\n\t\033[1;34m********************************************************\033[1;33m");
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n\t\tUSERNAME : \t\033[1;37m %s  \033[1;33m   ",u1.uname);
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n\t\tPASSWORD :\t \033[1;37m%s \033[1;33m",u1.pword);
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                 if(strcmpi(u1.admin_status,"yes")==0)

                {
                printf("\n\t\tUSER ROLE :\t\033[1;31m ADMIN \033[1;33m");
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");
                }
                else
                {
                printf("\n\t\tUSER ROLE :\t\033[1;32m NORMAL USER \033[1;33m");
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");
                }

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..\n\n");
                printf("\n\t\033[1;31m1.\033[1;37mUSER ID");
                printf("\n\t\033[1;31m2.\033[1;37mUSERNAME");
                printf("\n\t\033[1;31m3.\033[1;37mPASSWORD");
                printf("\n\t\033[1;31m4.\033[1;37mADMIN STATUS");
                printf("\n\t\033[1;31m5.\033[1;34mALL THE DETAILS");

                printf("\n\n\t\t\033[1;31m6.\033[1;32mGO BACK TO USER MANAGEMENT MENU.\033[1;33m");

                do
                {
                  printf("\n\n\n\tENTER YOUR CHOICE:");
                    fflush(stdin);

                printf("\033[1;37m");
                    scanf("%d",&num);
                    fflush(stdin);

                    switch(num)
                    {

                    case 1:
printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");

                        printf("\nENTER THE NEW DATA: ");
                        printf ( "\n\tENTER USER ID:\t");
                        printf("\033[1;37m");
                        scanf(" %s",&id);
                        rewind(fp7);

        while(!valid_user_ID(id))
        {
            fflush(stdin);
            printf("\033[1;33m");
            printf ( "\n\tENTER USER ID:\t");
            printf("\033[1;37m");
            scanf(" %s",&id);
            rewind(fp7);
        }

        u1.user_id=valid_user_ID(id);
                        break;

                    case 2:
printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\tENTER USERNAME: ");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(u1.uname);

            while(!valid_username(u1.uname))
        {
           printf("\033[1;33m");
            printf("\n\tENTER USERNAME: ");
            fflush(stdin);
            printf("\033[1;37m");
            gets(u1.uname);

        }
                        break;

                    case 3:
printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
            printf("\n\tENTER PASSWORD: ");
            printf("\033[1;37m");
            gets(u1.pword);
            fflush(stdin);
            while(!valid_password(u1.pword))
        {
            printf("\033[1;33m");
            printf("\n\tENTER PASSWORD: ");
            fflush(stdin);
            printf("\033[1;37m");
            gets(u1.pword);

        }
                        break;

                    case 4:
printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                       printf("\n\tENTER ADMIN STATUS(YES/NO): ");
			fflush(stdin);
			printf("\033[1;37m");
            scanf("%s",&u1.admin_status);

            while(!strcmpi(u1.admin_status,"yes")==0&&!strcmpi(u1.admin_status,"no")==0)
        {
            printf("\033[1;31m");
            printf("\n\t*Please enter \"YES\"or\"NO\"...");
            printf("\033[1;33m");
            printf("\n\tENTER ADMIN STATUS(Y/N): ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%s",&u1.admin_status);

        }
                        break;

                    case 5:
printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA: ");
                        printf ( "\n\tENTER USER ID:\t");
                        printf("\033[1;37m");
                        scanf(" %s",&id);
                        rewind(fp7);

        while(!valid_user_ID(id))
        {
            printf("\033[1;33m");
            printf ( "\n\tENTER USER ID:\t");
            printf("\033[1;37m");
            fflush(stdin);
            scanf(" %s",&id);
        }

        u1.user_id=valid_user_ID(id);

printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                        printf("\n\tENTER USERNAME: ");
                        fflush(stdin);
                        printf("\033[1;37m");
                        gets(u1.uname);

            while(!valid_username(u1.uname))
        {
            printf("\033[1;33m");
            printf("\n\tENTER USERNAME: ");
            fflush(stdin);
            printf("\033[1;37m");
            gets(u1.uname);
        }

printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
            printf("\n\tENTER PASSWORD: ");
            fflush(stdin);
            printf("\033[1;37m");
            gets(u1.pword);
            while(!valid_password(u1.pword))
        {
            printf("\033[1;33m");
            printf("\n\tENTER PASSWORD: ");
            printf("\033[1;37m");
            gets(u1.pword);
            fflush(stdin);
        }


printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\nENTER THE NEW DATA:");
                       printf("\n\tENTER ADMIN STATUS(YES/NO): ");
			fflush(stdin);
			printf("\033[1;37m");
            scanf("%s",&u1.admin_status);

            while(!strcmpi(u1.admin_status,"yes")==0&&!strcmpi(u1.admin_status,"no")==0)
        {
            printf("\033[1;31m");
            printf("\n\t*Please enter \"YES\"or\"NO\"...");
            printf("\033[1;33m");
            printf("\n\tENTER ADMIN STATUS(Y/N): ");
            fflush(stdin);
            printf("\033[1;37m");
            scanf("%s",&u1.admin_status);
        }

                    case 6:
printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");

                        return ;
                        break;


                    default:
 printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                        printf("\033[1;31m");
                        printf("\nYOU HAVE ENTERD SOMETHING ELSE...PLEASE ENTER A CORRECT CHOICE\n");
                        printf("\033[1;33m");
                        break;

                    }
                }
                while(num<1||num>6);
                fseek(fp7,-sizeof(ur),SEEK_CUR);
                fwrite(&u1,sizeof(ur),1,fp7);
                fseek(fp7,-sizeof(ur),SEEK_CUR);
                fread(&u1,sizeof(ur),1,fp7);
                choice=5;
                break;
           }
        }

if(choice==5)
    {
            system("cls");
            printf("\n");
                printf("\n");

                printf("\n\t\033[1;34m********************************************************");
                          printf("\n\t*********** \033[1;33mUSER ID:\033[1;37m %04d\033[1;31m ***********",u1.user_id);
                printf("\n\t\033[1;34m********************************************************\033[1;33m");
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n\t\tUSERNAME : \t\033[1;37m %s  \033[1;33m   ",u1.uname);
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                printf("\n\t\tPASSWORD :\t \033[1;37m%s \033[1;33m",u1.pword);
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");
                 if(strcmpi(u1.admin_status,"yes")==0)

                {
                printf("\n\t\tUSER ROLE :\t\033[1;31m ADMIN \033[1;33m");
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");
                }
                else
                {
                printf("\n\t\tUSER ROLE :\t\033[1;32m NORMAL USER \033[1;33m");
                printf("\n\033[1;34m-----------------------------------------------------------------------------------------------------\033[1;33m");

                printf("\n");
                }
            fclose(fp7);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER USER DETAILS...?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);
          }

        else
        {
            printf("\033[1;31m");
            printf("\nUSER DOES NOT EXIST::\n");
            printf("\033[1;33m");
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
            fflush(stdin);
        	scanf(" %c",&choice);

        }
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp7 ) ;
    printf("\n\tPRESS ENTER TO EXIT......");
    getch();

}

void view_users()
{
/*********************************************************
**This function is used to view user details
*********************************************************/
    FILE *fp7,*fp4;
    ur u1;
    int SUPER_ADMIN=0,count_normal_users=0,count_admin=0,found=0;
    char userslist[3000];

       if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a37.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

   system("cls");
        printf("\n\n\n\t\033[1;34mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mLIST OF USERS\033[1;34m\t\t\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");

printf("\n\n  \t\033[1;34m------------------------------------------------------------------\033[1;34m");

      fp7 = fopen ( "DATA\\records\\userslist", "rb" ) ;
      rewind(fp7);

     while(fread(&u1,sizeof(ur),1,fp7))
        {
         if(strcmpi(u1.admin_status,"yes")==0)
            {
                found=1;
                count_admin++;
          printf("\033[1;33m ");
          printf("\n\tUSER ID :\033[1;37m %04d \033[1;33m \n\tUSERNAME :\033[1;37m %s \033[1;33m \n\tUSER ROLE : \033[1;31mADMIN\033[1;33m",u1.user_id,u1.uname);

             if(strcmp(user_type,"\033[1;33mSUPER ADMIN MODE")==0)
                {
                 printf("\n\tPASSWORD : \033[1;32m%s", u1.pword);
                }

        printf("\n  \t\033[1;34m------------------------------------------------------------------\033[1;34m");
            }
          if(strcmpi(u1.admin_status,"no")==0)
            {
                found=1;
                count_normal_users++;

                printf("\033[1;33m ");
         printf("\n\tUSER ID :\033[1;37m %04d  \033[1;33m\n\tUSERNAME :\033[1;37m %s \033[1;33m \n\tUSER ROLE : \033[1;32mNORMAL USER\033[1;33m",u1.user_id,u1.uname);
             if(strcmp(user_type,"\033[1;33mSUPER ADMIN MODE")==0)
                {
                 printf("\n\tPASSWORD :\033[1;32m %s",u1.pword );
                }
                printf("\n  \t\033[1;34m------------------------------------------------------------------\033[1;34m");
          }
        }
if(found){
        printf("\n\033[1;37m\tTHERE ARE \033[1;32m%d\033[1;31m ADMIN/ADMINS\033[1;37m AND\033[1;32m %d\033[1;32m NORMAL USERS.",count_admin,count_normal_users);
         }
    else{
        printf("\n\033[1;37m\tTHERE ARE NO OTHER USERS.");
       }
        printf("\n\033[1;31m\tNote:- Only super admin can see user passwords.");

    printf("\n\n\t\033[1;33m PRESS ANY KEY TO EXIT... ");
    getch();

 fclose ( fp7 ) ;
}

void delete_users()
{
/*********************************************************
This function is used to delete users from the system
*********************************************************/
 system("cls");
    ur u1;
    FILE *fp7,*ft7,*fp6,*fp4;
    char input_pword[50],c;
    char another = 'Y';
    int choice,check,id;
    int j=0,found=0,k=0;

       if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a38.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

   system("cls");
        printf("\n\n\n\t\033[1;37mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mREMOVE USERS\033[1;34m\t\t\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\033[1;33m");

         k=0;
               if (strcmp(user_type,"\033[1;34mUSER MODE")==0||strcmp(user_type,"\033[1;31mADMIN MODE")==0)
                {

                printf("\033[1;31m\n\t\t");
                for (k = 0; k < 63; k++){
                printf("%c",205);}
                printf("  \n\t\t%c                                                             %c",186,186);
                printf("  \n\t\t%c     ONLY SUPER ADMIN CAN ADD,EDIT OR DELETE USER RECORDS.   %c",186,186);
                printf("  \n\t\t%c                                                             %c",186,186);
                printf("  \n\t\t");
                for (k = 0; k < 63; k++){
                printf("%c",205);}
                printf("\033[1;33m");
                printf("\n\n\tPRESS ANY KEY TO EXIT...");
                getch();
                return 0;

                }

   fp6 = fopen( "DATA\\records\\password" , "r");
   while (fscanf(fp6, "%s", pword)!=EOF)

 printf("\n\n\tENTER PASSWORD");
  printf("\n\t");
 printf("\033[1;37m");
    int i=0;
    while(i<50)
	{
	    input_pword[i]=getch();
	    c=input_pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	input_pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(pword,input_pword)==0)
     {
printf("\033[1;32m");
printf("\n  \033[1;32m---------------------------------------------------------------\033[1;32m");
     printf("\n\t\t*ACCESS GRANTED*");
printf("\n  \033[1;32m---------------------------------------------------------------\033[1;33m");
   while ( another == 'Y' || another == 'y' )

    {

    	/*printf("\n\tENTER THE NAME OF PRISONER TO BE DELETED:");
		fflush(stdin);
        gets(prisoner records);*/
        fp7 = fopen ("DATA\\records\\userslist", "r" ) ;
        if ( fp7 == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXIST");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getch();
                    return ;
				}
				ft7=fopen("DATA\\records\\temp","w");

				if(ft7==NULL)
                {
                	printf("\nSYSTEM ERROR");
                    printf("\nPRESS ANY KEY TO GO BACK");
                    getch();
                    return ;
                }
                printf("\033[1;33m");
                printf("\n\tENTER THE ID OF THE USER TO BE DELETED:");
                fflush(stdin);
                printf("\033[1;37m");
                scanf("%d",&id);
                rewind(fp7);

        		while(fread(&u1,sizeof(ur),1,fp7)==1)
                {

                    if(u1.user_id==id)
                        {
                            found=1;
                        }
                    else

                     fwrite(&u1,sizeof(ur),1,ft7);
                }

        fclose(fp7);
        fclose(ft7);
        fclose(fp6);

        if(found)
            {
                ft7=fopen("DATA\\records\\temp","r");
                fp7=fopen("DATA\\records\\userslist","w");
                while(fread(&u1,sizeof(ur),1,ft7))
                {
                    fwrite(&u1,sizeof(ur),1,fp7);
                }
        fclose(fp7);
        fclose(ft7);

            printf("\033[1;32m");
        printf("\nDELETED SUCCESFULLY...");
         printf("\033[1;33m");
                   getch();

            }

       else{
              printf("\033[1;31m");
             printf("ID IS INCORRECT");
              printf("\033[1;33m");
             getch();
             }

        remove("DATA\\records\\temp");
        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        fflush(stdin);
        scanf(" %c",&another);

               }

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

     }
	else
	{
		printf("\nSorry!Invalid password\n");
    }
		getch();

fclose ( fp7 );
}

void audio_settings()
{
system("cls");
char choice;
char audio_settings[3000];
int size,len;
FILE *fp4;
int k=0;
if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a30.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

system("cls");
        printf("\n\n\n\t\033[1;37mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37mAUDIO SETTINGS\033[1;31m\t\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");
        printf("\033[1;33m");


fp4 = fopen( "DATA\\records\\audio" , "r");
    while (fscanf(fp4, "%s", audio_switch)!=EOF)

                                                printf("\033[1;31m\n\n\n\t\t");
                                                for (k = 0; k < 57; k++){
                                                printf("%c",205);}
                                                printf("  \n\t\t%c                                                       %c",186,186);

                                                printf("  \n\t\t%c  \033[1;37m\t\tSYSTEM AUDIO : \033[1;33m %s\033[1;31m \t\t\t%c",186,audio_switch,186);
                                                printf("  \n\t\t%c                                                       %c",186,186);
                                                printf("  \n\t\t");
                                                for (k = 0; k < 57; k++){
                                                printf("%c",205);}
                                                printf("\033[1;33m");


                      if (strcmp(audio_switch,"on")==0){
                             printf("\n\n\DO YOU WANT TO TURN OFF SYSTEM SOUNDS?(Y/N)");
                             scanf(" %c",&choice);

                               if (choice =='Y'||choice=='y'){
                                     strcpy(audio_switch,"off");
                                    /* remove("audio");*/
                                     fp4 = fopen ("audio", "w");
                                     fprintf(fp4, "%s", "off");
                                     fclose(fp4);

                                            printf("\033[1;31m\n\t\t");
                                            for (k = 0; k < 57; k++){
                                            printf("%c",205);}
                                            printf("  \n\t\t%c                                                       %c",186,186);

                                            printf("  \n\t\t%c  \033[1;37m\t\tSYSTEM AUDIO : \033[1;31m %s\033[1;31m \t\t\t%c",186,audio_switch,186);
                                            printf("  \n\t\t%c                                                       %c",186,186);
                                            printf("  \n\t\t");
                                            for (k = 0; k < 57; k++){
                                            printf("%c",205);}
                                            printf("\033[1;33m");

                                     printf("\n\n\tPRESS ANY KEY TO EXIT");
                                     getch();
                                     settings_menu();
                                     }
                                    else{
                                            printf("\033[1;31m\n\t\t");
                                            for (k = 0; k < 57; k++){
                                            printf("%c",205);}
                                            printf("  \n\t\t%c                                                       %c",186,186);

                                            printf("  \n\t\t%c  \033[1;37m\t\tSYSTEM AUDIO  : \033[1;32m %s\033[1;31m\t\t\t%c",186,audio_switch,186);
                                            printf("  \n\t\t%c                                                       %c",186,186);
                                            printf("  \n\t\t");
                                            for (k = 0; k < 57; k++){
                                            printf("%c",205);}
                                            printf("\033[1;33m");

                                     printf("\n\n\tPRESS ANY KEY TO EXIT");
                                    getch();
                                    settings_menu();
                                }
                       }

                  else
                      if (strcmp(audio_switch,"off")==0){
                             printf("\n\n\DO YOU WANT TO TURN ON SYSTEM SOUNDS?(Y/N)");
                             scanf(" %c",&choice);

                               if (choice =='Y'||choice=='y'){
                                     strcpy(audio_switch,"on");
                                     fp4 = fopen ("audio", "w");
                                     fprintf(fp4, "%s", "on");
                                     fclose(fp4);
                                      printf("\033[1;31m\n\t\t");
                                            for (k = 0; k < 57; k++){
                                            printf("%c",205);}
                                            printf("  \n\t\t%c                                                       %c",186,186);

                                            printf("  \n\t\t%c  \033[1;37m\t\tSYSTEM AUDIO  : \033[1;32m %s\033[1;31m\t\t\t%c",186,audio_switch,186);
                                            printf("  \n\t\t%c                                                       %c",186,186);
                                            printf("  \n\t\t");
                                            for (k = 0; k < 57; k++){
                                            printf("%c",205);}
                                            printf("\033[1;33m");

                                    printf("\n\n\tPRESS ANY KEY TO EXIT");
                                    getch();
                                    settings_menu();

                                     }
                                    else{
                                            printf("\033[1;31m\n\t\t");
                                            for (k = 0; k < 57; k++){
                                            printf("%c",205);}
                                            printf("  \n\t\t%c                                                       %c",186,186);

                                            printf("  \n\t\t%c  \033[1;37m\t\tSYSTEM AUDIO : \033[1;31m %s\033[1;31m \t\t\t %c",186,audio_switch,186);
                                            printf("  \n\t\t%c                                                       %c",186,186);
                                            printf("  \n\t\t");
                                            for (k = 0; k < 57; k++){
                                            printf("%c",205);}
                                            printf("\033[1;33m");

                                    printf("\n\n\tPRESS ANY KEY TO EXIT");
                                    getch();
                                    settings_menu();

                                }
                       }

           fclose(fp4);
        printf("\nPRESS ANY KEY TO EXIT");
        getch();
        settings_menu();
}

void system_reset_menu()
{

system("cls");
FILE *fp3,*fp4;
int size=0,k=0;
char choice='Y';
int ch;

                if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a39.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }
               if (strcmp(user_type,"\033[1;34mUSER MODE")==0||strcmp(user_type,"\033[1;31mADMIN MODE")==0)
                {

                printf("\033[1;31m\n\t\t");
                for (k = 0; k < 48; k++){
                printf("%c",205);}
                printf("  \n\t\t%c                                              %c",186,186);
                printf("  \n\t\t%c     ONLY SUPER ADMIN CAN RESET THE SYSTEM.   %c",186,186);
                printf("  \n\t\t%c                                              %c",186,186);
                printf("  \n\t\t");
                for (k = 0; k < 48; k++){
                printf("%c",205);}
                printf("\033[1;33m");
                printf("\n\n\tPRESS ANY KEY TO EXIT...");

                 getch();
                 return 0;

                }

fp3 = fopen("DATA\\records\\prison records", "r");
if (fp3!=NULL)
	{
		fseek (fp3, 0, SEEK_END);
		size = ftell(fp3);
		//printf("Size of the file in bytes: &#37;lu\n", size);
	}

if (size == 0){
    printf("\033[1;31m");
    printf("\n\t*Before reset the system,You have to added prison details to this system.\n\t Go to the \"prison records\" in the main menu and add prison details to the system");
    printf("\033[1;33m");
    printf("\n\n\tPRESS ANY KEY TO GO BACK TO THE MAIN MENU....");
    getch();
    main_menu();
}

         if(strcmp(audio_switch,"on")==0)
    {

    }

do{

        system("cls");
        printf("\n\n\n\t\033[1;34mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mSYSTEM RESET MENU\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mRESET PRISONER DETAILS\t\t\033[1;37m[1]\033[1;34m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mRESET STAFF MEMBER DETAILS\t\033[1;37m[2]\033[1;34m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mRESET WHOLE SYSTEM\t\t\033[1;37m[3]\033[1;34m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mRESET USERS LIST\t\t\033[1;37m[4]\033[1;34m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mGO BACK\t\t\t\t\033[1;37m[5]\033[1;34m\t\t\t|");
		printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mBACK TO MAIN MENU\t\t\033[1;37m[6]\033[1;34m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\t\033[1;33mEXIT\t\t\t\t\033[1;37m[7]\033[1;34m\t\t\t|");
        printf("\n  \t\t|\t\t\t\t\t\t\t\t|\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;33m");
        printf("\n\n\n\tENTER YOUR CHOICE:");
        fflush(stdin);
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:reset_prisoner_details();
        system("cls");

        break;

         case 2:reset_staff_member_details();
        system("cls");

        break;

          case 3:
        reset_whole_system();
        system("cls");
        break;

         case 4:
        reset_user_details();
        system("cls");
        break;


        case 5:
           security_settings(0);
            break;

        case 6:
            main_menu();
            break;

        case 7:
            exit_screen();
            break;

        default:
            printf("\nINVALID CHOICE.PLEASE ENTER A NUMBER FROM 1 TO 6.");
            printf("\nDO YOU WANT TO TRY AGAIN?(Y/N)");
            fflush(stdin);
            scanf(" %c",&choice);
        }

}while(choice=='y'||choice=='Y');

}

void reset_prisoner_details()
{
/*******************************************************************
This function is used to remove all prisoner details from the system
*********************************************************************/
  char ch;
  system("cls");
  FILE *fp4;

   if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a40.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

        system("cls");
        printf("\n\n\n\t\033[1;34mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mRESET PRISONER DETAILS\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;31m");
printf("\n\t\tWARNING!!!)");
printf("\033[1;37m");
printf("\n\n\tDO YOU WANT TO DELETE WHOLE PRISONER RECORDS FROM THE SYSTEM?(Y/N)");
printf("\033[1;31m");
scanf(" %c",&ch);
printf("\033[1;33m");
if(ch=='Y'||ch=='y')
{
   remove("DATA\\records\\prisoner records");
   printf("\033[1;32m");
   printf("\n\tPRISONER RECORDS DELETED SUCCESFULLY");
   printf("\033[1;33m");

}
printf("\n\t\033[1;33mPRESS ANY KEY TO EXIT");
   getch();
}

void reset_staff_member_details()
{
/*******************************************************************
This function is used to remove all staff member details from the system
*********************************************************************/
  char ch;
  system("cls");
  FILE *fp4;

       if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a41.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }
        system("cls");
        printf("\n\n\n\t\033[1;34mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mRESET STAFF MEMBER DETAILS\033[1;34m\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;31m");

printf("\n\t\tWARNING!!!)");
printf("\033[1;37m");
printf("\n\n\tDO YOU WANT TO DELETE WHOLE STAFF MEMBER RECORDS FROM THE SYSTEM?(Y/N)");
printf("\033[1;31m");
scanf(" %c",&ch);
printf("\033[1;33m");
if(ch=='Y'||ch=='y')
{
   remove("DATA\\records\\staff member records");
   printf("\033[1;32m");
   printf("\n\tSTAFF MEMBER RECORDS DELETED SUCCESFULLY");
   printf("\033[1;33m");
}


printf("\n\t\033[1;33mPRESS ANY KEY TO EXIT");
   getch();

}

void reset_user_details()
{
/*******************************************************************
This function is used to remove all user details from the system
*********************************************************************/
  char ch;
  system("cls");
  FILE *fp4;

      if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a42.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

        system("cls");
        printf("\n\n\n\t\033[1;34mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mRESET USER DETAILS\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;31m");
printf("\n\t\tWARNING!!!)");
printf("\033[1;37m");
printf("\n\n\tDO YOU WANT TO DELETE WHOLE USER LIST FROM THE SYSTEM?(Y/N)");
printf("\033[1;31m");
scanf(" %c",&ch);
printf("\033[1;33m");
if(ch=='Y'||ch=='y')
        {
           remove("DATA\\records\\users_list");
           printf("\033[1;32m");
           printf("\n\tPRISON RECORDS DELETED SUCCESFULLY");
           printf("\033[1;33m");

        }
printf("\n\t\033[1;33mPRESS ANY KEY TO EXIT");
getch();

}

void reset_whole_system()
{
/*******************************************************************
This function is used to remove all details from the system
*********************************************************************/
char ch;
system("cls");
FILE *fp4;

       if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a43.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }
        system("cls");
        printf("\n\n\n\t\033[1;34mSYSTEM AUDIO= \033[1;32m%s",audio_switch);printf("\t\t\t%s",user_type);
        printf("\n\t\t\033[1;34m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;34m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;34m");
        printf("\n  \t\t|\t\t\033[1;37mRESET WHOLE SYSTEM\033[1;34m\t\t\t\t|");
        printf("\n  \t\t|\033[1;34m---------------------------------------------------------------|\033[1;31m");
printf("\n\t\tWARNING!!!)");
printf("\n\n\tDO YOU WANT TO DELETE WHOLE RECORDS FROM THE SYSTEM?(Y/N)");
scanf(" %c",&ch);
if(ch=='Y'||ch=='y')
{
   remove("DATA\\records\\prisoner records");
   remove("DATA\\records\\staff member records");
   remove("DATA\\records\\prison records");
   printf("\n\tPRISONER RECORDS DELETED SUCCESFULLY");
   printf("\n\tSTAFF MEMBER RECORDS DELETED SUCCESFULLY");
   printf("\n\tPRISON RECORDS DELETED SUCCESFULLY");
   getch();
}

printf("\n\t\033[1;33mPRESS ANY KEY TO EXIT");
   getch();

}

void login()
{

    int a=0,i=0,k=0,j=0;
    char input_uname[50],c=' ';
    char input_pword[50],code[10];
    /*char user[10]="akila";
    char pass[10]="usjp";*/
    FILE *fp5,*fp6,*fp7;
    ur u1;

    if(strcmp(audio_switch,"on")==0)
    {
    mciSendString("close mp3", NULL, 0, NULL);
    mciSendString("open \"DATA\\audio\\welcome MP3.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("play mp3", NULL, 0, NULL);
    }

     printf("\033[1;31m");
	 printf(".......................................................................................................................\n");
     printf(".......................................................................................................................\n");
	 printf("......PPPPPPPPPPP....RRRRRRRRRRRR.....IIIIIIII....SSSSSSSSSS.,....OOOOOOOOOOO....NNNNN.......NNNN......................\n");
     printf("......PPPPPPPPPPPP...RRRRRRRRRRRRR....IIIIIIII...SSSSSSSSSSSS.,..OOOOOOOOOOOOO...NNNNNN......NNNN......................\n");
     printf("......PPPP.....PPPP..RRRR.....RRRRR.....IIII....SSSS......SSSS..OOOO.......OOOO..NNNNNNN.....NNNN......................\n");
     printf("......PPPP.....PPPP..RRRR.....RRRRR.....IIII....SSSS............OOOO.......OOOO..NNNN.NNN....NNNN......................\n");
     printf("......PPPPPPPPPPPP...RRRRRRRRRRRRR......IIII.....SSSSSSSSSSS....OOOO.......OOOO..NNNN..NNN...NNNN......................\n");
     printf("......PPPPPPPPPPP....RRRRRRRRRRRR.......IIII......SSSSSSSSSSSS..OOOO.......OOOO..NNNN...NNN..NNNN......................\n");
     printf("......PPPP...........RRRR....RRRR.......IIII..............SSSS..OOOO.......OOOO..NNNN....NNN.NNNN......................\n");
     printf("......PPPP...........RRRR.....RRRR......IIII....SSSS......SSSS..OOOO.......OOOO..NNNN.....NNNNNNN......................\n");
     printf("......PPPP...........RRRR......RRRR...IIIIIIII...SSSSSSSSSSSS....OOOOOOOOOOOOO...NNNN......NNNNNN......................\n");
     printf("......PPPP...........RRRR.......RRRR..IIIIIIII....SSSSSSSSSS......OOOOOOOOOOO....NNNN.......NNNNN......................\n");
     printf("\033[1;33m");
     printf("                                                                                                                       \n");
     printf("    MMM     MMM  AAAAAAA  NNN   NN  AAAAAAA   GGGGGGG  EEEEEEEE MMM      MMM EEEEEEEE NNN   NN TTTTTTTT                \n");
     printf("    MMMM   MMMM AA     AA NNNN  NN AA     AA GG        EE       MMMM    MMMM EE       NNNN  NN    TT                   \n");
     printf("    MM MM MM MM AAAAAAAAA NN NN NN AAAAAAAAA GG   GGGG EEEEEE   MM MM  MM MM EEEEEE   NN NN NN    TT                   \n");
     printf("    MM  MMM  MM AA     AA NN  NNNN AA     AA GG     GG EE       MM  MMMM  MM EE       NN  NNNN    TT                   \n");
     printf("    MM   M   MM AA     AA NN   NNN AA     AA  GGGGGGG  EEEEEEEE MM   MM   MM EEEEEEEE NN   NNN    TT                   \n");
     printf("\033[1;31m");
     printf(".......................................................................................................................\n");
     printf("......SSSSSSSSSS...YYYY........YYYY..SSSSSSSSSS...TTTTTTTTTTTT.EEEEEEEEEEEE..MMMMM..............MMMMM..................\n");
     printf(".....SSSSSSSSSSSS...YYYY......YYYY..SSSSSSSSSSSS..TTTTTTTTTTTT.EEEEEEEEEEEE..MMMMMM............MMMMMM..................\n");
     printf("....SSSS......SSSS...YYYY....YYYY..SSSS......SSSS.....TTTT.....EEEE..........MMMMMMM..........MMMMMMM..................\n");
     printf("....SSSS..............YYYY..YYYY...SSSS...............TTTT.....EEEE..........MMMMMMMM........MMMMMMMM..................\n");
     printf(".....SSSSSSSSSSSS......YYYYYYYY.....SSSSSSSSSSSS......TTTT.....EEEEEEEEEE....MMMM.MMMM......MMMM.MMMM..................\n");
     printf("......SSSSSSSSSSSS......YYYYYY.......SSSSSSSSSSSS.....TTTT.....EEEEEEEEEE....MMMM..MMMM....MMMM..MMMM..................\n");
     printf("..............SSSS.......YYYY................SSSS.....TTTT.....EEEE..........MMMM...MMMM..MMMM...MMMM..................\n");
     printf("....SSSS......SSSS.......YYYY......SSSS......SSSS.....TTTT.....EEEE..........MMMM....MMMMMMMM....MMMM..................\n");
     printf(".....SSSSSSSSSSSS........YYYY.......SSSSSSSSSSSS......TTTT.....EEEEEEEEEEEE..MMMM.....MMMMMM.....MMMM..................\n");
     printf("......SSSSSSSSSS.........YYYY........SSSSSSSSSS.......TTTT.....EEEEEEEEEEEE..MMMM......MMMM......MMMM..................\n");
     printf(".......................................................................................................................\n");
     printf("\033[1;33m");
     printf("..........................................PRESS ANY KEY TO CONTINUE....................................................\n");
        getch();

	system("cls");

    printf("\n\t\t\033[1;31m*****************************************************************");
    printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
    printf("\n\t\t*****************************************************************\033[1;31m");

    fp6 = fopen( "DATA\\records\\password" , "rb");
    rewind(fp6);
    while (fscanf(fp6, "%s", pword)!=EOF)

    fp5 = fopen( "DATA\\records\\username" , "rb");
    rewind(fp5);
    while (fscanf(fp5, "%s", uname)!=EOF)

    fp7 = fopen ( "DATA\\records\\userslist", "rb" ) ;
    rewind(fp7);

strcpy(user_type,"NO USER")==0;

    do
{



  printf("\033[1;31m");
    printf("\n\t\t***********************\033[1;33m  LOGIN SCREEN\033[1;31m  **************************\n\n  ");
    printf("\033[1;31m");
    printf(" \n\t\t\tENTER USERNAME:-");
    printf("\033[1;33m");
    fflush(stdin);
	scanf("%s",&input_uname);
fp7 = fopen( "DATA\\records\\userslist" , "rb");
rewind(fp7);


	while(fread(&u1,sizeof(ur),1,fp7)){
	if(strcmp(input_uname,uname)!=0&&strcmp(input_uname,u1.uname)!=0)
    {
        printf("\033[1;31m\n\t\t\t*Wrong username.Please try again. \033[1;31m");
        a++;
        getch();
        fflush(stdin);

    }
    else{
            printf("\033[1;32m\t\t\t\t[Correct username]\033[1;31m");
  printf("\033[1;31m");
	printf(" \n\t\t\tENTER PASSWORD:-");
	fflush(stdin);
  printf("\033[1;33m");
	while(i<100)
	{
	    input_pword[i]=getch();
	    c=input_pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	input_pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);

		if(strcmp(input_uname,uname)==0 && strcmp(input_pword,pword)==0)
	{
	    system("cls");
	    strcpy(user_type,"\033[1;33mSUPER ADMIN MODE")==0;

	    if(strcmp(audio_switch,"on")==0)
    {

    mciSendString("close mp3", NULL, 0, NULL);
    mciSendString("open \"DATA\\audio\\super admin.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("play mp3", NULL, 0, NULL);
    }

    printf("\033[1;32m");
	printf("  \n\n\n\n\n\n\t\t");
	printf("  \n\t\t HELLO.. \033[1;33mSUPER ADMIN\033[1;37m %s \033[1;32m!!!              ",uname);
	printf("\n\t\t");

	k=0;
	j=0;

	for (k = 0; k < 70; k++){
	printf("%c",205);}
	printf("  \n\t\t%c                                                                    %c",186,186);

	printf("  \n\t\t%c WELCOME TO PRISON MANAGEMENT SYSTEM !!! YOUR LOGIN IS SUCCESSFUL   %c",186,186);
	printf("  \n\t\t%c                                                                    %c",186,186);
	printf("  \n\t\t");
	for (j = 0; j < 70; j++){
    printf("%c",205);}

     printf("\033[1;33m");

	printf("\n\n\n\t\t\tPress any key to continue...");
	getch();//holds the screen
	return 0;
	}
else{
fp7 = fopen( "DATA\\records\\userslist" , "rb");
rewind(fp7);

	while(fread(&u1,sizeof(ur),1,fp7))
        {
    if(strcmp(input_uname,u1.uname)==0 && strcmp(input_pword,u1.pword)==0)
	{
	    system("cls");


          if(strcmpi(u1.admin_status,"yes")==0){


                strcpy(user_type,"\033[1;31mADMIN MODE")==0;

                 if(strcmp(audio_switch,"on")==0)
    {

    mciSendString("close mp3", NULL, 0, NULL);
    mciSendString("open \"DATA\\audio\\admin.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("play mp3", NULL, 0, NULL);
    }
    k=0;
    j=0;

    printf("\033[1;32m");
	printf("  \n\n\n\n\n\n\t\t");
	printf("  \n\t\t HELLO.. \033[1;31mADMIN\033[1;37m %s \033[1;32m!!!              ",u1.uname);
	printf("\n\t\t");
	for (k = 0; k < 70; k++){
	printf("%c",205);}
	printf("  \n\t\t%c                                                                    %c",186,186);

	printf("  \n\t\t%c WELCOME TO PRISON MANAGEMENT SYSTEM !!! YOUR LOGIN IS SUCCESSFUL   %c",186,186);
	printf("  \n\t\t%c                                                                    %c",186,186);
	printf("  \n\t\t");
	for (j = 0; j < 70; j++){
    printf("%c",205);}

        printf("\033[1;33m");

            printf("\n\n\n\t\t\tPress any key to continue...");
            getch();
            fclose(fp7);//holds the screen
            return 0;
          }

        if(strcmpi(u1.admin_status,"no")==0)
        {

                     strcpy(user_type,"\033[1;34mUSER MODE")==0;
                     if(strcmp(audio_switch,"on")==0)
    {

    mciSendString("close mp3", NULL, 0, NULL);
    mciSendString("open \"DATA\\audio\\user.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("play mp3", NULL, 0, NULL);
    }

    k=0;
    j=0;

    printf("\033[1;32m");
	printf("  \n\n\n\n\n\n\t\t");
	printf("  \n\t\t HELLO.. \033[1;31mUSER\033[1;37m %s \033[1;32m!!!              ",u1.uname);
	printf("\n\t\t");
	for (k = 0; k < 70; k++){
	printf("%c",205);}
	printf("  \n\t\t%c                                                                    %c",186,186);

	printf("  \n\t\t%c WELCOME TO PRISON MANAGEMENT SYSTEM !!! YOUR LOGIN IS SUCCESSFUL   %c",186,186);
	printf("  \n\t\t%c                                                                    %c",186,186);
	printf("  \n\t\t");
	for (j = 0; j < 70; j++){
    printf("%c",205);}

    printf("\033[1;33m");
	printf("\n\n\n\t\t\tPress any key to continue...");
	getch();
	fclose(fp7);//holds the screen
	return 0;

           }
        }

      }

   }


 if(strcmp(user_type,"NO USER")==0)
	{
		printf("\n\033[1;31m\t\t\t\t[Wrong password]\033[1;33m");
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen

	}

	fclose(fp5);
	fclose(fp6);
	fclose(fp7);

    }}
}while(a<=2);
	if (a>2)
	{
		printf("\033[1;31m");
		printf("\n\n\n\t\t***********************************************************************");
		printf("\n\t*SORRY..!!! YOU HAVE FAILED TO LOG IN TO THE SYSTEM FOR 3 TIMES!!!");
		printf("\033[1;33m");
		printf("\n\t*SYSTEM WILL BE AUTOMATICALLY EXIT!!!");
		printf("\033[1;33m");
		getch();
		exit(0);

		}
		system("cls");



/*system("cls");
printf("\nuser type=%s",user_type);
getch();*/
/*FILE *fp8;
  remove("DATA\\records\\current user");
  fp8 = fopen ("DATA\\records\\current user", "w");
        fprintf(fp8,"%s",user_type);
        fclose(fp8);*/


}


void change_username()
{
/*******************************************************************
This function is used to change the user name of the super admin
********************************************************************/
system("cls");
FILE *fp5;
char choice;
char new_uname[100];
   if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a44.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

printf("\n  **************************CHANGE USERNAME  **************************  ");

  fp5 = fopen( "DATA\\records\\username" , "rb");
  rewind(fp5);
    while (fscanf(fp5, "%s", uname)!=EOF)
        printf("\n\n\tYOUR CURRENT  USERNAME :- %s",uname);

    printf("\n\nDO YOU WANT TO ADD NEW USERNAME?(Y/N)");
    scanf(" %c",&choice);

    if(choice=='Y'||choice=='y')
    {
        printf("\n\tENTER YOUR NEW USERNAME:-");
        scanf("%s",&new_uname);

        fflush(stdin);
       while (!valid_username(new_uname))
       {
        printf("\n\tYOUR NEW USERNAME IS TOO LONG.PLEASE ENTER A NEW USERNAME WITH MAXIMUM OF 30 CHARACTERS");
        printf("\n\tENTER YOUR NEW USERNAME:-");
        scanf("%s",&new_uname);
        fflush(stdin);
       }

        strcpy(uname,new_uname);
        fp5 = fopen ("DATA\\records\\username", "w");
        fprintf(fp5, "%s",uname);

        printf("\n\tYOUR NEW USERNAME IS SUCCESSFULLY SAVED");
        printf("\nYOUR NEW USERNAME :- %s",uname);
        printf("\nPRESS ANY KEY TO EXIT");
        getch();
        }
     else{
        printf("\nPRESS ANY KEY TO EXIT");
        getch();
     }
    fclose(fp5);
   security_settings(0);
    }



void change_password()
 {
/*******************************************************************
This function is used to change the password of the super admin
********************************************************************/
system("cls");
FILE *fp6;
char choice;
char new_pword[100];

   if(strcmp(audio_switch,"on")==0)
    {
     mciSendString("close mp3", NULL, 0, NULL);
     mciSendString("open \"DATA\\audio\\a45.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
     mciSendString("play mp3", NULL, 0, NULL);
    }

printf("\n  **************************CHANGE USERNAME  **************************  ");

  fp6 = fopen( "DATA\\records\\password" , "rb");
  rewind(fp6);
    while (fscanf(fp6, "%s", pword)!=EOF)
        printf("\n\n\tYOUR CURRENT  PASSWORD :- %s",pword);

    printf("\n\nDO YOU WANT TO ADD NEW PASSWORD?(Y/N)");
    scanf(" %c",&choice);
    if(choice=='Y'||choice=='y')
    {
        printf("\n\tENTER YOUR NEW PASSWORD:-");
        scanf("%s",&new_pword);
        fflush(stdin);
         while (!valid_password(new_pword))
       {
        printf("\n\tYOUR NEW PASSWORD IS TOO LONG.PLEASE ENTER A NEW PASSWORD WITH MAXIMUM OF 30 CHARACTERS");
        printf("\n\tENTER YOUR NEW PASSWORD:-");
        scanf("%s",&new_pword);
        fflush(stdin);
       }

        strcpy(pword,new_pword);
        fp6 = fopen ("DATA\\records\\password","w");
        fprintf(fp6, "%s",pword);
        printf("\n\tYOUR NEW PASSWORD IS SUCCESSFULLY SAVED");
        printf("\nYOUR NEW PASSWORD :- %s",pword);
        printf("\nPRESS ANY KEY TO EXIT");

        getch();
        }
     else{
        printf("\nPRESS ANY KEY TO EXIT");
        getch();
         }
    fclose(fp6);
   security_settings(0);
}


void exit_screen()
{
/*******************************************************************
This function is used to display exit screen of the system
*******************************************************************/
    char choice;
    printf("\n\t DO YOU WANT TO EXIT FROM THE PRISON MANAGEMENT SYSTEM?(Y/N)");
    fflush(stdin);
    scanf(" %c",&choice);
    if(choice=='Y'||choice=='y')
          {
               system("cls");
                          if(strcmp(audio_switch,"on")==0)
                {

                mciSendString("close mp3", NULL, 0, NULL);
                mciSendString("open \"DATA\\audio\\a6-exit screen.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
                mciSendString("play mp3", NULL, 0, NULL);
                }

              printf("\n\n\033[1;33mThanks for using prison management system");
              printf("\n\n\t\033[1;31m..................................................................................................");
              printf("\n\t...BBBBBBBBB..YY......YY..EEEEEEEE...........BBBBBBBBB..YY......YY..EEEEEEEE.....00..00............");
              printf("\n\t...BB......BB..YY....YY...EE.................BB......BB..YY....YY...EE...........00..00............");
              printf("\n\t...BB......BB...YY..YY....EE.................BB......BB...YY..YY....EE...........00..00............");
              printf("\n\t...BBBBBBBBB.....YYYY.....EEEEEE.............BBBBBBBBB.....YYYY.....EEEEEE.......00..00............");
              printf("\n\t...BB......BB.....YY......EE.................BB......BB.....YY......EE...........00..00............");
              printf("\n\t...BB......BB.....YY......EE.................BB......BB.....YY......EE.............................");
              printf("\n\t...BBBBBBBBB......YY......EEEEEEEE...........BBBBBBBBB......YY......EEEEEEEE.....00..00............");
              printf("\n\t...................................................................................................\033[1;33m");
              getch();
              exit(0);
          }

}

void credit()
{
     system("cls");
        printf("\n\n\n\t\033[1;31mSYSTEM AUDIO= \033[1;32m%s\t\t\t",audio_switch); printf("%s",user_type);
        printf("\n\t\t\033[1;31m*****************************************************************");
        printf("\n\t\t*********** \033[1;37mPRISON MANAGEMENT SYSTEM \033[1;31m****************************");
        printf("\n\t\t*****************************************************************");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;31m");
        printf("\n  \t\t|\t\t\033[1;37m CREDIT\t\t \033[1;31m\t\t\t\t|");
        printf("\n  \t\t|\033[1;31m---------------------------------------------------------------|\033[1;33m");

        if(strcmp(audio_switch,"on")==0)
                {

                mciSendString("close mp3", NULL, 0, NULL);
                mciSendString("open \"DATA\\audio\\credits.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
                mciSendString("play mp3", NULL, 0, NULL);
                }
        printf("\n\n\tThis prison management system was created by P.M.Akila Salinda Srikantha,\n\ta first year undergraduate of department of computer science in university of Sri Jayewardenepura. \n\tHe has created this system under the guidance of Dr Kasun jinasena and Mr Asanka Peiris.");
        printf("\n\n\t\033[1;31mPress any key to go back\033[1;33m");
        getch();
}
