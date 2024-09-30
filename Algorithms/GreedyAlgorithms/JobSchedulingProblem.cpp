#include <iostream>
#include <vector>
using namespace std;
struct Job {
    int id;
    int deadLine;
    int profit;
};
bool jobCompare(Job a, Job b){
    return (a.profit > b.profit);
}
void jobSequencing(vector<Job>& jobs){
    // Sort the Jobs according to their profits
    sort(jobs.begin(), jobs.end(), jobCompare);
    int n = jobs.size(); // Slots
    vector<int> result(n, -1);
    vector<bool> slot(n, false);
    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        // Find a free slot
        for (int j = min(n,jobs[i].deadLine)-1; j >= 0 ; j--) {
            // If this slot is free
            if (!slot[j]){
                result[j] = i; // Add that job to the result
                slot[j] = true; // Update the slot to true
                maxProfit += jobs[i].profit; // Update the profit
                break;
            }
        }
    }
    cout << "Maximum Profit Sequencing Of JOBS: ";
    for (int i = 0; i < n; ++i) {
        if (result[i] != -1){
            cout << jobs[result[i]].id << " ";
        }
    }
    cout << endl << "Total Profit: " << maxProfit << endl;
}
int main() {
    vector<Job> jobs = {
            {1,4,20},
            {2,1,10},
            {3,1,40},
            {4,1,30}
    };
    jobSequencing(jobs);
    return 0;
}
