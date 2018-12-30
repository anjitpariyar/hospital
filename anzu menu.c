#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
  
struct patient
{
       int age;
       char name[100];
       char address[100];
       char disease[100];
       char gender[100];
};
void appendRecord();
void readRecord();
void updateRecord();
void deleteRecord();
void searchRecord();

int main()
{
                            int choice;
                            
                             while(1)
                             {                                     
                             printf("\n\t\t*******************************************************");
                             printf("\n\t\t **** WELCOME TO HOSPITAL MANAGEMENT SYSTEM****");
                             printf("\n\t\t*****************************************************");
                             printf("\n\t\t\t1.Enter Patient Detail \n");
                             printf("\n\t\t\t2.View Patient Detail \n");
                             printf("\n\t\t\t3.Search Patient Detail \n");
                             printf("\n\t\t\t4.Update Patient Detail \n");
                             printf("\n\t\t\t5.Delete Patient Detail \n");
                             printf("\n\t\t\t6.Exit/Quit \n");
                             printf("Enter your choice:");
                             scanf("%d", &choice);
                             switch (choice)
                             {
                                    case 1:
                                         appendRecord();
                                         break;
                                    case 2:
                                         readRecord();
                                         break;
                                    case 3:
                                         searchRecord();
                                         break;
                                    case 4:
                                         updateRecord();
                                         break;
                                    case 5:
                                         deleteRecord();
                                         break;
                                    case 6:
                                         printf("YOU ARE ABOUT TO EXIT. THANK YOU \n");
                                         exit(1);
                                    default:
                                         printf("\n\a\aSorry Invalid Choice");
                                         printf("\n Would You Like To Go Main Menu");
                                   
                                         getch();
                                         }
                                         
                                         }
                                         
}                                         
void appendRecord()
{
     printf("\n1.Enter Patient Detail.\n");
        
       {
           struct patient pat;
           
           printf("\nFill up the blanks to enter patient detail.\n");
           printf("\nEnter name:");
           scanf("%s", &pat.name);
           printf("\nEnter age:");
           scanf("%d", &pat.age);
           printf("\nEnter gender:");
           scanf("%s", &pat.gender);
           printf("\nEnter disease:");
           scanf("%s", &pat.disease);
           printf("\nEnter address:");
           scanf("%s", &pat.address);
           
           printf("\nPatient Name:-\t\t%s", pat.name);
           printf("\nPatient Age:-\t\t%d", pat.age);
           printf("\nPatient Gender:-\t%s", pat.gender);
           printf("\nPatient Disease:-\t%s", pat.disease);
           printf("\nPatient Address:-\t%s", pat.address);
           
           FILE *fptr;
           fptr = fopen("D:\\program.txt","a");
           if(fptr == NULL)
           {
                   printf("Error!");
                   exit(1);
                   }
                   fwrite(&pat, sizeof(pat),1,fptr);
                   fclose(fptr);
                   getch();
                   }
           

}
void readRecord()
{
     printf("\n2.View Patient Detail.\n");
       {
           struct patient pat;
           
           FILE*fptr;
           fptr=fopen("D:\\program.txt","r");
           if(fptr == NULL)
           {
                         printf("Error!");
                         exit(1);
           }
           rewind(fptr);
           while(fread(&pat, sizeof(pat), 1, fptr) == 1)
           {
                             printf("\n Name:- %s \n Age:- %d \n Gender:- %s \n Disease:- %s \n Address:- %s \n", pat.name, pat.age, pat.gender, pat.disease, pat.address);
           }
           fclose(fptr);
           getch();                                             
       }
                                               

}
void searchRecord()
{
     printf("\n3.Search Patient Detail\n");

       {
           struct patient pat;
           
           FILE *fptr;
           fptr = fopen("D:\\program.txt","r");
           if(fptr == NULL)
           {
                         printf("Error!");
                         exit(1);
           }
           rewind(fptr);
           int age, count=0;
           printf("Enter age  to be searched:-");
           scanf("%d", &age);
           while(fread(&pat,sizeof(pat),1,fptr) == 1)
           {
           count ++;
           if(age == pat.age)
           {
                  printf("Record found:-");
                  printf("\nName:- %s \n Age:-%d\nDisease:- %s \n Gender:-%s\nAddress:- %s", pat.name, pat.age, pat.disease, pat.gender, pat.address);
                  count++;
           }
           }
           if(count==0)
           {
                       printf("Not Found.");
           }
           fclose(fptr);
           getch();
                                                                               

}
}
void updateRecord()
{
     printf("\n4.Update Patient Detail\n");
{
    struct patient pat;
    FILE *fptr, *tfptr;
    fptr = fopen("D:\\program.txt","r");
    tfptr = fopen("D:\\temp.txt","w"); 
    if(fptr == NULL)
    {
            printf("Error!");
            exit(1);
    }
    rewind(fptr);
    int age;
    printf("Enter age to be updated:-");
    scanf("%d", &age);
    int count = 0;
    while(fread(&pat, sizeof(pat),1,fptr));
    {
                      if(age == pat.age)
                      {
                             printf("Enter new data.");
                      printf("\nEnter new name:-");
                      scanf("%s", &pat.name);
                      printf("\nEnter new gender:-");
                      scanf("%s", &pat.gender);
                      printf("\nEnter new disease:-");
                      scanf("%s", &pat.disease);
                      printf("\nEnter new address:-");
                      scanf("%s", &pat.address);
                      
                      count++;
                      
                      fwrite(&pat, sizeof(pat),1,tfptr);
                      }
                      else 
                      {
                          fwrite(&pat, sizeof(pat),1,tfptr);
                      }
                      }
                          fclose(fptr);
                          fclose(tfptr);
                          
                          remove("D:\\program.txt");
                          rename("D:\\temp.txt","D:\\program.txt");
                          
                          if(count > 0)
                          printf("File updated.");
                          else
                          printf("Record not found to update.");
                          getch();
                          }
                          
}
void deleteRecord()
{
         printf("\n5.Delete Patient Detail\n");
       {
           struct patient pat;
           
           FILE *fptr, *tfptr;
    fptr = fopen("D:\\program.txt","r");
    tfptr = fopen("D:\\temp.txt","w");
    if(fptr == NULL)
    {
            printf("Error!");
            exit(1);
    }
    rewind(fptr);
    int age;
    printf("Enter age to be deleted:-");
    scanf("%d", &age);

    while(fread(&pat, sizeof(pat),1,fptr)==1)
    {
                  
                      if(age!= pat.age)
                      {
                               fwrite(&pat, sizeof(pat),1,tfptr);
                      } 
    }
    printf("Record deleted.");
    getch();
    fclose(fptr);
    fclose(tfptr);
                      
    remove("D:\\program.txt");
    rename("D:\\temp.txt","D:\\program.txt");
        getch();

}

}


                                                                             
                                         
                                    
          
   
