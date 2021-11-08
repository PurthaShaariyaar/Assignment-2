#include <iostream> 

using namespace std;

string encryptCeaser(string plainText, int k) {
    
    // stores the encrypted text 
    string ecrypted;

    ecrypted = plainText;

    for (int i = 0; i < plainText.length(); i++)
    {
        if (plainText[i] >= 'A' && plainText[i] <= 'Z') // for uppercase characters , substract 65 from them
            ecrypted[i] = 65 + (plainText[i] + k - 65) % 26;
        else if (plainText[i] >= 'a' && plainText[i] <= 'z') // for lowercase characters , substract 97 from them
            ecrypted[i] = 97 + (plainText[i] + k - 97) % 26;

        // taking mod of 26 so that character again comes back to start if go beyond range
    }
    return ecrypted;
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
    const int k = 4;
    string str;
    cout << "Enter message: " << endl;
    fflush(stdin);
    getline(cin, str);
    cout << "The encrpted text is: " << encryptCeaser(str, k);
}
