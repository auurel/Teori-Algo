#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Struct untuk menyimpan tugas dengan prioritas
struct Task {
    int priority;
    string task;
    
    // Overload operator > untuk membuat min-heap
    bool operator>(const Task& other) const {
        return priority > other.priority;
    }
};

int main() {
    // Deklarasi priority queue dengan min-heap
    priority_queue<Task, vector<Task>, greater<Task>> pq;

    // Menambahkan beberapa task ke priority queue
    pq.push({3, "Task C"});
    pq.push({1, "Task A"});
    pq.push({2, "Task B"});
    pq.push({4, "Task D"});

    // Mengambil elemen dari priority queue dan menampilkannya
    cout << "Priority Queue:" << endl;
    while (!pq.empty()) {
        Task t = pq.top();
        pq.pop();
        cout << "Priority: " << t.priority << ", Task: " << t.task << endl;
    }

    return 0;
}
