
#include <stdio.h>
#include <string.h> //needed for strcmp and strcpy
#include <stdlib.h>

/*Function: node constructor
What it does: creates node for the linked list
*/
typedef struct node {
/*PS: When I first started reading the HW I thought userID and itemID will be long numbers, so I thought taking them as a string would be better.
After I created the linkedlist and looked at the output examples I realized they are also integers, but I didn't change them.*/
    char userID[5];
    char itemID[5];
    float rating;
    //creates the next node
    struct node *next;
} Node;

//pointer for the head node
Node *head = NULL;

/*Function: createcreateNewNode
Parameters: userID[] and itemID[] are char arrays, rating is a float
What it does: creates node for the linked list
*/
Node *createNewNode(char userID[], char itemID[], float rating) {
    //malloc allocates memory for the node to be created
    Node *node = (Node*)malloc(sizeof(Node));
    //put the userID, itemID and rating to
    //node's userID, itemID and rating
    strcpy(node->userID, userID);
    strcpy(node->itemID, itemID);
    node->rating =rating;
    //since we don't know if there is a next node
    //we make it NULL
    node->next = NULL;
    //return the node pointer to the new node
    return node;
}

/*Function: insert
Parameters: userID[] and itemID[] are char arrays, rating is a float
What it does: inserts the nodes to the linked List
*/
void insert(char userID[], char itemID[], float rating) {
    Node *curr = head;
    //if we already have the data about the input:
    while (curr != NULL) {
        //Check if we already have the rating for a given userID and itemID
        if (strcmp(curr->userID, userID) == 0 && strcmp(curr->itemID, itemID) == 0) {
        //if so, just change the rating.
            curr->rating = rating;
        printf("Customer rating (%s, %s) is updated\n", userID, itemID);
            return;
        }
        //move the pointer to the next node
        curr = curr->next;
    }
    //create a new node if user is entering for the first time
    Node *node = createNewNode(userID, itemID, rating);
    //if list is empty insert head
    if (head == NULL) {
        head = node;
    } else {
        Node *curr = head;
        //find the last node to add the values
        while (curr->next != NULL) {
            curr = curr->next;
        }
        //go to the next node
        curr->next = node;
    }
    printf("Customer rating (%s, %s) is added successful\n", userID, itemID);
}


/*Function: removeGivenNode
Parameters: userID[] and itemID[] are char arrays
What it does: removes the nodes from the linked List
*/
void removeGivenNode(char userID[], char itemID[]) {
    //we need two pointers: curr and prev in order to attach
    //the nodes that are left after the removal
    Node *curr = head;
    //since curr points to head it doesn't have any previous nodes
    Node *prev = NULL;

    while (curr != NULL) {
        //if we find the node that is equal to the given node:
        if (strcmp(curr->userID, userID) == 0 && strcmp(curr->itemID, itemID) == 0) {
            //is the given node head of the list?
            //if so, move the head to the next node
            if (prev == NULL) {
                head = curr->next;
            } else {
                //links between two nodes are updated and given node is removed
                prev->next = curr->next;
            }
            //delete the given node
            free(curr);
            printf("Customer rating (%s, %s) is removed successful\n", userID, itemID);
            return;
        }

        //after the removal, previous node became the current node
        prev = curr;
        //and now the current node points to the next one
        curr = curr->next;
    }
    printf("Customer rating (%s, %s) does not exist\n", userID, itemID);
}


/*
THIS METHOD IS FOR DEBUGGING
I had some errors along the way so I needed to print the linkedlist from time to time
to debug.
*/
void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("(%s, %s, %.1f) -> ", current->userID, current->itemID, current->rating);
        current = current->next;
    }
    printf("NULL\n");
}



/*Function: ratingfunc
Parameters: userID[] and itemID[] are char arrays
What it does: prints the rating of the given item from the given user
*/
void ratingfunc(char userID[], char itemID[]) {
    Node *current = head;
    while (current != NULL) {
        //checks if we have the given user and given item in the list
         if (strcmp(current->userID, userID) == 0 && strcmp(current->itemID, itemID) == 0) {
          printf("Customer rating (%s, %s) is: %.1f\n", userID, itemID, (current->rating));
            return;
        }
        current = current->next;
    }
    //if the user haven't given a rating for the item:
    printf("Customer rating (%s, %s) is: 0.0\n", userID, itemID);
}


/*Function: calcAverage
Parameters: itemID[] is a char array
What it does: prints the average rating of the given item
*/
void calcAverage(char itemID[]) {
    //define a sum and make it 0 at the beginning
    float sumOfRatings = 0.0;
    //define a count to count the occurence of the item
    //so that we can divide
    int count = 0;

    Node *current = head;
    while (current != NULL) {
        //if the given item is found in the list:
        if (strcmp(current->itemID, itemID) == 0) {
            //update sum and count
            sumOfRatings = sumOfRatings + current->rating;
            count++;
        }
        //points to the next node
        current = current->next;
    }
    //if there is no data about the given item:
    if (count == 0) {
        printf("Average rating (%s) is: 0\n", itemID);
    } else {
        float average = sumOfRatings / count;
        printf("Average rating (%s) is: %.1f\n", itemID, average);
    }
}



//MAIN FUNCTION
int main() {
    //define the userID, itemID and rating again
    char userID[5];
    char itemID[5];
    float rating;
    //create a string to check the input from the user
    char whichFunction[10];
//use a do-while loop to check the input from the user
    do {
        scanf("%s", whichFunction);
        //if user enters INSERT, take the arguments and call the function
        if (strcmp(whichFunction, "INSERT") == 0) {
            scanf("%s", userID);
            scanf("%s", itemID);
            scanf("%f", &rating);
            insert(userID, itemID, rating);
        }
        //if user enters REMOVE, take the arguments and call the function
        else if (strcmp(whichFunction, "REMOVE") == 0) {
            scanf("%s", userID);
            scanf("%s", itemID);
            removeGivenNode(userID, itemID);
        }
        //if user enters AVERAGE, take the arguments and call the function
        else if (strcmp(whichFunction, "AVERAGE") == 0) {
            scanf("%s", itemID);
            calcAverage(itemID);
        }
        //if user enters RATING, take the arguments and call the function
        else if (strcmp(whichFunction, "RATING") == 0) {
            scanf("%s", userID);
            scanf("%s", itemID);
            ratingfunc(userID, itemID);
        }
        //end when user enters FINISH
    } while (strcmp(whichFunction, "break") != 0);

//printList(head);
    return 0;
}

/*Contributed by Hasret Türkmen*/
