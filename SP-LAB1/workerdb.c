/* In order to create an employee database,
this programme reads data from a text file.
Subsequently, the user is prompted to do operations on the database.
The creation of a unique helper library facilitates file reading.

Shubham Das
11/1/2023
*/

#include <stdio.h>
#include <string.h>
#include "readfile.h"
#define MAXNAME 64

extern FILE *file; // variable used to read data file
struct person      // Data structure used to store employees into the DB
{
    char fname[MAXNAME];
    char lname[MAXNAME];
    int id;
    int salary;
};
struct person db[1024];   // Create array of person struct for DB
int employee_counter = 0; // Used to keep track of how many employees are in the DB
char term;                // used for validation checks

/* The below function is used to print out the DB */
void PrintDB(struct person x[], int x_size)
{
    int i;

    printf("\nName\t\t\t\tSALARY\t   ID\n");
    printf("----------------------------------------------\n");
    for (i = 0; i < x_size; i++)
    {
        printf("%-15s\t%-15s\t%d\t%d\n", x[i].fname, x[i].lname, x[i].salary, x[i].id);
    }
    printf("----------------------------------------------\n");
    printf(" Number of Employees (%d)\n", x_size);
}

/* The below function looks up a user from the DB via their Employee ID using binary search.
If the user is not found it returns a "User not found" message.
A recursive binary search function. It returns location of x in given array arr[l..r] is present,
otherwise -1
*/
int LookupID(struct person arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid].id == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid].id > x)
            return LookupID(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return LookupID(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

/* The below function looks up a user from the DB via their last name using a linear search.
If the user is not found it returns a "User not found" message */
int LookupLName(struct person arr[], int m, char *name)
{
    int i;
    for (i = 0; i < m; i++)
    {
        if (strcmp(arr[i].lname, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

/* Adds an employee to the DB. Prompts user for employee details and validates that the info
is in the correct format */
int AddEmployee(struct person arr[])
{
    char newfname[MAXNAME];
    char newlname[MAXNAME];
    int newsalary;
    int confirm;

    printf("\nEnter the first name of the employee: ");
    scanf("%s", newfname);
    if (strlen(newfname) > 64)
    {
        printf("Invalid entry. Please try again.\n");
        return 0;
    }
    printf("Enter the last name of the employee: ");
    scanf("%s", newlname);
    if (strlen(newfname) > 64)
    {
        printf("Invalid entry. Please try again.\n");
        return 0;
    }
    printf("Enter employee's salary (30000 to 150000): ");
    scanf("%d", &newsalary);
    if (newsalary < 30000 || newsalary > 150000)
    {
        printf("Invalid entry. Please try again.\n");
        return 0;
    }
    printf("\nDo you want to add the following employee to the DB?\n");
    printf("\t%s %s, \tSalary: %d\n", newfname, newlname, newsalary);
    printf("\nEnter 1 for yes, 0 for no: ");
    scanf("%d", &confirm);

    if (confirm == 1)
    {
        strcpy(db[employee_counter].fname, newfname);
        strcpy(db[employee_counter].lname, newlname);
        db[employee_counter].salary = newsalary;
        db[employee_counter].id = db[employee_counter - 1].id + 1;
        employee_counter++;
        printf("New employee added!\n");
    }
    return 1;
}

/* The below function loads in the data from the data file and creates the DB */
void CreateDB(char *datafile)
{
    if (open_file(datafile) == 0)
    {
        char buffer[135];
        int ret;
        while (fgets(buffer, sizeof(buffer), file))
        {
            ret = read_int(buffer, 1, &db[employee_counter].id);
            ret = read_int(buffer, 2, &db[employee_counter].salary);
            ret = read_string(buffer, 1, &db[employee_counter].fname);
            ret = read_string(buffer, 2, &db[employee_counter].lname);
            employee_counter++;
        }

        if (feof(file)) // hit end of file
        {
            close_file(file);
        }
    }
}

// Used for sorting
void Swap(struct person *xp, struct person *yp)
{
    struct person temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform Selection Sort on Employee ID
void SelectionSort(struct person arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j].id < arr[min_idx].id)
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        Swap(&arr[min_idx], &arr[i]);
    }
}

/* Main function that displays the DB actions menu to the user until they choose to close out of the program. */
int main(int argc, char *argv[])
{
    if (argc != 2) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf("usage: %s filename\n", argv[0]);
    }
    else
    {
        CreateDB(argv[1]);                   // Calls the function above to create the DB from the input data file
        SelectionSort(db, employee_counter); // Sorts the DB by Employee ID

        int choice; // User's menu selection
        int x = 0;  // employee location in DB
        // Continue to display the DB menu until the user selects option '5' to quit
        while (1)
        {
            printf("\nEmployee DB Menu:\n");
            printf("----------------------------------\n");
            printf("\t(1) Print the Database\n");
            printf("\t(2) Lookup by ID\n");
            printf("\t(3) Lookup by Last Name\n");
            printf("\t(4) Add an Employee\n");
            printf("\t(5) Quit\n");
            printf("----------------------------------\n");
            printf("Enter your choice: ");

            scanf("%d", &choice); // Read user choice for DB menu

            // Select the appropriate function based on user selection.
            switch (choice)
            {
            case 1:
                PrintDB(db, employee_counter);
                break;
            case 2:;
                int target_ID; // target employee ID to search
                printf("\nPlease enter an employee ID: ");
                scanf("%d", &target_ID);
                x = LookupID(db, 0, employee_counter, target_ID);
                if (x == -1)
                {
                    printf("\nUser with employee ID '%d' not found\n", target_ID);
                }
                else
                {
                    printf("\nName\t\t\t\tSALARY\t   ID\n");
                    printf("----------------------------------------------\n");
                    printf("%-15s\t%-15s\t%d\t%d\n", db[x].fname, db[x].lname, db[x].salary, db[x].id);
                    printf("----------------------------------------------\n");
                }

                break;
            case 3:;
                char target_name[MAXNAME]; // target name to search
                printf("\nPlease enter an employee's last name: ");
                scanf("%s", target_name);
                x = LookupLName(db, employee_counter, target_name);
                if (x == -1)
                {
                    printf("\nUser with last name '%s' not found\n", target_name);
                }
                else
                {
                    printf("\nName\t\t\t\tSALARY\t   ID\n");
                    printf("----------------------------------------------\n");
                    printf("%-15s\t%-15s\t%d\t%d\n", db[x].fname, db[x].lname, db[x].salary, db[x].id);
                    printf("----------------------------------------------\n");
                }
                break;
            case 4:
                AddEmployee(db);
                break;
            case 5:
                printf("\nLater!\n");
                return 0;
                break;
            default:
                printf("\nInvalid input. Please try again.\n");
                break;
            }
        }
    }
}