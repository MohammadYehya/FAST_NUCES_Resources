#include <iostream>
using namespace std;
class WarehouseItem
{
	private:
		int ItemID;
		string ItemName;
		int ItemAmount;
		static int TotalUniqueItemsInWarehouse;
	public:
		void setItemID(const int i)
		{ItemID = i;}
		void setItemName(const string n)
		{ItemName = n;}
		void setItemAmount(const int a)
		{ItemAmount = a;}
		const int getItemID()
		{return ItemID;}
		const string getItemName()
		{return ItemName;}
		const int getItemAmount()
		{return ItemAmount;}
		
		static void decTotalUniqueItemsInWarehouse(){
		TotalUniqueItemsInWarehouse--;cout << "An item has been removed!" << endl;
		}
		static void incTotalUniqueItemsInWarehouse(){
		TotalUniqueItemsInWarehouse++;cout << "New item added!" << endl;
		}
	
		WarehouseItem(){incTotalUniqueItemsInWarehouse();}
		WarehouseItem(int ID , string n , int amount )
		{
			ItemID = ID;
			ItemName = n;
			ItemAmount = amount;
			incTotalUniqueItemsInWarehouse();
		}
		~WarehouseItem()
		{
			decTotalUniqueItemsInWarehouse();
		}
};
int WarehouseItem::TotalUniqueItemsInWarehouse = 0;
int main()
{
	WarehouseItem *t = new WarehouseItem();
	delete t;
}
