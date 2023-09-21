#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int NumPeople, price;
    int MaxPrice = 0;
    int index = 0;
    string name;
    int* PriceList;
    string* NameList;


    cin >> NumPeople;
    PriceList = new int[NumPeople];
    NameList = new string[NumPeople];

    for(int i = 0; i < NumPeople; i++) {
        cin >> name >> price;

        PriceList[i] = price;
        NameList[i] = name;

        for(int j = 0; j < i; j++) {
            if(PriceList[i] == PriceList[j]) {
                NameList[i] = "NONE";
                NameList[j] = "NONE";
            }
        }
    }

    for(int k = 0; k < NumPeople; k++) {
        if(NameList[k] != "NONE") {
                if(MaxPrice < PriceList[k]) {
                    MaxPrice = PriceList[k];
                    index = k;
                }
        }
    }

    if(MaxPrice == 0) cout << "NONE" << endl;
    else cout << NameList[index] << endl;

    delete[] PriceList;
    delete[] NameList;
}
