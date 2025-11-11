#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    int pid, arrival, burst, priority;
    int remaining, completion, turnaround, waiting;
    bool completed;
};

// Comparator for sorting by arrival time
bool compareArrival(Process a, Process b) {
    if (a.arrival == b.arrival)
        return a.pid < b.pid;
    return a.arrival < b.arrival;
}

// -------------------- Round Robin Scheduling --------------------
void roundRobin(vector<Process> p) {
    int n = p.size();
    int quantum;
    cout << "\nEnter Time Quantum: ";
    cin >> quantum;

    int currentTime = 0, completed = 0;
    queue<int> q;
    vector<int> gantt;
    vector<bool> inQueue(n, false);

    sort(p.begin(), p.end(), compareArrival);

    // Push processes arriving at time 0
    for (int i = 0; i < n; i++) {
        p[i].remaining = p[i].burst;
        if (p[i].arrival <= currentTime && !inQueue[i]) {
            q.push(i);
            inQueue[i] = true;
        }
    }

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        gantt.push_back(p[idx].pid);

        int execTime = min(quantum, p[idx].remaining);
        p[idx].remaining -= execTime;
        currentTime += execTime;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= currentTime && !inQueue[i] && p[i].remaining > 0) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (p[idx].remaining == 0) {
            p[idx].completion = currentTime;
            completed++;
        } else {
            q.push(idx);
        }

        if (q.empty() && completed < n) {
            for (int i = 0; i < n; i++) {
                if (p[i].remaining > 0) {
                    currentTime = max(currentTime, p[i].arrival);
                    q.push(i);
                    inQueue[i] = true;
                    break;
                }
            }
        }
    }

    float avgTAT = 0, avgWT = 0;
    for (auto &proc : p) {
        proc.turnaround = proc.completion - proc.arrival;
        proc.waiting = proc.turnaround - proc.burst;
        avgTAT += proc.turnaround;
        avgWT += proc.waiting;
    }

    // Gantt Chart
    cout << "\nGantt Chart (Round Robin):\n ";
    for (int i = 0; i < gantt.size(); i++) {
        if (i == 0 || gantt[i] != gantt[i - 1])
            cout << "|  P" << gantt[i] << "  ";
    }
    cout << "|\n";

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &proc : p) {
        cout << "P" << proc.pid << "\t" << proc.arrival << "\t" << proc.burst
             << "\t" << proc.completion << "\t" << proc.turnaround << "\t" << proc.waiting << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << avgTAT / n;
    cout << "\nAverage Waiting Time: " << avgWT / n << "\n";
}

// -------------------- Priority Scheduling --------------------
void priorityScheduling(vector<Process> p) {
    int n = p.size();
    sort(p.begin(), p.end(), compareArrival);

    int completed = 0, currentTime = 0;
    vector<int> gantt;

    while (completed != n) {
        int idx = -1, highestPriority = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= currentTime && !p[i].completed) {
                if (p[i].priority < highestPriority) {
                    highestPriority = p[i].priority;
                    idx = i;
                } else if (p[i].priority == highestPriority && p[i].arrival < p[idx].arrival) {
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].completion = currentTime + p[idx].burst;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            p[idx].completed = true;
            currentTime = p[idx].completion;
            gantt.push_back(p[idx].pid);
            completed++;
        } else {
            currentTime++;
        }
    }

    float avgTAT = 0, avgWT = 0;
    for (auto &proc : p) {
        avgTAT += proc.turnaround;
        avgWT += proc.waiting;
    }

    cout << "\nGantt Chart (Priority Scheduling):\n ";
    for (int i = 0; i < gantt.size(); i++)
        cout << "|  P" << gantt[i] << "  ";
    cout << "|\n";

    cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (auto &proc : p) {
        cout << "P" << proc.pid << "\t" << proc.arrival << "\t" << proc.burst << "\t" << proc.priority
             << "\t" << proc.completion << "\t" << proc.turnaround << "\t" << proc.waiting << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << avgTAT / n;
    cout << "\nAverage Waiting Time: " << avgWT / n << "\n";
}

// -------------------- Main Function --------------------
int main() {
    int n, choice;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "\nEnter Process ID: ";
        cin >> processes[i].pid;
        cout << "Enter Arrival Time: ";
        cin >> processes[i].arrival;
        cout << "Enter Burst Time: ";
        cin >> processes[i].burst;
        cout << "Enter Priority: ";
        cin >> processes[i].priority;
        processes[i].remaining = processes[i].burst;
        processes[i].completed = false;
    }

    do {
        cout << "\nChoose Scheduling Algorithm:\n";
        cout << "1. Round Robin\n2. Priority (Non-Preemptive)\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: roundRobin(processes); break;
            case 2: priorityScheduling(processes); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
