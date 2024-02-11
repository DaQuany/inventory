#include<iostream>
#include<list>
#include<map>
#include<string>
using namespace std;

//display what the bag is containing at the moment
void bag(map<string, int>& itemlist, int money);

//display the main menu
void displayMain(int money);

//display the all the items that they can buy
void displayItem(map<string, int>& items);

void main()
{
    //items that a player bought
    map<string, int>itemlist;
    
    //items that are available to purchase
    map<string, int>items;

    items["sword"] = { 500 };
    items["wand"] = { 700 };
    items["helmet"] = { 100 };
    items["armor"] = { 300 };
    items["boots"] = { 50 };
    items["shield"] = { 200 };
    items["arrow"] = { 10 };
    items["bow"] = { 400 };

    //money that a player currently has
    int money = 1000;

    //selector for the main menu
    int input;

    //selector for the item purchase
    string select;

    do {
        displayMain(money);
        cin >> input;

        //if a player chose to buy an item
        if (input == 1)
        {
            displayItem(items);
            cin >> select;
            
            //find the item from the map
            if (items.find(select)!=items.end())
            {
                if (money - items[select] < 0) // if the money is not enough, display decline
                {
                    cout << "Your card has been declined!!!" << endl;
                }
                else // if the money is enough, add to the map that represent the player's bag
                {
                    itemlist[select] = {items[select]};
                    
                    //subtract the item's price from the player's pocket
                    money -= items[select];
                }
            }

            // if the item is not found from a map, try again from the beginning
            else
            {
                cout << "item not found. Please try again." << endl;
            }
        }
        else if (input == 2) // if a player wants to sell what's in the bag
        {
            //display what is in the bag so far
            bag(itemlist, money);

            cin >> select;

            if (itemlist.find(select) != itemlist.end())
            {
                money += items[select];
                itemlist.erase(select);
            }
        }
        else if (input < 3 || input > 3)
        {
            cout << "Please try again." << endl;
        }
    } while (input != 3);

}

void displayMain(int money) {
    cout << "Money : " << money << endl;
    cout << "--------MENU----------" << endl;
    cout << "--------1.BUY---------" << endl;
    cout << "--------2.SELL--------" << endl;
    cout << "--------3.EXIT--------" << endl;
}

void displayItem(map<string, int>& items) {
    int index = 0;
    for (auto i = items.begin(); i != items.end(); i++) 
    {
        cout << ++index << ": " << i->first << " | " << i->second << endl;
    }

}

void bag(map<string, int>& itemlist, int money) {
    int index = 0;
    for (auto iter = itemlist.begin(); iter != itemlist.end(); iter++)
    {
        cout << ++index << ": " << iter->first << " | " << iter->second << endl;
    }
}