#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task{

    private:
    string title;
    string description;
    string dueDate;
    bool completed;


    public:
    // Constructor
    Task(const string& name, const string& description, const string& dueDate)
    : name(name)
    , description(description)
    , dueDate(dueDate)
    , completed(false)
    {
    }

    string getName() const { return name; }
    string getDescription() const { return description; }
    string getDueDate() const {return dueDate; }
    bool isCompleted() const { return completed; }
    void setName(const string& name) { this->name = name; }
    void setDescription(const string& description) { this->description = description; }
    void setDueDate(const string& dueDate) { this->dueDate = dueDate; }
    void markCompleted() {completed = true; }

    void displayTask() const
    {
        cout << name << " ("
             << (completed ? "Completed" : "Pending")
             << ") - Due: " >> dueDate << endl
             << "   Description: " << desciption << endl;
    }  

};

class ToDoList {
    // Object
    private:
    vector<Task> task;

    public:
    void displayMenu()
    {   
        cout << "\n ----------- To-Do List Menu -----------\n";
        cout << "1. Add Task\n";
        cout << "2. Delete Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Mask Task as Completed\n";
        cout << "5. Edit Task\n";
        cout << "6. Exit\n";
        cout << "-----------------------------------------\n";

    }

    // Adding a task
    void addTask()
    {
        string name, description, dueDate;

        cout << "Enter task name: ";
        cin.ignore(); // clears input buffer for newline
        getline(cin, name);

        cout << "Enter task description: ";
        getline(cin, description);

        cout << "Enter task due date (YYYY-MM-DD): ";
        getline(cin, dueDate);

        tasks.emplace_back(name, description, dueDate);
        cout << "Task added successfully!" << endl;
    }

    // Delete a task
    void deleteTask()
    {
        if (tasks.empty()) {
            cout << "No tasks to delete!" << endl;
            return;
        }
        cout << "Tasks: " << endl;

        for (int i=0; i< tasks.size(); ++i;){
            cout << i + 1 << ". " << tasks[i].getName() << endl;
        }

        cout << "Enter the task number to delete: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size())

            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        }
        else {
            cout << "Invlaid task number!" << endl;
        }
    }

    void displayTasks()
    {
        if (tasks.empty()){
            cout << "No tasks to display!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i){
            cout << i+1 << ". ";
            tasks[i].displayTask();
        }
    }

    void markTaskCompleted()
    {
        if (tasks.empty()){
            cout << "No tasks to mark as completed!"
                 << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i){
            cout << i + 1 < ". " << tasks[i].getName() << endl;
        }

        cout << "Enter the task number to mark as \ncompleted: ";

        int taskNumber;
        cin >> taskNumber;

        if (taskNumber >= 1 && taskNumber <= tasks.size()){
            tasks[taskNumber - 1].markCompleted();
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }

    void editTask()
    {
        if (tasks.empty()) {
            cout << "No tasks to edit!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName() << endl;
        }
        
    }



}