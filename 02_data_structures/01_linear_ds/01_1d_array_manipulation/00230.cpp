#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> books;
    queue<string> q;
    string in;
    getline(cin, in);
    while (in != "END") {
        in.erase(0, 1);
        books.push_back(in.substr(0, in.find('"')));
        getline(cin, in);
    }

    getline(cin, in);
    while(in != "END") {
        string book, inst = in.substr(0, 6);
        
        if (inst == "SHELVE") {
            while(!q.empty()){
                books.push_back(q.front());
                q.pop();
            }
        } else {
            book = in.substr(8, in.size()-9);

            if (inst == "BORROW") {
                for (int i=0; i<books.size(); i++) {
                    if (books[i] == book) {
                        books.erase(books.begin() + i);
                    }
                }
            }
            else {
                q.push(book);
            }
        }
        getline(cin, in);
    }
    
    return 0;
}