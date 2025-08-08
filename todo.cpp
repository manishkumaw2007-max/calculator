// todo.cpp
#include <bits/stdc++.h>
using namespace std;

struct Task {
    int id;
    string desc;
    bool done;
};

vector<Task> tasks;
int nextId = 1;
const string DBFILE = "tasks.db";

void loadTasks() {
    ifstream fin(DBFILE);
    if (!fin) return;
    string line;
    while (getline(fin, line)) {
        if(line.empty()) continue;
        // format: id|done|desc
        stringstream ss(line);
        string id_s, done_s, desc;
        if (!getline(ss, id_s, '|')) continue;
        if (!getline(ss, done_s, '|')) continue;
        if (!getline(ss, desc)) desc = "";
        Task t;
        t.id = stoi(id_s);
        t.done = (done_s == "1");
        t.desc = desc;
        tasks.push_back(t);
        nextId = max(nextId, t.id + 1);
    }
    fin.close();
}

void saveTasks() {
    ofstream fout(DBFILE);
    for (auto &t : tasks) {
        fout << t.id << "|" << (t.done ? "1" : "0") << "|" << t.desc << "\n";
    }
    fout.close();
}

void addTask() {
    cout << "Task description dalen: ";
    string s;
    getline(cin, s);
    if (s.empty()) {
        cout << "Empty task nahi add hota.\n";
        return;
    }
    Task t{nextId++, s, false};
    tasks.push_back(t);
    saveTasks();
    cout << "Task added with id " << t.id << ".\n";
}

void listTasks() {
    if (tasks.empty()) {
        cout << "Koi task nahi hai.\n";
        return;
    }
    cout << "ID  | Status | Description\n";
    cout << "----+--------+------------------------------\n";
    for (auto &t : tasks) {
        cout << setw(3) << t.id << " | " << (t.done ? "Done   " : "Pending") << " | " << t.desc << "\n";
    }
}

void markComplete() {
    cout << "Kaunsa ID complete mark karna hai? ID dalen: ";
    int id;
    if (!(cin >> id)) { cin.clear(); cin.ignore(10000,'\n'); cout << "Invalid input.\n"; return; }
    cin.ignore(10000,'\n');
    for (auto &t : tasks) {
        if (t.id == id) {
            if (t.done) cout << "Task already marked done.\n";
            else {
                t.done = true;
                saveTasks();
                cout << "Task " << id << " marked done.\n";
            }
            return;
        }
    }
    cout << "Task id nahi mila.\n";
}

void removeTask() {
    cout << "Kaunsa ID remove karna hai? ID dalen: ";
    int id;
    if (!(cin >> id)) { cin.clear(); cin.ignore(10000,'\n'); cout << "Invalid input.\n"; return; }
    cin.ignore(10000,'\n');
    auto it = remove_if(tasks.begin(), tasks.end(), [&](const Task &t){ return t.id == id; });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        saveTasks();
        cout << "Task " << id << " removed.\n";
    } else {
        cout << "Task id nahi mila.\n";
    }
}

void showMenu() {
    cout << "\n--- To-Do List Menu ---\n";
    cout << "1. Add task\n";
    cout << "2. List tasks\n";
    cout << "3. Mark task complete\n";
    cout << "4. Remove task\n";
    cout << "5. Exit\n";
    cout << "Choice (1-5): ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    loadTasks();
    while (true) {
        showMenu();
        int ch;
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Invalid choice. Dobara try karein.\n";
            continue;
        }
        cin.ignore(10000,'\n'); // consume newline
        switch (ch) {
            case 1: addTask(); break;
            case 2: listTasks(); break;
            case 3: markComplete(); break;
            case 4: removeTask(); break;
            case 5:
                cout << "Bye! Tasks saved in '" << DBFILE << "'.\n";
                return 0;
            default:
                cout << "Invalid choice. 1-5 me se chunen.\n";
        }
    }
    return 0;
}
