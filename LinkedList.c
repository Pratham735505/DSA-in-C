#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>


int createlist();
int list;
void goto_label();


//For Singly and Circular Linked List
struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* new;
struct node* temp;
struct node* temppre;
struct node* first = NULL;
struct node* last = NULL;


//For Doubly and Circular Doubly Linked List
struct dnode
{
    struct dnode* prev;
    int data;
    struct dnode* next;
};

struct dnode* dhead = NULL;
struct dnode* dnew;
struct dnode* dtemp;
struct dnode* dtemppre;
struct dnode* dfirst = NULL;
struct dnode* dlast = NULL;


//Funcs for Single Linked List
void sins();
void sdel();
void sdis();
void ssear();

//Funcs for Doubly Linked List
void dins();
void ddel();
void ddis();
void dsear();

//Funcs for Circular Linked List
void cins();
void cdel();
void cdis();
void csear();

//Funcs for Circular Doubly Linked List
void cdins();
void cddel();
void cddis();
void cdsear();


void main()
{
    int slm, silm;

    clrscr();

    //printf("\t\tLinked List Implementation.\n\t\t© Aryan Prajapati 😏\n\n");
    createlist();

    printf("Which Linked List you want to use : \n");
    printf("\n1. Singly Linked List.\n2. Doubly Linked List.\n3. Circular Linked List.\n4. Circular Doubly Linked List.\n5. Exit.\n\n");
    printf("Enter your choice : ");
    scanf("%d",&slm);

    switch (slm)
    {
    case 1: //Singly Linked List

        do
        {
            printf("\n\nWhich operation you want to perform : \n");
            printf("1. Insertion.\n2. Deletion.\n3. Display.\n4. Search.\n5. Exit.\n\n");
            printf("Enter your choice : ");
            scanf("%d",&silm);

            switch (silm)
            {
            case 1:
                sins();
                break;

            case 2:
                sdel();
                break;

            case 3:
                sdis();
                break;

            case 4:
                ssear();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid Choice.");
            }
        } while(silm != 5);
        break;


    case 2: //Doubly Linked List

        do
        {
            printf("\nWhich operation you want to perform : \n");
            printf("1. Insertion.\n2. Deletion.\n3. Display.\n4. Search.\n5. Exit.\n\n");
            printf("Enter your choice : ");
            scanf("%d",&silm);

            switch (silm)
            {
            case 1:
                dins();
                break;

            case 2:
                ddel();
                break;

            case 3:
                ddis();
                break;

            case 4:
                dsear();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid Choice.");
            }
        } while(silm != 5);

        break;


    case 3: //Circular Linked List

        do
        {
            printf("\nWhich operation you want to perform : \n");
            printf("1. Insertion.\n2. Deletion.\n3. Display.\n4. Search.\n5. Exit.\n\n");
            printf("Enter your choice : ");
            scanf("%d",&silm);

            switch (silm)
            {
            case 1:
                cins();
                break;

            case 2:
                cdel();
                break;

            case 3:
                cdis();
                break;

            case 4:
                csear();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid Choice.");
            }
        } while(silm != 5);

        break;


    case 4: //Circular Doubly Linked List

        /*do
        {
            printf("\nWhich operation you want to perform : \n");
            printf("1. Insertion.\n2. Deletion.\n3. Display.\n4. Search.\n5. Exit\n\n");
            printf("Enter your choice : ");
            scanf("%d",&silm);

            switch (silm)
            {
            case 1:
                //cdins();
                break;

            case 2:
                //cddel();
                break;

            case 3:
                //cddis();
                break;

            case 4:
                //cdsear();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid Choice.");
            }
        } while(silm != 5);*/

        printf("Under Maintenance.");

        break;

    case 5:

        exit(0);
        break;

    default:
        printf("Invalid Choice.");
    }
    getch();
}



//Funcs For Singly Linked List

void sins()
{
    int ch, val, pos, count, i=1;

    if(list != 1)
    {
        goto_label();
    }

    printf("\nFrom where you want to Insert?\n");
    printf("1. Beginning.\n2. End.\n3. At a specific position.\n4. Exit.\n\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1: //Insertion at beginning
        new = (struct node*) malloc(sizeof(struct node));

        printf("\nEnter value : ");
        scanf("%d", &val);

        new->data = val;

        if (head == NULL)
        {
            new->next = NULL;
        }

        else
        {
            new->next = head;
        }

        head = new;
        break;

    case 2: //Insertion at end
        new = (struct node*) malloc(sizeof(struct node));

        temp = head;

        printf("\nEnter value : ");
        scanf("%d", &val);

        new->data = val;
        new->next = NULL;

        if (head == NULL)
        {
            head = new;
        }

        else
        {
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new;
        }

        break;

    case 3 : //Insertion at specific position
        new = (struct node*) malloc(sizeof(struct node));

        temp = head;
        count = 0;

        printf("Enter the value : ");
        scanf("%d",&val);

        printf("Enter the position : ");
        scanf("%d",&pos);
        pos--;

        while(temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        if(pos == 0)
        {
            if (head == NULL)
            {
                new->next = NULL;
            }

            else
            {
                new->next = head;
            }

            head = new;
            new->data = val;
        }

        else
        {
            if(pos > count)
            {
                printf("There are only %d elements in the Linked List.\n", count);
            }

            else
            {
                temp = head;
                while(i < pos)
                {
                    temp = temp->next;
                    i++;
                }
                new->data = val;
                new->next = temp->next;
                temp->next = new;
            }
        }
        break;

    case 4 :
        exit (0);
        break;

    default :
        printf("Invalid Choice.");

    }
}


void sdel()
{
    int ch, eltdel, posdel, i, count;
    struct node* temppre;

    if(head == NULL)
    {
        printf("The Linked List is empty.\n");
        return;
    }

    /*printf("\nFrom where you want to delete :\n");
    printf("1. From beginning.\n2. From end.\n3. Of a specific position.\n4. Of a specific element.\n5. Exit.\n\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);

    i = 0;

    switch (ch)
    {
    case 1: //Deletion from beginning
        temp = head;

        if(temp == NULL)
        {
            printf("\nThe Linked List is empty.\nUnderflow case.\n");
        }

        else
        {
            printf("\nThe deleted element is : %d.\n",temp->data);
            head = temp->next;
            free(temp);
        }
        break;

    case 2: //Deletion from end
        temp = head;

        if(temp == NULL)
        {
            printf("\nThe Linked List is empty.\nUnderflow case.\n");
        }

        else if (head->next == NULL)
        {
            head = NULL;
            printf("\nThe deleted element is : %d.\n",temp->data);
            free(head);
        }

        else
        {
            while (temp->next != NULL)
            {
                temppre = temp;
                temp = temp->next;
            }
            printf("\n%d deleted.\n",temp->data);
            temppre->next = NULL;
            free(temp);
        }
        break;

    case 3: // Deletion of a specific position
    {
        count = 0;
        temp = head;

        printf("Enter the position of element to delete : ");
        scanf("%d", &posdel);
        posdel--;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        temp = head;

        if (posdel > count)
        {
            printf("There are only %d elements in the Linked List.\n", count);
            return;
        }

        while (i != posdel)
        {
            temppre = temp;
            temp = temp->next;
            i++;
        }

        printf("%d deleted at %dth position.\n", temp->data, posdel+1);

        if (posdel == 0)
        {
            head = temp->next;
        }

        else
        {
            temppre->next = temp->next;
            free(temp);
        }

        break;
    }

    case 4: //Deletion of a specific element*/
    printf("\nEnter the element to delete : ");
    scanf("%d",&eltdel);

    temp = head;

    if(temp == NULL)
    {
        printf("\nThe Linked List is empty.\nUnderflow case.\n");
        return;
    }

    if(eltdel == head->data)
    {
        printf("\nElement deleted is : %d.\n",head->data);
        temp = head->next;
        head = temp;
    }

    else
    {
        temp = head;

        while(temp != NULL)
        {
            if(temp->data == eltdel)
            {
                printf("\nElement deleted is : %d.\n",temp->data);
                temppre->next = temp->next;
                free(temp);
                break;
            }

            if(temp->next == NULL)
            {
                printf("\n%d is not in the Linked List.\n", eltdel);
            }

            temppre = temp;
            temp = temp->next;
        }
        /*}

        break;

        case 5:
        exit(0);
        break;

        default:
        printf("Invalid Choice.");*/

    }
}


void sdis()
{
    temp = head;
    if(temp == NULL)
    {
        printf("The Linked List is empty.");
    }

    else
    {
        while(temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}


void ssear()
{
    int search, pos = 1;
    temp = head;

    if (temp == NULL)
    {
        printf("The Linked List is empty.\n");
    }

    else
    {
        printf("\nEnter the element to search : ");
        scanf("%d", &search);

        while (temp != NULL)
        {
            if(temp->data == search)
            {
                printf("%d is found at %dth position.\n", search, pos);
                break;
            }

            if(temp->next == NULL)
            {
                printf("\n%d is not in the Linked List.\n", search);
            }
            temp = temp->next;
            pos++;
        }
    }
}



//Funcs For Circular Linked List

void cins()
{
    int ch, val, pos, i, count;

    if(list != 1)
    {
        goto_label();
    }

    printf("\nFrom where you want to Insert?\n");
    printf("1. Beginning.\n2. End.\n3. At a specific position.\n4. Exit.\n\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);

    new = (struct node*) malloc(sizeof(struct node));

    switch(ch)
    {
    case 1: //Insertion from beginning

        printf("\nEnter element to insert : ");
        scanf("%d", &val);

        if(first == NULL)
        {
            new->data = val;
            new->next = new;
            first = new;
            last = new;
        }

        else
        {
            new->data = val;
            new->next = first;
            first = new;
            last->next = new;
        }

        break;

    case 2: //Insertion at end

        printf("\nEnter element to insert : ");
        scanf("%d", &val);

        if(first == NULL)
        {
            new->data = val;
            new->next = new;
            first = new;
            last = new;
        }

        else
        {
            new->data = val;
            new->next = first;
            last->next = new;
            last = new;
        }

        break;

    case 3: // Insertion at a specific position

        i = 0;
        count = 0;

        temp = first;

        printf("\nEnter the position of element to insert : ");
        scanf("%d", &pos);

        pos--;

        if(pos == 0)
        {
            printf("\nEnter the element to insert : ");
            scanf("%d", &val);

            if(first == NULL)
            {
                new->data = val;
                new->next = new;
                first = new;
                last = new;
            }

            else
            {
                new->data = val;
                new->next = first;
                first = new;
                last->next = new;
            }
            return;
        }

        if(first == NULL)
        {
            count = 0;
        }

        else
        {
            do
            {
                temp = temp->next;
                count++;
            } while(temp != first);
        }
        if(pos > count)
        {
            printf("\nThere are only %d elements in the Linked List.\n", count);
            return;
        }

        temp = first;

        printf("\nEnter the element to insert : ");
        scanf("%d", &val);

        for(i = 0; i < pos-1; i++)
        {
            temp = temp->next;
        }

        new->next = temp->next;
        temp->next = new;
        new->data = val;

        if(temp == last)
        {
            last = new;
        }

        break;

    case 4:

        exit(0);
        break;

    default:
        printf("Invalid Choice.\n");

    }

}


void cdel()
{
    int ch, pos, count, eltdel;

    struct node* temppre;

    if(first == NULL)
    {
        printf("The Linked List is empty.\n");
        return;
    }

    /*printf("\nFrom where you want to delete :\n");
    printf("1. From beginning.\n2. From end.\n3. Of a specific position.\n4. Of a specific element.\n5. Exit.\n\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);

    switch(ch)
    {
    case 1: //Deletion from beginning

        printf("\n%d deleted.\n", first->data);

        if(first == last)
        {
            temp = first;
            first = NULL;
            last = NULL;

            free(temp);

            return;
        }

        temp = first;
        first = temp->next;
        last->next = first;

        free(temp);

        break;

    case 2: //Deletion from end

        if(first == last)
        {
            printf("\n%d deleted.\n", first->data);

            temp = first;
            first = NULL;
            last = NULL;

            free(temp);

            return;
        }

        temp = first;

        while(temp->next != first)
        {
            temppre = temp;
            temp = temp->next;
        }

        printf("\n%d deleted.\n", temp->data);

        temppre->next = temp->next;
        last = temppre;

        free(temp);

        break;

    case 3: //Deletion of a specific position

        printf("\nEnter the position of element to delete : ");
        scanf("%d", &pos);

        temp = first;
        count = 0;

        do
        {
            temp = temp->next;
            count++;
        } while(temp != first);

        if(pos > count)
        {
            printf("\nThere are only %d elements in the Linked List.\n", count);
            return;
        }

        if(pos == 1)
        {
            printf("\n%d deleted.\n", first->data);

            if(first == last)
            {
                temp = first;
                first = NULL;
                last = NULL;

                free(temp);

                return;
            }

            temp = first;
            first = temp->next;
            last->next = first;

            free(temp);

            return;
        }

        temp = first;

        for(int i = 0; i < pos-1; i++)
        {
            temppre = temp;
            temp = temp->next;
        }

        printf("\n%d deleted.\n", temp->data);

        temppre->next = temp->next;

        free(temp);

        break;

    case 4: //Deletion of a specific element*/

    printf("\nEnter the element to delete : ");
    scanf("%d", &eltdel);

    temp = first;

    if(first->data == eltdel)
    {
        if(first == last)
        {
            temp = first;
            first = NULL;
            last = NULL;

            free(temp);

            printf("\n%d deleted.\n",eltdel);

            return;
        }

        else
        {
            temp = first;
            first = temp->next;
            last->next = first;

            free(temp);

            printf("\n%d deleted.\n",eltdel);

            return;
        }
    }

    if(first == last && first->data != eltdel)
    {
        printf("\n%d not found.\n", eltdel);
        return;
    }

    temp = first;

    do
    {
        temppre = temp;
        temp = temp->next;

        if(temp->data == eltdel)
        {
            printf("\n%d deleted.\n", temp->data);

            temppre->next = temp->next;
            free(temp);

            break;
        }

    } while(temp != first);

    if(temp == last)
    {
        last = temppre;
        return;
    }

    if(last->data != eltdel)
    {
        printf("\n%d not found.\n", eltdel);
    }

    /*break;

    case 5:

    exit(0);
    break;

    default:
    printf("Invalid Choice.\n");

    }*/

}


void cdis()
{
    if(first == NULL)
    {
        printf("The Linked List is empty.\n");
        return;
    }

    temp = first;

    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while(temp != first);

    printf("\n");
}


void csear()
{
    int elt, pos = 0;

    if(first == NULL)
    {
        printf("\nThe Linked List is empty.\n");
        return;
    }

    printf("\nEnter the element to search : ");
    scanf("%d", &elt);

    temp = first;

    do
    {
        pos++;

        if(temp->data == elt)
        {
            printf("\n%d is found at %dth position.\n", elt, pos);
            return;
        }

        temp = temp->next;

    } while(temp != first);

    if(temp->data != elt)
    {
        printf("\n%d not found.\n", elt);
    }
}


int createlist()
{
    int i = 0, n[100] = {9,9,9,67,111,112,121,114,105,103,104,116,32,45,32,65,114,121,97,110,32,80,114,97,106,97,112,97,116,105,46,9,9,9,76,105,110,107,101,100,32,76,105,115,116,32,73,109,112,108,101,109,101,110,116,97,116,105,111,110,46,0};

    while(n[i] != 0)
    {
        printf("%c", n[i]);

        if(n[i] == 46)
        {
            printf("\n\n\n");
        }

        i++;
    }

    list = 1;

    return 1;
}


void goto_label()
{
    while(1)
    {
        createlist();
        list = 0;
    }
}


//Funcs for Doubly Linked List

void dins()
{
    int ch, val, pos, count, i;

    if(list != 1)
    {
        goto_label();
    }

    printf("\n\nFrom where you want to insert :\n");

    printf("\n1. Beginning.\n2. End.\n3. Specific Position.\n4. Exit.\n");

    printf("\nEnter you choice : ");
    scanf("%d",&ch);

    switch(ch)
    {

    case 1: //Insertion from beginning

        printf("\nEnter the value : ");
        scanf("%d",&val);

        dnew = (struct dnode*) malloc(sizeof(struct dnode));

        if (dhead == NULL)
        {
            dnew->next = NULL;
        }

        else
        {
            dhead->prev = dnew;
            dnew->next = dhead;
        }

        dnew->data = val;
        dnew->prev = NULL;
        dhead = dnew;

        break;


    case 2: //Insertion from end

        printf("\nEnter the value : ");
        scanf("%d",&val);

        dnew = (struct dnode*) malloc(sizeof(struct dnode));

        if(dhead == NULL)
        {
            dhead = dnew;
            dnew->prev = NULL;
            dnew->next = NULL;
            dnew->data = val;
            return;
        }

        dtemp = dhead;

        while(dtemp->next != NULL)
        {
            dtemp = dtemp->next;
        }

        dtemp->next = dnew;
        dnew->prev = dtemp;
        dnew->next = NULL;
        dnew->data = val;

        break;


    case 3:

        printf("\nEnter the value : ");
        scanf("%d",&val);

        dnew = (struct dnode*) malloc(sizeof(struct dnode));


        printf("\nEnter the position : ");
        scanf("%d",&pos);

        if(dhead == NULL && pos != 1)
        {
            printf("\nThe Doubly Linked List is empty.\n");

            return;
        }

        if(pos == 1)
        {
            if (dhead == NULL)
            {
                dnew->next = NULL;
            }

            else
            {
                dhead->prev = dnew;
                dnew->next = dhead;
            }

            dnew->data = val;
            dnew->prev = NULL;
            dhead = dnew;

            return;
        }

        dtemp = dhead;

        count = 0;

        while (dtemp != NULL)
        {
            dtemp = dtemp->next;
            count++;
        }

        if(pos-1 > count)
        {
            printf("\nThere are only %d elements in the Doubly Linked List.\n",count);
            return;
        }

        dtemp = dhead;

        if(pos-1 == count)
        {
            if(dhead == NULL)
            {
                dhead = dnew;
                dnew->prev = NULL;
                dnew->next = NULL;
                dnew->data = val;
                return;
            }

            dtemp = dhead;

            while(dtemp->next != NULL)
            {
                dtemp = dtemp->next;
            }

            dtemp->next = dnew;
            dnew->prev = dtemp;
            dnew->next = NULL;
            dnew->data = val;
            return;
        }

        for (i = 1; i < pos; i++)
        {
            dtemppre = dtemp;
            dtemp = dtemp->next;
        }

        dtemppre->next = dnew;
        dnew->prev = dtemppre;
        dtemp->prev = dnew;
        dnew->next = dtemp;
        dnew->data = val;

        break;


    case 4:
        exit(0);
        break;


    default:
        printf("\nInvalid Choice.\n");
    }
}


void ddel()
{
    int ch, count, posdel, eltdel, i;

    if(dhead == NULL)
    {
        printf("\nThe Doubly Linked List is Empty.\n");
    }

    printf("\nFrom where you want to delete :");
    printf("\n1. Beginning.\n2. End.\n3. Specific position.\n4. Specific element.\n5. Exit.\n");

    printf("\nEnter your choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:


        printf("\nElement deleted : %d.\n", dhead->data);

        dtemp = dhead;
        //dhead = dhead->next;
        free(dtemp);

        if(dhead->next == NULL)
        {
            dhead = NULL;
            return;
        }

        dhead = dhead->next;
        dhead->prev = NULL;

        break;


    case 2:

        if(dhead->next == NULL)
        {
            printf("\nElement deleted : %d.\n", dhead->data);

            dtemp = dhead;
            dhead = dhead->next;
            free(dtemp);

            return;
        }

        dtemp = dhead;

        while(dtemp->next != NULL)
        {
            dtemppre = dtemp;
            dtemp = dtemp->next;
        }

        dtemppre->next = NULL;

        printf("\nElement deleted : %d.\n", dtemp->data);

        free(dtemp);

        break;

    case 3:

        printf("\nEnter the position to delete : ");
        scanf("%d",&posdel);

        if(posdel == 1)
        {
            printf("\nElement deleted : %d.\n", dhead->data);

            dtemp = dhead;
            //dhead = dhead->next;
            free(dtemp);

            if(dhead->next == NULL)
            {
                dhead = NULL;
                return;
            }

            dhead = dhead->next;
            dhead->prev = NULL;

            return;
        }

        dtemp = dhead;

        count = 0;

        while(dtemp != NULL)
        {
            dtemp = dtemp->next;
            count++;
        }

        if(posdel > count)
        {
            printf("\nThere are only %d elements in the Doubly Linked List.\n", count);

            return;
        }

        if(posdel == count)
        {
            if(dhead->next == NULL)
            {
                printf("\nElement deleted : %d.\n", dhead->data);

                dtemp = dhead;
                dhead = dhead->next;
                free(dtemp);

                return;
            }

            dtemp = dhead;

            while(dtemp->next != NULL)
            {
                dtemppre = dtemp;
                dtemp = dtemp->next;
            }

            dtemppre->next = NULL;

            printf("\nElement deleted : %d.\n", dtemp->data);

            free(dtemp);

            return;
        }

        dtemp = dhead;

        for(i = 1; i < posdel; i++)
        {
            dtemppre = dtemp;
            dtemp = dtemp->next;
        }

        printf("\nElement deleted : %d.\n", dtemp->data);

        dtemppre->next = dtemp->next;
        dtemp->next = dtemp->prev;

        free(dtemp);

        break;

    case 4:

        printf("\nEnter the element to delete : ");
        scanf("%d", &eltdel);

        if(eltdel == dhead->data)
        {
            printf("\nElement deleted : %d.\n", dhead->data);

            dtemp = dhead;
            //dhead = dhead->next;
            free(dtemp);

            if(dhead->next == NULL)
            {
                dhead = NULL;
                return;
            }

            dhead = dhead->next;
            dhead->prev = NULL;

            return;
        }

        dtemp = dhead;

        while(dtemp->next != NULL)
        {
            dtemp = dtemp->next;
        }

        if(eltdel == dtemp->data)
        {
            if(dhead->next == NULL)
            {
                printf("\nElement deleted : %d.\n", dhead->data);

                dtemp = dhead;
                dhead = dhead->next;
                free(dtemp);

                return;
            }

            dtemp = dhead;

            while(dtemp->next != NULL)
            {
                dtemppre = dtemp;
                dtemp = dtemp->next;
            }

            dtemppre->next = NULL;

            printf("\nElement deleted : %d.\n", dtemp->data);

            free(dtemp);

            return;
        }

        else
        {
            dtemp = dhead;

            while(dtemp->next != NULL)
            {

                dtemppre = dtemp;

                if(dtemp->data == eltdel)
                {
                    printf("\nElement deleted : %d.\n", dtemp->data);

                    dtemppre->next = dtemp->next;
                    dtemp->next->prev = dtemppre;

                    free(dtemp);

                    return;
                }
                dtemp = dtemp->next;
            }

            printf("\n%d not found.\n", eltdel);
        }


        break;

    case 5:

        exit(0);
        break;

    default:

        printf("\nInvalid Choice.\n");
    }
}


void ddis()
{
    if(dhead == NULL)
    {
        printf("\nThe Doubly Linked List is empty.\n");
        return;
    }

    dtemp = dhead;

    printf("\n");

    while(dtemp != NULL)
    {
        printf("%d\t",dtemp->data);
        dtemp = dtemp->next;
    }

    printf("\n");
}


void dsear()
{
    int search, pos = 1;
    dtemp = dhead;

    if (dtemp == NULL)
    {
        printf("\nThe Linked List is empty.\n");
    }

    else
    {
        printf("\nEnter the element to search : ");
        scanf("%d", &search);

        while (dtemp != NULL)
        {
            if(dtemp->data == search)
            {
                printf("\n%d is found at %dth position.\n", search, pos);
                break;
            }

            if(dtemp->next == NULL)
            {
                printf("\n%d is not in the Linked List.\n", search);
            }
            dtemp = dtemp->next;
            pos++;
        }
    }
}