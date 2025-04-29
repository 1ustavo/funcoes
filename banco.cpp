#include <iostream>
using namespace std;

float depositary(float balance, float value) {
	float result = balance + value;
	cout << "Deposit successful. Updated balance: " << result << endl;
	return result;
}

void sake(float balance, float sake) {
	if (sake > balance) {
		cout << "Insufficient funds!" << endl;
	}
	else {
		float r = balance - sake;
		cout << "Withdrawal successful. Updated balance: " << r << endl;
	}
}

float lending(float balance, float loan) {
	float interest = loan * 0.10f;
	cout << "Monthly interest (10%): " << interest << endl;
	cout << "Total to repay: " << (loan + interest) << endl;
	float new_balance = balance + loan;
	cout << "Loan credited. Updated balance: " << new_balance << endl;
	return new_balance;
}

int main() {
	float balance = 1000;
	int choice;
	float amount;

	cout << "Welcome to bank" << endl;

	while (true) {
		cout << "What would you like to do today?" << endl;
		cout << "1 - Deposit" << endl;
		cout << "2 - Withdraw" << endl;
		cout << "3 - Request a loan" << endl;
		cout << "4 - Check balance" << endl;
		cout << "5 - Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: //deposito
			cout << "Enter amount to deposit: ";
			cin >> amount;
			if (amount <= 0) {
				cout << "Invalid amount!" << endl;
			}
			else {
				balance = depositary(balance, amount);
			}
			break;

		case 2: //saque
			cout << "Enter amount to withdraw: ";
			cin >> amount;
			if (amount <= 0) {
				cout << "Invalid amount!" << endl;
			}
			else {
				sake(balance, amount);
			}
			break;

		case 3: //emprestimo

			cout << "Loan options: " << endl;
			cout << "1 - 500" << endl;
			cout << "2 - 5.000" << endl;
			cout << "3 - 10.000" << endl;
			cout << "Enter your choice (1-3): ";
			int loan_option;
			cin >> loan_option;

			float loan_amount;
			switch (loan_option) {
			case 1:
				loan_amount = 500;
				break;
			case 2:
				loan_amount = 5000;
				break;
			case 3:
				loan_amount = 10000;
				break;
			default:
				cout << "Invalid loan option!" << endl;
				continue;
			}
			balance = lending(balance, loan_amount);
			break;

		case 4: // ver saldo
			cout << "Current balance: " << balance << endl;
			break;

		case 5:
			cout << "Thank you for using The bank, Goodbye!" << endl;
			return 0;

		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	}
	return 0;
}
