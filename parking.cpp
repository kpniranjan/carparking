#include <bits/stdc++.h>
using namespace std;

class ParkingLot
{
public:
	int N;							   //number of parking slot
	vector<bool> isbooked;			   //to store status of slots
	map<int, pair<string, string>> ds; // to store meta data of slot

	//constructor
	ParkingLot(int n)
	{
		N = n;
		//
		for (int i = 0; i <= n; i++)
		{
			isbooked.push_back(false); //intially are empty
		}
	}

	//get nearest empty slot
	int getSlot()
	{
		for (int i = 1; i <= N; i++)
		{
			if (isbooked[i] == false)
				return i;
		}
		return -1;
	}

	//adding car to slot

	void insert(int slot, string reg, string color)
	{
		isbooked[slot] = true;
		ds[slot] = make_pair(reg, color);
	}

	//delete
	void deleteCar(int slot)
	{
		ds.erase(slot);
		isbooked[slot] = false;
	}

	//display
	void display()
	{
		cout << "Registeration Number \t\t|\tColor\t|\t Slot No." << endl;
		for (auto ele : ds)
		{
			cout << ele.second.first << "\t\t\t|"
				 << "\t" << ele.second.second << "\t|\t" << ele.first << endl;
		}

		while (1)
		{
			string choice;
			cout << "\n\nEnter yes if want to remove car from list else no : ";
			cin >> choice;
			if (choice == "yes")
			{
				int slot_no;
				cout << "Car Slot no from the list : ";
				cin >> slot_no;
				deleteCar(slot_no);
			}
			else
				break;
		}
	}

	//serach

	vector<string> searchUsingColor(string carColor)
	{
		vector<string> res;
		for (auto entry : ds)
		{
			if (entry.second.second == carColor)
			{
				res.push_back(entry.second.first);
			}
		}
		return res;
	}
	int findByRegNo(string regNo)
	{
		for (auto entry : ds)
		{
			if (entry.second.first == regNo)
			{
				return entry.first;
			}
		}
		return -1;
	}
	vector<int> searchSlotsUsingColor(string carColor)
	{
		vector<int> res;
		for (auto entry : ds)
		{
			if (entry.second.second == carColor)
			{
				res.push_back(entry.first);
			}
		}
		return res;
	}
	void search()
	{
		while (1)
		{
			cout << "\n";
			cout << "Press 1. To search Registration numbers of all cars of a particular colour." << endl;
			cout << "Press 2. To search a using Registeration Number " << endl;
			cout << "Press 3. To search Slot numbers of all slots where a car of a particular colour is parked" << endl;
			cout << "Press 4. To Go Black" << endl;
			int choice;
			cin >> choice;
			string carColor;
			string reg_no;
			int resslot;
			vector<int> res1;
			vector<string> res;
			switch (choice)
			{
			case 1:
				cout << "Enter Color : " << endl;
				cin >> carColor;
				res = searchUsingColor(carColor);
				if (res.size() > 0)
				{
					cout << "Cars having Color : " << carColor << " has following Registeration number :" << endl;
					for (auto c : res)
					{
						cout << c << endl;
					}
				}
				else
				{
					cout << "Car having Color : " << carColor << " is not parked at any slot" << endl;
				}
				break;
			case 2:
				cout << "Enter Registeration Number of Car : " << endl;
				cin >> reg_no;
				resslot = findByRegNo(reg_no);
				if (resslot != -1)
				{
					cout << "Car With Registeration Number : " << reg_no << " is parked at Slot number " << resslot << endl;
				}
				else
				{
					cout << "Car With Registeration Number : " << reg_no << " is not parked at any slot" << endl;
				}
				break;

			case 3:
				cout << "Enter Color : " << endl;
				cin >> carColor;
				res1 = searchSlotsUsingColor(carColor);
				if (res1.size() > 0)
				{
					cout << "Cars having Color : " << carColor << " are parked at following Slots :" << endl;
					for (auto sl : res1)
					{
						cout << sl << endl;
					}
				}
				else
				{
					cout << "Car having Color : " << carColor << " is not parked at any slot" << endl;
				}

				break;
			case 4:
				return;
			default:
				cout << "Enter Valid choice please" << endl;
			}
		}
	}
};

/* Utility Functions */

//to generate random slot

set<int> getRandSlots(int n, int m)
{
	set<int> st;
	while (st.size() < m)
	{
		int x = rand();
		x = x % n;
		x + 1;
		st.insert(x);
	}
	return st;
}

//to generate random color
string getColor()
{
	string Colors[] = {"Black", "White", "Blue", "Red"};
	int m = rand();
	m = m % 4;
	return Colors[m];
}

//to get random reg no
char getRanChar()
{
	int m = rand();
	m = m % 26;
	char ch = 65 + m;
	return ch;
}
int getRandigit()
{
	return rand() % 10;
}
string getRegNo()
{
	// Format : KA-01-HH-1234

	string res;
	for (int i = 1; i <= 2; i++)
	{
		res.push_back(getRanChar());
	}
	res.push_back('-');

	for (int i = 1; i <= 2; i++)
	{
		int x = getRandigit();
		res += to_string(x);
	}
	res.push_back('-');
	for (int i = 1; i <= 2; i++)
	{
		res.push_back(getRanChar());
	}
	res.push_back('-');
	for (int i = 1; i <= 4; i++)
	{
		int x = getRandigit();
		res += to_string(x);
	}
	return res;
}

int main()
{

	int n;
	cout << "Enter Number of slots int Parking : ";
	cin >> n;
	ParkingLot p1(n);
	cout << "Enter Number of intials car : " << endl; //no. of cars currently in the parking lot
	int m;
	cin >> m;
	cout << "Wait for a while ... setting up the ParkingLot  " << endl;

	set<int> slots = getRandSlots(n, m);
	for (auto slot : slots)
	{
		//genrating random car details

		string color = getColor();
		string regno = getRegNo();
		p1.insert(slot, regno, color);
	}

	cout << "\n\n\t\t\t\t\tGreat... All SetUp done... we are good to go ahead....." << endl;

	while (1)
	{
		cout << "Press 1. Display List " << endl;
		cout << "Press 2. Insert New Car at Nearest Slot \t" << endl;
		cout << "Press 3. For Find details" << endl;
		cout << "Press 4. For Exit" << endl;
		cout << "Enter Your Choice : " << endl;
		int choice;
		cin >> choice;
		string rgno;
		string carColor;
		int nearest_slot;
		switch (choice)
		{
		case 1:
			cout << "List of cars along with their details :\n\n";
			p1.display();

			break;
		case 2:
			nearest_slot = p1.getSlot();
			if (nearest_slot != -1)
			{
				cout << "Enter Number Plat Registeration Number : (eg. : KA-01-HH-1234 ) " << endl;
				cin >> rgno;
				cout << "Enter Car Colour : " << endl;
				cin >> carColor;
				p1.insert(nearest_slot, rgno, carColor);
			}
			else
			{
				cout << "All Parking slots are filled ...Sorry....Come after some time" << endl;
			}

			break;
		case 3:
			p1.search();
			break;
		case 4:
			cout << "Thank you For using This System " << endl;
			return 0;
		default:
			cout << "Enter Valid choice please" << endl;
		}
	}
	return 0;
}