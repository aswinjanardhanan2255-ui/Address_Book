#include "contact.h"

void listContacts(AddressBook *addressBook) 
{
    //to copy dummy contact to addressbook
    
    printf("................................................................\n");
    printf("Name\t               Mobile\t      Email\n");
    printf("................................................................\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%-20s %-15s %-30s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}
void createContact(AddressBook *addressBook) 
{
    printf("Enter name: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name );
    printf("\nEnter phone number: ");
    scanf("%s",addressBook->contacts[addressBook->contactCount].phone );
    char *phone=addressBook->contacts[addressBook->contactCount].phone;
    if(strlen(phone)!=10)
    {
        printf("Ivalid phone number,please enter 10 digit number\n");
        return;
    }
    for(int i=0;i<10;i++)
    {
        if(phone[i]<'0' || phone[i]>'9')
        {
            printf("Invalid mobile number, number must be digits only\n");
            return;
        }
    }

    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(phone, addressBook->contacts[i].phone) == 0)
        {
            printf("This phone number already exists in the contact list!\n");
            return;
        }
    }
    
    printf("\nEnter email: ");
    scanf("%s",addressBook->contacts[addressBook->contactCount].email );
    char *email=addressBook->contacts[addressBook->contactCount].email;
    if(strstr(email,"@gmail.com")==NULL)
    {
        printf("Invalid email,must contain @gmail.com\n");
        return;
    }

    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(email, addressBook->contacts[i].email) == 0)
        {
            printf("This email already exists in the contact list!\n");
            return;
        }
    }

    addressBook->contactCount++;
    printf("Contact created.");

}

void searchContact(AddressBook *addressBook) 
{
    char check[40];
    int choice,found=0;
    printf("\nsearch by:\n1.Name\n2.Phone number\n3.Email\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Enter the name: ");
        scanf(" %[^\n]",check);
        break;
        case 2:
        printf("Enter the Mobile number: ");
        scanf(" %[^\n]",check);
        break;
        case 3:
        printf("Enter the email: ");
        scanf(" %[^\n]",check);
        break;
        default:
        printf("Enter the valid choice.");
        return;
    }
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if((choice==1 && strcmp(check,addressBook->contacts[i].name)==0) ||
        (choice==2 && strcmp(check,addressBook->contacts[i].phone)==0)||
        (choice==3 && strcmp(check,addressBook->contacts[i].email)==0))
        {
            printf("\nContact founded......\n");
            printf("Name: %s",addressBook->contacts[i].name);
            printf("\nPhone: %s",addressBook->contacts[i].phone);
            printf("\nEmail: %s",addressBook->contacts[i].email);
            found=1;
            break;

        }
    }
    if(found==0)
    {
        printf("No contact found\n");
    }
}

void editContact(AddressBook *addressBook) 
{
    char check[40];
    int choice, found = 0;
    printf("\nSearch by:\n1.Name\n2.Phone number\n3.Email\nEnter your choice: ");
    scanf(" %d", &choice);
    switch(choice)
    {
        case 1:
            printf("Enter the name: ");
            scanf(" %[^\n]", check);
            break;
        case 2:
            printf("Enter the Mobile number: ");
            scanf(" %[^\n]", check);
            break;
        case 3:
            printf("Enter the email: ");
            scanf(" %[^\n]", check);
            break;
        default:
            printf("Enter a valid choice.\n");
            return;
    }

    for(int i=0;i<addressBook->contactCount;i++)
    {
        if((choice==1 && strcmp(check,addressBook->contacts[i].name)==0) ||
           (choice==2 && strcmp(check,addressBook->contacts[i].phone)==0) ||
           (choice==3 && strcmp(check,addressBook->contacts[i].email)==0))
        {
            printf("\nContact found.....!\n");
            printf("Name: %s", addressBook->contacts[i].name);
            printf("\nPhone: %s", addressBook->contacts[i].phone);
            printf("\nEmail: %s", addressBook->contacts[i].email);

            char new_name[40], new_phone_number[20], new_email[50];
            int edit;
            printf("\nWhat do you want to edit:\n1.Name\n2.Phone number\n3.Email\n4.Name&Phone\n5.Name&Email\n6.Phone&Email\n7.All of them\n");
            printf("Enter your choice: ");
            scanf(" %d", &edit);

            if(edit==1 || edit==4 || edit==5 || edit==7)
            {
                printf("\nEnter new name: ");
                scanf(" %[^\n]", new_name);
                strcpy(addressBook->contacts[i].name, new_name);
            }

            if(edit==2 || edit==4 || edit==6 || edit==7)
            {
                int valid=0;
                while(!valid)
                {
                    printf("\nEnter new Phone number: ");
                    scanf(" %[^\n]", new_phone_number);
                    if(strlen(new_phone_number)!=10)
                    {
                        printf("Invalid phone number, must be 10 digits.\n");
                        continue;
                    }
                    int digitsonly=1;
                    for(int j=0;j<10;j++)
                    {
                        if(new_phone_number[j]<'0' || new_phone_number[j]>'9')
                        {
                            digitsonly=0;
                            break;
                        }
                    }
                    if(!digitsonly)
                    {
                        printf("Invalid mobile number, must contain only digits.\n");
                        continue;
                    }

                    
                    int duplicate=0;
                    for(int k=0;k<addressBook->contactCount;k++)
                    {
                        if(k!=i && strcmp(new_phone_number, addressBook->contacts[k].phone)==0)
                        {
                            printf("This phone number already exists in the contact list!\n");
                            duplicate=1;
                            break;
                        }
                    }
                    if(duplicate) continue;

                    strcpy(addressBook->contacts[i].phone,new_phone_number);
                    valid=1;
                }
            }

            if(edit==3 || edit==5 || edit==6 || edit==7)
            {
                int valid=0;
                while(!valid)
                {
                    printf("\nEnter new email: ");
                    scanf(" %[^\n]", new_email);
                    if(strstr(new_email,"@gmail.com")==NULL)
                    {
                        printf("Invalid email, must contain @gmail.com\n");
                        continue;
                    }

                
                    int duplicate=0;
                    for(int k=0;k<addressBook->contactCount;k++)
                    {
                        if(k!=i && strcmp(new_email, addressBook->contacts[k].email)==0)
                        {
                            printf("This email already exists in the contact list!\n");
                            duplicate=1;
                            break;
                        }
                    }
                    if(duplicate) continue;

                    strcpy(addressBook->contacts[i].email,new_email);
                    valid=1;
                }
            }

            printf("\nContact updated successfully.\n");
            found=1;
            break;
        }
    }

    if(!found)
    {
        printf("\nNo contact found.\n");
    }
}


void deleteContact(AddressBook *addressBook) 
{
    char check[40];
    int choice,found=0;
    printf("\nsearch by:\n1.Name\n2.Phone number\n3.Email\nEnter your choice:");
    scanf(" %d",&choice);
    switch(choice)
    {
        case 1:
        printf("Enter the name: ");
        scanf(" %[^\n]",check);
        break;
        case 2:
        printf("Enter the Mobile number: ");
        scanf(" %[^\n]",check);
        break;
        case 3:
        printf("Enter the email: ");
        scanf(" %[^\n]",check);
        break;
        default:
        printf("Enter the valid choice.");
        return;
    }
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if((choice==1 && strcmp(check,addressBook->contacts[i].name)==0) ||
        (choice==2 && strcmp(check,addressBook->contacts[i].phone)==0)||
        (choice==3 && strcmp(check,addressBook->contacts[i].email)==0))
        {
            printf("\nContact founded......\n");
            printf("Name: %s",addressBook->contacts[i].name);
            printf("\nPhone: %s",addressBook->contacts[i].phone);
            printf("\nEmail: %s",addressBook->contacts[i].email);
            char conform;
            printf("Do you want to delete this contact?(y/n):");
            scanf(" %c",&conform);
            if(conform=='y'||conform=='Y')
            {
                for(int j=i;j<addressBook->contactCount-1;j++)
                {
                    addressBook->contacts[j]=addressBook->contacts[j+1];
                }
                addressBook->contactCount--;
                printf("\nContact deleted\n");
                return;
            }
            else
            {
                printf("\nInvalid input,please enter valid choice(y/n):\n");
            }
            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("No contact found to delete.");
        return;
    }

}
void saveandexisttocsv(AddressBook *addressBook, const char *filename)
{
    FILE *file=fopen(filename,"w");
    if(file==NULL)
    {
        printf("Failed to open file");
        return;
    }
    fprintf(file, "Name, phone,Email\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(file, "%s,%s,%s\n",addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
    }
    fclose(file);
    printf("contact is successflly updated or saved\n");
}
void loadFromCSV(AddressBook *addressBook, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file==NULL)
    {
        printf("No CSV file found.\n");
        addressBook->contactCount = 0;
        return;
    }

    char header[200];
    fscanf(file,"%[^\n]\n", header); 

    addressBook->contactCount = 0;
    while(addressBook->contactCount < MAX_CONTACTS)
    {
        if(fscanf(file,"%[^,],%[^,],%[^\n]\n", 
         addressBook->contacts[addressBook->contactCount].name,
         addressBook->contacts[addressBook->contactCount].phone,
         addressBook->contacts[addressBook->contactCount].email) != 3)
         {
            break;
         }
        addressBook->contactCount++;
    }

    fclose(file);
    return;
}
