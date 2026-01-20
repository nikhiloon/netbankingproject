#include <stdio.h>

int main()
{
    int pin[5] = {1234, 5678, 9012, 3456, 7890};// ispe loop laga hai jisse 5 users ka pin store ho sake 
    int enter_pin;

    int transaction_type [5][100];//yeh bhi 5 logo ke liye hai 
    float transaction_amount[5][100];
    float balance [5] = {1000.0, 2500.0, 3000.0, 1500.0, 5000.0};
    int option;
    int user_index = -1;
    int count[5] = {0,0,0,0,0};

    printf("Enter your PIN: ");
    scanf("%d", &enter_pin);
    for (int i = 0; i < 5; i++)
    {
        if (pin[i] == enter_pin)
        {
            user_index = i;
            break;
        }
    }
    if (user_index == -1) {
        printf("incorrect print try again\n");
        return 0;
    }

    {

        printf("Welcome to net banking\n");
        do
        {
            printf("\nChoose your option:\n1. Check balance  \n2. Withdraw money\n  3. Deposit money\n  4. Search transaction history\n5. Exit\n");
       
        scanf("%d", &option);
        
        if (option == 1)
        {
            printf(" your balance is %f", balance[user_index]);// simple balance check karne ke liye option 1 pr jaye
        }
        else if (option == 2)
        {
            float withdraw_amount;
            printf(" enter amount to withdraw: ");//withdraw amount lene ke liye 
            scanf("%f", &withdraw_amount);
            if (withdraw_amount > balance[user_index])
            {
                printf(" insufficient balance");
            }
            else
            {
                balance[user_index]-= withdraw_amount;
                transaction_type[user_index][count[user_index]] = 2; // 2 for withdrawal
                transaction_amount[user_index][count[user_index]]= withdraw_amount;// isse store hoga withdraw amount ka record
                count[user_index]++ ;
                printf(" withdraw sucessfully !! new balance is %f", balance[user_index]);
            }
        }
        else if (option == 3)
        {
            float deposit_amount;
            printf(" enter amount to deposit: ");//wo amount likho jo tum diposit karne chahte ho 
            scanf("%f", &deposit_amount);
            balance[user_index] += deposit_amount;
            transaction_type[user_index][count[user_index]] = 3; // 3 for deposit
            transaction_amount[user_index][count[user_index]] = deposit_amount;// isse store hoga deposit amount ka record 
            count[user_index]++;

            printf(" amount deposited successfully.!!! new balance is %f", balance[user_index]);
        }
        else if (option == 4){ // search transaction history check karne ke liye option 4 pr jaye 
        int search;


        
            printf(" enter transaction type to search 2 for withdrawal 3 for deposit:");
            scanf("%d", &search);
            printf(" transactsion history:\n");
            int found = 0;
        for (int i = 0; i < count[user_index]; i++)
            { 
            if (transaction_type[user_index][i] == search)
            {
                found = 1;
                if (search == 2)
                {
                    printf(" withdrawal of amount: %f\n", transaction_amount[user_index][i]);// ye line withdrawal amount ko print karega
                }
                else  
                {
                    printf(" deposit of amount: %f\n", transaction_amount[user_index][i]);// ye line deposit amount ko print karega
                }
            }
        }
        if (!found)
        {
            printf("No transaction found.");
        }
        }
          else if (option == 5)
        {
            printf("Thank you for using net banking. Goodbye!\n");
            
        }

        else
        {
            printf(" invalid option selected");
        }
        
      
        } while ( option != 5);// iss loop ka matlab hai tak tak loop chalta rahega jab tk user 5 option choose na kare jisse loop ecit ho jaye
        }
    
    
    return 0;
}