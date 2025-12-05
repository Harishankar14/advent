// #include <bits/stdc++.h>
// #include <string>
// #include <vector>
// #include <cstdio>
// using namespace std;

// /*
//    Our major motive is nothing but we have to find out the count of 
//    fresh ingredients within the ingredients id.

//    major condition is that, we have been given a fresh ingredient ID range.
//    example (3-5): inclusive this means {3,4,5}
//    now assume that in the ingredient id, there is 1. 
//    We cannot consider 1 as fresh ingredient id !! Why 
//    Simply because it was not in the range of {3-5}

// so if not in the range of fresh ingredients id 
// 		then  flag it as non fresh 
// 		return the count of fresh ingredient id in  ingredient id list 
// */

// void a(){
// 	string a = "12-15";
// 	int number = 7;
// 	int start;
// 	int end;
// 	//now wee need to parse this 
// 	if(sscanf(a.c_str(),"%d-%d",&start,&end)==2){
// 		if(number >=start && number <=end){
// 			cout<<"Yes"<<endl;
// 		}else{
// 			cout<<"No"<<endl;
// 		}
// 	}
// }


struct Range {
    long long  start, end;
};

int main() {
    std::vector<Range> ranges; // This acts as your "memory" of valid ranges
    std::string line;
    long long count = 0;

    int s, e;
    if (sscanf(line.c_str(), "%d-%d", &s, &e) == 2) {
    	ranges.push_back({s, e}); 
    }
    long long id;
    while (std::cin >> id) {
        // For this specific ID, check if it fits in ANY of the saved ranges
        bool present = false;
        
        for (const auto& r : ranges) {
            if (id >= r.start && id <= r.end) {
                present = true;
                break; 
            }
        }
        if (present) {
        	count++;
        }
    }

    std::cout << "Total valid IDs: " << count << std::endl;

    return 0;
}

// second approach much more optimal or preferef

vector<pair<long long, long long>> ranges;

void optimal() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    while (cin >> s) {
        int pos = s.find('-');
        if (pos == -1) break;

        long long a = stoll(s.substr(0, pos));
        long long b = stoll(s.substr(pos+1));
        ranges.push_back(make_pair(a, b));
    }

    sort(ranges.begin(), ranges.end());

    long long res = 0;
    long long left = ranges[0].first;
    long long right = ranges[0].second;
    for (int i = 0; i < ranges.size(); i++) {
        if (ranges[i].first <= right) {
            right = max(right, ranges[i].second);
        } else {
            res += right - left + 1;
            left = ranges[i].first;
            right = ranges[i].second;
        }
    }

    res += right - left + 1;

    cout << res << '\n';

    return 0;
}
