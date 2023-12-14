/*This program provides a simple interactive experience where the user can input names,
 and the program will use Bubble Sort to alphabetically sort and display the names. 
 It's a practical way to visualize and understand the Bubble Sort algorithm.*/

#include <iostream>
#include <vector>

using namespace std;

// Custom swap function for swapping elements in a vector
void customSwap(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<string>& names) {
    int n = names.size();
    bool swapped;

    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (names[i - 1] > names[i]) {
                customSwap(names[i - 1], names[i]);
                swapped = true;
            }
        }
        --n;
    } while (swapped);
}

int main() {
    vector<string> names;

    cout << "Enter names (type 'end' when done):\n";
    string name;
    while (true) {
        cout << "> ";
        cin >> name;
        if (name == "end") {
            break;
        }
        names.push_back(name);
    }

    bubbleSort(names);

    cout << "\nSorted Names:\n";
    for (const auto& sortedName : names) {
        cout << sortedName << "\n";
    }

    return 0;
}
