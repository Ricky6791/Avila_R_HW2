#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void isPalindromic(string p);
void makePalindromic(string p);

void isPalindromic(vector<string> q);
void makePalindromic(vector<string> q);

void isPalindromic(vector<int> r);
void makePalindromic(vector<int> r);

int main(){
    string input;
    cout << "What do you wanna check to see if it is a palindrome?\n";
    getline (cin, input);
    string p = input;
    vector<string> q;
    string empty = "";
    int i = 0;
    int length = 0;
    while(i <= input.length()){
        if (input[i] != ' '){
            empty += input[i];
        }
        else if (input[i] == ' '){
            q.push_back(empty);
            empty = "";
        }
        if (i == input.length() && input[i] != ' '){
        //if last character isnt space
        q.push_back(empty);
        }
        i++;
    }
    stringstream iss(input);
    int number;
    vector<int> r;
    while (iss >> number){
        r.push_back(number);
    }

    isPalindromic(p);
    isPalindromic(q);
    isPalindromic(r);
    return 0;
}

void isPalindromic(string p){
    string backwards = p;
    reverse(backwards.begin(), backwards.end());
    if (p == backwards){
        cout << "Palindromic string.\n";
    }
    else {
        /*return "Not a palindrome\n";*/
         makePalindromic(p);
    }
}
void makePalindromic(string p){
    cout << "Not a palindromic string. A generated one : ";
    string savedCharacters;
    string backwards;
    string original = p;
    while (p != backwards && p.length() >= 2){
        backwards = p;
        reverse(backwards.begin(), backwards.end());
        savedCharacters.append(p,0,1);
        p.erase(0,1);
    }
    reverse(savedCharacters.begin(), savedCharacters.end());
    cout << original + savedCharacters << endl;

}
void isPalindromic(vector<string> q){
    vector<string> backwards = q;
    
    reverse(backwards.begin(), backwards.end());
    if (q == backwards){
        cout << "is a palindromic sentence\n";
    }
    else{
        makePalindromic(q);
    }
}

void makePalindromic(vector<string> q){
    cout << "Not a palindromic sentence. A generated one: ";
  
    vector<string> back = q;
    //grab words and put them in the back after words have been reversed from previous make palindrome
    for(int i = q.size(); i >= 0; i--){
        back.push_back(q[i]);
    }
    for(int i = 0; i < back.size(); i++){
        cout << back[i]<< " ";
    }
    cout << endl;

}

void isPalindromic(vector<int> r){
    vector<int> compare = r;
    reverse(compare.begin(), compare.end());
    //compares the mirror image of it
    if (r == compare){  
        cout << "is a Palindromic number sequence"<<endl;
    }
    else{
        makePalindromic(r);
    }
}

void makePalindromic(vector<int> r){
    cout << "Not a palindromic number sequence. A generated one: ";
    //vector<int> reverse = r;
    int length = r.size();
    //cout << length - 1 << endl;
    //get the first element and last element and start comparing
    for (int i = 0, j = length - 1; i <= j;){
        //if same continue
        if(r[i] == r[j]){
            i++;
            j--;
        }
        else{
            j--;
            r.push_back(r[j]);
        }
    }
    for(int i = 0; i < r.size(); i++){
        cout << r[i]<< " ";
    }
    

}