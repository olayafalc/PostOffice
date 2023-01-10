#include <iostream>
#include <vector>

#include "Correspondence.h"
#include "Letter.h"
#include "Telegram.h"
#include "Package.h"

using namespace std;

Letter readNewLetter(Letter newL);
void receive(std::vector<Letter>& listLetter);
void deliver(std::vector<Letter>& listLetter);
void showFirstElement(std::vector<Letter>& listLetter);
void showList(std::vector<Letter>& listLetter);
double calculatePrice(std::vector<Letter>& listLetter);

Telegram readNewTelegram(Telegram newT);
void receive(std::vector<Telegram>& listTelegram);
void deliver(std::vector<Telegram>& listTelegram);
void showFirstElement(std::vector<Telegram>& listTelegram);
void showList(std::vector<Telegram>& listTelegram);
double calculatePrice(std::vector<Telegram>& listTelegram);

Package readNewPackage(Package newP);
void receive(std::vector<Package>& listPackage);
void deliver(std::vector<Package>& listPackage);
void showFirstElement(std::vector<Package>& listPackage);
void showList(std::vector<Package>& listPackage);
double calculatePrice(std::vector<Package>& listPackage);

int main()
{
    std::vector<Letter> listLetter;
    std::vector<Telegram> listTelegram;
    std::vector<Package> listPackage;

    int option, type;
    double totalPrice=0;
    system("clear");
    cout << "----------------------- " << endl;
    cout << "WELCOME TO POST OFFICE!" << endl;
    cout << "----------------------- " << endl;

    do{
        cout <<"\nWhat would you like to do?" << endl;
        cout << "1) Receive New Correspondence" << endl;
        cout << "2) Deliver Correspondence" << endl;
        cout << "3) Calculate Price" << endl;
        cout << "4) Show list" << endl;
        cout << "5) Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> option;
        switch(option){
            case 1:
                cout << "You have chosen 'Receive New Correspondence'" << endl;
                cout << "\nInsert the type of the correspondence:\n1)Letter   2)Telegram   3)Package" << endl;
                cin >> type;
                switch(type){
                    case 1:
                        receive(listLetter);
                        break;
                    case 2:
                        receive(listTelegram);
                        break;
                    case 3:
                        receive(listPackage);
                        break;
                    default:
                        cout << "It doesn't exist that type of correspodence, sorry :(" << endl;
                        break;
                }
                break;
            case 2:
                cout << "You have chosen 'Deliver Correspondence'" << endl;
                cout << "\nInsert the type of the correspondence:\n1)Letter   2)Telegram   3)Package" << endl;
                cin >> type;
                switch(type){
                    case 1:
                        deliver(listLetter);
                        break;
                    case 2:
                        deliver(listTelegram);
                        break;
                    case 3:
                        deliver(listPackage);
                        break;
                    default:
                        cout << "It doesn't exist that type of correspodence, sorry :(" << endl;
                        break;
                }
                break;
            case 3:
                cout << "You have chosen 'Calculate Price'" << endl;
                if (!(listLetter.empty() && listTelegram.empty() && listPackage.empty())){
                    totalPrice = totalPrice + calculatePrice(listLetter);
                    totalPrice = totalPrice + calculatePrice(listTelegram);
                    totalPrice = totalPrice + calculatePrice(listPackage);
                }
                cout << "The total price that the Post Office will earn with the actual correspondence is " << totalPrice << " pln" << endl;
                break;

            case 4:
                cout << "You have chosen 'Show List'\n" << endl;
                showList(listLetter);
                showList(listTelegram);
                showList(listPackage);
                break;

            case 5:
                cout << "You have chosen 'Exit'. GOODBYE!" << endl;
                break;

            default:
                cout << "You have chosen an incorrect option. Please, try again" << endl;
                break;
            }
        cout << "----------------------- " << endl;
        }while(option!=5);

    return 0;
}

/****************LETTER FUNCTIONS****************/
Letter readNewLetter(Letter newL){
    string s1, s2, s3, answer;
    int d,m,y;

    cout << "Insert the data of the correspondence:" << endl;
    cout << "   Receiver: ";
    cin >> s1;
    newL.set_to_name(s1);
    cout << "   Shipping address: ";
    cin >> s2;
    newL.set_to_address(s2);
    cout << "   Sender: ";
    cin >> s3;
    newL.set_from_name(s3);
    cout << "\n   Insert the data of the letter:" << endl;
    cout << "       Insert the date of the letter:" << endl;
    cout << "           Day: ";
    cin >> d;
    cout << "           Month: ";
    cin >> m;
    cout << "           Year: ";
    cin >> y;
    newL.set_from_date(d,m,y);
    cout << "       Abroad (Y/N): ";
    cin >> answer;
    if (answer=="Y" || answer=="y"){
        newL.setAbroad(true);
    } else {
        newL.setAbroad(false);
    }
    newL.print();
    return newL;
}

void receive(std::vector<Letter>& listLetter){
    Letter newL("","","",1,1,1,false,false);
    Letter readL("","","",1,1,1,false,false);
    string answer;

    cout << "\nYou are receiveing a new letter" << endl;
    readL = readNewLetter(newL);
    cout << "\nDo you want to store the new letter? (Y/N):";
    cin >> answer;
    if (answer=="Y" || answer=="y"){
        //cout << "lo guardo" << endl;
        listLetter.push_back(readL);
        cout << "Letter received" << endl;
    } else {
        //cout << "lo borro";
        readL.~Letter();
    }
}

void deliver(std::vector<Letter>& listLetter){
    string answer;

    if (listLetter.empty()) {
        cout << "There are no letters to deliver" << endl;
    } else {
        //cout << "Muestro una carta y si quiere el usuario la envio" << endl;
        showFirstElement(listLetter);
        cout << "Are you sure you want to deliver this letter? (Y/N):";
        cin >> answer;
        if (answer=="Y" || answer=="y"){
            //cout << "lo envio = elimino" << endl;
            listLetter.erase(listLetter.begin());
            cout << "Letter delivered" << endl;
        }
    }
}

void showFirstElement(std::vector<Letter>& listLetter){
    const Letter& first = listLetter.front();
    first.print();
}

void showList(std::vector<Letter>& listLetter) {
    if(listLetter.empty()){
        cout << "There are no letters" << endl;
    } else {
        for(Letter l:listLetter) {
            //cout << "imprimo todas las cartas" << endl;
            l.print();
        }
    }
}

double calculatePrice(std::vector<Letter>& listLetter){
    bool older;
    double pricePerLetter;
    double totalPrice=0;
    for(Letter l:listLetter) {
        older = l.isOver30DaysOld();
        l.setOlder(older);
        pricePerLetter = l.getPrice();
        totalPrice = totalPrice+pricePerLetter;
    }
    cout << "The price of the total of letters is " << totalPrice << " pln" << endl;
    return totalPrice;
}
/****************LETTER FUNCTIONS****************/

/****************TELEGRAM FUNCTIONS****************/
Telegram readNewTelegram(Telegram newT){
    string s1, s2, s3;
    int amount;
    int tax;

    cout << "Insert the data of the correspondence:" << endl;
    cout << "   Receiver: ";
    cin >> s1;
    newT.set_to_name(s1);
    cout << "   Shipping address: ";
    cin >> s2;
    newT.set_to_address(s2);
    cout << "   Sender: ";
    cin >> s3;
    newT.set_from_name(s3);
    cout << "\n   Insert the data of the telegram:" << endl;
    cout << "       Amount of words: ";
    cin >> amount;
    newT.set_amount_words(amount);
    cout << "       Tax: ";
    cin >> tax;
    newT.setTax(tax);
    newT.print();

    return newT;
}

void receive(std::vector<Telegram>& listTelegram){
    Telegram newT("","","",0,0);
    Telegram readT("","","",0,0);
    string answer;

    cout << "\nYou are receiveing a new telegram" << endl;
    readT = readNewTelegram(newT);
    cout << "\nDo you want to store the new telegram? (Y/N):";
    cin >> answer;
    if (answer=="Y" || answer=="y"){
        //cout << "lo guardo" << endl;
        listTelegram.push_back(readT);
        cout << "Telegram received" << endl;
    } else {
        //cout << "lo borro";
        readT.~Telegram();
    }
}

void deliver(std::vector<Telegram>& listTelegram) {
    string answer;

    if (listTelegram.empty()) {
        cout << "There are no telegrams to deliver" << endl;
    } else {
        //cout << "A telegram is shown and if the user wants it is stored" << endl;
        showFirstElement(listTelegram);
        cout << "Are you sure you want to deliver this telegram? (Y/N):";
        cin >> answer;
        if (answer=="Y" || answer=="y"){
            //cout << "lo envio = elimino" << endl;
            listTelegram.erase(listTelegram.begin());
            cout << "Telegram delivered" << endl;
        }
    }
}

void showFirstElement(std::vector<Telegram>& listTelegram) {
    const Telegram& first = listTelegram.front();
    first.print();
}

void showList(std::vector<Telegram>& listTelegram) {
    if(listTelegram.empty()){
        cout << "There are no telegrams" << endl;
    } else {
        for(Telegram t:listTelegram) {
            t.print();
        }
    }
}

double calculatePrice(std::vector<Telegram>& listTelegram){
    double pricePerTelegram;
    double totalPrice=0;
    for(Telegram t:listTelegram) {
        pricePerTelegram = t.getPrice();
        totalPrice = totalPrice+pricePerTelegram;
    }
    cout << "The price of the total of telegrams is " << totalPrice << " pln" << endl;
    return totalPrice;
}
/****************TELEGRAM FUNCTIONS****************/

/****************PACKAGE FUNCTIONS****************/
Package readNewPackage(Package newP){
    string s1, s2, s3;
    int urg;
    double weight;

    cout << "Insert the data of the correspondence:" << endl;
    cout << "   Receiver: ";
    cin >> s1;
    newP.set_to_name(s1);
    cout << "   Shipping address: ";
    cin >> s2;
    newP.set_to_address(s2);
    cout << "   Sender: ";
    cin >> s3;
    newP.set_from_name(s3);
    cout << "\n   Insert the data of the package:" << endl;
    cout << "       Weight (kg): ";
    cin >> weight;
    newP.setWeight(weight);
    cout << "\n   Urgence of the shipping: 1)urgent   2)medium   3)no urgent" << endl;
    cin >> urg;
    switch(urg){
        case 1:
            newP.setUrg(Urgence::urgent);
            break;
        case 2:
            newP.setUrg(Urgence::medium);
            break;
        case 3:
            newP.setUrg(Urgence::no_urgent);
            break;
        default:
            newP.setUrg(Urgence::no_urgent);
            break;
    }
    newP.print();

    return newP;
}

void receive(std::vector<Package>& listPackage){
    Package newP("","","",0,Urgence::no_urgent);
    Package readP("","","",0,Urgence::no_urgent);
    string answer;

    cout << "\nYou are receiveing a new package" << endl;
    readP = readNewPackage(newP);
    cout << "\nDo you want to store the new package? (Y/N):";
    cin >> answer;
    if (answer=="Y" || answer=="y"){
        //cout << "lo guardo" << endl;
        listPackage.push_back(readP);
        cout << "Package received" << endl;
    } else {
        //cout << "lo borro";
        readP.~Package();
    }
}

void deliver(std::vector<Package>& listPackage) {
    string answer;

    if (listPackage.empty()) {
        cout << "There are no packages to deliver" << endl;
    } else {
        showFirstElement(listPackage);
        cout << "Are you sure you want to deliver this package? (Y/N):";
        cin >> answer;
        if (answer=="Y" || answer=="y"){
            //cout << "lo envio = elimino" << endl;
            listPackage.erase(listPackage.begin());
            cout << "Package delivered" << endl;
        }
    }
}

void showFirstElement(std::vector<Package>& listPackage) {
    const Package& first = listPackage.front();
    first.print();
}

void showList(std::vector<Package>& listPackage) {
    if(listPackage.empty()){
        cout << "There are no packages" << endl;
    } else {
        for(Package p:listPackage) {
            p.print();
        }
    }
}

double calculatePrice(std::vector<Package>& listPackage){
    double pricePerPackage;
    double totalPrice=0;
    for(Package p:listPackage) {
        pricePerPackage = p.getPrice();
        totalPrice = totalPrice+pricePerPackage;
    }
    cout << "The price of the total of packages is " << totalPrice << " pln" << endl;
    return totalPrice;
}
/****************PACKAGE FUNCTIONS****************/
