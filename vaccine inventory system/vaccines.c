#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE_LENGTH 80
struct vaccines
{
	char name[10];
	char code[5];
	char producing_country[20];
	float Dosage_required;
	int population_covered;
	int distributed_quantity;
};
int main()
{
	int num;
	printf("Enter:\n");
	printf("1:To create inventory\n");
	printf("2:To update vaccine quantities\n");
	printf("3:To search for vaccines\n");
	printf("4: To list vaccines\n");
	printf("Enter details in order of their stated chronology\n");
scanf("%d",&num);
switch(num)
{
	case 1:
		createinventory();
		break;
		case 2:
			update_quantities();
			break;
			case 3:
				search();
				break;
		case 4:
			displayVaccines();
			break;
		default:
			printf("invalid entry");
}
	
	
}
int displayVaccines()
{
	char c[MAX_LINE_LENGTH]={0};
	FILE *fPtr;
		fPtr=fopen("vaccine.txt","r");
	if(fPtr==NULL)
	{
		printf("An error occured while opening file");
	}
		else{
while(fgets(c, MAX_LINE_LENGTH,fPtr))
{
	printf("%s",c);
}
	}
}
	int createinventory()
	{struct vaccines v;
	int i,a;
	printf("Enter the number of records you want to insert:");
	scanf("%d",&i);
	/*for(a=0;a>i;a++)
	{*/
		printf("1.Enter the name of the vaccines\n2.code of vaccines\n3.Producing country\n4.Dosage Required\n5. Population covered\n6.Quantity distributed\n");
		scanf("%s %s %s %d %d %d",v.name,v.code,v.producing_country,&v.Dosage_required,&v.population_covered,&v.distributed_quantity);
		FILE *fPtr;
	fPtr=fopen("vaccine.txt","a");
	if(fPtr==NULL)
	{
		printf("An error occured while opening file");
	}
	else{
		fprintf(fPtr,"%s %s %s %d %d %d %d\n",v.name, v.code,v.producing_country,v.Dosage_required,v.population_covered,v.distributed_quantity);
	
	}
}
 
void update_quantities()
{
}
//function to perform searching task
int search()
{ 
	FILE *fPtr;
	fPtr=fopen("vaccine.txt","r");
char code[10];
char tmp[512];
	printf("Enter code of vaccine you want to search:");
	scanf("%s",&code);
   FILE *fp;
   char word[50];
   char ch;
   char *filename = "vaccine.txt";
   int count = 0;
   int position[10];
   int pointer = 0;
   int loop;

   /*  open for reading only */
   fp = fopen("vaccine.txt", "r");

   do 
   {
      ch = fscanf(fPtr, "%s", word); 
      if(strcmp(word, code) == 0)
        {
         position[count] = pointer;     
         count++;
        }
      pointer++;
      //printf("%s",word);       
   } while (ch != EOF); 

    if(count == 0)  
        printf("'%s' not found in %s\n", code, filename);
    else
        {
        printf("'%s' is found at -> ", code);
        for(loop = 0; loop<count; loop++)
            {
                printf("%d ", position[loop]);
                fgets(word,loop,fPtr);
           printf("position and the distributed quantity is %s.\n",word);
             
            }
            
        }
        
   fclose(fp);

   return 0;
}


//}
