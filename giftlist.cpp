//Created by Karthik Chavan k1833342 @ 7/8/2020
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

//GiftsList ADT
class GiftsList
{
private:
   struct Gifts
   {
      string name;//Name of gift item
      Gifts* next;//Point to next gift

      Gifts(string n) : name(n), next(nullptr) {}
   };
   Gifts* head;//Head of gifts list

public:
   GiftsList() : head(nullptr) {}

   // Function to insert gifts in list of gifts
   void insert(string n)
   {

      Gifts* newGift = new Gifts(n);
      if (head == nullptr)
      {
         head = newGift;
      }
      else
      {
         Gifts* ptr = head;
         while (ptr->next != nullptr)
            ptr = ptr->next;
         ptr->next = newGift;
      }
   }

   /*
   *   Function to print Content of gifts list
   */
   void print()
   {
      Gifts* ptr = head;
      while (ptr != nullptr)
      {
         if (ptr->next == nullptr)
            cout << ptr->name << endl;
         else
            cout << ptr->name << ", ";
         ptr = ptr->next;
      }
   }
};

//Class NiceList
class NiceList
{
private:
   struct List
   {
      string name;
      GiftsList gifts; // GiftsList ADT
      List* next;

      List(string n, GiftsList g) : name(n), gifts(g), next(nullptr) {}
   };

   List* head;

public:
   NiceList() : head(nullptr) {}//To create an empty list

   // Insert a new person's name and a list of gifts received by him/her
   void insert(string name, GiftsList gifts)
   {
      List* newNode = new List(name, gifts);
      if (head == nullptr)//If NiceList is empty
      {
         head = newNode;
      }
      else
      {
         List* ptr = head;
         while (ptr->next != nullptr)
            ptr = ptr->next;
         ptr->next = newNode;
      }
   }

   // Add one more gift to the list of gifts for a given kid’s name
   void addGift(string n, string giftName)
   {
      List* ptr = head;
      while (ptr->name != n && ptr != nullptr)
      {
         ptr = ptr->next;
      }
      ptr->gifts.insert(giftName);//Insert new gift
   }

   // Function to print NiceList content
   void print()
   {
      List* ptr = head;
      while (ptr != nullptr)
      {
         cout << "Name: " << ptr->name << ", Gifts: ";
         ptr->gifts.print();
         ptr = ptr->next;
      }
   }
};


int main()
{
   NiceList NL1;

   GiftsList GL1, GL2, GL3;
   string name;
   string item;


   //name1
   cout << "enter name: ";
   cin >> name;
   cout << "enter item 1: ";
   cin >> item;
   GL1.insert(item);
   cout << "enter item 2: ";
   cin >> item;
   GL1.insert(item);
   cout << "enter item 3: ";
   cin >> item;
   GL1.insert(item);
   NL1.insert(name, GL1);
   //name2
   cout << "enter name: ";
   cin >> name;
   cout << "enter item 1: ";
   cin >> item;
   GL2.insert(item);
   cout << "enter item 2: ";
   cin >> item;
   GL2.insert(item);
   cout << "enter item 3: ";
   cin >> item;
   GL2.insert(item);
   NL1.insert(name, GL2);

   //name3
   cout << "enter name: ";
   cin >> name;
   cout << "enter item 1: ";
   cin >> item;
   GL3.insert(item);
   cout << "enter item 2: ";
   cin >> item;
   GL3.insert(item);
   cout << "enter item 3: ";
   cin >> item;
   GL3.insert(item);
   NL1.insert(name, GL3);

   cout << "Content of Nice List: ";
   NL1.print();//Print Nice List

   return 0;
}
