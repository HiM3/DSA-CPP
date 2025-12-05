#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T>
class MemoryCalculate {
	private:
		T id;
		string name;
	public:
		MemoryCalculate(T id, string name) : id(id), name(name) {}
		void display() const {
			cout << "ID: " << id << ", Name: " << name << endl;
		}
		T getId() const {
			return id;
		}
};
template <typename T>
class StudentManagement {
	private:
		vector<MemoryCalculate<T>> students;

	public:
		void addStudent(T id, string name) {
			students.push_back(MemoryCalculate<T>(id, name));
		}
		void displayAll() const {
			if (students.empty()) {
				cout << "No students in the list." << endl;
				return;
			}
			for (const auto& student : students) {
				student.display();
			}
		}
		void removeStudentById(T id) {
			auto it = remove_if(students.begin(), students.end(),
			[id](const MemoryCalculate<T>& student) {
				return student.getId() == id;
			});

			if (it != students.end()) {
				students.erase(it, students.end());
				cout << "Student with ID " << id << " removed successfully." << endl;
			} else {
				cout << "Student with ID " << id << " not found." << endl;
			}
		}
		void searchStudentById(T id) const {
			for (const auto& student : students) {
				if (student.getId() == id) {
					cout << "Student found: ";
					student.display();
					return;
				}
			}
			cout << "Student with ID " << id << " not found." << endl;
		}
};




int main() {
	StudentManagement<int> management;
	int choice, id;
	string name;

	do {
		cout << "\nStudent Management System\n";
		cout << "1. Add Student\n";
		cout << "2. Display All Students\n";
		cout << "3. Remove Student by ID\n";
		cout << "4. Search Student by ID\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter Student ID and Name: ";
				cin >> id;
				cin.ignore();
				getline(cin, name);
				management.addStudent(id, name);
				break;
			case 2:
				management.displayAll();
				break;
			case 3:
				cout << "Enter Student ID to Remove: ";
				cin >> id;
				management.removeStudentById(id);
				break;
			case 4:
				cout << "Enter Student ID to Search: ";
				cin >> id;
				management.searchStudentById(id);
				break;
			case 5:
				cout << "Exiting...\n";
				break;
			default:
				cout << "Invalid choice! Try again.\n";
		}
	} while (choice != 5);

	return 0;
}
