#include <stdio.h>

struct BankAccount {
    int accountNumber;
    char name[50];
    float balance;
};

void registerAccount(struct BankAccount* account) {
    printf("Enter your account number: ");
    scanf("%d", &(account->accountNumber));

    printf("Enter your name: ");
    scanf("%s", account->name);

    account->balance = 0;

    printf("Account registered successfully!\n");
}

void deposit(struct BankAccount* account, float amount) {
    account->balance += amount;
    printf("Amount deposited successfully!\n");
}

void withdraw(struct BankAccount* account, float amount) {
    if (amount > account->balance) {
        printf("Insufficient balance!\n");
    } else {
        account->balance -= amount;
        printf("Amount withdrawn successfully!\n");
    }
}

void checkBalance(struct BankAccount* account) {
    printf("Account Number: %d\n", account->accountNumber);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

int main() {
    struct BankAccount account;
    int choice;
    float amount;

    printf("Bank Application Menu\n");
    printf("1. Register Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerAccount(&account);
                break;

            case 2:
                printf("Enter the amount to deposit: ");
                scanf("%f", &amount);
                deposit(&account, amount);
                break;

            case 3:
                printf("Enter the amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&account, amount);
                break;

            case 4:
                checkBalance(&account);
                break;

            case 5:
                printf("Thank you for using the bank application!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
