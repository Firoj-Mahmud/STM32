

                     /* Student Log Program*/


#include<stdio.h>
#include<stdint.h>
#include<string.h>

// Dfenition of a student records

typedef struct
{
    int rollNumber;
    char name[100];
    char branch[50];

    int semister;

}STUDENT_INFO_t;

int max_record = 10;
STUDENT_INFO_t students[10];

void display_menu(void);
int read_menu_code(void);
void decode_menu_code(int8_t menu_code);
void display_all_records(STUDENT_INFO_t *record, int8_t max_record);
int check_roll_number(int roll_number, STUDENT_INFO_t *record, int8_t max_record);
int add_new_record(STUDENT_INFO_t *record, int8_t max_record);
int delete_record(STUDENT_INFO_t *record, int8_t max_record);


int main()
{
    int8_t menu_code;
    int8_t app_continue =1;
    printf("Student rcord management programn\n");

    while(app_continue)
    {
        display_menu();
        menu_code = read_menu_code();
        if(menu_code)
        {
            decode_menu_code(menu_code);
        }
        else{
            app_continue = 0;
            printf("Exiting application \n");

        }
    }

    return 0;
}

 //this function displays the menu to user

void display_menu(void)
{
    printf("Display all record press 1 \n");
    printf("Add new record press     2 \n");
    printf("Delete a record press    3\n");
    printf("Exit applicationpress    0\n");
    printf("Enter any option here:   ");
}

int read_menu_code(void)
{
    int input;
    scanf("%d", &input); //this function retuns the input code by user
    return input;
}


void decode_menu_code(int8_t menu_code)
{
     int8_t ret;

    switch(menu_code)
    {
        case 1:
        printf("Displaying all students record\n");
        display_all_records(students,max_record);
        break;
        case 2:
        printf("Add a new record\n");
        ret = add_new_record(students,max_record);
        !ret ? printf("Record add unsuccessful\n") : printf("Record added successfully\n");
        break;
        case 3:
        printf("Delete a record\n");
        ret = delete_record(students,max_record);
        ret ? printf("Record deleted successfully\n") : printf("Record not found\n");
        break;
        default:
			printf("Invalid input\n");
    }

}

void display_all_records(STUDENT_INFO_t *record, int8_t max_record)
{
    int record_found = 0;
    for(int i=0; i<max_record; i++)
    {
        if(record[i].rollNumber)
        {
        record_found = 1;
        printf("********\n");
        printf("rollNumber : %u\n",record[i].rollNumber);
            printf("studentSemister   : %u\n",record[i].semister);
            printf("studentBranch     : %s\n",record[i].branch);
            printf("studentName       : %s\n",record[i].name);
            printf("***********\n");
        }

    }
     if(! record_found)
        printf("No records found\n");
}

int check_roll_number(int roll_number, STUDENT_INFO_t *record, int8_t max_record)
{

    int is_exist = 0;
    for(int i = 0 ; i < max_record ; i++)
    {
        if ( record[i].rollNumber == roll_number)
        {
            is_exist = 1;
            break;
        }
    }

    return is_exist;

}

int add_new_record(STUDENT_INFO_t *record, int8_t max_record)
{
    int add_status =0;
    int is_exist=0;
    int roll_number;
    int i;
    for(i=0; i<max_record; i++)
    {
        if(!record[i].rollNumber)
        {
            //add roll roll_number

                printf("Enter the rollNumber : ");
                scanf("%d",&roll_number);
                is_exist = check_roll_number(roll_number,students,max_record);
                if(! is_exist)
                {
                	add_status = 1; //adding new record
                    record[i].rollNumber = roll_number;
                    printf("Enter the studentSemister   : ");
                    scanf("%d",&record[i].semister);
                    getchar();
                    printf("Enter the studentBranch     : ");
                    scanf("%50[^\n]s",record[i].branch);
                    getchar();
                    printf("Enter the studentName       : ");
                    scanf("%50[^\n]s",record[i].name);


        }
        else
        {
            printf("roll number alredy exist\n");

        }
        break;
    }
}
 if(i == max_record)
        printf("No space available\n");

    return add_status;

}
// delete record

int delete_record(STUDENT_INFO_t *record, int8_t max_record)
{
    int8_t delete_flag = 0;
    int roll_number;

    printf("Enter the roll number of the student:");
    scanf("%d",&roll_number);

     for(int i = 0 ; i < max_record ; i++)
    {
         if( roll_number == record[i].rollNumber)
        {
            delete_flag = 1;
            memset(&record[i],0,sizeof(STUDENT_INFO_t));
            break;
        }
    }

    return delete_flag;
}
