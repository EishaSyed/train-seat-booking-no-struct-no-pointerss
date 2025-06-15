#include <iostream>
using namespace std;

// 3D array: 3 bogies, 7 rows, 4 seats per row
int train[3][7][4] = {
    {   // Bogie 1
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 2, 2, 0},
        {2, 1, 0, 0},
        {0, 0, 0, 2},
        {1, 1, 1, 1}
    },
    {   // Bogie 2
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 2, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 0, 2, 2}
    },
    {   // Bogie 3
        {1, 0, 0, 1},
        {0, 0, 0, 0},
        {2, 2, 2, 2},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 1, 0}
    }
};

void showMenu() {
    cout << "\n===== Train Seat Booking Menu =====" << endl;
    cout << "1. Book a Seat" << endl;
    cout << "2. View Seat Layout" << endl;
    cout << "3. Exit" << endl;
    cout << "===================================" << endl;
}

void showSeats() {
    cout << "\nSeat Layout:\n";
    cout << "0 = Available, 1 = Booked, 2 = Not Available\n\n";

    for (int b = 0; b < 3; ++b) {
        cout << " Bogie " << b + 1 << ":\n";
        for (int i = 0; i < 7; ++i) {
            cout << "Row " << i + 1 << ": ";
            for (int j = 0; j < 4; ++j) {
                // Format like [A][B] passageway [C][D]
                if (j == 2) cout << "  "; // Space for passageway
                cout << train[b][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void bookSeat() {
    int bogie, row, col;
    cout << "Enter bogie (1-3): ";
    cin >> bogie;
    cout << "Enter row (1-7): ";
    cin >> row;
    cout << "Enter column (1-4): ";
    cin >> col;

    bogie--;
    row--;
    col--;

    if (bogie < 0 || bogie >= 3 || row < 0 || row >= 7 || col < 0 || col >= 4) {
        cout << "Invalid seat location!" << endl;
        return;
    }

    if (train[bogie][row][col] == 1) {
        cout << "Seat is already booked!" << endl;
    } else if (train[bogie][row][col] == 2) {
        cout << "Seat is not available!" << endl;
    } else if (train[bogie][row][col] == 0) {
        train[bogie][row][col] = 1;
        cout << "Seat booked successfully in Bogie " << bogie + 1 << ", Row " << row + 1 << ", Column " << col + 1 << "!" << endl;
    } else {
        cout << "Unknown seat status!" << endl;
    }
}

int main() {
    int choice;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookSeat();
                break;
            case 2:
                showSeats();
                break;
            case 3:
                cout << "Exiting the system. Have a safe journey!" << endl;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
