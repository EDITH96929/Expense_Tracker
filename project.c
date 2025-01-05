#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_DESCRIPTION_LENGTH 100

// Structure Definitions
typedef struct {
    int id;
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    char type[10]; // "Income" or "Expense"
} Transaction;

// Global Variables
Transaction transactions[MAX_TRANSACTIONS];
int transactionCount = 0;

// Function Prototypes
void addTransaction();
void viewTransactions();
void generateReport();
float calculateBalance();

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Generate Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction();
                break;
            case 2:
                viewTransactions();
                break;
            case 3:
                generateReport();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Add Transaction Function
void addTransaction() {
    if (transactionCount >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Cannot add more transactions.\n");
        return;
    }

    Transaction newTransaction;
    newTransaction.id = transactionCount + 1;

    printf("Enter description: ");
    getchar();
    fgets(newTransaction.description, MAX_DESCRIPTION_LENGTH, stdin);
    newTransaction.description[strcspn(newTransaction.description, "\n")] = '\0';

    printf("Enter amount: ");
    scanf("%f", &newTransaction.amount);

    printf("Enter type (Income/Expense): ");
    scanf("%s", newTransaction.type);

    transactions[transactionCount++] = newTransaction;

    printf("Transaction added successfully.\n");
}

// View Transactions Function
void viewTransactions() {
    printf("\n%-5s %-30s %-10s %-10s\n", "ID", "Description", "Amount", "Type");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("%-5d %-30s %-10.2f %-10s\n", transactions[i].id, transactions[i].description, transactions[i].amount, transactions[i].type);
    }
}

// Generate Report Function
void generateReport() {
    float totalIncome = 0, totalExpense = 0;
    for (int i = 0; i < transactionCount; i++) {
        if (strcmp(transactions[i].type, "Income") == 0) {
            totalIncome += transactions[i].amount;
        } else if (strcmp(transactions[i].type, "Expense") == 0) {
            totalExpense += transactions[i].amount;
        }
    }

    printf("\nExpense Report\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Net Balance: %.2f\n", totalIncome - totalExpense);
}

// Calculate Balance Function
float calculateBalance() {
    float balance = 0;
    for (int i = 0; i < transactionCount; i++) {
        if (strcmp(transactions[i].type, "Income") == 0) {
            balance += transactions[i].amount;
        } else if (strcmp(transactions[i].type, "Expense") == 0) {
            balance -= transactions[i].amount;
        }
    }
    return balance;
}
