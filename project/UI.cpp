//
// Created by bienu on 5/21/2022.
//

#include "UI.h"
#include <iostream>
#include <string>

using namespace std;

UI::UI(Network &network) : network(network) {
}

UI::~UI() = default;

void UI::menu() {
    string option;
    do {
        uiShowMenu();
        cin >> option;
        if (option == "1")
            usersMenu();
        else if (option == "2")
            friendshipMenu();
        else if (option == "3")
            messageMenu();
        else if (option == "4")
            cout << "\n Programul se va inchide. Multumim!" << endl;
        else
            cout << "\n Optiune invalida. Reincercati!" << endl;
    } while (option != "4");
}

void UI::uiShowMenu() {
    cout << "\n 1. Optiuni utilizatori" << endl;
    cout << "\n 2. Optiuni prietenie" << endl;
    cout << "\n 3. Optiuni mesaje" << endl;
    cout << "\n 4. Iesire" << endl;
    cout << "\n =====================================" << endl;
    cout << "\n Alegeti optiunea dorita: ";
}

void UI::uiShowMenuUsers() {
    cout << "\n 1. Adaugare utilizator" << endl;
    cout << "\n 2. Actualizare utilizator" << endl;
    cout << "\n 3. Stergere utilizator" << endl;
    cout << "\n 4. Afisare utilizatori" << endl;
    cout << "\n 5. Detalii despre un utilizator" << endl;
    cout << "\n 6. Revenire meniu principal" << endl;
    cout << "\n =====================================" << endl;
    cout << "\n Alegeti optiunea dorita: ";
}

void UI::uiShowMenuFriendships() {
    cout << "\n 1. Adaugare prietenie" << endl;
    cout << "\n 2. Stergere prietenie" << endl;
    cout << "\n 3. Afisare lista de prieteni a unui utilizator" << endl;
    cout << "\n 4. Afisare prieteni comuni" << endl;
    cout << "\n 5. Revenire meniu principal" << endl;
    cout << "\n =====================================" << endl;
    cout << "\n Alegeti optiunea dorita: ";
}

void UI::uiShowMenuMessages() {
    cout << "\n 1. Trimitere mesaj" << endl;
    cout << "\n 2. Editare mesaj" << endl;
    cout << "\n 3. Stergere mesaj" << endl;
    cout << "\n 4. Afisare conversatie dintre doi utilizatori" << endl;
    cout << "\n 5. Afisare lista conversatii a unui utilizator" << endl;
    cout << "\n 6. Revenire meniu principal" << endl;
    cout << "\n =====================================" << endl;
    cout << "\n Alegeti optiunea dorita: ";
}

void UI::usersMenu() {
    string op;
    do {
        uiShowMenuUsers();
        cin >> op;
        if (op == "1")
            uiAddUser();
        else if (op == "2")
            uiUpdateUser();
        else if (op == "3")
            uiDeleteUser();
        else if (op == "4")
            uiAllUser();
        else if (op == "5")
            uiOneUser();
        else if (op == "6")
            cout << "Revenire meniu principal." << endl;
        else
            cout << "Optiune gresita, reincercati!" << endl;
    } while (op != "6");
}

void UI::friendshipMenu() {
    string op2;
    do {
        uiShowMenuFriendships();
        cin >> op2;
        if (op2 == "1")
            uiAddFriendship();
        else if (op2 == "2")
            uiDeleteFriendship();
        else if (op2 == "3")
            uiUserFriendships();
        else if (op2 == "4")
            uiCommonFriends();
        else if (op2 == "5")
            cout << "Revenire meniu principal." << endl;
        else
            cout << "Optiune gresita, reincercati!" << endl;
    } while (op2 != "5");
}

void UI::messageMenu() {
    string op3;
    do {
        uiShowMenuMessages();
        cin >> op3;
        if (op3 == "1")
            uiSendMessage();
        else if (op3 == "2")
            uiUpdateMessage();
        else if (op3 == "3")
            uiDeleteMessage();
        else if (op3 == "4")
            uiConversation();
        else if (op3 == "5")
            uiUserConversations();
        else if (op3 == "6")
            cout << "Revenire meniu principal." << endl;
        else
            cout << "Optiune gresita, reincercati!" << endl;
    } while (op3 != "6");
}

void UI::uiAddUser() {
    try {
        string name, password, fullName;
        cout << "Dati numele de utilizator: ";
        cin >> name;
        cout << "Dati parola contului: ";
        cin >> password;
        cout << "Dati numele intreg al utilizatorului: ";
        cin.ignore();
        getline(cin, fullName);
        network.addUser(name, password, fullName);
    }
    catch (invalid_argument &e) { cout << e.what() << endl; }
}

void UI::uiUpdateUser() {
    try {
        string name, password, fullName;
        cout << "Dati numele de utilizator pentru actualizare: ";
        cin >> name;
        cout << "Dati parola contului: ";
        cin >> password;
        cout << "Dati numele utilizatorului: ";
        cin.ignore();
        getline(cin, fullName);

        string name2, password2, fullName2;
        cout << "Dati noul nume de utilizator: ";
        cin >> name2;
        cout << "Dati noua parola a contului: ";
        cin >> password2;
        cout << "Dati numele utilizatorului: ";
        cin.ignore();
        getline(cin, fullName2);
        network.updateUser(name, password, fullName,
                           name2, password2, fullName2);
    }
    catch (invalid_argument &e) { cout << e.what() << endl; }

}

void UI::uiDeleteUser() {
    try {
        string name, password, fullName;
        cout << "Dati numele de utilizator: ";
        cin >> name;
        cout << "Dati parola contului: ";
        cin >> password;
        cout << "Dati numele utilizatorului: ";
        cin.ignore();
        getline(cin, fullName);
        network.deleteUser(name, password, fullName);
    }
    catch (invalid_argument &e) { cout << e.what() << endl; }
}

void UI::uiAllUser() {
    cout << network.getUsers().getValues();
}

void UI::uiOneUser() {
    string username;
    cout << "Dati numele de utilizator: ";
    cin >> username;
    User user = network.getUserByUsername(username);
    if (user.getUserName() == "")
        cout << "Utilizatorul nu a fost gasit! Reincercati!" << endl;
    else
        cout << user << endl;

}

void UI::uiAddFriendship() {
    try {
        string username1, username2;
        cout << "Dati numele primului utilizator: ";
        cin >> username1;
        cout << "Dati numele celui de-al doilea utilizator: ";
        cin >> username2;

        network.addFriendship(username1, username2);
    }
    catch (invalid_argument &e) { cout << e.what() << endl; }
}

void UI::uiDeleteFriendship() {
    try {
        string username1, username2;
        cout << "Dati numele primului utilizator: ";
        cin >> username1;
        cout << "Dati numele celui de-al doilea utilizator: ";
        cin >> username2;

        network.deleteFriendship(username1, username2);
    }
    catch (invalid_argument &e) { cout << e.what() << endl; }
}

void UI::uiUserFriendships() {
    string username;
    cout << "Dati numele utilizatorului: ";
    cin >> username;
    cout << network.userFriends(username);
}

void UI::uiCommonFriends() {
    string username1, username2;
    cout << "Dati numele primului utilizator: ";
    cin >> username1;
    cout << "Dati numele celui de-al doilea utilizator: ";
    cin >> username2;
    cout << network.commonFriends(username1, username2);

}

void UI::uiSendMessage() {
    string username1, username2, message;
    cout << "Dati username-ul expeditorului: ";
    cin >> username1;
    cout << "Dati username-ul destinatarului: ";
    cin >> username2;
    cout << "Dati mesajul: " << endl;
    cin.ignore();
    std::getline(std::cin, message);

    network.addMessage(username1, username2, message);
}

void UI::uiUpdateMessage() {
    try {
        string username1, username2, message, messagee;
        cout << "Dati username-ul expeditorului: ";
        cin >> username1;
        cout << "Dati username-ul destinatarului: ";
        cin >> username2;
        cout << "Dati mesajul vechi: ";
        cin >> message;
        cout << "Dati mesajul nou: ";
        cin.ignore();
        getline(cin, messagee);
        network.updateMessage(username1, username2, message, messagee);
    }
    catch (invalid_argument &e) { cout << e.what() << endl; }
}

void UI::uiDeleteMessage() {
    try {
        string username1, username2, message;
        cout << "Dati username-ul expeditorului: ";
        cin >> username1;
        cout << "Dati username-ul destinatarului: ";
        cin >> username2;
        cout << "Dati mesajul: ";
        cin.ignore();
        getline(cin, message);
        network.deleteMessage(username1, username2, message);
    }
    catch (invalid_argument &e) { cout << e.what() << endl; }
}

void UI::uiConversation() {
    string username1, username2;
    cout << "Dati username-ul primului utilizator: ";
    cin >> username1;
    cout << "Dati username-ul celui de-al doilea utilizator: ";
    cin >> username2;
    cout << network.getConversation(username1, username2);
}

void UI::uiUserConversations() {
    string username;
    cout << "Dati username-ul utilizatorului: ";
    cin >> username;
    Dictionary<string, Array<Message>> conversations;
    conversations = network.getUserConversations(username);
    cout << "\nConversatiile utilizatorului " << username << ": " << endl;
    for (int i = 0; i < conversations.getSize(); i++) {
        cout << "\n Cu utilizatorul ";
        cout << conversations.getKeys().getElement(i) << ":" << endl;
        cout << conversations.getValues().getElement(i);
    }
}
