// Jehad Hamayel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define numOfStud 1000
#define numOfChar 50
#define numOfCharInLine 200
#define CharOfAnswer 4
//functions prototype
void AscendingOrderByID (char [][numOfChar],int [],double [],int);//Ascending order based on ID
void AscendingOrderByNames (char [][numOfChar],int [],double [],int);//Ascending order based on name
void DescendingOrderByScores (char [][numOfChar],int [],double [],int);//Ascending order based on score
void PrintInfo (char [][numOfChar],int [],double [],int);//Function for printing ID, name and score

int main()
{   //Define arrays of type Character
    char file[numOfChar],NamesOfStud[numOfStud][numOfChar],info[numOfCharInLine],*token,Question[CharOfAnswer];
    int ids[numOfStud],i,j=0,choice;//Defining arrays of type integer
    double score[numOfStud],Assignment,Quizzes,MidtermExam,PracticalExam,FinalExam;//Defining arrays of type double

    printf("Enter the name of file you want:\n");//Ask the user to enter the file name
    gets(file);//Read file name

    FILE *in,*out;//Define files
    in = fopen(file,"r");//Make the file in read

    while(fgets(info,numOfCharInLine,in)!=NULL)//while loop for reading from file
    {
        token = strtok(info,"$");//String up to $
        ids[j] = atoi(token);//Converting a String to an Intger
        token = strtok(NULL,"$");//String up to $
        strcpy(NamesOfStud[j],token);//Copy the string and place it in the required array
        token = strtok(NULL,"$");//String up to $
        Assignment = atof(token);//Converting a String to an double
        token = strtok(NULL,"$");//String up to $
        Quizzes = atof(token);//Converting a String to an double
        token = strtok(NULL,"$");//String up to $
        MidtermExam = atof(token);//Converting a String to an double
        token = strtok(NULL,"$");//String up to $
        PracticalExam = atof(token);//Converting a String to an double
        token = strtok(NULL,"$");//String up to $
        FinalExam = atof(token);//Converting a String to an double
        //Calculating the student's score
        score[j]=(Assignment*0.15) + (Quizzes*0.15) + (MidtermExam*0.25) + (PracticalExam*0.10) + (FinalExam*0.35);
        j++;
        token = strtok(NULL,"$");
    }
    fclose(in);//close file
    //Print the option for the operations in the program
    printf("Choose the transaction number from the following operations 1 to 6:\n");
    printf("1) Sort data in ascending order according to students IDs and then display it.\n");
    printf("2) Sort data in ascending order according to students names and then display it.\n");
    printf("3) Sort data in descending order according to students scores and then display it.\n");
    printf("4) Ask the user to enter a student ID and display his score.\n");
    printf("5) Ask the user to enter a student name and display his score.\n");
    printf("6) Exit the program.\n");
    //Ask the user to choose an operation
    printf("The number of operations:\n");
    scanf("%d",&choice);
    if(choice < 1 || choice > 6)
        printf("Choose the correct operation number\n");
    //while loop In order to print the options based on the option, the function is called for the desired action
    while(choice != 6)//stop if option 6
    {
    if(choice == 1)
    {
        AscendingOrderByID (NamesOfStud,ids,score,j);//call function.
        PrintInfo (NamesOfStud,ids,score,j);//call function.
        printf("would you like to save the current result yes or no\n");//Ask user if he/she like to save the result
        scanf("%s",Question);

        if(strcmp(Question,"yes")==0)//Check if the user wants to save the result or not
        {
        //Ask the user for the name of the file he/she want to save in
        printf("Enter the name of file you want to save in\n");
        scanf("%s",file);
        out = fopen(file,"w");//Open the file you want to save in
        //print to file
        fprintf(out,"ID             Student Name              Score\n");
        for(i=0;i<j;i++)
            fprintf(out,"%d   %-25s %.3f\n",ids[i],NamesOfStud[i],score[i]);

        fclose(out);//close file
        }
    }

    if(choice == 2)
    {
        AscendingOrderByNames (NamesOfStud,ids,score,j);//call function.
        PrintInfo (NamesOfStud,ids,score,j);//call function.
        printf("would you like to save the current result yes or no\n");//Ask user if he/she like to save the result
        scanf("%s",Question);

        if(strcmp(Question,"yes")==0)//Check if the user wants to save the result or not
        {
        //Ask the user for the name of the file he/she want to save in
        printf("Enter the name of file you want to save in\n");
        scanf("%s",file);
        out = fopen(file,"w");//Open the file you want to save in
        //print to file
        fprintf(out,"ID             Student Name              Score\n");
        for(i=0;i<j;i++)
            fprintf(out,"%d   %-25s %.3f\n",ids[i],NamesOfStud[i],score[i]);

        fclose(out);//close file
        }
    }

    if(choice == 3)
    {
        DescendingOrderByScores (NamesOfStud,ids,score,j);//call function.
        PrintInfo (NamesOfStud,ids,score,j);//call function.

        printf("would you like to save the current result yes or no\n");//Ask user if he/she like to save the result
        scanf("%s",Question);

        if(strcmp(Question,"yes")==0)//Check if the user wants to save the result or not
        {
        //Ask the user for the name of the file he/she want to save in
        printf("Enter the name of file you want to save in\n");
        scanf("%s",file);
        out = fopen(file,"w");//Open the file you want to save in
        //print to file
        fprintf(out,"ID             Student Name              Score\n");
        for(i=0;i<j;i++)
            fprintf(out,"%d   %-25s %.3f\n",ids[i],NamesOfStud[i],score[i]);

        fclose(out);//close file
        }
    }

    if(choice == 4)
    {
        int ID,id=0,IdCorrect=0;
        //Ask the user to enter the ID whose score we want to search for
        printf("Enter ID:\n");
        scanf("%d",&ID);
        for(i=0;i<j;i++)//for loop to compare and search for the application of the ID that we want to know its score
            {
                if(ID == ids[i])
                {
                    IdCorrect=1;
                    id=i;
                }
            }

            if(IdCorrect)//Check if the information is present or not
                printf("The score is %.3f\n",score[id]);
            else
                printf("This student does not exist\n");
    }

    if(choice == 5)
    {
        char NAME[numOfChar];
        int nameCorrect=0,id = 0;
        //Ask the user to enter the Name whose score we want to search for
        printf("Enter Name of student:\n");
        fflush(stdin);
        gets(NAME);

        for(i=0;i<j;i++)//for loop to compare and search for the application of the ID that we want to know its score
        {
            if(strcmp(NAME,NamesOfStud[i])==0)
                {
                    nameCorrect=1;
                    id=i;
                }
        }

        if(nameCorrect)//Check if the information is present or not
                printf("The score is %.3f\n",score[id]);
        else
                printf("This student does not exist\n");
    }
    //Print the option for the operations in the program
    printf("Choose the transaction number from the following operations 1 to 6:\n");
    printf("1) Sort data in ascending order according to students IDs and then display it.\n");
    printf("2) Sort data in ascending order according to students names and then display it.\n");
    printf("3) Sort data in descending order according to students scores and then display it.\n");
    printf("4) Ask the user to enter a student ID and display his score.\n");
    printf("5) Ask the user to enter a student name and display his score.\n");
    printf("6) Exit the program.\n");
    //Ask the user to choose an operation
    printf("The number of operations:\n");
    scanf("%d",&choice);

    if(choice < 1 || choice > 6)
        printf("Choose the correct operation number\n");
    }
    printf("Thank you and bye");

     return 0;//Exit the program
}

void AscendingOrderByID (char NamesOfStud[][numOfChar],int ids[],double score[],int j)//function definition.
{
    int i,k,tempi;
    char tempc[j];
    double tempd;

    for(i=0;i<j-1;i++)//for loop for Ascending order
        for(k=0;k<j-1;k++)
            if(ids[k]>ids[k+1])
            {
                strcpy(tempc,NamesOfStud[k]);
                strcpy(NamesOfStud[k],NamesOfStud[k+1]);
                strcpy(NamesOfStud[k+1],tempc);
                tempi = ids[k];
                ids[k] = ids[k+1];
                ids[k+1] = tempi;
                tempd = score[k];
                score[k] = score[k+1];
                score[k+1] = tempd;
            }
}

void PrintInfo (char NamesOfStud[][numOfChar],int ids[],double score[],int j)//function definition.
{
    int i;
    //do the printing
    printf("ID        Student Name              Score\n");
    for(i=0;i<j;i++)
            printf("%d   %-25s %.3f\n",ids[i],NamesOfStud[i],score[i]);
}

void AscendingOrderByNames (char NamesOfStud[][numOfChar],int ids[],double score[],int j)//function definition.
{
    int i,k,tempi;
    char tempc[j];
    double tempd;

    for(i=0;i<j-1;i++)//for loop for Ascending order
        for(k=0;k<j-1;k++)
            if(strcmp(NamesOfStud[k],NamesOfStud[k+1])>0)
            {
                strcpy(tempc,NamesOfStud[k]);
                strcpy(NamesOfStud[k],NamesOfStud[k+1]);
                strcpy(NamesOfStud[k+1],tempc);
                tempi = ids[k];
                ids[k] = ids[k+1];
                ids[k+1] = tempi;
                tempd = score[k];
                score[k] = score[k+1];
                score[k+1] = tempd;
            }
}

void DescendingOrderByScores (char NamesOfStud[][numOfChar],int ids[],double score[],int j)//function definition.
{
    int i,k,tempi;
    char tempc[j];
    double tempd;

    for(i=0;i<j-1;i++)//for loop for Ascending order
        for(k=0;k<j-1;k++)
            if(score[k]<score[k+1])
            {
                strcpy(tempc,NamesOfStud[k]);
                strcpy(NamesOfStud[k],NamesOfStud[k+1]);
                strcpy(NamesOfStud[k+1],tempc);
                tempi = ids[k];
                ids[k] = ids[k+1];
                ids[k+1] = tempi;
                tempd = score[k];
                score[k] = score[k+1];
                score[k+1] = tempd;
            }
}
