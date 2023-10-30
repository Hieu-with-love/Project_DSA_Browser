// Project_DSA_Browser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

struct NodeWindow {
	// data;
	Window window;
	NodeWindow* prev;
	NodeWindow* next;
	NodeWindow(Window item) {
		this->window = item;
		this->prev = NULL;
		this->next = NULL;
	}
};
class WindowList {
private :
	NodeWindow* head;
	NodeWindow* tail;
	NodeWindow* current;
public:
	WindowList() {
		head = NULL;
		tail = NULL;
		current = NULL;
	}
	void addWindow(string thongbao) {
		NodeWindow *newNode = new NodeWindow(thongbao);
		if (head == NULL) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		current = tail;
	}
	void deleteWindow() {
		if (head == NULL) {
			cout << "Danh sach rong khong xoa" << endl;
			return;
		}
		else if (head == tail) {
			NodeWindow* p = head;
			head = tail = current = NULL;
			delete p;
		}
		else {
			if (current == head) {
				head = current->next;
			}
			else if (current == tail) {
				tail = current->prev;
			}
			NodeWindow* p = current;
			if (current->prev) {
				current->prev->next = current->next;
			}
			if (current->next) {
				current->next->prev = current->prev;
			}
			current = current->next;
			delete p;
		}
	}
	void backWindow() {
		if (current == head) {
			cout << "Dang o window dau tien. Khong the back." << endl;
		}
		else {
			current = current->prev;
		}
	}
	void nextWindow() {
		if (current == tail) {
			cout << "Dang o window cuoi cung. Khong the next" << endl;
		}
		else {
			current = current->next;
		}
	}
	void printCurrentWindow() {
		cout << current->data << endl;
	}
};

struct NodePage
{
    string url;
    NodePage* next;
    NodePage* prev;
    NodePage(string val)
    {
        url = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Tab {
public:
    NodePage* head;
    NodePage* tail;
    NodePage* currentPage;

    Tab() {
        head = nullptr;
        tail = nullptr;
    }

    void addTail(string address) {
        NodePage* newNode = new NodePage(address);
        currentPage = newNode;
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }


    void deleteHead() {
        if (head != nullptr) {
            NodePage* temp = head;
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                // If head becomes nullptr, update tail as well
                tail = nullptr;
            }

            currentPage = head;
            delete temp;
        }
        else
        {
            cout << "This TAB is empty." << endl;
        }
    }

    void deleteTail() {
        if (tail != nullptr) {
            NodePage* temp = tail;
            tail = tail->prev;

            if (tail != nullptr) {
                tail->next = nullptr;
            }
            else {
                // If tail becomes nullptr, update head as well
                head = nullptr;
            }
            currentPage = tail;
            delete temp;
        }
        else
        {
            cout << "This TAB is empty." << endl;
        }
    }

    void display() {
        NodePage* current = head;
        while (current != nullptr) {
            cout << current->url << " " << endl;
            current = current->next;
        }
        cout << endl;
    }

    void moveNext()
    {
        if (currentPage->next == nullptr)
        {
            cout << "You are at the last Page." << endl;
        }
        else
            currentPage = currentPage->next;
    }
    void moveBack()
    {
        if (currentPage->prev == nullptr)
        {
            cout << "You are at the first Page." << endl;
        }
        else
            currentPage = currentPage->prev;
    }
};

struct NodeTab
{
    Tab tab;
    NodeTab* next;
    NodeTab* prev;
    NodeTab(Tab val)
    {
        tab = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Window {
public:
    NodeTab* head;
    NodeTab* tail;
    NodeTab* currentTab;

    Window() {
        head = nullptr;
        tail = nullptr;
    }

    void addTail(Tab tab) {
        NodeTab* newNode = new NodeTab(tab);
        currentTab = newNode;
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }


    void deleteHead() {
        if (head != nullptr) {
            NodeTab* temp = head;
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                // If head becomes nullptr, update tail as well
                tail = nullptr;
            }

            currentTab = head;
            delete temp;
        }
        else
        {
            cout << "This TAB is empty." << endl;
        }
    }

    void deleteTail() {
        if (tail != nullptr) {
            NodeTab* temp = tail;
            tail = tail->prev;

            if (tail != nullptr) {
                tail->next = nullptr;
            }
            else {
                // If tail becomes nullptr, update head as well
                head = nullptr;
            }
            currentTab = tail;
            delete temp;
        }
        else
        {
            cout << "This TAB is empty." << endl;
        }
    }

    void display() {
        NodeTab* current = head;
        while (current != nullptr) {
            current->tab.display();
            current = current->next;
        }
        cout << endl;
    }

    void moveNext()
    {
        if (currentTab->next == nullptr)
        {
            cout << "You are at the last Tab." << endl;
        }
        else
            currentTab = currentTab->next;
    }
    void moveBack()
    {
        if (currentTab->prev == nullptr)
            cout << "You are at the first Tab." << endl;
        else
            currentTab = currentTab->prev;
    }
};

// Struct để đại diện cho sự kiện lịch sử trong một ngày cụ thể
struct HistoryEvent {
	string event;
	HistoryEvent* prev;
	HistoryEvent* next;

	HistoryEvent(string event) : event(event), prev(NULL), next(NULL) {}
};

// Struct để đại diện cho một ngày và danh sách các sự kiện lịch sử trong ngày đó
struct DayHistory {
	time_t date;
	vector<HistoryEvent*> events;

	DayHistory(time_t date) : date(date) {}
};

class HistoryList {
private:
	vector<DayHistory*> history;

public:
	// Hàm thêm một sự kiện lịch sử vào danh sách theo ngày
	void addEvent(string event, time_t date) {
		HistoryEvent* newEvent = new HistoryEvent(event);
		for (DayHistory* day : history) {
			if (day->date == date) {
				day->events.push_back(newEvent);
				newEvent->prev = day->events.back();
				if (day->events.size() > 1) {
					day->events[day->events.size() - 2]->next = newEvent;
				}
				return;
			}
		}

		// Nếu ngày chưa tồn tại trong lịch sử, thêm một ngày mới và thêm sự kiện đó vào ngày mới
		DayHistory* newDay = new DayHistory(date);
		newDay->events.push_back(newEvent);
		history.push_back(newDay);
	}

	// Hàm in ra tất cả các sự kiện lịch sử cho một ngày cụ thể
	void printEventsForDate(time_t date) {
		for (DayHistory* day : history) {
			if (day->date == date) {
				cout << "Lich su cho ngay " << ctime(&date) << ":\n";
				for (HistoryEvent* event : day->events) {
					cout << " - " << event->event << endl;
				}
				return;
			}
		}
		cout << "Khong co lich su cho ngay " << ctime(&date) << endl;
	}

	void deleteEventsForDate(time_t date) {
		for (DayHistory* day : history) {
			if (day->date == date) {
				for (HistoryEvent* event : day->events) {
					delete event; // Xóa từng sự kiện lịch sử
				}
				day->events.clear(); // Xóa tất cả sự kiện lịch sử trong ngày
				// Nếu bạn muốn xóa cả ngày khỏi lịch sử, bạn có thể sử dụng:
				// delete day;
				// history.erase(remove(history.begin(), history.end(), day), history.end());
				return;
			}
		}
		cout << "Khong co lich su cho ngay " << ctime(&date) << " de xoa." << endl;
	}
	void deleteLatestEventForDate(time_t date) {
		for (DayHistory* day : history) {
			if (day->date == date) {
				if (!day->events.empty()) {
					HistoryEvent* latestEvent = day->events.back();
					delete latestEvent;
					day->events.pop_back();
				}
				if (day->events.empty()) {
					// Nếu không còn sự kiện lịch sử trong ngày, bạn có thể xóa cả ngày
					// delete day;
					// history.erase(remove(history.begin(), history.end(), day), history.end());
				}
				return;
			}
		}
		cout << "Khong co lich su cho ngay " << ctime(&date) << " de xoa." << endl;
	}
};


int main()
{
	WindowList windowList;
	HistoryList history;
	time_t today = time(NULL);
	windowList.addWindow("Day la window 1");
	history.addEvent("Ban vua them mot window", today);
	windowList.addWindow("Day la window 2");
	history.addEvent("Ban vua them mot window", today);
	windowList.addWindow("Day la window 3");
	history.addEvent("Ban vua them mot window", today);
	history.printEventsForDate(today);
	history.deleteLatestEventForDate(today);
	history.printEventsForDate(today);
	return 0;
}


