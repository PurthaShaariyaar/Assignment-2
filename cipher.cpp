#include <iostream> 

using namespace std;

string encryptCeaser(string plainText, int k) {
    
    // stores the encrypted text 
    string ecrypted;

    ecrypted = plainText;

    for (int i = 0; i < plainText.length(); i++)
    {
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
            ecrypted[i] = 65 + (plainText[i] + k - 65) % 26;
            
        else if (plainText[i] >= 'a' && plainText[i] <= 'z')
            ecrypted[i] = 97 + (plainText[i] + k - 97) % 26;

        // taking mod of 26 so that character again comes back to start if go beyond range
    }
    return ecrypted;
}

string decryptCeaser(string plainText, int k) {
    
    // stores the decrypted text 
    string decrypted = ""; 

    decrypted = plainText;

    // use the for loop to check each char of inputText
    for (int i = 0; i < plainText.length(); i++) {

        if (plainText[i] >= 'A' && plainText[i] <= 'Z') 
            decrypted[i] = 65 + (plainText[i] - k - 65) % 26;
            
        else if (plainText[i] >= 'a' && plainText[i] <= 'z') 
            decrypted[i] = 97 + (plainText[i] - k - 97) % 26;
    }

    // return the decrypted string 
    return decrypted;
}

int main() {
    const int k = 7;
    string str;
    string option;
    // int method;
    int choice;
    cout << "Welcome to Cryptographic Techniques Program" << endl;
    cout << "If you want to use this program enter Y, if you don't enter N: " << endl; 
    cin >> option; 

    while (option == "Y" && option != "N") {

        cout << "Choose a Ceaser method, enter 1 to Encrypt or 2 to Decrypt: " << endl;
        cin >> choice; 

        cout << "Please enter the message: " << endl;
        fflush(stdin);
        getline(cin, str);

        if (choice == 1) {
            cout << encryptCeaser(str, k) << endl;
        } else if (choice == 2) {
            cout << decryptCeaser(str, k) << endl;
        }

        cout << "Do you want to continue using this program, enter Y to continue or N to exit" << endl;
        cin >> option; 
    }

    cout << "Thank you for using our Cryptographic Techniques Program!" << endl;
}
