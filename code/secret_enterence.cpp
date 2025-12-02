#include <bits/stdc++.h>
#include <vector>
#include <variant>
#include <string>
using namespace std;

/*numbers from 0 to 99 
	turn the dial -> make a small click 
	Rotation (starts with l,r) l -> left (lower number), r -> right (higher number)
	distance value -> no of clicks the dial should be rotated in that direction. 
*/

void some_fun(){
	using ElementType = std::variant<std::string,int>;
	vector<ElementType> myvector;
	myvector.push_back("Hello");
	myvector.push_back(1);

	// inorder to access the element we can use lambda 
	for(const auto& item:myvector){
		std::visit([](auto&& arg){
			cout<<arg<<endl;
		},item);
	}
}



int main() {
    int current_pos = 50; // inital starting given as 50 .. should be golden star. 
    int password_count = 0;
    
    string token;
    while (cin >> token) {
        char direction = token[0];     // taking only the first part suppose if input is L99, load L into dir.
        int distance = stoi(token.substr(1)); //common sense. 
        if (direction == 'R') {
            current_pos = (current_pos + distance) % 100;
        } 
        else if (direction == 'L') {
            current_pos = current_pos - distance;
            current_pos %= 100;      // buffer it upto 99 
            if (current_pos < 0) {   // if neg  add 100
                current_pos += 100;
            }
        }
        if (current_pos == 0) {
            password_count++;
        }
    }
    cout << "Final Password Count: " << password_count << endl;
    return 0;
}
