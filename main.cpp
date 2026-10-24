//Eduardo Avila
//COMSC - 210 - 5293
//Lab 27 - Villager Map

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

void displayVillagers(const map<string, tuple<int, string, string>> &villagers);
void plusFriendship(map<string, tuple<int,string,string>> &villagers);
void minusFriendship(map<string,tuple<int,string,string>> &villagers);
void addVillager(map<string,tuple<int,string,string>> &villagers);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    villagers["Audie"] = make_tuple(5, "Dog", "Woopty Doo!");
    villagers["Raymond"] = make_tuple(8,"Cat","Nice fit");
    villagers.insert({"Marshal", make_tuple(3, "Bird", "Fetch me their souls!")});

    int choice = 0;

    while (choice != 4){
        cout << "1. Increase Friendship" << endl;
        cout << "2. Decrease Friendship" << endl;
        cout << "3. Search Villager" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        cin.ignore(10000, '\n');

        switch (choice){
            case 1:
                cout << endl;
                plusFriendship(villagers);
                cout << endl;
                break;

            case 2:
                cout << endl;
                minusFriendship(villagers);
                cout << endl;
                break;

            case 3: {
                cout << endl;
                string name;

                cout << "Villager name to search: ";
                getline(cin,name);

                auto it = villagers.find(name);

                if (it != villagers.end()){
                    cout << name << " [";
                    cout << get<0>(it->second) << ", ";
                    cout << get<1>(it->second) << ", ";
                    cout << get<2>(it->second) << "]" << endl;
                }
                else {
                    cout << "\nResident " << name << " was not found in the registry." << endl;
                }
                break;
            }

            case 4:
                cout << "\nProgram Exiting." << endl;
                break;

            default:
                cout << "\nError. Try again." << endl;
        }
    }


/*
    // access the map using a range-based for loop
    cout << "Villager details (range-based for loop):" << endl;

    for (auto pair : villagers) {
        cout << pair.first << " [";
        cout << get<0>(pair.second) << ", ";
        cout << get<1>(pair.second) << ", ";
        cout << get<2>(pair.second) << "] " << endl;
    }

    // access the map using iterators
    cout << "\nVillager details (iterators):" << endl;

    for (map<string, tuple<int, string, string>>::iterator it = villagers.begin(); 
            it != villagers.end(); ++it) {
        cout << it->first << " [";
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second) << "]" << endl;
    }

    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);

    if (it != villagers.end()) {  // the iterator points to beyond the end of the map

        cout << "\nFound " << searchKey << ": " << endl;
        cout << searchKey << " [";
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second) << "]" << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;
    */

    return 0;
}

void addVillager(map<string,tuple<int,string,string>> &villagers){
    string name;
    int fPoints;
    string species;
    string catchphrase;

    cout << "\nEnter new villager's name: ";
    getline(cin, name);

    //make sure villager doesnt exist
    if (villagers.find(name) != villagers.end()){
        cout << "\nVillager Resident exists in the registry!" << endl;
        return;
    }

    cout << "Enter Friendship Level 0-10: ";
    cin >> fPoints;
    cin.ignore(10000,'\n');

    cout << "Enter Species: ";
    getline(cin,species);

    cout << "Enter Catchprase: ";
    getline(cin,catchphrase);

    villagers[name] = make_tuple(fPoints,species,catchphrase);

    cout << "Villager Resident " << name << " added to the registry." << endl;
    displayVillagers(villagers);
}

void displayVillagers(const map<string, tuple<int,string,string>> &villagers){
    cout << "\nVillager details:" << endl;
    for (auto pair : villagers){
        cout << pair.first << " [";
        cout << get<0>(pair.second) << ", ";
        cout << get<1>(pair.second) << ", ";
        cout << get<2>(pair.second) << "]" << endl;
    }
}

void plusFriendship(map<string,tuple<int,string,string>> &villagers){
    string name;

    cout << "What is villager resident's name: ";
    getline(cin, name);

    auto it = villagers.find(name);

    if (it != villagers.end()) {
        int fPoints = get<0>(it->second);
        fPoints++;

        get<0>(it->second) = fPoints;

        cout << "\n" << name << "'s friendship points went up!" << endl;
    }
    else {
        cout << "\nResident " << name << " was not found in the registry." << endl;
    }

    displayVillagers(villagers);
}

void minusFriendship(map<string,tuple<int,string,string>> &villagers){
    string name;

    cout << "What is villager resident's name: ";
    getline(cin, name);

    auto it = villagers.find(name);

    if (it != villagers.end()) {
        int fPoints = get<0>(it->second);

        //check to make sure it doesnt go negative
        if (fPoints > 0){
            fPoints--;
            get<0>(it->second) = fPoints;
            cout << name << "'s friendship points went down!" << endl;
        }
        else {
            cout << "\n" << name << "'s friendship points can't go lower than 0!" << endl;
        }
    }
    else {
        cout << "\nResident " << name << " was not found in the registry." << endl;
    }

    displayVillagers(villagers);
}