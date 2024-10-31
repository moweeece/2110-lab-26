// COMSC-210 | Mauricio Espinosa | Lab 26
// IDE Used: Visual Studio Code & Github

#include <iostream>
#include <chrono>
#include <vector>    // for vector
#include <list>      // for list
#include <set>       // for set
#include <fstream>   // for reading files
#include <iomanip>   // for setw()
#include <string>
#include <algorithm>
using namespace std;
using namespace std::chrono;


// function declarations
void readDataVec(const string&, vector<string>&);
void readDataList(const string&, list<string>&);
void readDataSet(const string&, set<string>&);

void sortDataVec(vector<string>&);
void sortDataList(list<string>&);

void insertDataVec(vector<string>&);
void insertDataList(list<string>&);
void insertDataSet(set<string>&);

void deleteDataVec(vector<string>&);
void deleteDataList(list<string>&);
void deleteDataSet(set<string>&);


int main() {
    // vector, list, and set declarations
    vector<string> vec1;
    list<string> list1;
    set<string> set1;

    const string fileName = "codes.txt";

    // header output
    cout << setw(15) << "Operation" << setw(15) << "Vector" << setw(15) << "List" << setw(15) << "Set" << endl;

    // READING DATA
    // Reading Data from Vector
    auto startReadVec = high_resolution_clock::now();
    readDataVec(fileName, vec1);               // call readData function and pass the name of the file and each container type
    auto endReadVec = high_resolution_clock::now();
    auto durationReadVec = duration_cast<milliseconds>(endReadVec - startReadVec);

    // Reading Data from List
    auto startReadList = high_resolution_clock::now();
    readDataList(fileName, list1);               // call readData function and pass the name of the file and each container type
    auto endReadList = high_resolution_clock::now();
    auto durationReadList = duration_cast<milliseconds>(endReadList - startReadList);

    // Reading Data from Vector
    auto startReadSet = high_resolution_clock::now();
    readDataSet(fileName, set1);               // call readData function and pass the name of the file and each container type
    auto endReadSet = high_resolution_clock::now();
    auto durationReadSet = duration_cast<milliseconds>(endReadSet - startReadSet);

    // Read time output
    cout << setw(15) << "Read" << setw(15) << durationReadVec.count() << setw(15) << durationReadList.count() << setw(15) << durationReadSet.count() << endl;


    // SORTING DATA
    // Sort Vector Data
    auto startSortVec = high_resolution_clock::now();
    sortDataVec(vec1);                               // call sortData function and pass vector (no set since set is already sorted)
    auto endSortVec = high_resolution_clock::now();
    auto durationSortVec = duration_cast<milliseconds>(endSortVec - startSortVec);

    // Sort List Data
    auto startSortList = high_resolution_clock::now();
    sortDataList(list1);                               // call sortData function and pass vector (no set since set is already sorted)
    auto endSortList = high_resolution_clock::now();
    auto durationSortList = duration_cast<milliseconds>(endSortList - startSortList);

    // Sort time output
    int durationSortSet = 0;  // because an element is automatically sorted in a set
    cout << setw(15) << "Sort" << setw(15) << durationSortVec.count() << setw(15) << durationSortList.count() << setw(15) << durationSortSet << endl;


    // INSERTING DATA
    // Insert Data to Vector
    auto startInsertVec = high_resolution_clock::now();
    insertDataVec(vec1);                      // call insertData function to insert data to vector
    auto endInsertVec = high_resolution_clock::now();
    auto durationInsertVec = duration_cast<milliseconds>(endInsertVec - startInsertVec);

    // Insert Data to List
    auto startInsertList = high_resolution_clock::now();
    insertDataList(list1);                      // call insertData function to insert data to list
    auto endInsertList = high_resolution_clock::now();
    auto durationInsertList = duration_cast<milliseconds>(endInsertList - startInsertList);

    // Insert Data to Set
    auto startInsertSet = high_resolution_clock::now();
    insertDataSet(set1);                      // call insertData function to insert data to set
    auto endInsertSet = high_resolution_clock::now();
    auto durationInsertSet = duration_cast<milliseconds>(endInsertSet - startInsertSet);

    // Insert time output
    cout << setw(15) << "Insert" << setw(15) << durationInsertVec.count() << setw(15) << durationInsertList.count() << setw(15) << durationInsertSet.count() << endl;


    // DELETEING DATA
    // Delete Data from Vector
    auto startDeleteVec = high_resolution_clock::now();
    deleteDataVec(vec1);                     // call the deleteData function to delete data from vector
    auto endDeleteVec = high_resolution_clock::now();
    auto durationDeleteVec = duration_cast<milliseconds>(endDeleteVec - startDeleteVec);

     // Delete Data from List
    auto startDeleteList = high_resolution_clock::now();
    deleteDataList(list1);                     // call the deleteData function to delete data from list
    auto endDeleteList = high_resolution_clock::now();
    auto durationDeleteList = duration_cast<milliseconds>(endDeleteList - startDeleteList);

     // Delete Data from Set
    auto startDeleteSet = high_resolution_clock::now();
    deleteDataSet(set1);                     // call the deleteData function to delete data from set
    auto endDeleteSet = high_resolution_clock::now();
    auto durationDeleteSet = duration_cast<milliseconds>(endDeleteSet - startDeleteSet);

    // Delete time output
    cout << setw(15) << "Delete" << setw(15) << durationDeleteVec.count() << setw(15) << durationDeleteList.count() << setw(15) << durationDeleteSet.count() << endl;
     

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/


// function to read data and add to vector
void readDataVec(const string& filename, vector<string>& vecRead)
{
    // open the file
    ifstream file(filename);
    string tempCode;

    // check if file is opened
    if (!file.is_open())
    {
        cerr << "Error Opening the file." << endl;
        return;   // exit the function
    }

    // read the code from the file and insert it into each container type
    while (file >> tempCode)
    {
        vecRead.push_back(tempCode);
    }

    // close the file
    file.close();
}

// function to read data and add to list
void readDataList(const string& filename, list<string>& listRead)
{
    // open the file
    ifstream file(filename);
    string tempCode;

    // check if file is opened
    if (!file.is_open())
    {
        cerr << "Error Opening the file." << endl;
        return;   // exit the function
    }

    // read the code from the file and insert it into the list
    while (file >> tempCode)
    {
        listRead.push_back(tempCode);
    }

    // close the file
    file.close();
}

// function to read data and add to set
void readDataSet(const string& filename, set<string>& setRead)
{
    // open the file
    ifstream file(filename);
    string tempCode;

    // check if file is opened
    if (!file.is_open())
    {
        cerr << "Error Opening the file." << endl;
        return;   // exit the function
    }

    // read the code from the file and insert it into the set
    while (file >> tempCode)
    {
        setRead.insert(tempCode);
    }

    // close the file
    file.close();
}


// function to sort vector data 
void sortDataVec(vector<string>& vecSort)
{
    // sort the vector
    sort(vecSort.begin(), vecSort.end());
}

// function to sort list data
void sortDataList(list<string>& listSort)
{
    // sort the list
    listSort.sort();
}


// function to insert data to vector
void insertDataVec(vector<string>& vecInsert)
{
    string insertCode = "TESTCODE";
    // find middle of a vector
    size_t vectorMiddleInsert = vecInsert.size() / 2;   // vector size divided by 2 for estimated middle position
    
    // insert the test code
    vecInsert.insert(vecInsert.begin() + vectorMiddleInsert, insertCode);
}

// function to insert data to list
void insertDataList(list<string>& listInsert)
{
    string insertCode = "TESTCODE";
    // find middle of a list
    auto listMiddleInsert = next(listInsert.begin(), listInsert.size() / 2);  // iterator traverse from the beginning of the list to the middle of the list
    
    // insert the test code
    listInsert.insert(listMiddleInsert, insertCode);
}

// function to insert data to set
void insertDataSet(set<string>& setInsert)
{
    string insertCode = "TESTCODE";
    // set inserts in the correct order so no need to find the middle
    
    // insert the test code
    setInsert.insert(insertCode);
}


// function to delete data from vector
void deleteDataVec(vector<string>& vecDelete)
{
    // find middle of a vector
    size_t vectorMiddleDelete = vecDelete.size() / 2;   // vector size divided by 2 for estimated middle position

    // insert the middle-ish element
    vecDelete.erase(vecDelete.begin() + vectorMiddleDelete);
}

// function to delete data from list
void deleteDataList(list<string>& listDelete)
{
    // find middle of a list
    auto listMiddleDelete = next(listDelete.begin(), listDelete.size() / 2);  // iterator traverse from the beginning of the list to the middle of the list

    // insert the middle-ish element
    listDelete.erase(listMiddleDelete);
}

// function to delete data from set
void deleteDataSet(set<string>& setDelete)
{
    // find middle of a set
    size_t setMiddleDelete = setDelete.size() / 2;

    // deleting an element from the set
    auto it = setDelete.begin();   // set iterator at the beginning of the set
    advance(it, setMiddleDelete);  // advance the iterator the middle of the set
    setDelete.erase(it);           // erase where the iterator is
}