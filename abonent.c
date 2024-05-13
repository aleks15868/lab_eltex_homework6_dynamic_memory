#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

typedef struct {
        char name[10];//Abonent name
        char second_name[10];//Abonent surname
        char tel[10];//Abonent phone
} abonent;

/**
 * @brief The function of adding a subscriber to the list
 * @param [in,out] Abonent Struct Abonent, array of abonents
 * @param [in] Number int, the last number of the subscriber
 * 
 */
abonent* Add_Abonent(abonent* Abonent, int* Number)
{
    int Input; //Selection of the menu
    char Stop_Flag='n';//Confirmation add when choosing input =2,Y -> N
    printf("\nMenu Add:\n1)One subscriber\n2)Many subscriber\n3)Exit");                              
    printf("\nInput:");
    scanf("%d",&Input);//Entering the choice
    switch(Input)
    {
	    case 1:
			Abonent = (abonent*)realloc(Abonent, (*Number) * sizeof(abonent));//Selection of memory for the subscriber
			if (Abonent == NULL) {
				printf("Ошибка выделения памяти!\n");
				exit(1);
			}
		    printf("Abonent name:");
		    scanf("%s",Abonent[*Number-1].name);//Entering a name
		    printf("Abonent surname:");
		    scanf("%s",Abonent[*Number-1].second_name);//Entering the surname
		    printf("Abonent telephone:");
		    scanf("%s",Abonent[*Number-1].tel);//Entering the phone
		    *Number+=1;
		    break;
	    case 2:
		    do{
				Abonent = (abonent*)realloc(Abonent, (*Number) * sizeof(abonent));//Selection of memory for the subscriber
				if (Abonent == NULL) {
					printf("Ошибка выделения памяти!\n");
					exit(1);
				}
			    printf("Abonent name:");
				scanf("%s",Abonent[*Number-1].name);//Entering a name
				printf("Abonent surname:");
				scanf("%s",Abonent[*Number-1].second_name);//Entering the surname
				printf("Abonent telephone:");
				scanf("%s",Abonent[*Number-1].tel);//Entering ThePhone
				*Number+=1;
				printf("Should I stop?(y/n):");
				fflush(stdin);
				scanf("%s",&Stop_Flag);
			}
			while((Stop_Flag!='Y') && (Stop_Flag!='y'));//if Y Or Y >stop
		default:
			break;                                                                   
    }
	return Abonent;
}
/**
 * @brief Conclusion on the screen of all users
 * 
 * @param [in] Abonent_List Struct Abonent, array of abonents
 * @param [in] Number int, the last number of the subscriber
 */
void Print_Table(abonent* Abonent_List, int* Number)
{	
	printf("┌──────────┬──────────┬──────────┬──────────┐\n");//Top heading
	printf("│     №    │   Name   │ Surname  │Telephone │\n");
	printf("├──────────┼──────────┼──────────┼──────────┤\n");
	for (int Strock = 0; Strock < *Number-1; Strock++) {//The cycle of all abonents
        printf("│%10d│%10s│%10s│%10s│\n", (Strock+1), Abonent_List[Strock].name,Abonent_List[Strock].second_name,Abonent_List[Strock].tel);
        if (Strock!= *Number-2){ //Tracking the opening table with the last element
                        printf("├──────────┼──────────┼──────────┼──────────┤\n");
                } else {
                        printf("└──────────┴──────────┴──────────┴──────────┘\n");
                }

    	}
}
/**
 * @brief Conclusion of all elements with a similar name
 * 
 * @param [in] Abonent_List Struct Abonent, array of abonents
 * @param [in] Number int, the last number of the subscriber
 */
void Find_Table(abonent* Abonent_List, int* Number)
{
	char Find_Name[10];// variable for the search name
	printf("\nInput find name:");
	scanf("%s",Find_Name);// Record for the search name
        printf("┌──────────┬──────────┬──────────┬──────────┐\n");//Top heading
        printf("│     №    │   Name   │ Surname  │Telephone │\n");
        printf("├──────────┼──────────┼──────────┼──────────┤\n");

        for (int Strock = 0; Strock < *Number-1; Strock++) {// Busting all elements
		if ((strcmp (Find_Name, Abonent_List[Strock].name)==0))// if Find_Name == abonent name
			{
				printf("│%10d│%10s│%10s│%10s│\n", (Strock+1), Abonent_List[Strock].name,Abonent_List[Strock].second_name,Abonent_List[Strock].tel);
				if (Strock!= *Number-2) {// if the element is not the last
						printf("├──────────┼──────────┼──────────┼──────────┤\n");
				}
						
			}
		}
		printf("└──────────┴──────────┴──────────┴──────────┘\n");
}

/**
 * @brief Removal of a subscriber from an array
 * 
 * @param [in,out] Abonent_List Struct Abonent, array of abonents
 * @param [in] Number int, the last number of the subscriber
 */
abonent* Delete_Abonent(abonent* Abonent_List, int* Number)
{
	int Number_Abonent;// Subscriber number in the List for Delete
	printf("Input number list abonents:");
	scanf("%d",&Number_Abonent);
	if ((Number_Abonent>=0) && (Number_Abonent<*Number)) // If Number_Abonent [0;*Number]
	{
		Number_Abonent--;
		abonent temp = Abonent_List[Number_Abonent]; // Subscriber's recording temporarily in temp
		for (int i = Number_Abonent; i < *Number - 2; i++) { // Reloading the array starting with number_abonent
			Abonent_List[i] = Abonent_List[i + 1];
		}
		Abonent_List[*Number-2] = temp; // insert of the remote element into the last element
		*Number = *Number-1;
		Abonent_List = (abonent*)realloc(Abonent_List, (*Number) * sizeof(abonent));// Relting of a dynamic array
	}
	else
	{
		printf("No such number!!!");
	}
	return Abonent_List;
}
/**
 * @brief The main function
 * 
 * @return int 0
 */
int main()
{               
    int Choise=0;// Selection of the menu
    abonent* Abonent_List = NULL;// Initialization of the array of abonents
    int Last_Number_Add_Abonent=1;// Record of the beginning of a half -axle element in an array Abonent_List
    while(Choise<5)
    {
        switch(Choise)
        {
        case 1:
			Abonent_List = Add_Abonent(Abonent_List, &Last_Number_Add_Abonent);// Add to an array of abonents
            break;
        case 2:
			if (Last_Number_Add_Abonent<=0){
				printf("Error:Number<0\n");
			}
			else
			{
				Abonent_List = Delete_Abonent(Abonent_List, &Last_Number_Add_Abonent);// removal from the array of abonents
			}
            break;                                                                                   
        case 3:
            Find_Table(Abonent_List, &Last_Number_Add_Abonent);// Search by array of abonents
            break;
        case 4:
			if (Abonent_List == NULL) {
					printf("Ошибка выделения памяти!\n");
					exit(1);
				}
			else
			{
				printf("Last_Number_Add_Abonent: %d!\n", Last_Number_Add_Abonent);
				Print_Table(Abonent_List, &Last_Number_Add_Abonent);// Conclusion of all abonents
			}
            break;                                                                                  
        default :
            break;
        }
        printf("Menu:\n1) Add a subscriber\n2) Delete the subscriber\n3) Search for a subscriber by name\n4) Output of all records\n5) Exit\n");
        printf("Input:");
        scanf("%d",&Choise);
    }

    free(Abonent_List);// Exception of the array of abonents

    return 0;
}
