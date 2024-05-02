#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<int> job_id(n);
    vector<int> deadline(n);
    vector<int> profit(n);

    cout << "\nEnter the details of the jobs:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "\nJob " << i + 1 << ":" << endl;
        cout << "Enter the id of the job: ";
        cin >> job_id[i];
        cout << "Enter the deadline of the job: ";
        cin >> deadline[i];
        cout << "Enter the profit of the job: ";
        cin >> profit[i];
    }

    vector<int> slots(*max_element(deadline.begin(), deadline.end()) + 1, 0);

    int total_profit = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = deadline[i]; j > 0; --j) {
            if (slots[j] == 0) {
                slots[j] = job_id[i];
                total_profit += profit[i];
                break;
            }
        }
    }

    cout << "\nScheduled Jobs: ";
    for (int i = 1; i < slots.size(); ++i) {
        if (slots[i] != 0) {
            cout << slots[i] << " ";
        }
    }
    cout << "\n\nTotal Profit: " << total_profit << endl;

    return 0;
}
