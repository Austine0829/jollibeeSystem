#include <iostream>
#include <fstream>

using namespace std;

using std:: string, std:: cout, std:: cin;

namespace rem
{
    int remove(std::string const& filename)
    {
        return std::remove(filename.c_str());
    }
}

namespace ren
{
    int rename(std::string const& filename, std::string const& filename2)
    {
        return std::rename(filename.c_str(), filename2.c_str());
    }
}

class jollibeeSystem{
    protected: 
     string userName;
     string userPass;
     string accName;
     int userBalance = 0;
    
    public:
     string productName;
     int productPrice;

    public:
     string orderStorageOne[18];
     string orderStorageTwo[18];
     string orderStorageThree[17];
     string orderStorageFour[9];
     string orderStorageFive[17];
     string orderStorageSix[2];
     string orderStorageSeven[14];
     string orderStorageEight[10];
     string orderStorageNine[12];
     string orderStorageTen[3];
     int quantity[17];
     int quantityTwo[18];
     int quantityThree[17];
     int quantityFour[9];
     int quantityFive[17];
     int quantitySix[2];
     int quantitySeven[14];
     int quantityEight[10];
     int quantityNine[12];
     int quantityTen[3];
     int size[10] = {sizeof(orderStorageOne)/sizeof(orderStorageOne[0]),
                    sizeof(orderStorageTwo)/sizeof(orderStorageTwo[0]),
                    sizeof(orderStorageThree)/sizeof(orderStorageThree[0]),
                    sizeof(orderStorageFour)/sizeof(orderStorageFour[0]),
                    sizeof(orderStorageFive)/sizeof(orderStorageFive[0]),
                    sizeof(orderStorageSix)/sizeof(orderStorageSix[0]),
                    sizeof(orderStorageSeven)/sizeof(orderStorageSeven[0]),
                    sizeof(orderStorageEight)/sizeof(orderStorageEight[0]),
                    sizeof(orderStorageNine)/sizeof(orderStorageNine[0]),
                    sizeof(orderStorageTen)/sizeof(orderStorageTen[0])};
     int totalBill = 0;
     
    public:
     jollibeeSystem(string productName, int productPrice){
        this->productName = productName;
        this->productPrice = productPrice;
     }

     ~jollibeeSystem(){
     }

     void printProduct(){

         cout << "---------------------------------------------------------------------------------\n";
         cout << "|Product Name: " << productName << "\n";
         cout << "|Product Price: " << productPrice << "\n";
         cout << "---------------------------------------------------------------------------------\n";
     }   

     void confirmBillFunc(){

        fstream accountData, accountData2;

         cout << "--------------------------------------------------\n";
         cout << "|\tEnter Passoword To Confirm Payment       |\n";
         cout << "--------------------------------------------------\n";
        
         cout << "Enter Password: ";
         cin >> userPass;
        
        accountData.open(userPass + ".txt", ios::in);
        accountData >> userName >> userPass >> accName >> userBalance;

        if (accountData.is_open())
        {   
            
            if (totalBill > userBalance)
            {  
                 
                 cout << "------------------------------------------------------------------\n";
                 cout << "|\t\t  Insufficient Jollibee Coins.                   |\n";
                 cout << "|\tPlease Recharge Your Account Before Ordering Again.      |\n";
                 cout << "------------------------------------------------------------------\n";

                 accountData2.open(userPass + "2.txt", ios::out | ios::app);

                 accountData2 << userName << " " << userPass << " " << accName << " " << userBalance;        
            }
            
            else
            {
                 accountData2.open(userPass + "2.txt", ios::out | ios::app);

                 userBalance -= totalBill;

                 accountData2 << userName << " " << userPass << " " << accName << " " << userBalance;     

                 printReceipt();
            }
           
        }

        else
        {
            accountData2 << userName << " " << userPass << " " << accName << " " << userBalance;
        }
              
        accountData.close();
        accountData2.close();

        rem::remove(userPass + ".txt");
        ren::rename(userPass + "2.txt", userPass + ".txt");
     }

     void printReceipt(){

         cout << "------------------------------------------------------------------------------------\n";
         cout << "|\t\t\t  YOU ORDERED THE FOLLOWING ITEMS                          |\n";
         cout << "------------------------------------------------------------------------------------\n";
    
        for (int i = 0; i < size[i]; i++)
        {
            if (!orderStorageOne[i].empty())
            {
                 cout << orderStorageOne[i] << " " << quantity[i] << "x\n";
            }

            else if (!orderStorageTwo[i].empty())
            {
                 cout << orderStorageTwo[i] << " " << quantityTwo[i] << "x\n";
            }
            
            else if (!orderStorageThree[i].empty())
            {
                 cout << orderStorageThree[i] << " " << quantityThree[i] << "x\n";
            }
            
            else if (!orderStorageFour[i].empty())
            {
                 cout << orderStorageFour[i] << " " << quantityFour[i] << "x\n";
            }

            else if (!orderStorageFive[i].empty())
            {
                 cout << orderStorageFive[i] << " " << quantityFive[i] << "x\n";
            }

            else if (!orderStorageSix[i].empty())
            {
                 cout << orderStorageSix[i] << " " << quantitySix[i] << "x\n";
            }

            else if (!orderStorageSeven[i].empty())
            {
                 cout << orderStorageSeven << " " << quantitySeven[i] << "x\n";
            }

            else if (!orderStorageEight[i].empty())
            {
                 cout << orderStorageEight[i] << " " << quantityEight[i] << "x\n";
            }

            else if (!orderStorageNine[i].empty())
            {
                 cout << orderStorageNine[i] << " " << quantityNine[i] << "x\n";
            }
            
            else if (!orderStorageTen[i].empty())
            {
                 cout << orderStorageTen[i] << " " << quantityTen[i] << "x\n";
            }
        }

        cout << "------------------------------------------------------------------------------------\n"; 
        cout << "|Total Bill: " << totalBill << "\n";
        cout << "------------------------------------------------------------------------------------\n";        
        
        exitFunc();
     }

     void exitFunc(){
        
        int choice;

        cout << "---------------------------------------\n";
        cout << "|\tENTER ANY NUMBER TO EXIT      |\n";
        cout << "---------------------------------------\n";
        
        cout << "Enter: ";
        cin >> choice;

        if(choice = 1)
        {
             cout << "------------------------------------------------\n";
             cout << "|\tThank You For Visiting Jollibee!       |\n";
             cout << "------------------------------------------------\n";
        }
        
        else
        {
             cout << "------------------------------------------------\n";
             cout << "|\tThank You For Visiting Jollibee!       |\n";
             cout << "------------------------------------------------\n";
        }
     }
};

class orderingSystem : public jollibeeSystem{
    public:
     orderingSystem(string productName, int productPrice) : jollibeeSystem(productName, productPrice){  
     }

    public:
     void jollibeeMenuFunc();
     void bestSellersFunc();
     void newProductsFunc();
     void familyMealsFunc();
     void breakfastFunc();
     void chickenjoyFunc();
     void chickenNuggetsFunc();
     void burgersFunc();
     void jollySpaghettiFunc();
     void burgerSteakFunc();
     void superMealsFunc();
};

class userSystem : public orderingSystem{
    public:
    userSystem(string productName, int productPrice) : orderingSystem(productName, productPrice){
    }
    
     public:
     void userMenuFunc();
     void signInFunc();
     void signUpFunc();
     void userInterface();
};

int main (){

    userSystem menu(" ", 0);
    jollibeeSystem *pOut = &menu;

    menu.userMenuFunc();

    return 0;
}

void userSystem :: userMenuFunc(){

    int choice;

    cout << "-----------------------------------\n";
    cout << "|\tWELCOME TO JOLLIBEE       |\n";
    cout << "|---------------------------------|\n";
    cout << "|\t    [1]Sign In            |\n";
    cout << "|\t    [2]Sign Up            |\n";
    cout << "-----------------------------------\n";
    
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        
         signInFunc();

        break;

    case 2:
         
         signUpFunc();

        break;
    
    default:

         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";
         
         userMenuFunc();

        break;
    }
}

void userSystem :: signInFunc(){

   fstream accountData, accountData2;

   string tempUserName;
   string tempUserPass;

   cout << "-----------------------------------\n";
   cout << "|\tWELCOME TO JOLLIBEE       |\n";
   cout << "-----------------------------------\n";

   cout << "Enter Your Username: ";
   cin >> tempUserName;

   cout << "Enter Your Password: ";
   cin >> tempUserPass;

   accountData.open(tempUserPass + ".txt", ios::in);
   accountData >> userName >> userPass >> accName >> userBalance;

   if (tempUserName == userName && tempUserPass == userPass)
   {
         accountData2.open(tempUserPass + "2.txt", ios::out | ios::app);

         accountData2 << userName << " " << userPass << " " << accName << " " << userBalance;
   }
   
   else
   {
         accountData2 << userName << " " << userPass << " " << accName << " " << userBalance;
   }

   accountData.close();
   accountData2.close();

   rem::remove(tempUserPass + ".txt");
   ren::rename(tempUserPass + "2.txt", tempUserPass + ".txt");

   if (tempUserName == userName && tempUserPass == userPass)
   {
         userInterface();
   }

   else
   {
         cout << "--------------------------------------------\n";
         cout << "|\tInvalid Username Or Password!      |\n";
         cout << "--------------------------------------------\n";
         userMenuFunc();
   }
}

void userSystem :: signUpFunc(){
   
    ofstream accountData;

    cout << "-----------------------------------\n";
    cout << "|\tWELCOME TO JOLLIBEE       |\n";
    cout << "-----------------------------------\n";

    cout << "Enter Username: ";
    cin >> userName;

    cout << "Enter PassWord: ";
    cin >> userPass;

    cout << "Enter Your Name: ";
    cin >> accName;

    accountData.open(userPass + ".txt", ios::out | ios::app);

    if (accountData.is_open())
    {
         accountData << userName << " " << userPass << " " << accName << " " << userBalance;
    
         cout << "---------------------------------------------\n";
         cout << "|\tYour Account Has Been Created       |\n";
         cout << "---------------------------------------------\n";   
    }

    else
    {   
        cout << "------------------------------------\n";
        cout << "|\tSign Up Unsuccessful       |\n";
        cout << "------------------------------------\n";
    }

    accountData.close();
    
    userMenuFunc();
}

void userSystem :: userInterface(){
    
    int choice;

    cout << "----------------------------------------\n"; 
    cout << "|Account Name: " << accName << "\n";
    cout << "|---------------------------------------\n";
    cout << "|Jollibee Coins: " << userBalance << "\n";   
    cout << "|---------------------------------------\n";
    cout << "|[1]Jollibee Menu                      |\n";
    cout << "|[2]Log Out                            |\n";
    cout << "----------------------------------------\n";

    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
         
         jollibeeMenuFunc();

        break;

    case 2: 

         cout << "---------------------------------------\n";
         cout << "|\tAccount Has Been Log Out      |\n";
         cout << "---------------------------------------\n";
         
         main();

        break;
    
    default:

         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";

         userInterface();

        break;
    }   
}

void orderingSystem :: jollibeeMenuFunc(){

    int choice;

    cout << "-----------------------------\n";
    cout << "|\tJOLLIBEE MENU       |\n";
    cout << "|---------------------------|\n";
    cout << "|[1]Best Seller             |\n";
    cout << "|[2]New Products            |\n";
    cout << "|[3]Family Meals            |\n";
    cout << "|[4]Breakfast               |\n";
    cout << "|[5]Chickenjoy              |\n";
    cout << "|[6]Chicken Nuggets         |\n";
    cout << "|[7]Burgers                 |\n";
    cout << "|[8]Jolly Spaghetti         |\n";
    cout << "|[9]Burger Steak            |\n";
    cout << "|[10]Super Meals            |\n";
    cout << "|[11]Chicken Sandwich       |\n"; 
    cout << "|[12]Jolly Hotdog & Pies    |\n";
    cout << "|[13]Palabok                |\n";
    cout << "|[14]Fries & Sides          |\n";
    cout << "|[15]Desserts               |\n";
    cout << "|[16]Beverages              |\n";
    cout << "|[17]Jollibee Kids Meal     |\n";
    cout << "|[00]Confirm Order          |\n";
    cout << "-----------------------------\n";

    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        
         bestSellersFunc();

        break;

    case 2:

         newProductsFunc();

        break;

    case 3:

         familyMealsFunc();

        break;

    case 4:

         breakfastFunc();

        break;

    case 5:
        
         chickenjoyFunc();

        break;

    case 6:

         chickenNuggetsFunc();

        break;

    case 7:

         burgersFunc();

        break;

    case 8:

         jollySpaghettiFunc();

        break;

    case 9:

         burgerSteakFunc();

        break;

    case 10:

         superMealsFunc();

        break;

    case 00:

         confirmBillFunc();

        break;
    
    default:

         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";
         
         jollibeeMenuFunc();

        break;
    }
}

void orderingSystem :: bestSellersFunc(){
    
    orderingSystem prodOne("6-pc. Chickenjoy With Palabok Family Pan", 894);
    orderingSystem prodTwo("8-pc. Chickenjoy With Palabok Family Pan", 1054);
    orderingSystem prodThree("1-pc. Chickenjoy w/Burger Steak & Half Jolly Spaghetti Super Meal", 212);
    orderingSystem prodFour("1-pc. Chickenjoy w/Jolly Spaghetti", 132);
    orderingSystem prodFive("1-pc. Chickenjoy", 82);
    orderingSystem prodSix("2-pc. Chickenjoy", 163);
    orderingSystem prodSeven("Yumburger, Half Jolly Spaghetti & Reg.Fries Super Meal", 137);
    orderingSystem prodEight("Cheesy Yumburger", 69);
    orderingSystem prodNine("Yumburger", 40);
    orderingSystem prodTen("Jolly Spaghetti w/Yumburger", 122);
    orderingSystem prodEleven("Jolly Spaghetti", 60);
    orderingSystem prodTwelve("Chicken Bucket Family Meals", 758);
    orderingSystem prodThirteen("6-pc. Chickenjoy Solo", 449);
    orderingSystem prodFourteen("8-pc. Chickenjoy Solo", 549);
    orderingSystem prodFifteen("Yumburger Family Savers", 276);
    orderingSystem prodSixteen("Burger Bundle", 382);
    orderingSystem prodSeventeen("Jolly Spaghetti & Palabok Family Pan", 237);

    int choice;
    
do
{

    cout << "---------------------------------------------------------------------------------\n";
    cout << "|\t\t\t   JOLLIBEE BEST SELLER MENU                            |\n";
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|[1]" << prodOne.productName << "\n";
    cout << "|[2]" << prodTwo.productName << "\n";
    cout << "|[3]" << prodThree.productName << "\n";
    cout << "|[4]" << prodFour.productName << "\n";
    cout << "|[5]" << prodFive.productName << "\n";
    cout << "|[6]" << prodSix.productName << "\n";
    cout << "|[7]" << prodSeven.productName << "\n";
    cout << "|[8]" << prodEight.productName << "\n";
    cout << "|[9]" << prodNine.productName << "\n";
    cout << "|[10]" << prodTen.productName << "\n";
    cout << "|[11]" << prodEleven.productName << "\n";
    cout << "|[12]" << prodTwelve.productName << "\n";
    cout << "|[13]" << prodThirteen.productName << "\n";
    cout << "|[14]" << prodFourteen.productName << "\n";
    cout << "|[15]" << prodFifteen.productName << "\n";
    cout << "|[16]" << prodSixteen.productName << "\n";
    cout << "|[17]" << prodSeventeen.productName << "\n";
    cout << "|[0]Back\n";
    cout << "---------------------------------------------------------------------------------\n";
         
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        
        prodOne.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[0];

             totalBill += prodOne.productPrice * quantity[0];
             orderStorageOne[0] += prodOne.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }
    
        break;

    case 2:
        
        prodTwo.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[1];

             totalBill += prodTwo.productPrice * quantity[1];
             orderStorageOne[1] += prodTwo.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 3:
        
        prodThree.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[2];

             totalBill += prodThree.productPrice * quantity[2];
             orderStorageOne[2] += prodThree.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 4:
        
        prodFour.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[3];

             totalBill += prodFour.productPrice * quantity[3];
             orderStorageOne[3] += prodFour.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 5:
        
        prodFive.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[4];

             totalBill += prodFive.productPrice * quantity[4];
             orderStorageOne[4] += prodFive.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 6:

        prodSix.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[5];

             totalBill += prodSix.productPrice * quantity[5];
             orderStorageOne[5] += prodSix.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 7:
     
        prodSeven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[6];

             totalBill += prodSeven.productPrice * quantity[6];
             orderStorageOne[6] += prodSeven.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 8:
                
        prodEight.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[7];

             totalBill += prodEight.productPrice * quantity[7];
             orderStorageOne[7] += prodEight.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 9:
 
        prodNine.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[8];

             totalBill += prodNine.productPrice * quantity[8];
             orderStorageOne[8] += prodNine.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 10: 
        
        prodTen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[9];

             totalBill += prodTen.productPrice * quantity[9];
             orderStorageOne[9] += prodTen.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 11:
        
        prodEleven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[10];

             totalBill += prodEleven.productPrice * quantity[10];
             orderStorageOne[10] += prodEleven.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 12:

        
        prodTwelve.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[11];

             totalBill += prodTwelve.productPrice * quantity[11];
             orderStorageOne[11] += prodTwelve.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 13:
        
        prodThirteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[12];

             totalBill += prodThirteen.productPrice * quantity[12];
             orderStorageOne[12] += prodThirteen.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 14:

        prodFourteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[13];

             totalBill += prodFourteen.productPrice * quantity[13];
             orderStorageOne[13] += prodFourteen.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 15:

        
        prodFifteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[14];

             totalBill += prodFifteen.productPrice * quantity[14];
             orderStorageOne[14] += prodFifteen.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 16:

        prodSixteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[15];

             totalBill += prodSixteen.productPrice * quantity[15];
             orderStorageOne[15] += prodSixteen.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break;

    case 17:

        prodSeventeen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantity[16];

             totalBill += prodSeventeen.productPrice * quantity[16];
             orderStorageOne[16] += prodSeventeen.productName; 
        }
        
        else
        {
             bestSellersFunc();
        }

        break; 

    case 0:

        break;
    
    default:

         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";

         bestSellersFunc();
        
        break;
    }

} 
    
while (choice != 0); 

jollibeeMenuFunc(); 

}

void orderingSystem :: newProductsFunc(){

    orderingSystem prodOne("Iced Mocha", 64);
    orderingSystem prodTwo("Iced Mocha Float", 80);
    orderingSystem prodThree("6-pc. Chickne Nuggets", 105);
    orderingSystem prodFour("10-pc. Chicken Nuggets", 186);
    orderingSystem prodFive("Chicken Nuggets Kiddie Meal", 120);
    orderingSystem prodSix("Buko Pandan Sundae", 63);
    orderingSystem prodSeven("Ube Cheese Pie", 50);
    orderingSystem prodEight("Ube Cheese Pie 3 Pies To-Go", 144);
    orderingSystem prodNine("Ube Cheese Pie 6 Pies To-Go", 287);
    orderingSystem prodTen("1-pc. Chickenjoy w/Coke Float", 143);
    orderingSystem prodEleven("1-pc. Chickenjoy w/Pepsi Float", 143);
    orderingSystem prodTwelve("Mini Chocolate Sundae", 27);
    orderingSystem prodThirteen("Crunchy Chicken Sandwich", 59);
    orderingSystem prodFourteen("Crunchy Chicken Sandwich w/Drinks", 95);
    orderingSystem prodFifteen("Crunchy Chicken Sandwich w/Fries & Drinks", 127);
    orderingSystem prodSixteen("Hot Fresh Brew", 48);
    orderingSystem prodSeventeen("Iced Latte", 53);
    orderingSystem prodEighteen("Jolly Crispy Fries Bucket", 162);

    int choice;

do
{
     
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|\t\t\t   JOLLIBEE BEST SELLER MENU                            |\n";
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|[1]" << prodOne.productName << "\n";
    cout << "|[2]" << prodTwo.productName << "\n";
    cout << "|[3]" << prodThree.productName << "\n";
    cout << "|[4]" << prodFour.productName << "\n";
    cout << "|[5]" << prodFive.productName << "\n";
    cout << "|[6]" << prodSix.productName << "\n";
    cout << "|[7]" << prodSeven.productName << "\n";
    cout << "|[8]" << prodEight.productName << "\n";
    cout << "|[9]" << prodNine.productName << "\n";
    cout << "|[10]" << prodTen.productName << "\n";
    cout << "|[11]" << prodEleven.productName << "\n";
    cout << "|[12]" << prodTwelve.productName << "\n";
    cout << "|[13]" << prodThirteen.productName << "\n";
    cout << "|[14]" << prodFourteen.productName << "\n";
    cout << "|[15]" << prodFifteen.productName << "\n";
    cout << "|[16]" << prodSixteen.productName << "\n";
    cout << "|[17]" << prodSeventeen.productName << "\n";
    cout << "|[18]" << prodEighteen.productName << "\n";
    cout << "|[0]Back\n";
    cout << "---------------------------------------------------------------------------------\n";
     
     cout << "Enter Choice: ";
     cin >> choice;

    switch (choice)
    {
    case 1:
               
        prodOne.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
        cout << "Enter Quantity: ";
        cin >> quantityTwo[0];

             totalBill += prodOne.productPrice * quantityTwo[0];
             orderStorageTwo[0] += prodOne.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 2:
            
        prodTwo.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[1];

             totalBill += prodTwo.productPrice * quantityTwo[1];
             orderStorageTwo[1] += prodTwo.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 3:
              
        prodThree.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[2];

             totalBill += prodThree.productPrice * quantityTwo[2];
             orderStorageTwo[2] += prodThree.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 4:

        prodFour.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[3];

             totalBill += prodFour.productPrice * quantityTwo[3];
             orderStorageTwo[3] += prodFour.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 5:

        prodFive.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[4];

             totalBill += prodFive.productPrice * quantityTwo[4];
             orderStorageTwo[4] += prodFive.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 6:
            
        prodSix.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[5];

             totalBill += prodSix.productPrice * quantityTwo[5];
             orderStorageTwo[5] += prodSix.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 7: 

        prodSeven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[6];

             totalBill += prodSeven.productPrice * quantityTwo[6];
             orderStorageTwo[6] += prodSeven.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 8:

        prodEight.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[7];

             totalBill += prodEight.productPrice * quantityTwo[7];
             orderStorageTwo[7] += prodEight.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 9:

        prodNine.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[8];

             totalBill += prodNine.productPrice * quantityTwo[8];
             orderStorageTwo[8] += prodNine.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 10:

        prodTen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[9];

             totalBill += prodTwo.productPrice * quantityTwo[9];
             orderStorageTwo[9] += prodTwo.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 11:

        prodEleven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[10];

             totalBill += prodEleven.productPrice * quantityTwo[10];
             orderStorageTwo[10] += prodEleven.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 12:
             
        prodTwelve.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[11];

             totalBill += prodTwelve.productPrice * quantityTwo[11];
             orderStorageTwo[11] += prodTwelve.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 13:

        prodThirteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[12];

             totalBill += prodThirteen.productPrice * quantityTwo[12];
             orderStorageTwo[12] += prodThirteen.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 14:
            
        prodFourteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[13];

             totalBill += prodFourteen.productPrice * quantityTwo[13];
             orderStorageTwo[13] += prodFourteen.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 15:

        prodFifteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[14];

             totalBill += prodFifteen.productPrice * quantityTwo[14];
             orderStorageTwo[14] += prodFifteen.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 16:

        prodSixteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[15];

             totalBill += prodSixteen.productPrice * quantityTwo[15];
             orderStorageTwo[15] += prodSixteen.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 17:

        prodSeventeen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[16];

             totalBill += prodSeventeen.productPrice * quantityTwo[16];
             orderStorageTwo[16] += prodSeventeen.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 18:

        prodEighteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTwo[17];

             totalBill += prodEighteen.productPrice * quantityTwo[17];
             orderStorageTwo[17] += prodEighteen.productName; 
        }
        
        else
        {
             newProductsFunc();
        }

        break;

    case 0:

        break;
        
    default:

         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";
               
         newProductsFunc();  

        break;
    }
} 
    
while (choice != 0);

jollibeeMenuFunc();

}

void orderingSystem :: familyMealsFunc(){

    orderingSystem prodOne("6-pc. Chickenjoy Solo", 449);
    orderingSystem prodTwo("8-pc. Chickenjoy Solo", 549);
    orderingSystem prodThree("4-pc. Chickenjoy Family Solo Box", 326);
    orderingSystem prodFour("6-pc. Chickenjoy With Palabok Family Pan", 894);
    orderingSystem prodFive("8-pc. Chickenjoy With Palabok Family Pan", 1054);
    orderingSystem prodSix("Chickenjoy Buckent Family Meals", 758);
    orderingSystem prodSeven("Jolly Spaghetti & Palabok Family Pan", 237);
    orderingSystem prodEight("Burger Bundle", 382);
    orderingSystem prodNine("Yumburger Family Savers", 276);
    orderingSystem prodTen("Burger Steak Family Savers", 329);
    orderingSystem prodEleven("6-pc. Burger Steak Family Pan", 355);
    orderingSystem prodTwelve("8-pc. Burger Steak Family Pan", 470);
    orderingSystem prodThirteen("6-pc. Burger Steak w/Jolly Spaghetti Family Pan", 570);
    orderingSystem prodFourteen("8-pc. Burger Steak w/Jolly Spaghetti Family Pan", 650);
    orderingSystem prodFifteen("6-pc. Burger Steak w/Palabok Family Pan", 827);
    orderingSystem prodSixteen("8-pc. Burger Steak w/Palabok Family Pan", 923);
    orderingSystem prodSeventeen("Joy At Home Birthday Set", 80);

    int choice;

do
{
     
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|\t\t\t   JOLLIBEE BEST SELLER MENU                            |\n";
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|[1]" << prodOne.productName << "\n";
    cout << "|[2]" << prodTwo.productName << "\n";
    cout << "|[3]" << prodThree.productName << "\n";
    cout << "|[4]" << prodFour.productName << "\n";
    cout << "|[5]" << prodFive.productName << "\n";
    cout << "|[6]" << prodSix.productName << "\n";
    cout << "|[7]" << prodSeven.productName << "\n";
    cout << "|[8]" << prodEight.productName << "\n";
    cout << "|[9]" << prodNine.productName << "\n";
    cout << "|[10]" << prodTen.productName << "\n";
    cout << "|[11]" << prodEleven.productName << "\n";
    cout << "|[12]" << prodTwelve.productName << "\n";
    cout << "|[13]" << prodThirteen.productName << "\n";
    cout << "|[14]" << prodFourteen.productName << "\n";
    cout << "|[15]" << prodFifteen.productName << "\n";
    cout << "|[16]" << prodSixteen.productName << "\n";
    cout << "|[17]" << prodSeventeen.productName << "\n";
    cout << "|[0]Back\n";
    cout << "---------------------------------------------------------------------------------\n";
     
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
               
        prodOne.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
        cout << "Enter Quantity: ";
        cin >> quantityThree[0];

             totalBill += prodOne.productPrice * quantityThree[0];
             orderStorageThree[0] += prodOne.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 2:
            
        prodTwo.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[1];

             totalBill += prodTwo.productPrice * quantityThree[1];
             orderStorageThree[1] += prodTwo.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 3:
              
        prodThree.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[2];

             totalBill += prodThree.productPrice * quantityThree[2];
             orderStorageThree[2] += prodThree.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 4:

        prodFour.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[3];

             totalBill += prodFour.productPrice * quantityThree[3];
             orderStorageThree[3] += prodFour.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 5:

        prodFive.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[4];

             totalBill += prodFive.productPrice * quantityThree[4];
             orderStorageThree[4] += prodFive.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 6:
            
        prodSix.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[5];

             totalBill += prodSix.productPrice * quantityThree[5];
             orderStorageThree[5] += prodSix.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 7: 

        prodSeven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[6];

             totalBill += prodSeven.productPrice * quantityThree[6];
             orderStorageThree[6] += prodSeven.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 8:

        prodEight.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[7];

             totalBill += prodEight.productPrice * quantityThree[7];
             orderStorageThree[7] += prodEight.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 9:

        prodNine.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[8];

             totalBill += prodNine.productPrice * quantityThree[8];
             orderStorageThree[8] += prodNine.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 10:

        prodTen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[9];

             totalBill += prodTwo.productPrice * quantityThree[9];
             orderStorageThree[9] += prodTwo.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 11:

        prodEleven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[10];

             totalBill += prodEleven.productPrice * quantityThree[10];
             orderStorageThree[10] += prodEleven.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 12:
             
        prodTwelve.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[11];

             totalBill += prodTwelve.productPrice * quantityThree[11];
             orderStorageThree[11] += prodTwelve.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 13:

        prodThirteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[12];

             totalBill += prodThirteen.productPrice * quantityThree[12];
             orderStorageThree[12] += prodThirteen.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 14:
            
        prodFourteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[13];

             totalBill += prodFourteen.productPrice * quantityThree[13];
             orderStorageThree[13] += prodFourteen.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 15:

        prodFifteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[14];

             totalBill += prodFifteen.productPrice * quantityThree[14];
             orderStorageThree[14] += prodFifteen.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 16:

        prodSixteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[15];

             totalBill += prodSixteen.productPrice * quantityThree[15];
             orderStorageThree[15] += prodSixteen.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 17:

        prodSeventeen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityThree[16];

             totalBill += prodSeventeen.productPrice * quantityThree[16];
             orderStorageThree[16] += prodSeventeen.productName; 
        }
        
        else
        {
             familyMealsFunc();
        }

        break;

    case 0:

        break;
        
    default:

         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";
               
         familyMealsFunc();  

        break;
    }
} 
    
while (choice != 0);

jollibeeMenuFunc();

}

void orderingSystem :: breakfastFunc(){

    orderingSystem prodOne("Longganisa", 165);
    orderingSystem prodTwo("Beef Tapa", 165);
    orderingSystem prodThree("Corned Beef", 165);
    orderingSystem prodFour("1-pc. Breakfast Chickenjoy", 148);
    orderingSystem prodFive("Breakfast Burger Steak", 127);
    orderingSystem prodSix("Breakfast Hotdog", 122);
    orderingSystem prodSeven("2-pc. Pancakes", 82);
    orderingSystem prodEight("Bacon, Egg & Cheese Pancake Sandwich", 100);
    orderingSystem prodNine("Bacon, Egg & Cheese Sandwich", 95);

    int choice;

do
{
     
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|\t\t\t   JOLLIBEE BEST SELLER MENU                            |\n";
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|[1]" << prodOne.productName << "\n";
    cout << "|[2]" << prodTwo.productName << "\n";
    cout << "|[3]" << prodThree.productName << "\n";
    cout << "|[4]" << prodFour.productName << "\n";
    cout << "|[5]" << prodFive.productName << "\n";
    cout << "|[6]" << prodSix.productName << "\n";
    cout << "|[7]" << prodSeven.productName << "\n";
    cout << "|[8]" << prodEight.productName << "\n";
    cout << "|[9]" << prodNine.productName << "\n";
    cout << "|[0]Back\n";
    cout << "---------------------------------------------------------------------------------\n";
     
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
               
        prodOne.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
        cout << "Enter Quantity: ";
        cin >> quantityFour[0];

             totalBill += prodOne.productPrice * quantityFour[0];
             orderStorageFour[0] += prodOne.productName; 
        }
        
        else
        {
             breakfastFunc();
        }

        break;

    case 2:
            
        prodTwo.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFour[1];

             totalBill += prodTwo.productPrice * quantityFour[1];
             orderStorageFour[1] += prodTwo.productName; 
        }
        
        else
        {
             breakfastFunc();
        }

        break;

    case 3:
              
        prodThree.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFour[2];

             totalBill += prodThree.productPrice * quantityFour[2];
             orderStorageFour[2] += prodThree.productName; 
        }
        
        else
        {
             breakfastFunc();
        }

        break;

    case 4:

        prodFour.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFour[3];

             totalBill += prodFour.productPrice * quantityFour[3];
             orderStorageFour[3] += prodFour.productName; 
        }
        
        else
        {
             breakfastFunc();
        }

        break;

    case 5:

        prodFive.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFour[4];

             totalBill += prodFive.productPrice * quantityFour[4];
             orderStorageFour[4] += prodFive.productName; 
        }
        
        else
        {
             breakfastFunc();
        }

        break;

    case 6:
            
        prodSix.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFour[5];

             totalBill += prodSix.productPrice * quantityFour[5];
             orderStorageFour[5] += prodSix.productName; 
        }
        
        else
        {
             breakfastFunc();
        }

        break;

    case 7: 

        prodSeven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFour[6];

             totalBill += prodSeven.productPrice * quantityFour[6];
             orderStorageFour[6] += prodSeven.productName; 
        }
        
        else
        {
             breakfastFunc();
        }

        break;

    case 8:

        prodEight.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFour[7];

             totalBill += prodEight.productPrice * quantityFour[7];
             orderStorageFour[7] += prodEight.productName; 
        }
        
        else
        {
             breakfastFunc();
        }

        break;

    case 9:

        prodNine.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFour[8];

             totalBill += prodNine.productPrice * quantityFour[8];
             orderStorageFour[8] += prodNine.productName; 
        }
        
        else
        {
             breakfastFunc();
        }

        break;

    case 0:

        break;
        
    default:

         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";
               
         breakfastFunc();  

        break;
    }
} 
    
while (choice != 0);

jollibeeMenuFunc();

}

void orderingSystem :: chickenjoyFunc(){

    orderingSystem prodOne("1-pc. Chickenjoy w/Coke Float", 143);
    orderingSystem prodTwo("1-pc. Chickenjoy w/Pepsi Float", 143);
    orderingSystem prodThree("6-pc. Chickenjoy Solo", 449);
    orderingSystem prodFour("8-pc. Chickenjoy Solo", 549);
    orderingSystem prodFive("6-pc. Chickenjoy with Palabok Family Pan", 894);
    orderingSystem prodSix("8-pc. Chickenjoy with Palabok Family Pan", 1054);
    orderingSystem prodSeven("4-pc. Chickenjoy Family Box Solo", 326);
    orderingSystem prodEight("Chickenjoy Bucket Family Meals", 758);
    orderingSystem prodNine("1-pc. Chickenjoy w/Burger Steak & Half Jolly Spaghetti Super Meal", 212);
    orderingSystem prodTen("1-pc. Chickenjoy", 82);
    orderingSystem prodEleven("1-pc. Chickenjoy w/Jolly Spaghetti", 132);
    orderingSystem prodTwelve("1-pc. Chickenjoy w/Fries", 128);
    orderingSystem prodThirteen("1-pc. Chickenjoy w/Double Rice", 148);
    orderingSystem prodFourteen("2-pc. Chickenjoy", 163);
    orderingSystem prodFifteen("1-pc. Chickenjoy w/Palabok", 211);
    orderingSystem prodSixteen("1-pc. Chickenjoy w/Burger Steak", 132);
    orderingSystem prodSeventeen("1-pc. Chickenjoy w/Creamy Macaroni Soup", 164);

    int choice;

do
{

    cout << "---------------------------------------------------------------------------------\n";
    cout << "|\t\t\t   JOLLIBEE BEST SELLER MENU                            |\n";
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|[1]" << prodOne.productName << "\n";
    cout << "|[2]" << prodTwo.productName << "\n";
    cout << "|[3]" << prodThree.productName << "\n";
    cout << "|[4]" << prodFour.productName << "\n";
    cout << "|[5]" << prodFive.productName << "\n";
    cout << "|[6]" << prodSix.productName << "\n";
    cout << "|[7]" << prodSeven.productName << "\n";
    cout << "|[8]" << prodEight.productName << "\n";
    cout << "|[9]" << prodNine.productName << "\n";
    cout << "|[10]" << prodTen.productName << "\n";
    cout << "|[11]" << prodEleven.productName << "\n";
    cout << "|[12]" << prodTwelve.productName << "\n";
    cout << "|[13]" << prodThirteen.productName << "\n";
    cout << "|[14]" << prodFourteen.productName << "\n";
    cout << "|[15]" << prodFifteen.productName << "\n";
    cout << "|[16]" << prodSixteen.productName << "\n";
    cout << "|[17]" << prodSeventeen.productName << "\n";
    cout << "|[0]Back\n";
    cout << "---------------------------------------------------------------------------------\n";
     
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
               
        prodOne.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
        cout << "Enter Quantity: ";
        cin >> quantityFive[0];

             totalBill += prodOne.productPrice * quantityFive[0];
             orderStorageFive[0] += prodOne.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 2:
            
        prodTwo.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[1];

             totalBill += prodTwo.productPrice * quantityFive[1];
             orderStorageFive[1] += prodTwo.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 3:
              
        prodThree.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[2];

             totalBill += prodThree.productPrice * quantityFive[2];
             orderStorageFive[2] += prodThree.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 4:

        prodFour.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[3];

             totalBill += prodFour.productPrice * quantityFive[3];
             orderStorageFive[3] += prodFour.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 5:

        prodFive.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[4];

             totalBill += prodFive.productPrice * quantityFive[4];
             orderStorageFive[4] += prodFive.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 6:
            
        prodSix.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[5];

             totalBill += prodSix.productPrice * quantityFive[5];
             orderStorageFive[5] += prodSix.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 7: 

        prodSeven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[6];

             totalBill += prodSeven.productPrice * quantityFive[6];
             orderStorageFive[6] += prodSeven.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 8:

        prodEight.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[7];

             totalBill += prodEight.productPrice * quantityFive[7];
             orderStorageFive[7] += prodEight.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 9:

        prodNine.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[8];

             totalBill += prodNine.productPrice * quantityFive[8];
             orderStorageFive[8] += prodNine.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 10:

        prodTen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[9];

             totalBill += prodTwo.productPrice * quantityFive[9];
             orderStorageFive[9] += prodTwo.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 11:

        prodEleven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[10];

             totalBill += prodEleven.productPrice * quantityFive[10];
             orderStorageFive[10] += prodEleven.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 12:
             
        prodTwelve.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[11];

             totalBill += prodTwelve.productPrice * quantityFive[11];
             orderStorageFive[11] += prodTwelve.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 13:

        prodThirteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[12];

             totalBill += prodThirteen.productPrice * quantityFive[12];
             orderStorageFive[12] += prodThirteen.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 14:
            
        prodFourteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[13];

             totalBill += prodFourteen.productPrice * quantityFive[13];
             orderStorageFive[13] += prodFourteen.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 15:

        prodFifteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[14];

             totalBill += prodFifteen.productPrice * quantityFive[14];
             orderStorageFive[14] += prodFifteen.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 16:

        prodSixteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[15];

             totalBill += prodSixteen.productPrice * quantityFive[15];
             orderStorageFive[15] += prodSixteen.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 17:

        prodSeventeen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityFive[16];

             totalBill += prodSeventeen.productPrice * quantityFive[16];
             orderStorageFive[16] += prodSeventeen.productName; 
        }
        
        else
        {
             chickenjoyFunc();
        }

        break;

    case 0:

        break;
        
    default:

         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";
               
         chickenjoyFunc();  

        break;
    }
} 
    
while (choice != 0);

jollibeeMenuFunc();

}

void orderingSystem :: chickenNuggetsFunc(){

    orderingSystem prodOne("6-pc. Chicken Nuggets", 105);
    orderingSystem prodTwo("10-pc. Chicken Nuggets", 186);

    int choice;

do  
{
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|\t\t\t   JOLLIBEE BEST SELLER MENU                            |\n";
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|[1]" << prodOne.productName << "\n";
    cout << "|[2]" << prodTwo.productName << "\n";
    cout << "|[0]Back\n";
    cout << "---------------------------------------------------------------------------------\n";
     
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        
        prodOne.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySix[0];

             totalBill += prodOne.productPrice * quantitySix[0];
             orderStorageSix[0] += prodOne.productName; 
        }
        
        else
        {
             chickenNuggetsFunc();
        }

        break;

    case 2:

        prodTwo.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySix[1];

             totalBill += prodTwo.productPrice * quantitySix[1];
             orderStorageSix[1] += prodTwo.productName; 
        }
        
        else
        {
             chickenNuggetsFunc();
        }

        break;

    case 0:

        break;
    
    default:
        
         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";

         chickenNuggetsFunc();

        break;
    }
} 

while (choice != 0);

jollibeeMenuFunc();
    
}

void orderingSystem :: burgersFunc(){

    orderingSystem prodOne("Burger Bundle", 382);
    orderingSystem prodTwo("Yumburger Family Savers", 276);
    orderingSystem prodThree("Yumburger", 40);
    orderingSystem prodFour("Cheesy Yumburger", 69);
    orderingSystem prodFive("Bacon Cheesy Yumburger", 96);
    orderingSystem prodSix("Amazing Aloha Champ Burger Jr.", 125);
    orderingSystem prodSeven("Champ Jr.", 105);
    orderingSystem prodEight("Amazing Aloha Champ Jr. w/o Bacon", 122);
    orderingSystem prodNine("Double Amazing Aloha Champ Jr.", 170);
    orderingSystem prodTen("Double Amazing Aloha Champ Jr. w/o Bacon", 159);
    orderingSystem prodEleven("Champ", 179);
    orderingSystem prodTwelve("Aloha Champ", 246);
    orderingSystem prodThirteen("Jolly Spaghetti w/Yumburger", 122);
    orderingSystem prodFourteen("Yumburger, Half Jolly Spaghetti & Reg.Fries Super Meal", 137);
    
    int choice;

do
{
        
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|\t\t\t   JOLLIBEE BEST SELLER MENU                            |\n";
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|[1]" << prodOne.productName << "\n";
    cout << "|[2]" << prodTwo.productName << "\n";
    cout << "|[3]" << prodThree.productName << "\n";
    cout << "|[4]" << prodFour.productName << "\n";
    cout << "|[5]" << prodFive.productName << "\n";
    cout << "|[6]" << prodSix.productName << "\n";
    cout << "|[7]" << prodSeven.productName << "\n";
    cout << "|[8]" << prodEight.productName << "\n";
    cout << "|[9]" << prodNine.productName << "\n";
    cout << "|[10]" << prodTen.productName << "\n";
    cout << "|[11]" << prodEleven.productName << "\n";
    cout << "|[12]" << prodTwelve.productName << "\n";
    cout << "|[13]" << prodThirteen.productName << "\n";
    cout << "|[14]" << prodFourteen.productName << "\n";
    cout << "|[0]Back\n";
    cout << "---------------------------------------------------------------------------------\n";
     
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
               
        prodOne.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
        cout << "Enter Quantity: ";
        cin >> quantitySeven[0];

             totalBill += prodOne.productPrice * quantitySeven[0];
             orderStorageSeven[0] += prodOne.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 2:
            
        prodTwo.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[1];

             totalBill += prodTwo.productPrice * quantitySeven[1];
             orderStorageSeven[1] += prodTwo.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 3:
              
        prodThree.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[2];

             totalBill += prodThree.productPrice * quantitySeven[2];
             orderStorageSeven[2] += prodThree.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 4:

        prodFour.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[3];

             totalBill += prodFour.productPrice * quantitySeven[3];
             orderStorageSeven[3] += prodFour.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 5:

        prodFive.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[4];

             totalBill += prodFive.productPrice * quantitySeven[4];
             orderStorageSeven[4] += prodFive.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 6:
            
        prodSix.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[5];

             totalBill += prodSix.productPrice * quantitySeven[5];
             orderStorageSeven[5] += prodSix.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 7: 

        prodSeven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[6];

             totalBill += prodSeven.productPrice * quantitySeven[6];
             orderStorageSeven[6] += prodSeven.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 8:

        prodEight.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[7];

             totalBill += prodEight.productPrice * quantitySeven[7];
             orderStorageSeven[7] += prodEight.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 9:

        prodNine.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[8];

             totalBill += prodNine.productPrice * quantitySeven[8];
             orderStorageSeven[8] += prodNine.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 10:

        prodTen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[9];

             totalBill += prodTwo.productPrice * quantitySeven[9];
             orderStorageSeven[9] += prodTwo.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 11:

        prodEleven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[10];

             totalBill += prodEleven.productPrice * quantitySeven[10];
             orderStorageSeven[10] += prodEleven.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 12:
             
        prodTwelve.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[11];

             totalBill += prodTwelve.productPrice * quantitySeven[11];
             orderStorageSeven[11] += prodTwelve.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 13:

        prodThirteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[12];

             totalBill += prodThirteen.productPrice * quantitySeven[12];
             orderStorageSeven[12] += prodThirteen.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 14:
            
        prodFourteen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantitySeven[13];

             totalBill += prodFourteen.productPrice * quantitySeven[13];
             orderStorageSeven[13] += prodFourteen.productName; 
        }
        
        else
        {
             burgersFunc();
        }

        break;

    case 0:

        break;
        
    default:

         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";
               
         burgersFunc();  

        break;
    }
} 
    
while (choice != 0);

jollibeeMenuFunc();

}

void orderingSystem :: jollySpaghettiFunc(){

    orderingSystem prodOne("Jolly Spaghetti Family Pan", 237);
    orderingSystem prodTwo("Chicken Bucket w/Rice Jolly Spaghetti & Drins", 758);
    orderingSystem prodThree("6-pc. Burger Steak w/Jolly Spaghetti Family Pan", 570);
    orderingSystem prodFour("8-pc. Burger Steak w/Jolly Spaghetti Family Pan", 650);
    orderingSystem prodFive("Jolly Spaghetti", 60);
    orderingSystem prodSix("Jolly Spaghetti w/Yumburger", 122);
    orderingSystem prodSeven("Jolly Spaghetti w/Fries & Drinks", 133);
    orderingSystem prodEight("Jolly Spaghetti w/Burger Steak", 108);
    orderingSystem prodNine("1-pc. Chickenjoy w/Burger Steak & Half Jolly Spaghetti Super Meal", 212);
    orderingSystem prodTen("Yumburger, Half Jolly Spaghetti & Reg.Fries Super Meal", 137);

    int choice;

do
{
        
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|\t\t\t   JOLLIBEE BEST SELLER MENU                            |\n";
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|[1]" << prodOne.productName << "\n";
    cout << "|[2]" << prodTwo.productName << "\n";
    cout << "|[3]" << prodThree.productName << "\n";
    cout << "|[4]" << prodFour.productName << "\n";
    cout << "|[5]" << prodFive.productName << "\n";
    cout << "|[6]" << prodSix.productName << "\n";
    cout << "|[7]" << prodSeven.productName << "\n";
    cout << "|[8]" << prodEight.productName << "\n";
    cout << "|[9]" << prodNine.productName << "\n";
    cout << "|[10]" << prodTen.productName << "\n";
    cout << "|[0]Back\n";
    cout << "---------------------------------------------------------------------------------\n";
     
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
               
        prodOne.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
        cout << "Enter Quantity: ";
        cin >> quantityEight[0];

             totalBill += prodOne.productPrice * quantityEight[0];
             orderStorageEight[0] += prodOne.productName; 
        }
        
        else
        {
             jollySpaghettiFunc();
        }

        break;

    case 2:
            
        prodTwo.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityEight[1];

             totalBill += prodTwo.productPrice * quantityEight[1];
             orderStorageEight[1] += prodTwo.productName; 
        }
        
        else
        {
             jollySpaghettiFunc();
        }

        break;

    case 3:
              
        prodThree.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityEight[2];

             totalBill += prodThree.productPrice * quantityEight[2];
             orderStorageEight[2] += prodThree.productName; 
        }
        
        else
        {
             jollySpaghettiFunc();
        }

        break;

    case 4:

        prodFour.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityEight[3];

             totalBill += prodFour.productPrice * quantityEight[3];
             orderStorageEight[3] += prodFour.productName; 
        }
        
        else
        {
             jollySpaghettiFunc();
        }

        break;

    case 5:

        prodFive.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityEight[4];

             totalBill += prodFive.productPrice * quantityEight[4];
             orderStorageEight[4] += prodFive.productName; 
        }
        
        else
        {
             jollySpaghettiFunc();
        }

        break;

    case 6:
            
        prodSix.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityEight[5];

             totalBill += prodSix.productPrice * quantityEight[5];
             orderStorageEight[5] += prodSix.productName; 
        }
        
        else
        {
             jollySpaghettiFunc();
        }

        break;

    case 7: 

        prodSeven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityEight[6];

             totalBill += prodSeven.productPrice * quantityEight[6];
             orderStorageEight[6] += prodSeven.productName; 
        }
        
        else
        {
             jollySpaghettiFunc();
        }

        break;

    case 8:

        prodEight.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityEight[7];

             totalBill += prodEight.productPrice * quantityEight[7];
             orderStorageEight[7] += prodEight.productName; 
        }
        
        else
        {
             jollySpaghettiFunc();
        }

        break;

    case 9:

        prodNine.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityEight[8];

             totalBill += prodNine.productPrice * quantityEight[8];
             orderStorageEight[8] += prodNine.productName; 
        }
        
        else
        {
             jollySpaghettiFunc();
        }

        break;

    case 10:

        prodTen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityEight[9];

             totalBill += prodTwo.productPrice * quantityEight[9];
             orderStorageEight[9] += prodTwo.productName; 
        }
        
        else
        {
             jollySpaghettiFunc();
        }

        break;

    case 0:

        break;
        
    default:

         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";
               
         jollySpaghettiFunc();  

        break;
    }
} 
    
while (choice != 0);

jollibeeMenuFunc();

}

void orderingSystem :: burgerSteakFunc(){

    orderingSystem prodOne("Burger Steak Family Savers", 329);
    orderingSystem prodTwo("6-pc. Burger Steak Family Pan", 355);
    orderingSystem prodThree("8-pc. Burger Steak Family Pan", 470);
    orderingSystem prodFour("6-pc. Burger Steak w/Jolly Spaghetti Family Pan", 570);
    orderingSystem prodFive("8-pc. Burger Steak w/Jolly Spaghetti Family Pan", 650);
    orderingSystem prodSix("6-pc. Burger Steak w/Palabok Family Pan", 827);
    orderingSystem prodSeven("8-pc. Burger Steak w/Palabok Family Pan", 923);
    orderingSystem prodEight("1-pc. Burger Steak w/Fries & Drinks", 133);
    orderingSystem prodNine("1-pc. Burger Steak", 60);
    orderingSystem prodTen("2-pc. Burger Steak", 119);
    orderingSystem prodEleven("Jolly Spaghetti w/Burger Steak", 108);
    orderingSystem prodTwelve("1-pc. Chicken w/Burger Steak & Half Jolly Spaghetti Super Meal", 212);

    int choice;

do
{
        
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|\t\t\t   JOLLIBEE BEST SELLER MENU                            |\n";
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|[1]" << prodOne.productName << "\n";
    cout << "|[2]" << prodTwo.productName << "\n";
    cout << "|[3]" << prodThree.productName << "\n";
    cout << "|[4]" << prodFour.productName << "\n";
    cout << "|[5]" << prodFive.productName << "\n";
    cout << "|[6]" << prodSix.productName << "\n";
    cout << "|[7]" << prodSeven.productName << "\n";
    cout << "|[8]" << prodEight.productName << "\n";
    cout << "|[9]" << prodNine.productName << "\n";
    cout << "|[10]" << prodTen.productName << "\n";
    cout << "|[11]" << prodEleven.productName << "\n";
    cout << "|[12]" << prodTwelve.productName << "\n";
    cout << "|[0]Back\n";
    cout << "---------------------------------------------------------------------------------\n";
     
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
               
        prodOne.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
        cout << "Enter Quantity: ";
        cin >> quantityNine[0];

             totalBill += prodOne.productPrice * quantityNine[0];
             orderStorageNine[0] += prodOne.productName; 
        }
        
        else
        {
             burgerSteakFunc();
        }

        break;

    case 2:
            
        prodTwo.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityNine[1];

             totalBill += prodTwo.productPrice * quantityNine[1];
             orderStorageNine[1] += prodTwo.productName; 
        }
        
        else
        {
             burgerSteakFunc();
        }

        break;

    case 3:
              
        prodThree.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityNine[2];

             totalBill += prodThree.productPrice * quantityNine[2];
             orderStorageNine[2] += prodThree.productName; 
        }
        
        else
        {
             burgerSteakFunc();
        }

        break;

    case 4:

        prodFour.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityNine[3];

             totalBill += prodFour.productPrice * quantityNine[3];
             orderStorageNine[3] += prodFour.productName; 
        }
        
        else
        {
             burgerSteakFunc();
        }

        break;

    case 5:

        prodFive.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityNine[4];

             totalBill += prodFive.productPrice * quantityNine[4];
             orderStorageNine[4] += prodFive.productName; 
        }
        
        else
        {
             burgerSteakFunc();
        }

        break;

    case 6:
            
        prodSix.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityNine[5];

             totalBill += prodSix.productPrice * quantityNine[5];
             orderStorageNine[5] += prodSix.productName; 
        }
        
        else
        {
             burgerSteakFunc();
        }

        break;

    case 7: 

        prodSeven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityNine[6];

             totalBill += prodSeven.productPrice * quantityNine[6];
             orderStorageNine[6] += prodSeven.productName; 
        }
        
        else
        {
             burgerSteakFunc();
        }

        break;

    case 8:

        prodEight.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityNine[7];

             totalBill += prodEight.productPrice * quantityNine[7];
             orderStorageNine[7] += prodEight.productName; 
        }
        
        else
        {
             burgerSteakFunc();
        }

        break;

    case 9:

        prodNine.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityNine[8];

             totalBill += prodNine.productPrice * quantityNine[8];
             orderStorageNine[8] += prodNine.productName; 
        }
        
        else
        {
             burgerSteakFunc();
        }

        break;

    case 10:

        prodTen.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityNine[9];

             totalBill += prodTwo.productPrice * quantityNine[9];
             orderStorageNine[9] += prodTwo.productName; 
        }
        
        else
        {
             burgerSteakFunc();
        }

        break;

    case 11:

        prodEleven.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityNine[10];

             totalBill += prodEleven.productPrice * quantityNine[10];
             orderStorageNine[10] += prodEleven.productName; 
        }
        
        else
        {
             burgerSteakFunc();
        }

        break;

    case 12:
             
        prodTwelve.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityNine[11];

             totalBill += prodTwelve.productPrice * quantityNine[11];
             orderStorageNine[11] += prodTwelve.productName; 
        }
        
        else
        {
             burgerSteakFunc();
        }

        break;

    case 0:

        break;
        
    default:

         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";
               
         burgerSteakFunc();  

        break;
    }
} 
    
while (choice != 0);

jollibeeMenuFunc();

}

void orderingSystem :: superMealsFunc(){

    orderingSystem prodOne("1-pc. Chickenjoy w/Regular Fries & Half Jolly Spaghetti Super Meal", 191);
    orderingSystem prodTwo("1-pc. Chickenjoy w/Burger Steak & Half Jolly Spaghetti Super Meal", 212);
    orderingSystem prodThree("Yumburger, Half Jolly Spaghetti & Reg. Fries Super Meal",137);

    int choice;

do
{
        
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|\t\t\t   JOLLIBEE BEST SELLER MENU                            |\n";
    cout << "---------------------------------------------------------------------------------\n";
    cout << "|[1]" << prodOne.productName << "\n";
    cout << "|[2]" << prodTwo.productName << "\n";
    cout << "|[3]" << prodThree.productName << "\n";
    cout << "|[0]Back\n";
    cout << "---------------------------------------------------------------------------------\n";
     
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
               
        prodOne.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
        cout << "Enter Quantity: ";
        cin >> quantityTen[0];

             totalBill += prodOne.productPrice * quantityTen[0];
             orderStorageTen[0] += prodOne.productName; 
        }
        
        else
        {
             superMealsFunc();
        }

        break;

    case 2:
            
        prodTwo.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTen[1];

             totalBill += prodTwo.productPrice * quantityTen[1];
             orderStorageTen[1] += prodTwo.productName; 
        }
        
        else
        {
             superMealsFunc();
        }

        break;

    case 3:
              
        prodThree.printProduct();

        cout << "[1]Order\n";
        cout << "[2]Back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {   
             cout << "Enter Quantity: ";
             cin >> quantityTen[2];

             totalBill += prodThree.productPrice * quantityTen[2];
             orderStorageTen[2] += prodThree.productName; 
        }
        
        else
        {
             superMealsFunc();
        }

        break;

    case 0:

        break;
        
    default:

         cout << "------------------------------\n";
         cout << "|\tInvalid Choice!      |\n";
         cout << "------------------------------\n";
               
         superMealsFunc();  

        break;
    }
} 
    
while (choice != 0);

jollibeeMenuFunc();

}