#include <iostream> 

using namespace std;

string encryptCeaser(string inputText, int k) {
    
    // stores the encrypted text 
    string encrypted = "";

    // use for loop to check each char of inputText 
    for (int i = 0; i < inputText.length(); i++) {

        // if there is a space just return a space
        if (isspace(inputText[i])) {
            encrypted += inputText[i];
        }

        // check if it's an uppercase char if yes, apply shift 
        else if (isupper(inputText[i])) {
            encrypted += char(int(inputText[i] + k - 65) % 26 + 65); 
        }

        // if it's not uppercase, then lowercase, apply shift 
        else {
            encrypted += char(int(inputText[i] + k - 97) % 26 + 97);
        }
    }

    // return the encrypted string 
    return encrypted; 

}

string decryptCeaser(string inputText, int k) {
    
    // stores the decrypted text 
    string decrypted = ""; 

    // use the for loop to check each char of inputText
    for (int i = 0; i < inputText.length(); i++) {

        // check if it's an uppercase, apply reverse shift 
        if (isupper(inputText[i])) {
            decrypted += char(int(inputText[i] - k - 65) % 26 + 65);
        }

        // if it's not uppercase, then lowercase, apply reverse shift
        else {
            decrypted += char(int(inputText[i] - k - 97) + 97);
        }
    }

    // return the decrypted string 
    return decrypted;
}

int main() {
    
    // cipher key 
    const int k = 4; 
    string str; 


    cout << "Enter text: " << endl;
    cin >> str; 

    cout << "The decrypted text is: " << decryptCeaser(str, k);

}