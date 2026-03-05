#include "contact.h"

int main()
{
    int choice;
    AddressBook s1;
    loadFromCSV(&s1, "contacts.csv");
    if(s1.contactCount == 0) 
    {
        populate_contact(&s1); 
    }
    do
    {
        printf("\n1.Create Contact\n2.Edit Contact\n3.Search Contact\n4.Delete Contact\n5.List contact\n6.Save and exit\n");
        printf("Enter your choice between 1 and 6:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Create contact is selected\n");
            createContact(&s1);
            break;
            case 2:
            printf("Edit contact is selected\n");
            editContact(&s1);
            break;
            case 3:
            printf("Search contact is selected\n");
            searchContact(&s1);
            break;
            case 4:
            printf("Delete contact is selected\n");
            deleteContact(&s1);
            break;
            case 5:
            printf("List contact is selected\n");
            listContacts(&s1);
            printf("\n");
            break;
            case 6:
            printf("Edit and saved it\n");
            saveandexisttocsv(&s1,"contacts.csv");
            break;
            default:
            printf("Invalid choice\n");
        }
    }while(choice!=6);
    //all function calls should be inside the main 
}

